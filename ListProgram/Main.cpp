#include"Student.h"

int main(void)
{
	int choice;
	LinkedList<Student*>list;
	Student* st = new Student;
	Student* noob=new Student;
	
	do
	{
		cout << endl << "[0. 로드]    [1. 학생 추가]    [2. 추가할 학생 위치]    [3. 목록 출력]    [4. 정보 수정]    " << endl;
		cout << "[5. 검색]    [6. 총 학생수]    [7. 삭제]    [8. 세이브]   [9.리셋]    [999. 종료]" << endl;
		cout << "선택하세요" << endl;

		cin >> choice;
		if (cin.fail() == true)
		{
			cout << "잘못 입력하셨습니다" << endl;
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

			cout << "프로그램을 종료합니다" << endl;
			return 0;

		default:
			cout << "잘못 입력하셨습니다" << endl;
		}

	} while (1);


	return 0;

}

//Student* st = new Student;

	//int choice;



//do    
//{
//	cout << endl << "[0. 로드]    [1. 학생 추가]    [2. 추가할 학생 위치]    [3. 목록 출력]    [4. 정보 수정]    " << endl;
//	cout<<"[5. 검색]    [6. 총 학생수]    [7. 삭제]    [8. 세이브]   [9.리셋]    [999. 종료]" << endl;
//	cout<<"선택하세요"<<endl;
//	
//	cin >> choice;
//	if (cin.fail() == true)
//	{
//		cout << "잘못 입력하셨습니다" << endl;
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

//		cout << "프로그램을 종료합니다" << endl;
//		return 0;

//	default:
//		cout << "잘못 입력하셨습니다" << endl;
//	}

//} while (1);
//