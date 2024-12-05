#pragma once
#include <iostream>
template<typename T>
class List {
public:
	List();
	List(const List& other);
	~List();

	//Добавляет данные в конец списка
	void push_back(T data);
	//Возвращает размер односвязного списка
	int GetSize() {
		return Size;
	}
	//Перегрузка оператора по индексу
	T& operator[](const int index);
	//Добавляет элемнт в начало списка
	void pop_front();
	//Очищает списк
	void clear();
	//Добавляет элемент в начало списка
	void push_front(T data);
	//Выводит список
	void print();
	//Вставляет элемнт в список по индексу
	void insert(int index, T data);
	//Удаляет элемент по индексу
	void removeAT(int index);
	//Удаляет последний элемент
	void pop_back();

private:

	template<typename T>
	class Node {
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;
	Node<T>* head;
};

template<typename T>
List<T>::List() {
	Size = 0;
	head = nullptr;
};

template<typename T>
List<T>::~List() {
	clear();
}

template<typename T>
List<T>::List(const List& other) : Size(other.Size), head(nullptr) {
	if (other.head) {
		head = new Node<T>(other.head->data);
		Node<T>* current = head;
		Node<T>* otherCurrent = other.head->pNext;

		while (otherCurrent) {
			current->pNext = new Node<T>(otherCurrent->data);
			current = current->pNext;
			otherCurrent = otherCurrent->pNext;
		}
	}
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head;

		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}
template<typename T>
T& List<T>::operator[](const int index)
{
	if (index < 0 || index >= Size) {
		throw std::out_of_range("Index out of range");
	}


	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		else {
			current = current->pNext;
			counter++;
		}
	}

	throw std::out_of_range("Index out of range");
}
template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}
template<typename T>
void List<T>::clear()
{
	while (Size) {
		pop_front();
	}
}
template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);

	Size++;
}
template<typename T>
void List<T>::print()
{
	std::cout << std::endl;
	Node<T>* current = this->head;
	while (current != nullptr) {
		std::cout << current->data << std::endl;
		current = current->pNext;
	}
}
template<typename T>
void List<T>::insert(int index, T data)
{
	if (index < 0 || index > Size) {
		throw std::out_of_range("Index out of range");
	}

	if (index == 0) {
		push_front(data);
	}
	else {
		Node<T>* previous = this->head;
		for (int i = 0; i < --index; i++) {
			previous = previous->pNext;
		}
		Node<T>* NewNode = new Node<T>(data, previous->pNext);
		previous->pNext = NewNode;
		Size++;

	}
}
template<typename T>
void List<T>::removeAT(int index)
{
	if (index < 0 || index >= Size) {
		throw std::out_of_range("Index out of range");
	}

	if (index == 0) {
		pop_front();
	}
	else {
		Node<T>* previous = this->head;
		for (int i = 0; i < (index - 1); i++) {
			previous = previous->pNext;
		}
		Node<T>* DeleteNode = previous->pNext;
		previous->pNext = DeleteNode->pNext;
		delete DeleteNode;
		Size--;
	}
}
template<typename T>
void List<T>::pop_back()
{
	if (Size == 0) {
		throw std::out_of_range("List is empty");
	}

	if (Size == 1) {
		delete head;
		head = nullptr;
		Size--;
	}
	else {
		Node<T>* current = head;
		while (current->pNext->pNext != nullptr) {
			current = current->pNext;
		}
		delete current->pNext;
		current->pNext = nullptr;
	}
	Size--;
}
;

