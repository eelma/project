#define _CRT_SECURE_NO_WARNINGS
#include"List.h"
#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

void Node::NewStudent()
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


void Node::SaveData()
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

	for (; st != _Tail;st=st->Next)
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

/*
void Node::ReadData()
{
	fstream fp;
	fp.open("data.txt");
	if (!fp) { cout << "����" << endl; return; }
		while (!fp.eof()) {
		Student* st = new Student;

		cout << fixed;
		cout.precision(2);
		char a[10];
		int b;
		float f;

		fp >> a;
		strcpy(st->name, a);
		cout <<"�̸�: " << a ;
		
		fp >> b; 
		st->Kor = b;
		cout << "����: " << b;

		fp >> b;
		st->Eng = b;
		cout << "����: " << b;

		fp >> b;
		st->Mat = b;
		cout << "����: " << b;

		fp >> b;
		st->Total = b;
		cout << left << "����: " << b;

		fp >> f;
		st->ever = f;
		cout << "���: " << f<<endl;

		BInsert(st);
	}

	fp.close();
}*/

void Node::ReSet()
{

	Student* st = _Head->Next;
	if (st == _Tail)
	{
		cout << "���� �Ϸ�\n";
		return;
	}
	for (int i = 0; i < _icount; i++, st = st->Next)
	{
		Student* Prev = st->Prev;
		Student* Next = st->Next;
		delete st;
		Prev->Next = Next;
		Next->Prev = Prev;
		st = _Head;
	}
	_icount = 0;
	fstream fp;

	int nResult = remove("data.txt");
}

void Node::FNewStudent(Student* st2)
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

void Node::SInit()
{
	_Head = new Student;
	_Tail = new Student;

	memset(_Head, 0, sizeof(Student));
	memset(_Tail, 0, sizeof(Student));

	_Head->Next = _Tail;
	_Tail->Prev = _Head;
	
	_Temp = _Head;
	_icount = 0;

	fstream fp;
	fp.open("data.txt");
	if (!fp) {  return; }

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


void Node::BInsert(Student* st)
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
void Node::FInsert(Student* st)
{

	Student* Next = _Head->Next;
	_Head->Next = st;
	st->Next = Next;

	Next->Prev = st;
	st->Prev = _Head;

	_icount++;


}

Student* Node:: Search(Node*node)
{

	char name[10];
	cout << "ã���ô� �̸� : "; cin >> name;
	Student* temp = node->_Head;

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

void Node::SChange()
{

	char name[10];
	int kor, eng, mat, total;
	Student* temp = _Head;
	cout << "�̸� �Է�: "; cin >> name;
	
	for (int i = 0; i < _icount; i++, temp = temp->Next)
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

void Node::SPrint()
{
	cout << fixed;
	cout.precision(2);
	char name[10];
	cout << "�̸� �Է�: "; cin >> name;
	Student* temp = _Head;
	for (int i = 0; i < _icount; i++, temp = temp->Next)
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

void Node::SAllPrint()
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
	for (int i = 0; i < _icount; i++, st = st->Next)
	{
		cout << "�̸�: " << st->name << endl;
		cout << "��������: " << st->Kor << endl;
		cout << "��������: " << st->Eng << endl;
		cout << "��������: " << st->Mat << endl;
		cout << "���� : " << st->Total << endl;
		cout << "��� ����: " << st->ever << endl;
	}
	
}

void Node::SDelete()
{

	char name[10];
	Student* st = _Head->Next;
	Student* tm;
	Student* bm;
	cout << "�̸� �Է�: "; cin >> name;

	while (st!= NULL)
	{

		if (strcmp(st->name, name) == 0)
			break;
		st = st->Next;

	}
	if (st == NULL && strcmp(st->Prev->name, name) != 0)
	{
		cout << "ã���ô� ����� �����ϴ�\n\n";
		return;
	}

	tm = st->Next;//headnextnext
	bm = st->Prev;
	free(st);

	bm->Next = tm;
	tm->Prev = bm;

	_icount--;
	cout << "�����Ϸ�" << endl;
	//SInit();
}
void Node::TotalStudent()
{
	system("cls");
	cout << "�� " << _icount<<"��" << endl;

}