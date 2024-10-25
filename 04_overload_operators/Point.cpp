#include "Point.h"


string Point::print() const
{
	// (5,2)
	return  name + "(" + to_string(x) + "," + to_string(y) + ")";
}

Point Point::operator+(const Point& other) const
{
	//Point result; // x = 0, y = 0;
	//result.x = this->x + other.x;
	//result.y = this->y + other.y;
	//return result;
	return Point(this->x + other.x, this->y + other.y);
}

Point Point::operator-(const Point& other) const
{
	return Point(this->x - other.x, this->y - other.y);
}

bool Point::operator==(const Point& other) const
{
	return this->x == other.x and this->y == other.y;
}

bool Point::operator!=(const Point& other) const
{
	//return !(this->x == other.x and this->y == other.y);
	return !(*this == other);
}

Point Point::operator+=(double number)
{
	this->x += number;
	this->y += number;
	return *this;
}

Point& Point::operator++()
{
	++this->x;
	++this->y;
	return *this;
}

Point Point::operator++(int)
{
	Point tmp(*this); // copy ctor, зняли копію самого себе
	/*++this->x;
	++this->y;*/
	++* this; 
	return tmp;
}

Point::operator double() const
{
	return sqrt(x * x + y * y);
}
