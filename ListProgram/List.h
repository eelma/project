#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstdio>
#include <cstdlib> // _countof �����Ҵ� �迭 ũ�� ��ȯ
#include <cstring>
#include <cmath>
#include<fstream>
using namespace std;
static int _icount;

template<class T>
class Node
{
public:
	T TData;
	T* _Next;
	T* _Prev;

	Node() { _Next = _Prev = nullptr; };
	~Node(){}
};


class Student
{

public:
	char name[10];
	int Kor, Eng, Mat, Total;
	float ever;
	Student* Next;
	Student* Prev;
};


class LinkedList
{
private:
	
	Student* _Head = NULL;
	Student* _Tail = NULL;
	Student* _Temp = NULL;

public:
	void SInit();
	void SInsert(Student* st);
	void FInsert(Student* st);
	void BInsert(Student* st);
	void AllDelete();




	void Load();
	void SaveData();
	void TotalStudent();
	void NewStudent();
	void FNewStudent(Student* st);
	void SPrint();
	void SAllPrint();
	void SDelete();
	void SChange();
	void ReSet();

	Student* Search(LinkedList*list);
	~LinkedList();

};


void LinkedList::SInit()
{
	_Head = new Student;
	_Tail = new Student;

	memset(_Head, 0, sizeof(Student));
	memset(_Tail, 0, sizeof(Student));

	_Head->Next = _Tail;
	_Tail->Prev = _Head;

	_Temp = _Head;
	_icount = 0;

}

void LinkedList::FInsert(Student* st)
{

	Student* Next = _Head->Next;
	_Head->Next = st;
	st->Next = Next;

	Next->Prev = st;
	st->Prev = _Head;

	_icount++;


}

void LinkedList::BInsert(Student* st)
{
	//Prev = ������ �Ӹ�(���), ������ �Ӹ�->st, st�� �Ӹ�->Prev, Prev�� ����->st, st�� ���� ->����
	//������ �밡��= st/ Prev�� st
	Student* Prev = _Tail->Prev;
	_Tail->Prev = st;
	st->Prev = Prev;

	Prev->Next = st;
	st->Next = _Tail;

	_icount++;

}

void LinkedList::AllDelete()
{

	Student* st = _Head->Next;

	for (; st != _Tail; st = st->Next)
	{
		Student* Prev = st->Prev;
		Student* Next = st->Next;
		delete st;
		Prev->Next = Next;
		Next->Prev = Prev;
		st = _Head;
		_icount--;
	}
	//if (st == _Tail)
	//{
	//	cout << "���� �Ϸ�\n";
	//	return;
	//}

}






void LinkedList::Load()
{
	AllDelete();

	fstream fp;
	fp.open("data.txt");
	if (!fp) { cout << "�ε� ����" << endl; return; }
	else
	{
		cout << "�ε� ����" << endl;
	}
	for (; !fp.eof();) {

		cout << fixed;
		cout.precision(2);
		char a[10];
		int b;
		float f;
		Student* st = new Student;
		memset(st, 0, sizeof(Student));

		fp >> a;
		strcpy(st->name, a);

		fp >> b;
		if (b <= 0)
		{
			delete st;
			return;
		}
		st->Kor = b;

		fp >> b;
		st->Eng = b;

		fp >> b;
		st->Mat = b;

		fp >> b;
		st->Total = b;

		fp >> f;
		st->ever = f;
		b = f = 0;
		BInsert(st);
	}

	fp.close();
}

void LinkedList::SaveData()
{
	char name[10];
	int kor, eng, mat, total;
	float ever;

	Student* st = _Head->Next;

	fstream fp;
	fp << fixed;
	fp.precision(2);


	fp.open("data.txt", ios::out);

	if (!fp) { cout << "����" << endl; return; }

	for (; st != _Tail; st = st->Next)
	{
		fp << st->name << endl;
		fp << st->Kor << endl;
		fp << st->Eng << endl;
		fp << st->Mat << endl;
		fp << st->Total << endl;
		fp << st->ever << endl;
	}

	fp.close();


}

void LinkedList::TotalStudent()
{
	system("cls");
	cout << "�� " << _icount << "��" << endl;

}

