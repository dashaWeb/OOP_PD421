#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    List<int> list;
	for (size_t i = 0; i < 10; i++)
	{
		list.addHead(rand() % 100);
		list.print();
	}

	list.printR();

	list.removeHead();

	cout << "\n\n";
	list.print();
	list.printR();

	list.removeByData(0);
	cout << "\n\n";
	list.print();
	list.printR();
}

