#include <iostream>
#include "Point.h"
using namespace std;

int main()
{
    Point A(5,5,"A"), B(10,10,"B");
    cout << A.print() << endl;
    cout << B.print() << endl;

    Point C = A + B;
    Point D = C - B;
    C.setName("C");
    D.setName("D");
    cout << A.print() << " + " << B.print() << " = " << C.print() << endl;
    cout << C.print() << " - " << B.print() << " = " << D.print() << endl;

    cout << A.print() << " == " << B.print() << boolalpha << (A == B) << endl;
    cout << A.print() << " == " << D.print() << boolalpha << (A == D) << endl;
    cout << A.print() << " != " << D.print() << boolalpha << (A != D) << endl;
    cout << A.print() << " != " << B.print() << boolalpha << (A != B) << endl;

    A += 5;
    cout << A.print() << endl;
    //Point E = ++A + B;
    Point E = A++ + B;
    cout << E.print() << endl;
    cout << A.print() << endl;
    cout << "(double)A --> " << (double)A << endl;
}