void LinkedList::NewStudent()
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

	BInsert(st);
}

void LinkedList::FNewStudent(Student* st2)
{
	cout << fixed;
	cout.precision(2);

	if (st2 == NULL)
	{
		return;
	}
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

	Student* Next = st2->Next;//haed.next.next

	st2->Next = st;//head.next.next = st
	st->Next = Next;//st.next=head.next.next  
	Next->Prev = st;// head.next=st
	st->Prev = st2;//head=st2;

	_icount++;

}

void LinkedList::SPrint()
{
	cout << fixed;
	cout.precision(2);
	char name[10];
	cout << "�̸� �Է�: "; cin >> name;
	Student* temp = _Head;
	for (; temp->Next != _Tail; temp = temp->Next)
	{

		if (strcmp(name, temp->Next->name) == 0)
		{
			cout << "�̸�: " << temp->Next->name << endl;
			cout << "��������: " << temp->Next->Kor << endl;
			cout << "��������: " << temp->Next->Eng << endl;
			cout << "��������: " << temp->Next->Mat << endl;
			cout << "���� : " << temp->Next->Total << endl;
			cout << "��� ����: " << temp->Next->ever << endl;
			break;
		}


	}
	if (strcmp(name, temp->name) != 0 && temp->Next == _Tail)
		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;


}

void LinkedList::SAllPrint()
{
	cout << fixed;
	cout.precision(2);
	system("cls");
	Student* st = _Head->Next;
	if (st == _Tail)
	{
		cout << "����� �����Ͱ� �����ϴ�\n";
		return;
	}
	for (; st != _Tail; st = st->Next)
	{
		cout << "�̸�: " << st->name << endl;
		cout << "��������: " << st->Kor << endl;
		cout << "��������: " << st->Eng << endl;
		cout << "��������: " << st->Mat << endl;
		cout << "���� : " << st->Total << endl;
		cout << "��� ����: " << st->ever << endl;
	}

}

void LinkedList::SDelete()
{

	char name[10];
	Student* st = _Head->Next;
	Student* tm;
	Student* bm;
	cout << "�̸� �Է�: "; cin >> name;

	while (st != NULL)
	{

		if (strcmp(st->name, name) == 0)
			break;
		st = st->Next;

	}
	if (st == NULL)
	{
		cout << "ã���ô� ����� �����ϴ�\n\n";
		return;
	}

	tm = st->Next;
	bm = st->Prev;
	free(st);

	bm->Next = tm;
	tm->Prev = bm;

	_icount--;
	cout << "�����Ϸ�" << endl;
	//SInit();
}

void LinkedList::SChange()
{

	char name[10];
	int kor, eng, mat, total;
	Student* temp = _Head;
	cout << "�̸� �Է�: "; cin >> name;

	for (; temp->Next != _Tail; temp = temp->Next)
	{

		if (strcmp(name, temp->Next->name) == 0)
		{
			cout << "�̸�: "; cin >> name;
			strcpy(temp->Next->name, name);
			cout << "��������: "; cin >> kor;
			temp->Next->Kor = kor;
			cout << "��������: "; cin >> eng;
			temp->Next->Eng = eng;
			cout << "��������: "; cin >> mat;
			temp->Next->Mat = mat;
			total = kor + eng + mat;
			temp->Next->Total = total;
			temp->Next->ever = (float)total / 3;

			cout << "���� �Ϸ�" << endl;
			break;
		}


	}
	if (strcmp(name, temp->name) != 0 && temp->Next == _Tail)
		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;

}

void LinkedList::ReSet()
{

	AllDelete();

	int nResult = remove("data.txt");
}

Student* LinkedList::Search(LinkedList* list)
{

	char name[10];
	cout << "ã���ô� �̸� : "; cin >> name;
	Student* temp = list->_Head;

	for (int i = 0; i < _icount; i++, temp = temp->Next)
	{
		if (strcmp(name, temp->Next->name) != 0 && temp->Next == _Tail)
		{
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
			return 0;
		}
		if (strcmp(name, temp->Next->name) == 0)
		{

			return temp->Next;
		}


	}

	if (strcmp(name, temp->name) != 0 && temp->Next == _Tail)
	{
		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
		return 0;
	}

}
