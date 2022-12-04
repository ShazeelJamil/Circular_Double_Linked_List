#ifndef D_NODE_H
#define D_NODE_H
template<typename T>
struct DNode
{
	T info;
	DNode<T>* prevPtr;
	DNode<T>* nextPtr;
	DNode()
	{
		prevPtr = nullptr;
		nextPtr = nullptr;
	}
	DNode(T val)
	{
		info = val;
		nextPtr = nullptr;
		prevPtr = nullptr;
	}
};

#endif // !
