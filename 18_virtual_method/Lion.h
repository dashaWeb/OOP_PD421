#pragma once
#include "lib.h"
#include "Animal.h"

class Lion :
	public Animal
{
public:
	Lion(const string& place = "Africa", const size_t& age = 0, bool isAlone = false);
	void print() const override;
	void eat() const override;
	~Lion();
private:
	bool isAlone = true;
};
