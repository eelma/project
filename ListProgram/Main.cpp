#define _CRT_SECURE_NO_WARNINGS
#include"List.h"
#include<iostream>
#include<cstring>

int main(void)
{
	Student* st = new Student;

	int choice;
	Node* node = new Node;
	node->SInit();

	do    
	{
		cout << endl << "[1. �л� �߰�]    [2. �߰��� �л� ��ġ]    [3. ��� ���]    [4. ���� ����]    [5. �˻�]" << endl;
		cout<<"[6. �� �л���]    [7. ����]    [8. ���̺�]   [9.����]    [00. ����]" << endl;
		cout<<"�����ϼ���"<<endl;
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
		case 8:
			node->SaveData();
			break;

		case 9:
			node->ReSet();
			break;

		case 00:

			cout << "���α׷��� �����մϴ�" << endl;
			return 0;

		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
		}

	} while (1);
	
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
