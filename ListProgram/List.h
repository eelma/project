#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstdio>
#include <cstring>
#include<fstream>

using namespace std;


template<class T>
class Node
{
public:
	T TData;
	Node* _Next;
	Node* _Prev;

	Node()
	{ 
		_Next = _Prev = nullptr; 
	};
	~Node(){}
};


template<class T>
class LinkedList
{
	public:
	
	Node<T>* _Head = NULL;
	Node<T>* _Tail = NULL;
	Node<T>* _Temp = NULL;
	
public:
	static int _icount;

public:
	LinkedList();
//	~LinkedList();


public:
	void SInit();
	//void SInsert(Student* st);
	void FInsert(T node);
	void BInsert(T node);
	void AllDelete();

	//public:
	//	void SPrint();
	//	void SDelete();
	//	void ReSet();
};
template<class T>
int LinkedList<T>::_icount=0;

template<class T>
LinkedList<T>::LinkedList()
{
	
	_Head = new Node<T>;
	_Tail = new Node<T>;

	_Head->_Next = _Tail;
	_Tail->_Prev = _Head;

	_Temp = _Head;
	_icount = 0;
}
//
//template<class T>
//LinkedList<T>::~LinkedList()
//{
//	//delete _Head;
//	//delete _Tail;
//}

template<class T>
void LinkedList<T>::SInit()
{
	_Head = new Node<T>;
	_Tail = new Node<T>;

	_Head->_Next = _Tail;
	_Tail->_Prev = _Head;

	_Temp = _Head;

}
template<class T>
void LinkedList<T>::FInsert(T data)
{
	Node<T>* newnode = new Node<T>();
	newnode->TData = data;

	Node<T>* Next = _Head->_Next;
	
	_Head->_Next = newnode;
	newnode->_Prev = _Head;

	newnode->_Next = Next;
	Next->_Prev = newnode;
	

	_icount++;
}
template<class T>
void LinkedList<T>::BInsert(T data)
{
	Node<T>* newnode = new Node<T>();
	Node<T>* Prev = _Tail->_Prev;
	newnode->TData = data;

	_Tail->_Prev=newnode;
	newnode->_Next = _Tail;
	_Tail->_Prev = newnode;

	newnode->_Prev = Prev;
	Prev->_Next = newnode;

	_icount++;
}
template<class T>
void LinkedList<T>::AllDelete()
{

	Node<T>* st = _Head->_Next;

	for (; st != _Tail; st = st->_Next)
	{
		Node<T>* Prev = st->_Prev;
		Node<T>* Next = st->_Next;
		delete st;
		Prev->_Next = Next;
		Next->_Prev = Prev;
		st = _Head;
		_icount--;
	}
	/*if (st == _Tail)
	{
		cout << "삭제 완료\n";
		return;
	}*/
}
//
//
//
//
//
//

//
//void LinkedList::TotalStudent()
//{
//	system("cls");
//	cout << "총 " << _icount << "명" << endl;
//
//}
//
//
//
//void LinkedList::SPrint()
//{
//	cout << fixed;
//	cout.precision(2);
//	char name[10];
//	cout << "이름 입력: "; cin >> name;
//	Student* temp = _Head;
//	for (; temp->Next != _Tail; temp = temp->Next)
//	{
//
//		if (strcmp(name, temp->Next->name) == 0)
//		{
//			cout << "이름: " << temp->Next->name << endl;
//			cout << "국어점수: " << temp->Next->Kor << endl;
//			cout << "영어점수: " << temp->Next->Eng << endl;
//			cout << "수학점수: " << temp->Next->Mat << endl;
//			cout << "총점 : " << temp->Next->Total << endl;
//			cout << "평균 점수: " << temp->Next->ever << endl;
//			break;
//		}
//
//
//	}
//	if (strcmp(name, temp->name) != 0 && temp->Next == _Tail)
//		cout << "잘못 입력하셨습니다." << endl;
//
//
//}
//
//
//void LinkedList::SDelete()
//{
//
//	char name[10];
//	Student* st = _Head->Next;
//	Student* tm;
//	Student* bm;
//	cout << "이름 입력: "; cin >> name;
//
//	while (st != NULL)
//	{
//
//		if (strcmp(st->name, name) == 0)
//			break;
//		st = st->Next;
//
//	}
//	if (st == NULL)
//	{
//		cout << "찾으시는 대상이 없습니다\n\n";
//		return;
//	}
//
//	tm = st->Next;
//	bm = st->Prev;
//	free(st);
//
//	bm->Next = tm;
//	tm->Prev = bm;
//
//	_icount--;
//	cout << "삭제완료" << endl;
//	//SInit();
//}
//
//
//void LinkedList::ReSet()
//{
//
//	AllDelete();
//
//	int nResult = remove("data.txt");
//}
//
