#pragma once
#include "Animal.h"
class Wolf : //final : // final клас - від цього класу не можна успадковуватися
    public Animal
{
public:
    void print() const override;// final; // похідним типам заборонено перевизначати цей віотуальний метод
    void eat() const override;

    Wolf(const string& place = "Africa", const size_t& age = 0, const size_t& weight = 0);
    ~Wolf();
private:
    size_t weight;
};


class Dog :
    public Wolf
{
public:
    Dog(const string& place = "Africa", const size_t& age = 0, const size_t& weight = 0)
        :Wolf(place, age, weight)
    {
        cout << "\t >>>>>>>>>>>>> Ctor Dog ID #" << id << endl;
    }
    ~Dog()
    {
        cout << "\t >>>>>>>>>>>>> Dtor Dog ID #" << id << endl;
    }
    /*void print() const override {
        cout << "------------------------- Dog #" << id << " -------------------" << endl;
        cout << "\t Age   :: " << getAge() << endl;
        cout << "\t Place :: " << getPlace() << endl;
    }*/
    void eat() const override
    {
        cout << "Dog id " << id << " likes to eat sausage" << endl;
    }
};
