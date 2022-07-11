#pragma once
#define _CRT_SECURE_NO_WARNINGS
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
	Student* _Head;
	Student* _Tail;
	Student* _Temp;

public:
	Student NewStudent(Node* node);
	void Print(Node* node);
	Node SInit(Node* node);
	void SInsert(Node* node);
	void FInsert(Node* node);
	void BInsert(Node* node);
	void SPrint(Node* node);
	void SAllPrint(Node* node);
	void SDelete(Node* node);
	void Schange(Node* node);

};
