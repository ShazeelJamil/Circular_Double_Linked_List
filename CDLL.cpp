#include"CDLL.h"
#include<iostream>
using namespace std;
template<typename T>
CDLL<T>::CDLL()
{
	head = nullptr;
}
template<typename T>
void CDLL<T>::insertAtHead(const T& val)
{
	if (!head)
	{
		head = new DNode<T>(val);
		head->nextPtr = head;
		head->prevPtr = head;
		return;
	}
	DNode<T>* temp = new DNode<T>(val);
	head->prevPtr->nextPtr = temp;
	temp->prevPtr = head->prevPtr;
	head->prevPtr = temp;
	temp->nextPtr = head;
	head = temp;
}
template<typename T>
void CDLL<T>::insertAtTail(const T& val)
{
	if (!head)
	{
		insertAtHead(val);
		return;
	}
	DNode<T>* temp = new DNode<T>(val);
	temp->prevPtr = head->prevPtr;
	head->prevPtr->nextPtr = temp;
	temp->nextPtr = head;
	head->prevPtr = temp;	
}
template<typename T>
void CDLL<T>::deleteAtHead()
{
	if (!head)
		return;
	else if (head->nextPtr == head)
	{
		this->~CDLL();
		return;
	}
	DNode<T>* temp = head;
	head = head->nextPtr;
	temp->nextPtr = nullptr;
	head->prevPtr = temp->prevPtr;
	temp->prevPtr->nextPtr = head;
	temp->prevPtr = nullptr;
}
template<typename T>
void CDLL<T>::deleteAtTail()
{
	if (!head)
		return;
	else if (head->nextPtr == head)
	{
		this->~CDLL();
		return;
	}
	DNode<T>* temp = head->prevPtr;
	temp->nextPtr = nullptr;
	head->prevPtr = temp->prevPtr;
	temp->prevPtr = nullptr;
	head->prevPtr->nextPtr = head;
}
template<typename T>
void CDLL<T>::insertBefore(const T& key, const T& val)
{
	if (!head)
		return;
	DNode<T>* ptr = head;
	do
	{
		if (ptr->info == key)
		{
			DNode<T>* prev = ptr->prevPtr;
			DNode<T>* temp = new DNode<T>(val);
			temp->prevPtr = ptr->prevPtr;
			ptr->prevPtr = temp;
			temp->nextPtr = ptr; 
			prev->nextPtr = temp;
			return;
		}
		ptr = ptr->nextPtr;
	} while (ptr != head);
}
template<typename T>
void CDLL<T>::insertAfter(const T& key, const T& val)
{
	if (!head)
		return;
	else if (head->prevPtr->info == key)
	{
		insertAtTail(val);
		return;
	}
	DNode<T>* ptr = head;
	do
	{
		if (ptr->info == key)
		{
			DNode<T>* next = ptr->nextPtr;
			DNode<T>* temp = new DNode<T>(val);
			temp->nextPtr = next;
			next->prevPtr = temp;
			temp->prevPtr = ptr;
			ptr->nextPtr = temp;			
			return;
		}
		ptr = ptr->nextPtr;
	} while (ptr != head);
}
template<typename T>
void CDLL<T>::deleteBefore(const T& key)
{
	if (!head)
		return;
	if (head->nextPtr->info == key)
	{
		deleteAtHead();
		return;
	}
	DNode<T>* ptr = head;
	do
	{
		if (ptr->info == key)
		{
			DNode<T>* prev = ptr->prevPtr->prevPtr;
			prev->nextPtr->nextPtr = nullptr;
			prev->nextPtr->prevPtr = nullptr;
			delete prev->nextPtr;
			prev->nextPtr = ptr;
			ptr->prevPtr = prev;
			prev->nextPtr = ptr;
			return;
		}
		ptr = ptr->nextPtr;
	} while (ptr != head);
}
template <typename T>
void CDLL<T>::deleteAfter(const T& key)
{
	if (!head)
		return;
	if (head->prevPtr->info == key)
	{
		deleteAtHead();
		return;
	}
	DNode<T>* ptr = head;
	do
	{
		if (ptr->info == key)
		{
			DNode<T>* next = ptr->nextPtr->nextPtr;
			ptr->nextPtr->prevPtr = nullptr;
			ptr->nextPtr->nextPtr = nullptr;
			ptr->nextPtr = next;
			next->prevPtr = ptr;
			return;
		}
		ptr = ptr->nextPtr;
	} while (ptr != head);
}









template <typename T>
void CDLL<T>::display()
{
	if (!head)
		return;
	DNode<T>* ptr = head;
	do
	{
		cout << ptr->info << " ";
		ptr = ptr->nextPtr;
	} while (ptr != head);
}
template<typename T>
CDLL<T>::~CDLL()
{
	delete head;
	head = nullptr;
}