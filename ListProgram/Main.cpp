#define _CRT_SECURE_NO_WARNINGS
#include"List.h"
#include<iostream>
#include<cstring>

int main(void)
{/*
	Student* st = new Student;

	int choice;
	Node* node = new Node;
	node->SInit();

	do    
	{
		cout << endl << "[1. 학생 추가]    [2. 추가할 학생 위치]    [3. 목록 출력]    [4. 정보 수정]    [5. 검색]    [6. 총 학생수]    [7. 삭제]    [00. 종료]"<<endl;
		cout<<"선택하세요"<<endl;
		cin >> choice;
		

		switch(choice)
		{
		case 1:
			node->NewStudent();
			break;
			
		case 2:

			st = node->Search(node);
			node->FNewStudent(st);
			break;

		case 3:
			node->SAllPrint();
			break;

		case 4:
			node->SChange();
			break;

		case 5:
			node->SPrint();
			break;

		case 6:
			node->TotalStudent();
			break;

		case 7:
			node->SDelete();
			break;

		case 00:

			cout << "프로그램을 종료합니다" << endl;
			return 0;

		default:
			cout << "잘못 입력하셨습니다" << endl;
		}

	} while (1);*/
	
	Node* node = new Node;
	node->SInit();
	/*node->NewStudent();
	node->NewStudent();
	node->NewStudent();
	node->SaveData();*/
	node->ReadData();
	node->SAllPrint();
	node->ReSet();
	node->SAllPrint();

	return 0;

}


//
//node->NewStudent();
//
//
//
//
//st = node->Search(node);
//node->FNewStudent(st);
//
//
