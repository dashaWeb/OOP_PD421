#pragma once
#include <iostream>

using std::cout;
using std::endl;
using std::cin;


template <typename T>
struct Node // структура для опису одного вузла однозв. списку
{
	T data; 
	Node* next;
	Node(const T& data = T(), Node* next = nullptr)
		:data(data),next(next)
	{}
};

template <typename T>
class FwdList
{
public:
	FwdList() = default;
	void addHead(const T& data);
	void print() const;
	bool empty() const;
	void removeHead();
private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	size_t size = 0;
};

template<typename T>
inline void FwdList<T>::addHead(const T& data)
{
	Node<T>* tmp = new Node<T>(data, head);
	if (empty())
		tail = tmp;
	head = tmp;
	++size;
}

template<typename T>
inline void FwdList<T>::print() const
{
	if (empty())
	{
		cout << "List is Empty!" << endl;
		return;
	}
	auto tmp = head; // починаємо з початку списку
	cout << "List ::\t";
	while (tmp!=nullptr) // цикл працює, доки не дійшли до кінця списку
	{
		cout << tmp->data << "\t"; // виведи дані з вузла
		tmp = tmp->next; // перейшли на наступний вузол
	}
	cout << endl;
}

template<typename T>
inline bool FwdList<T>::empty() const
{
	return head == nullptr;
}

template<typename T>
inline void FwdList<T>::removeHead()
{
	if (empty())
		return;
	auto tmp = head; // запамятали старий head
	head = head->next; // перемістили head на наступний елемент (можливо стане nullptr)
	if (empty()) // якщо список стає порожнім, то виправляємо вказівник tail
		tail = nullptr;
	--size;
	delete tmp;
}
