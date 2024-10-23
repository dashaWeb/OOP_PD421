#include <iostream>
#include "Food.h"
using namespace std;

//MyClass.h -> struct(class) definition (prototype method) + realization of inline
//MyClass.cpp - realization of notinline
// main.cpp -> program



int main()
{
    cout << Food::MAX_WEIGHT << endl;

    Food food;
    food.setName("Borshch");
    food.setKkal(200);
    food.setWeight(250);
    food.print();

    Food olivie("Salad Olivie",330,200);
    olivie.print();

    Food clone = food; // ctor copy (compile create copy ctor = shallow copy
    //Food clone(food); // ctor copy (compile create copy ctor = shallow copy
    //Food clone{food} // ctor copy (compile create copy ctor = shallow copy
    clone = olivie;
    cout << "\t\t Clone  :: " << endl;
    clone.print();
    cout << "\t\t Origin :: " << endl;
    food.print();

    clone.setName("milk");

    cout << "\t\t Clone  :: " << endl;
    clone.print();
    cout << "\t\t Origin :: " << endl;
    food.print();

    cout << Food::getCounter() << endl;
    
}

