#include <iostream>
#include "Lion.h"
#include "Wolf.h"
using namespace std;
int main()
{
	Animal animal("South Africa", 3);
	animal.print();


	cout << "\n\n";
	Lion lion("Africa",4,false);
	lion.print();
	//lion.Animal::print();

	cout << "\n\n";
	Wolf wolf;
	wolf.print();
}
