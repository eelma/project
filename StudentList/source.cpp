#define _CRT_SECURE_NO_WARNINGS
#include"List.h"
#include<iostream>
#include<string.h>
using namespace std;

Student Node::NewStudent(Node* node)
{
	char name[10];
	int kor, eng, mat, total;
	Student* temp = new Student;
	Student* st = new Student;
	memset(st, 0, sizeof(Student));
	cout << "�л� �̸� �Է�: "; cin >> name;
	strcpy(st->name, name);
	cout << "���� ����: "; cin >> kor;
	st->Kor = kor;
	cout << "���� ����: "; cin >> eng;
	st->Eng = eng;
	cout << "���� ����: "; cin >> mat;
	st->Mat = mat;
	total = kor + eng + mat;
	st->Total = total;
	st->ever = (float)total / 3;

	if (node->_Head->Next == node->_Tail)
	{
		node->_Head->Next = st;
		st->Next = node->_Tail;
	}
	else
	{
		_Temp = node->_Head->Next;
		node->_Head->Next = st;
		st->Next = _Temp;
	}

	return *st;
	node->_icount++;
}

Node Node::SInit(Node* node)
{
	node->_Head = new Student;
	node->_Tail = new Student;
	node->_Temp = new Student;
	
	memset(node->_Head, 0, sizeof(Student));
	memset(node->_Tail, 0, sizeof(Student));
	memset(node->_Temp, 0, sizeof(Student));

	node->_Head->Next = node->_Tail;


	_icount = 0;

	return *node;
}
void Node::SInsert(Node* node)
{

	if (node->_Head == NULL)
		FInsert(node);
	else
		BInsert(node);
}
void Node::FInsert(Node* node)
{
	

}
void Node::BInsert(Node* node)
{
	

}
void Node::SPrint(Node*node)
{

	


}
void Node::Print(Node * node)
{
	for(int i=0;i<=_icount;i++)

	cout << "�̸�: " << node->_Head->Next->name<<endl;
	cout << "��������: "<<node->_Head->Next->Kor << endl;
	cout << "��������: " << node->_Head->Next->Eng << endl;
	cout << "��������: " << node->_Head->Next->Mat << endl;
	cout << "���� : " << node->_Head->Next->Total << endl;
	cout << "��� ����: " << node->_Head->Next->ever << endl;

}

