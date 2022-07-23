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
	~Node() {}
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
	~LinkedList();


public:
	void SInit();
	void FInsert(T node);
	void BInsert(T node);
	void AllDelete();

};
template<class T>
int LinkedList<T>::_icount = 0;

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

template<class T>
LinkedList<T>::~LinkedList()
{
	//delete _Head;
	//delete _Tail;
}

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

	_Tail->_Prev = newnode;
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

