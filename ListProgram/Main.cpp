#include"Student.h"

int main(void)
{
	int choice;
	LinkedList<Student*>list;
	Student* st = new Student;
	Student* noob=new Student;
	
	do
	{
		cout << endl << "[0. �ε�]    [1. �л� �߰�]    [2. �߰��� �л� ��ġ]    [3. ��� ���]    [4. ���� ����]    " << endl;
		cout << "[5. �˻�]    [6. �� �л���]    [7. ����]    [8. ���̺�]   [9.����]    [999. ����]" << endl;
		cout << "�����ϼ���" << endl;

		cin >> choice;
		if (cin.fail() == true)
		{
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			break;
		}

		switch (choice)
		{
		case 0:
			noob->Load(list);
			break;
		case 1:
			list.BInsert(noob->NewStudent());
			break;

		case 2:
			noob->Search(list);
			
			break;

		case 3:
			noob->SAllPrint(list);
			break;

		case 4:
			noob->SChange(list);
			break;

		case 5:
			noob->SPrint(list);
			break;

		case 6:
			noob->TotalStudent(list);
			break;

		case 7:
			noob->SDelete(list);
			break;
		case 8:
			noob->SaveData(list);
			break;

		case 9:
			//list->ReSet();
			break;
		case 10:
			list.AllDelete();
			break;

		case 999:

			cout << "���α׷��� �����մϴ�" << endl;
			return 0;

		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
		}

	} while (1);


	return 0;

}

//Student* st = new Student;

	//int choice;



//do    
//{
//	cout << endl << "[0. �ε�]    [1. �л� �߰�]    [2. �߰��� �л� ��ġ]    [3. ��� ���]    [4. ���� ����]    " << endl;
//	cout<<"[5. �˻�]    [6. �� �л���]    [7. ����]    [8. ���̺�]   [9.����]    [999. ����]" << endl;
//	cout<<"�����ϼ���"<<endl;
//	
//	cin >> choice;
//	if (cin.fail() == true)
//	{
//		cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
//		break;
//	}
//	
//	switch(choice)
//	{
//	case 0:
//		list->Load();
//		break;
//	case 1:
//		list->NewStudent();
//		break;
//		
//	case 2:

//		st = list->Search(list);
//		list->FNewStudent(st);
//		break;

//	case 3:
//		list->SAllPrint();
//		break;

//	case 4:
//		list->SChange();
//		break;

//	case 5:
//		list->SPrint();
//		break;

//	case 6:
//		list->TotalStudent();
//		break;

//	case 7:
//		list->SDelete();
//		break;
//	case 8:
//		list->SaveData();
//		break;

//	case 9:
//		list->ReSet();
//		break;
//	case 10:
//		list->AllDelete();
//		break;

//	case 999:

//		cout << "���α׷��� �����մϴ�" << endl;
//		return 0;

//	default:
//		cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
//	}

//} while (1);
//