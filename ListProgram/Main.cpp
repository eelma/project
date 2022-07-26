#include"Student.h"
void Menu()
{
	cout << endl << "----------0. 로드" << endl;
	cout << "----------1. 학생 추가" << endl;
	cout << "----------2. 지정 위치 추가" << endl;
	cout << "----------3. 목록 출력" << endl;
	cout << "----------4. 정보 수정" << endl;
	cout << "----------5. 검색" << endl;
	cout << "----------6. 학생 수" << endl;
	cout << "----------7. 지정 삭제" << endl;
	cout << "----------8. 저장" << endl;
	cout << "----------9. 정렬" << endl;
	cout << "----------10. 데이터 삭제" << endl;
	cout << "----------1927. 전체 리셋" << endl;
	cout << "----------999. 종료" << endl;
	cout << "선택하세요" << endl;
}
int main(void)
{
	int choice;
	LinkedList<Student*>list;

	Student* noob = new Student;

	do
	{
		
		Menu();
		
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
			noob->SearchInsert(list);

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
			noob->sorting(list);
			break;
		case 10:
			list.AllDelete();
			break;

		case 1927:
			noob->ReSet(list);
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