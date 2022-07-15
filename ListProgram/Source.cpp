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
	cout << "학생 이름 입력: "; cin >> name;
	strcpy(st->name, name);
	cout << "국어 점수: "; cin >> kor;
	st->Kor = kor;
	cout << "영어 점수: "; cin >> eng;
	st->Eng = eng;
	cout << "수학 점수: "; cin >> mat;
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

	cout << "학생 이름 입력: "; cin >> name;
	cout << "국어 점수: "; cin >> kor;
	cout << "영어 점수: "; cin >> eng;
	cout << "수학 점수: "; cin >> mat;
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
	cout << "학생 이름 입력: "; cin >> name;
	strcpy(st->name, name);
	cout << "국어 점수: "; cin >> kor;
	st->Kor = kor;
	cout << "영어 점수: "; cin >> eng;
	st->Eng = eng;
	cout << "수학 점수: "; cin >> mat;
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

			// 메모리로 부터 입출력
			fgets(strBuffer, 256, fp);

			sscanf_s(strBuffer, "%s%d%d%d%d%f", st->name,_countof(st->name), &st->Kor, &st->Eng, &st->Mat,&st->Total,&st->ever);
		
			fclose(fp);
		
			BInsert(st);

		printf("%s, %d, %d, %d", st->name, st->Kor, st->Eng, st->Mat);
		

}

void Node::BInsert(Student* st)
{
	//Prev = 꼬리의 머리(헤드), 꼬리의 머리->st, st의 머리->Prev, Prev의 다음->st, st의 다음 ->꼬리
	//꼬리의 대가리= st/ Prev는 st
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
	cout << "찾으시는 이름 : "; cin >> name;
	Student* temp = node->_Head;

	for (int i = 0; i < _icount; i++, temp = temp->Next)
	{
		if (strcmp(name, temp->Next->name) != 0 && temp->Next == _Tail)
		{
			cout << "잘못 입력하셨습니다." << endl;
			return 0;
		}
		if (strcmp(name, temp->Next->name) == 0)
		{

			return temp->Next;
		}
		

	}
	
	if (strcmp(name, temp->name) != 0 && temp->Next == _Tail)
	{
		cout << "잘못 입력하셨습니다." << endl;
		return 0;
	}

}

void Node::SChange()
{

	char name[10];
	int kor, eng, mat, total;
	Student* temp = _Head;
	cout << "이름 입력: "; cin >> name;
	
	for (int i = 0; i < _icount; i++, temp = temp->Next)
	{

		if (strcmp(name, temp->Next->name) == 0)
		{
			cout << "이름: "; cin >> name;
			strcpy(temp->Next->name, name);
			cout << "국어점수: "; cin >> kor;
			temp->Next->Kor = kor;
			cout << "영어점수: "; cin >> eng;
			temp->Next->Eng = eng;
			cout << "수학점수: "; cin >> mat;
			temp->Next->Mat = mat;
			total = kor + eng + mat;
			temp->Next->Total = total;
			temp->Next->ever = (float)total / 3;

			cout << "변경 완료" << endl;
			break;
		}


	}
	if (strcmp(name, temp->name) != 0 && temp->Next == _Tail)
		cout << "잘못 입력하셨습니다." << endl;

}

void Node::SPrint()
{
	cout << fixed;
	cout.precision(2);
	char name[10];
	cout << "이름 입력: "; cin >> name;
	Student* temp = _Head;
	for (int i = 0; i < _icount; i++, temp = temp->Next)
	{

		if (strcmp(name, temp->Next->name) == 0)
		{
			cout << "이름: " << temp->Next->name << endl;
			cout << "국어점수: " << temp->Next->Kor << endl;
			cout << "영어점수: " << temp->Next->Eng << endl;
			cout << "수학점수: " << temp->Next->Mat << endl;
			cout << "총점 : " << temp->Next->Total << endl;
			cout << "평균 점수: " << temp->Next->ever << endl;
			break;
		}


	}
	if (strcmp(name, temp->name) != 0 && temp->Next == _Tail)
		cout << "잘못 입력하셨습니다." << endl;


}

void Node::SAllPrint()
{
	cout << fixed;
	cout.precision(2);
	system("cls");
	Student* st = _Head->Next;
	if (st == _Tail)
	{
		cout << "저장된 데이터가 없습니다\n";
		return;
	}
	for (int i = 0; i < _icount; i++, st = st->Next)
	{
		cout << "이름: " << st->name << endl;
		cout << "국어점수: " << st->Kor << endl;
		cout << "영어점수: " << st->Eng << endl;
		cout << "수학점수: " << st->Mat << endl;
		cout << "총점 : " << st->Total << endl;
		cout << "평균 점수: " << st->ever << endl;
	}
	
}

void Node::SDelete()
{

	char name[10];
	Student* st = _Head->Next;
	Student* tm;
	cout << "이름 입력: "; cin >> name;

	while (st!= NULL)
	{

		if (strcmp(st->name, name) == 0)
			break;
		st = st->Next;

	}
	if (st == NULL && strcmp(st->Prev->name, name) != 0)
	{
		cout << "찾으시는 대상이 없습니다\n\n";
		return;
	}

	tm = st->Next;//headnextnext
	free(st);

	_Head->Next = tm;
	tm->Prev = _Head;

	_icount--;
	cout << "삭제완료" << endl;
}
void Node::TotalStudent()
{
	system("cls");
	cout << "총 " << _icount<<"명" << endl;

}