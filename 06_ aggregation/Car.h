#pragma once
#include "Engine.h"

class Car {
public:
	Car(const string& brand, const Engine& engine, size_t maxSpeed);
	Car(const string& brand, const string& model, const size_t& power, const double& volume, size_t maxSpeed);
	Car() = default;
	void print() const;
private:
	string brand = "Nobrand";
	Engine engine = { "Default",200,1.5 };
	//Engine engine; // nomodel, 0,0
	size_t maxSpeed = 120;
};

inline void Car::print() const
{
	cout << "Car " << brand << endl;
	engine.print();
	cout << "Max speed :: " << maxSpeed << endl;
}
inline Car::Car(const string& brand, const Engine& engine, size_t maxSpeed)
	:brand(brand),
	engine(engine),
	maxSpeed(maxSpeed)
{}

inline Car::Car(const string& brand, const string& model, const size_t& power, const double& volume, size_t maxSpeed) 
	:brand(brand),
	engine(model,power,volume), // ctor with parameters
	maxSpeed(maxSpeed)
{}