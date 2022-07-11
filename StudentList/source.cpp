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
void Node::SInsert(Student*st)
{
	_Temp->Next = st;
	st->Next = _Tail;
	_Temp = st;
	_icount++;
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
void Node::SChange()
{

	char name[10];
	int kor, eng, mat, total;

	cout << "이름 입력: "; cin >> name;
	for (int i = 0; i < _icount; i++, _Head = _Head->Next)
	{

		if (strcmp(name, _Head->Next->name) == 0)
		{
			cout << "이름: ";cin>>name;
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
			
			cout << "변경 완료"<<endl;
			break;
		}


	}
	if (strcmp(name, _Head->name) != 0 && _Head->Next == _Tail)
		cout << "잘못 입력하셨습니다." << endl;
	
}

void Node::Print()
{
	if (_Head->Next == NULL || _Head->Next == _Tail)
	{
		cout << "목록이 없습니다" << endl;
		return;
	
	for(int i=0;i<_icount;i++,_Head=_Head->Next)
	{
	cout << "이름: " << _Head->Next->name<<endl;
	cout << "국어점수: "<<_Head->Next->Kor << endl;
	cout << "영어점수: " <<_Head->Next->Eng << endl;
	cout << "수학점수: " << _Head->Next->Mat << endl;
	cout << "총점 : " << _Head->Next->Total << endl;
	cout << "평균 점수: " << _Head->Next->ever << endl;
	}
	}
}

void Node::SDelete()
{

	char name[10];
	Student* st;
	cout << "이름 입력: "; cin >> name;
	for (int i = 0; i < _icount; i++, _Head = _Head->Next)
	{

		if (strcmp(name, _Head->Next->name) == 0)
		{
			st = _Head->Next;
			free(_Head->Next);
			_Head->Next = st->Next;
			cout << "삭제 완료"<<endl;
			break;
		}


	}
	if (strcmp(name, _Head->name) != 0 && _Head->Next == _Tail)
		cout << "잘못 입력하셨습니다." << endl;


}
