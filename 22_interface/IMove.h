#pragma once
#include <iostream>
using namespace std;

// interface -  пропонує абстрактну поведінку (може містити чисто віртуальні функції)
struct IMove // 
{
	virtual void move() const = 0;
	virtual size_t getSpeed() const = 0;
};

// можна успадковувати інтерфейси
struct IFly : IMove
{
	virtual void fly() const = 0;
	virtual size_t getHeight() const = 0;
};

class Bird : public IFly
{
public:
	Bird(const size_t & height, const size_t& speed)
		:height(height),speed(speed)
	{
	}
	virtual void move() const
	{
		cout << "Bird " << typeid(*this).name() << " can walk and fly" << endl;
	}
	virtual size_t getSpeed() const  override
	{
		return speed;
	}
	virtual size_t getHeight() const override
	{
		return height;
	}
	virtual void fly() const override
	{
		cout << "Bird " << typeid(*this).name() << " can fly on height " << getHeight() << endl;
	}

private:
	size_t height;
	size_t speed;
};

class Eagle : public Bird
{
public:
	Eagle()
		:Bird(2000,30)
	{

	}
};

class Gull :public Bird
{
public:
	Gull()
		:Bird(500,5)
	{

	}
};

class Car : public IMove // клас Car реалізує інтерфейс IMove ( реалізує кожен абстрактний метод)
{
public:
	Car(const string& brand)
		:brand(brand)
	{
	}
	virtual void move() const
	{
		cout << "Car " << brand << " can move with speed " << getSpeed() << endl;
	}
	virtual size_t getSpeed() const
	{
		return 200;
	}

private:
	string brand;
};


void DemoMoveable(IMove* movable)
{
	cout << "------------- Demo func --------------" << endl;
	movable->move();
	cout << "Speed of moving :: " << movable->getSpeed() << endl;
}

class Owner
{
public:
	Owner(const string& name, IMove* moveable)
		:name{ name }, moveable{ moveable }
	{

	}
	void go()
	{
		moveable->move();
	}
private:
	IMove* moveable;
	string name;
};