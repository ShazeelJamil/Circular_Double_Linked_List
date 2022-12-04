#ifndef CDLL_H
#define CDLL_H
#include"DNode.h"
template<typename T>
class CDLL
{
	DNode<T>* head;
public:
	CDLL();
	void insertAtHead(const T& val);
	void insertAtTail(const T& val);
	void deleteAtHead();
	void deleteAtTail();
	void insertBefore(const T& key, const T& val);
	void insertAfter(const T& key, const T& val);
	void deleteBefore(const T& key);
	void deleteAfter(const T& key);
	void display();
	~CDLL();


	class iterator
	{
		friend class CDLL<T>;
		DNode<T>* ptr;
		iterator(DNode<T>* p)
		{
			ptr = p;
		}
	public:
		T& operator*()
		{
			return ptr->info;
		}
		const T& operator*() const
		{
			return ptr->info;
		}
		bool operator !=(const iterator& i)
		{
			return(ptr != i.ptr ? true : false);
		}
		void operator ++(T)
		{
			ptr = ptr->nextPtr;
		}
		void operator ++()
		{
			ptr = ptr->nextPtr;
		}
		void operator --(T)
		{
			ptr = ptr->prevPtr;
		}
		void operator --()
		{
			ptr = ptr->prevPtr;
		}
	};
	iterator begin()
	{
		return iterator(head);
	}
	iterator end()
	{
		return iterator(head->prevPtr);
	}





};
#endif // !CDLL_H
