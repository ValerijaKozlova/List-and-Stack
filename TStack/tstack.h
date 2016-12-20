#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include "../List/tlist.h"

using namespace std;

template <class ValType>
class TStack
{
private:
	TList<ValType>	list;	      
public:
	TStack();						// конструктор

	bool IsStackEmpty();		    // проверка на пустоту
	void Put(const ValType e1);	    // добавить элемент в стек
	void Get();					    // извлечь элемент из стека
	ValType Look();					// просмотреть вершину стека

};

template <class ValType>
TStack<ValType>::TStack() {};

template <class ValType>
bool TStack<ValType>::IsStackEmpty()
{
	return list.IsStackEmpty();
}

template <class ValType>
void TStack<ValType>::Put(const ValType e1)
{

	list.InsertBegin(e1);
}

template <class ValType>
void TStack<ValType>::Get()
{
	list.DeleteEnd();
}

template <class ValType>
ValType TStack<ValType>::Look()
{
	ValType top = list.View();
	return top;
}

#endif