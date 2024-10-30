#include <iostream>
using namespace std;

class Human {

public:
    Human() = default;
    Human(const string& name)
        :name(name)
    {}
    void think() const
    {
        cout << name << "\t";
        brain.think();
    }

    class Brain {
    public:
        Brain() = default;
        void think() const
        {
            cout << "Think Brain" << endl;
        }
    };
private:
    string name;
    Brain brain;
};



int main()
{
    Human Olia("Olia");
    Olia.think();

}
