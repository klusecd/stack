#ifndef __TSTACK_H__
#define __TSTACK_H__
#pragma once 

#include <iostream>

using namespace std;

const int MAX_STACK_SIZE = 1000;


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
		if ((s < 0) || (s > MAX_STACK_SIZE)) throw "Error";
		maxSize = s;
		size = 0;
		sStack = new ValType[maxSize];
	}

	TStack(const TStack &s)
	{
		size = s.size;
		maxSize = s.maxSize;
		sStack = new ValType[maxSize];
		for (int i = 0; i < Size; i++)
			sStack[i] = s.sStack[i];
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
	bool isEqual = 1;
	if ((size != s.size) || (maxSize != s.maxSize)) return 0;
	for (int i = 0; i <= maxSize; i++)
	{
		if (sStack[i] != s.sStack[i])
		{
			isEqual = 0;
			break;
		}
	}
	return isEqual;
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
	if (size == maxSize)
	{
		if (full()) throw "Stack full";
		maxSize *= 2.0;
		ValType *a = new int[maxSize];
		memmove(a, sStack, sizeof(*sStack) * size);
		delete[] sStack;
		sStack = a;
	}

	sStack[size] = elem;
	size++;;
}

void pop()
{
	if (empty()) throw "Stack empty";
	sStack[size]= '\0';
	size--;
}

};

#endif