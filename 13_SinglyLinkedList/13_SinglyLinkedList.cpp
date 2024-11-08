#include <iostream>
#include "FwdList.h"
using namespace std;
int main()
{
    FwdList<int> list;
    list.addHead(22);
    list.print();
    for (size_t i = 1; i < 5; i++)
    {
        list.addHead(i * 10);
        list.print();
    }

    cout << "\n\n Remove Head " << endl;
    while (!list.empty())
    {
        list.removeHead();
        list.print();
    }

    list.removeHead();
    list.print();

    list.addHead(11);
    list.print();
    list.addHead(22);
    list.print();
    list.addHead(33);
    list.print();
}

// 1. clear() - очищає всі елементи списку
// 2. деструктор
// 3. addTail(const T& data); - додавання вузла у кінець списку
// 4. *** void removeTAil() - вилучення останнього вузла у списку
