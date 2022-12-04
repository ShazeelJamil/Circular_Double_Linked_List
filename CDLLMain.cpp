#include"CDLL.h"
#include<iostream>
using namespace std;
int main()
{
	CDLL<int> q;
	q.insertAtTail(1);
	q.insertAtTail(3);
	q.insertAtTail(5);
	q.insertAtTail(6);
	

	//CDLL<int>::iterator i = q.begin();
	CDLL<int>::iterator j = q.end();
	
	
	//while (i != j)
	//{
	//	cout << *i << " ";
	//	i++;
	//}
	//cout << *i << " ";
	for (auto i : q)
		cout << i;
	cout << *j;


	return 0;
}