#pragma once
#include <iostream>
#include <cmath>
using namespace std;
__interface IShape
{
	double area() const;
};

class Circle : public IShape
{
public:
static const double PI_;
	void setRadius(const double& radius)
	{
		if (radius >= 0)
			this->radius = radius;
	}
	const double& getRadius() const
	{
		return radius;
	}
	double area() const override
	{
		return PI_ * pow(radius, 2);
	}
private:
	double radius = 0;
};

const double Circle::PI_ = 3.14;