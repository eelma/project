#include"Student.h"
void Menu()
{
	cout << endl << "----------0. �ε�" << endl;
	cout << "----------1. �л� �߰�" << endl;
	cout << "----------2. ���� ��ġ �߰�" << endl;
	cout << "----------3. ��� ���" << endl;
	cout << "----------4. ���� ����" << endl;
	cout << "----------5. �˻�" << endl;
	cout << "----------6. �л� ��" << endl;
	cout << "----------7. ���� ����" << endl;
	cout << "----------8. ����" << endl;
	cout << "----------9. ����" << endl;
	cout << "----------10. ������ ����" << endl;
	cout << "----------1927. ��ü ����" << endl;
	cout << "----------999. ����" << endl;
	cout << "�����ϼ���" << endl;
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

			cout << "���α׷��� �����մϴ�" << endl;
			return 0;

		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
		}

	} while (1);


	return 0;

}