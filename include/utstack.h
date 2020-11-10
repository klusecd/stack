#pragma once 

#include <iostream>

using namespace std;

const int MAX_SIZE = 1000;


template <class ValType>
class TStack
{
protected:
	ValType *sStack;
	int size;                
	int maxSize;               
public:

	TStack(int s = 10)
	{
		if ((s < 0) || (s > MAX_SIZE)) throw "Error";
		maxSize = s;
		size = 0;
		sStack = new ValType[maxSize];
	}

	TStack(const TStack &_s)
	{
		size = _s.size;
		maxSize = _s.maxSize;
		sStack = new ValType[maxSize];
		for (int i = 0; i < Size; i++)
			sStack[i] = _s.sStack[i];
	}

	~TStack()
	{
		delete[] sStack;
	}
	
TStack&  operator=(const TStack &s)
{
	maxSize = s.maxSize;
	size = s.size;
	sStack = new ValType[maxSize];
	for (int i = 0; i <= maxSize; i++)
		sStack[i] = s.sStack[i];
	return *this;
}

bool operator==(const TStack &s) const
{
	if ((size != s.size) || (maxSize != s.maxSize)) return false;
	for (int i = 0; i < maxSize; i++)
	{
		if (sStack[i] != s.sStack[i]) return false;
	}
	return true;
}

bool TStack<ValType>::operator!=(const TStack &s) const
{
	if (s == *this) return 0;
	return 1;
}

bool empty()
{
	if (size == 0) return 1;
	return 0;
}

bool full()
{
	if (maxSize == size) return 1;
	return 0;
}

void push(ValType elem)
{
	if (full()) throw "Stack full";
	if (size>=maxSize)
	{
		maxSize *= 2.0;
		ValType *a = new ValType[maxSize];
		memmove(a, sStack, sizeof(*sStack) * size);
		delete[] sStack;
		sStack = a;
	}
	sStack[size] = elem;
	size++;
}

void pop()
{
	if (empty()) throw "Stack empty";
	sStack[--size] = 0;
}

ValType top() {
	if (empty()) throw "Stack empty";
	return sStack[size - 1];
}

ValType operator[](int pos)
{
	if ((pos < 0) || (pos > maxSize)) throw "error";
	return sStack[pos];
}

void clear()
{
	size = 0;
}

};

template <class ValType>

class TQueue : public TStack<ValType>
{
private:
	TStack<ValType> top, tail;

public:
	TQueue(int s = 10) 
	{
		TStack <ValType> tmp(s);
		top = tmp;
		tail = tmp;
	}

	~TQueue() {}

	void pop() 
	{
		if (top.empty() && tail.empty()) throw "Queue is empty";

		if (tail.empty()) {
			while (!top.empty())
			{
				tail.push(top.top());
				top.pop();
			}
		}
		tail.pop();
		size--;
	}
	                    
	void push(ValType elem) 
	{
		top.push(elem);
		tail.clear();
	}

	bool operator==(const TQueue &q)
		{
			if ((!q.top.empty()) && (!top.empty()))
				if (top == q.top) return true;
			if ((!q.tail.empty()) && (!tail.empty()))
				if (tail == q.tail) return true;
			return false;
		}

	bool operator!=(const TQueue &q)
	{
		if (q == *this) return false;
		return true;
	}
};
