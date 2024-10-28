#include <iostream>
#include "Vector.h"

using namespace std;
int main()
{

    Vector arr(4,1);
    /*arr.print();
    arr[0] = 666;
    arr[1] = 222;
    arr.print();

    cout << arr[0] << endl;
    cout << arr[22] << endl;
    arr[22] = 2;*/

    for (size_t i = 0; i < arr.getSize(); i++)
    {
        arr[i] = rand() % 10 + 1;
    }
    arr.print();

    // [1:10:2]
    Vector splice = arr(2, 4);
    splice.print();
    splice.pushBack(33);
    splice.print();
    splice.pushBack(66);
    splice.print();
    splice.pushBack(77);
    splice.print();


}

// Task
/* До класу Vector додати наступний функціонал.
* arr    ==> 2 8 5 1 10 5 9 9 3 5
* splice ==> 5 1 10 22 33 44 
1. Використовуючи механізм перевантаження оператора +, обєднати два вектора (arr + splice) ==> new vector(2 8 5 1 10 5 9 9 3 5 5 1 10 22 33 44 )
 Vector operator + (const Vector& other) const;
2. Використовуючи механізм перевантаження оператора -, знайти унікальні елементи arr які не належать splice (arr - splice) ==> new vector(2 8 9 9 3)
Vector operator - (const Vector& other) const;
3. Використовуючи механізм перевантаження оператора *, результат новий вектор у якого кожне значення збільшили в n - разів 
Vector operator * (const size_t& n) const;
4. Перетворення до int повертає суму елементів масиву
explicit operator int() const;
5. Перетворення до char* повертає значення елементів массива у вигляді рядка
explicit operator char*() const;
methods
6. void pushBack(const int& value); ==> додати в кінець
7. void pushFront(const int& value); ==> додати на початок
8. void insert(const int& value, const size_t& index); ==> додати за вказаною позицією
9. void popBack(); ==> видалити в кінці
10. void popFront(); ==> видалити на початку
11. void remove(const size_t& index); ==> видалити за вказаною позицією
12. int find(const int& value); -1 - якщо немає, повертаємо індекс першого входження елемента 
*/