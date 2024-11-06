#pragma once
#include <iostream>

template<typename T>
class MyStack
{
	enum MyEnum {EMPTY = -1, DEFAULT_CAPACITY = 10, DEFAULT_GROW = 5};
public:
	MyStack(size_t capacity = DEFAULT_CAPACITY, size_t grow = DEFAULT_GROW);
	void push(const T& element);
	void pop();
	T top_() const;
	size_t size() const;
	bool empty() const;

	~MyStack();
private:
	int top = EMPTY;
	size_t capacity;
	size_t growStep;
	T* stack = nullptr;
	bool full() const;
	void reserve();
};

template<typename T>
inline MyStack<T>::MyStack(size_t capacity, size_t grow)
	: capacity(capacity), growStep(grow), stack(new T[capacity])
{
	//stack = new T[capacity];
}

template<typename T>
inline void MyStack<T>::push(const T& element)
{
	if (full())
		reserve();
	stack[++top] = element;
}

template<typename T>
inline void MyStack<T>::pop()
{
	if (!empty())
		--top;
}



template<typename T>
inline T MyStack<T>::top_() const
{
	if (!empty())
		std::cout << stack[top] << std::endl;
		return stack[top];
	std::cout << "top() error: stack is emrty" << std::endl;
	return T();
}

template<typename T>
inline size_t MyStack<T>::size() const
{
	return top + 1;
}

template<typename T>
inline bool MyStack<T>::empty() const
{
	return top == EMPTY;
}

template<typename T>
inline MyStack<T>::~MyStack()
{
	delete[] stack;
}

template<typename T>
inline bool MyStack<T>::full() const
{
	return top == capacity - 1;
}

template<typename T>
inline void MyStack<T>::reserve()
{
	T* tmp = new T[capacity += growStep];
	for (size_t i = 0; i < top+1; i++)
	{
		tmp[i] = stack[i];
	}
	delete[] stack;
	stack = tmp;
}
