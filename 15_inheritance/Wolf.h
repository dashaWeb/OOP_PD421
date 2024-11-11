#pragma once
#include "Animal.h"
class Wolf :
    public Animal
{
public:
    void print() const;


    Wolf(const string& place = "Africa", const size_t& age = 0, const size_t& weight = 0);
    ~Wolf();
private:
    size_t weight;
};

