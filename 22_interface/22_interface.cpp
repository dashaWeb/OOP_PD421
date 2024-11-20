#include "IMove.h"
#include "IShape.h"


int main()
{
    Eagle eagle;
    eagle.fly();

    Gull gull;
    gull.fly();
    gull.move();
    cout << "Speed :: " << gull.getSpeed() << endl;

    cout << endl;
    IFly& ify = eagle;
    ify.fly();

    cout << endl;
    IMove* imov = &eagle;
    imov->move();

    Car car("BMW");
    DemoMoveable(&car);

    cout << endl;
    Owner owner("Sergiy", &car);
    owner.go();


    IFly* fliers[]{ &eagle,&gull };
    for (auto& i : fliers)
    {
        i->fly();
    }

    cout << endl << endl;
    IMove* Moveables[]{ &eagle, &car, &gull };
    for (auto& i : Moveables)
    {
        i->move();
    }

    cout << "\n\n========================= ISHAPE =======================\n";
    Circle circle;
    circle.setRadius(10);
    cout << "Area :: " << circle.area() << endl;

    const char* test = new char [4]{'h','e','l','\0'};
    auto r = const_cast<char*>(test);
    cout << r << endl;
    r[0] = 'a';
    cout << r << endl;
}



// Визначити клас Квадрат (поле - сторона), який реалізує інтерфейс IShape