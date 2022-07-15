#define _CRT_SECURE_NO_WARNINGS
#include"List.h"
#include<iostream>
#include<string.h>
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


void Node::createData()
{
	char name[10];
	int kor, eng, mat, total;
	float ever;
	

	FILE* fp = 0;
	fopen_s(&fp, "data.txt", "w");
	if (fp == NULL) return;

	cout << "�л� �̸� �Է�: "; cin >> name;
	cout << "���� ����: "; cin >> kor;
	cout << "���� ����: "; cin >> eng;
	cout << "���� ����: "; cin >> mat;
	total = kor + eng + mat;
	ever = (float)total / 3;

	fprintf(fp, "%s%d%d%d%d%f\n", name, kor, eng, mat, total,ever);
		
	_icount++;


	fclose(fp);


}
void Node::FNewStudent(Student* st2)
{
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

}
void Node::ReadData()
{
	
		FILE* fp = 0;
		fopen_s(&fp, "data.txt", "r");

		if (fp == NULL) { return; }

		
			
		
		char strBuffer[256];// = { 0, };
		memset(strBuffer, 0, sizeof(char) * 256);

			Student* st = new Student;
			memset(st, 0, sizeof(Student));

			// �޸𸮷� ���� �����
			fgets(strBuffer, 256, fp);

			sscanf_s(strBuffer, "%s%d%d%d%d%f", st->name,_countof(st->name), &st->Kor, &st->Eng, &st->Mat,&st->Total,&st->ever);
		
			fclose(fp);
		
			BInsert(st);

		printf("%s, %d, %d, %d", st->name, st->Kor, st->Eng, st->Mat);
		

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
	free(st);

	_Head->Next = tm;
	tm->Prev = _Head;

	_icount--;
	cout << "�����Ϸ�" << endl;
}
void Node::TotalStudent()
{
	system("cls");
	cout << "�� " << _icount<<"��" << endl;

}