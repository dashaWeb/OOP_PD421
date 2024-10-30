#include <iostream>
#include "Engine.h"
#include "Car.h"
using namespace std;
int main()
{
    Engine engine("AB",420,3.8);
    engine.print();

    cout << endl;

    Car car;
    car.print();
    cout << endl;

    Car audi{ "Audi",engine,190 };
    audi.print();
    cout << endl;

    Car bmw{ "BMW",/*Engine*/{"Z1",480,4.1}, 210};
    bmw.print();
    cout << endl;

    Car mercedes("Mercedes","M1",400,3.5,250);
    mercedes.print();
    cout << endl;
}
