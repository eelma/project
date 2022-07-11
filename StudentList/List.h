#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
class Student
{

public:
	char name[10];
	int Kor,Eng,Mat,Total;
	float ever;
	Student* Next;
};

class Node
{
private:
	int _icount;
	Student* _Head=NULL;
	Student* _Tail = NULL;
	Student* _Temp = NULL;

public:
	void NewStudent();
	void Print();
	void SInit();
	void SInsert(Student* st);
	//void FInsert(Student* st);
	//void BInsert(Student* st);
	void SPrint();
	void SAllPrint();
	void SDelete();
	void SChange();

};
