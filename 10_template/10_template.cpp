#include <iostream>
#include "Matrix.h"
using namespace std;

//int sum(int a, int b)
//{
//    return a + b;
//}
//double sum(double a, double b)
//{
//    return a + b;
//}
//Fraction sum(Fraction a, Fraction b)
//{
//    return a + b;
//}

//template <typename T>
//T sum(T a, T b)
//{
//    return a + b;
//}


int main()
{
   /* cout << sum(1, 2) << endl;
    cout << sum(1.5, 2.6) << endl;
    cout << sum('a', ' ') << endl;*/

    // 1) компілятор створить визначення класу на основі шаблону класу, <T = int, size_t row = 2, size_t col = 3>
    // 2) створить обєкт класу (викликається відповідний конструктор)

    Matrix <int, 4, 5> m(3);
    //m.print();
    m(0, 1) = 22;
    cout << m << endl;

    cout << m + 2;

    Matrix<> m2;
    cout << m2 << endl;


    Matrix<double, 3, 3> m3(3.3);
    cout << m3 << endl;
    m3(1, 1) = 99.77;
    cout << m3 << endl;


    Matrix<string, 5, 5> s("Test");
    cout << s << endl;
    s(2, 2) = "Ok";
    cout << s << endl;
}
