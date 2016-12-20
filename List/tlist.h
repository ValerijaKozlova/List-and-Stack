#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>

using namespace std;

#ifndef __NODE__
#define __NODE__
template <class ValType>
struct node{
	node* next;
	ValType data;
};
#endif

template <class ValType>
class TList
{
protected:
	node<ValType>* head;	  //указатель на первый элемент
	int Size;
public:

//ћетоды:
  	TList();					                            //конструктор по умолчанию
	~TList();					                            //деструктор
	bool IsStackEmpty() const;			                    //проверка на пустоту
	void PrintStack() const;			                    //вывод
	
//‘ункции вставки:
	void InsertBegin(ValType str);				         	//вставить в начало элемент str
	void InsertEnd(ValType end);					    	//вставить в конец элемент end
	void Insert(ValType e1, node<ValType>* e2);	            //вставить элемент e2 после e1

//‘ункции удалени€:
	void DeleteBegin();										//удалить элемент в начале 
	void DeleteEnd();										//удалить элемент в конце
	void Delete(node<ValType>* e1);		                    //удалить элемент после temp

	node<ValType>* Search(ValType a);						//поиск элемента a
	ValType View(); 
};

//конструктор по умолчанию
template <class ValType>
TList<ValType>::TList() {head=0;}

//деструктор
template <class ValType>
TList<ValType>::~TList()
{
	if (head!=0)
	{
		node<ValType>* temp;
		while(head->next!=0) 
		{
			temp=head;
			head=head->next;
			delete temp;
		}
	}
}

//проверка на пустоту
template <class ValType>
bool TList<ValType>::IsStackEmpty() const
{
	if(head) return false;
	else return true;
}

//вывод
template <class ValType>
void TList<ValType>::PrintStack() const
{
	if(head)
	{
		node<ValType>* temp=head;
		while(temp->next)
		{
			cout<<temp->data<<' ';
			temp=temp->next;
		}
		cout<<temp->data<<'\n';
	}
	else cout<<"List is empty"<<'\n';
}

//‘”Ќ ÷»» ¬—“ј¬ »
//вставить в начало элемент str
template <class ValType>
void TList<ValType>::InsertBegin(ValType str)
{

	node <ValType> * tmp = new node <ValType>;
	tmp->data = str;
	tmp->next = head;
	head = tmp;
}

//вставить в конец элемент end
template <class ValType>
void TList<ValType>::InsertEnd(ValType end)
{
	{
		if (IsStackEmpty())
		{
			InsertBegin(end);
			return;
		}
		node <ValType> * tmp = new node <ValType>;
		node <ValType> * ptr = head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = tmp;
	}
}

//вставить элемент e2 после e1
template <class ValType>
void TList<ValType>::Insert(ValType e1, node<ValType>* e2)
{
	if (e2)
	{
		node <ValType> * tmp = new node <ValType>;
		e2->next = tmp;
	
	}
	else
	{
		node <ValType> * tmp = new node <ValType>;
		head = tmp;
	}
}

//‘”Ќ ÷»» ”ƒјЋ≈Ќ»я
//удалить элемент в начале
template <class ValType>
void TList<ValType>::DeleteBegin()
{
	if(head)
	{
		node<ValType>* temp=head;
		head=head->next;
		delete temp;
	}
}

//удалить элемент в конце
template <class ValType>
void TList<ValType>::DeleteEnd()
{
	if(head)
	{
		if(head->next)
		{
			node<ValType>* temp=head;
			while(temp->next->next) temp=temp->next;
			delete temp->next;
			temp->next=0;
		}
		else
		{
			delete head;
			head=0;
		}
	}
}

//удалить элемент после temp
template <class ValType>
void TList<ValType>::Delete(node<ValType>* e1)
{
	if((e1)&&(e1->next))
	{
		node<ValType>* temp=e1->next;
		e1->next=e1->next->next;
		delete temp;
	}
}

//поиск элемента a
template <class ValType>
node<ValType>* TList<ValType>::Search(ValType a)
{
	if(head)
	{
		node<ValType>* temp=head;
		while((temp)&&(temp->data!=a)) temp=temp->next;
		return temp;
	}
	else return 0;
}

template <class ValType>
ValType TList<ValType>::View() 
{ 
	return head->data;
}

#endif