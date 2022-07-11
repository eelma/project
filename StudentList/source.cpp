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

	_Temp->Next = st;
	st->Next = _Tail;
	_Temp = st;
	_icount++;
}

void Node::SInit()
{
	_Head = new Student;
	_Tail = new Student;

	memset(_Head, 0, sizeof(Student));
	memset(_Tail, 0, sizeof(Student));

	_Head->Next = _Tail;
	_Temp = _Head;
	_icount = 0;

}
void Node::SInsert(Student* st)
{
	_Temp->Next = st;
	st->Next = _Tail;
	_Temp = st;
	_icount++;
}

void Node::SChange()
{

	char name[10];
	int kor, eng, mat, total;

	cout << "이름 입력: "; cin >> name;
	for (int i = 0; i < _icount; i++, _Head = _Head->Next)
	{

		if (strcmp(name, _Head->Next->name) == 0)
		{
			cout << "이름: "; cin >> name;
			strcpy(_Head->Next->name, name);
			cout << "국어점수: "; cin >> kor;
			_Head->Next->Kor = kor;
			cout << "영어점수: "; cin >> eng;
			_Head->Next->Eng = eng;
			cout << "수학점수: "; cin >> mat;
			_Head->Next->Mat = mat;
			total = kor + eng + mat;
			_Head->Next->Total = total;
			_Head->Next->ever = (float)total / 3;

			cout << "변경 완료" << endl;
			break;
		}


	}
	if (strcmp(name, _Head->name) != 0 && _Head->Next == _Tail)
		cout << "잘못 입력하셨습니다." << endl;

}

void Node::SPrint()
{
	char name[10];
	cout << "이름 입력: "; cin >> name;
	for (int i = 0; i < _icount; i++, _Head = _Head->Next)
	{

		if (strcmp(name, _Head->Next->name) == 0)
		{
			cout << "이름: " << _Head->Next->name << endl;
			cout << "국어점수: " << _Head->Next->Kor << endl;
			cout << "영어점수: " << _Head->Next->Eng << endl;
			cout << "수학점수: " << _Head->Next->Mat << endl;
			cout << "총점 : " << _Head->Next->Total << endl;
			cout << "평균 점수: " << _Head->Next->ever << endl;
			break;
		}


	}
	if (strcmp(name, _Head->name) != 0 && _Head->Next == _Tail)
		cout << "잘못 입력하셨습니다." << endl;


}

void Node::SAllPrint()
{
	Student* st = _Head->Next;
	if (st == NULL || st == _Tail)
	{
		cout << "저장된 데이터가 없습니다\n\n";
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
	Student* st=_Head;
	Student* tm;
	cout << "이름 입력: "; cin >> name;

	while (st->Next!=NULL)
	{

		if (strcmp(st->Next->name, name) == 0)
			break;
		st = st->Next;

	}
	if (st->Next == NULL && strcmp(st->name, name) != 0)
	{
		cout << "찾으시는 대상이 없습니다\n\n";
		return;
	}
	tm = st->Next->Next;
	free(st->Next);
	st->Next = tm;
	_icount--;
	cout << "삭제완료" << endl;
}
