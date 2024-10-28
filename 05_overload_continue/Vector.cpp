#include "Vector.h"

Vector::Vector()
	:Vector(1)
{
}

Vector::Vector(const size_t& size)
{
	this->size = size;
	this->capacity = size;
	this->arr = new int[this->size] {}; // створили память для масиву і занулили {}
}

Vector::Vector(const size_t& size, const int& value)
	:Vector(size)
{
	for (size_t i = 0; i < this->size; i++)
	{
		arr[i] = value;
	}
}

Vector::Vector(const Vector& other)
	:Vector(other.size)
{
	/*this->size = other.size;
	this->arr = new int[other.size];*/

	for (size_t i = 0; i < this->size; i++)
	{
		this->arr[i] = other.arr[i];
	}
}
// a = b;
Vector& Vector::operator=(const Vector& other)
{
	if (this->arr != nullptr)
		delete[] this->arr;
	this->size = other.size;
	this->capacity = this->size;
	this->arr = new int[other.size];

	for (size_t i = 0; i < this->size; i++)
	{
		this->arr[i] = other.arr[i];
	}
	return *this;
}

Vector::~Vector()
{
	if (this->arr != nullptr)
		delete[] this->arr;
}

void Vector::print() const
{
	cout << "\n Array has " << size << " elements: \n\t";
	for (size_t i = 0; i < this->size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void Vector::pushBack(const int& value)
{
	if (size >= capacity)
	{
		resize();
	}
	arr[size++] = value;
}

int Vector::operator[](size_t index) const
{
	if (isValidIndex(index))
		return arr[index];
	std::cerr << ">>>>>>>>> Error index (get) : " << index << endl;
	return INT_MIN;
}

int& Vector::operator[](size_t index)
{
	static int errValue;
	if (isValidIndex(index))
		return arr[index];
	std::cerr << ">>>>>>>>> Error index (set) : " << index << endl;
	return errValue;
}

Vector Vector::operator()(size_t startIndex, size_t lastIndex) const
{
	if (startIndex >= size)
		return Vector(0);
	if (lastIndex >= size)
		lastIndex = size - 1;
	if (startIndex > lastIndex)
		std::swap(startIndex, lastIndex);
	// 10 20 *30 *40 *50 60  // start = 2; last = 4

	Vector tmp(lastIndex - startIndex + 1);
	for (size_t i = 0; i < tmp.size; i++)
	{
		tmp[i] = this->arr[i + startIndex];
	}

	return tmp;
}
