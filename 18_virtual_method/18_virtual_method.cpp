#include <iostream>
#include <vector>
#include "Lion.h"
#include "Wolf.h"
using namespace std;
int main()
{
	Animal animal("South Africa", 3);
	animal.print();


	cout << "\n\n";
	Lion lion("Africa", 4, false);
	lion.print();
	//lion.Animal::print();

	cout << "\n\n";
	Wolf wolf;
	wolf.print();

	cout << "\n\n ==================================== \n\n";

	// при PUBLIC успадкуванні підтримується неявне перетворення від похідного типу до базового
	cout << "Animal test = lion " << endl;
	Animal test = lion; // copy ctor
	test.print();

	test = (Animal&)wolf; // використовувати явне перетворення від похідного типу до базового - PROTECTED наслідування
	test.print();

	cout << "\n\n ==================================== \n\n";
	//Animal arr[]{ lion,(Animal&)wolf };
	vector<Animal*> zoo{ &lion,(Animal*)&wolf, &animal, new Lion("North Africa",10,true), new Dog("Ukraine",5,15)};
	for (auto& i : zoo)
	{
		i->print();
		i->eat();
		cout << endl;
	}

	cout << "\n\n ==================================== \n\n";
}
