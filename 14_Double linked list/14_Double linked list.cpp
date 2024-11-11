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


/*

List(const List<T>& other); // copy ctor
List<T>& operator = (const List<T>& other)
~List();
void clear();
void addTail(const T& data);
void removeTail();
*/
