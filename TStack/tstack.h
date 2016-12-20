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
	TStack();						// �����������

	bool IsStackEmpty();		    // �������� �� �������
	void Put(const ValType e1);	    // �������� ������� � ����
	void Get();					    // ������� ������� �� �����
	ValType Look();					// ����������� ������� �����

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