#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstdio>
#include <cstdlib> // _countof 정적할당 배열 크기 반환
#include <ctime>
#include <cstring>
#include <cmath>
#include<fstream>
using namespace std;

class Student
{

public:
	char name[10];
	int Kor, Eng, Mat, Total;
	float ever;
	Student* Next;
	Student* Prev;
};

class Node
{
private:
	int _icount;
	Student* _Head = NULL;
	Student* _Tail = NULL;
	Student* _Temp = NULL;

public:
	void SaveData();
	void TotalStudent();
	void NewStudent();
	void SInit();
	void SInsert(Student* st);
	void FInsert(Student* st);
	void FNewStudent(Student* st);
	void BInsert(Student* st);
	void SPrint();
	void SAllPrint();
	void SDelete();
	void SChange();
	void ReadData();
	void ReSet();

	Student* Search(Node*node);
	~Node();

};
