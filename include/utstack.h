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
	int Size;                
	int maxSize;               
public:

	TStack(int s = 10)
	{
		if ((s < 0) || (s > MAX_STACK_SIZE)) throw "Error";
		maxSize = s;
		Size = 0;
		sStack = new ValType[maxSize];
	};         

	TStack(const TStack &s)
	{
		Size = s.Size;
		maxSize = s.maxSize;
		sStack = new ValType[maxSize];
		for (int i = 0; i < Size; i++)
			sStack[i] = s.sStack[i];
	};  

	~TStack()
	{
		delete[] sStack;
	}
	
TStack&  operator=(const TStack &s)
{
	if ((Size != s.Size) || (maxSize != s.maxSize))
	{
		maxSize = s.maxSize;
		Size = s.Size;
		delete[] sStack;
		sStack = new ValType[maxSize];
	}
	for (int i = 0; i <= maxSize; i++)
		sStack[i] = s.sStack[i];
	return *this;
}

bool operator==(const TStack &s) const
{
	bool l = 1;
	if ((Size != s.Size) || (maxSize != s.maxSize)) return 0;
	for (int i = 0; i <= maxSize; i++)
	{
		if (sStack[i] != s.sStack[i])
		{
			l = 0;
			break;
		}
	}
	return l;
}

bool TStack<ValType>::operator!=(const TStack &s) const
{
	if (s == *this) return 0;
	return 1;
}

bool empty()
{
	if (Size == 0) return 1;
	return 0;
}

bool full()
{
	if (maxSize == Size) return 1;
	return 0;
}


void push(ValType elem)
{
	if (full()) throw "Stack full";
	Size++;;
	sStack[Size] = elem;
}

void pop()
{
	if (empty()) throw "Stack empty";
	sStack[Size]= '\0';
	Size--;
	
}

};

#endif