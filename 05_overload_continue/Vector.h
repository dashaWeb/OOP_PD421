#pragma once
#include <iostream>
using std::cout;
using std::endl;
class Vector {
public:
	Vector(); // по замовчуванню, довжина масива = 1
	Vector(const size_t& size); // 1 params, довжина масива = size
	Vector(const size_t& size, const int& value); // 2 params, довжина масива = size, заповнений значеннями value

	Vector(const Vector& other); // copy ctor
	Vector& operator =(const Vector& other);
	~Vector();


	const size_t& getSize() const { return size; }
	void print() const;
	void pushBack(const int& value);

	int operator[] (size_t index) const; // повертати елемент масиву за індексом get;
	int& operator[](size_t index); // повертати посилання на елемент масиву за індексом; set

	Vector operator()(size_t startIndex, size_t lastIndex) const;

private:
	int* arr = nullptr;
	size_t size = 0;
	bool isValidIndex(size_t index) const;
	size_t capacity = 0;
	void resize();
};

inline bool Vector::isValidIndex(size_t index) const
{
	return index < size;
}

inline void Vector::resize()
{
	this->capacity *= 2;
	int* tmp = new int[this->capacity];
	for (size_t i = 0; i < this->size; i++)
	{
		tmp[i] = arr[i];
	}
	delete[] arr;
	arr = tmp;
}
