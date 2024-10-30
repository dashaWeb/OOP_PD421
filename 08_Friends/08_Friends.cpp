#include <iostream>
#include "Pupil_Teacher.h"
using namespace std;

class Point {
public: 
    Point(const double& x, const double& y)
        :x{ x }, y{y}
    {

    }
    Point() = default;
    friend void reset(Point& point);
private:
    double x, y;
    friend void print(const Point& point);
};

void print(const Point& point)
{
    cout << point.x << ", " << point.y << endl;
}

void reset(Point& point)
{
    point.x = 0;
    point.y = 0;
}


int main()
{
    /*Point A(5,10);
    print(A);
    reset(A);
    print(A);*/

    Pupil olia("Olia", 7, 8);
    olia.print();

    Teacher teacher;
    teacher.setMarkMath(olia, 12);
    teacher.setMarkEnglish(olia, 13);
    olia.print();
}
