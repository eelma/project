#pragma once
#include"List.h"

class Student
{
public:
	char* name;
	int Kor, Eng, Mat, Total;
	float ever;
public:
	Student()
	{
		Kor = Eng = Mat = Total = ever = 0;
	}
	Student(const char* myname, int kor, int eng, int mat) :Kor(kor), Eng(eng), Mat(mat)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		Total = Kor + Eng + Mat;
		ever = (float)Total / 3;
	}
	~Student()
	{
		delete []name;
	}

public:
	Student* NewStudent();

	template<class T>
	void Load(LinkedList<T> list);

	template<class T>
	void SaveData(LinkedList<T> list);

	template<class T>
	void SChange(LinkedList<T> list);


	template<class T>
	void SAllPrint(LinkedList<T> list);

	template<class T>
	void Search(LinkedList<T> list);

	template<class T>
	void TotalStudent(LinkedList<T> list);

	template<class T>
	void FNewStudent(LinkedList<T> st2);

	template<class T>
	void SPrint(LinkedList<T> list);

	template<class T>
	void SDelete(LinkedList<T> list);


};











Student* Student::NewStudent()
{
	char name[20];
	int len;
	int kor, eng, mat, total;
	//Student* temp = new Student;
	Student* st = new Student;
	//memset(st, 0, sizeof(Student));
	cout << "�л� �̸� �Է�: "; cin >> name;
	len = strlen(name);
	st->name = new char[len] + 1;
	strcpy(st->name, name);
	cout << "���� ����: "; cin >> kor;
	st->Kor = kor;
	cout << "���� ����: "; cin >> eng;
	st->Eng = eng;
	cout << "���� ����: "; cin >> mat;
	st->Mat = mat;
	total = kor + eng + mat;
	st->Total = total;
	st->ever = (float)total / 3;

	return st;

}



template<class T>
void Student::Load(LinkedList<T> list)
{
	list.AllDelete();


	fstream fp;
	fp.open("data.txt");
	if (!fp) { cout << "�ε� ����" << endl; return; }
	else
	{
		cout << "�ε� ����" << endl;
	}
	for (; !fp.eof();) {

		cout << fixed;
		cout.precision(2);
		char a[10];
		int b;
		float f;
		Student* st = new Student;
		memset(st, 0, sizeof(Student));
		st->name = new char[strlen(a) + 1];

		fp >> a;
		strcpy(st->name, a);

		fp >> b;
		if (b <= 0)
		{
			return;
		}
		st->Kor = b;

		fp >> b;
		st->Eng = b;

		fp >> b;
		st->Mat = b;

		fp >> b;
		st->Total = b;

		fp >> f;
		st->ever = f;
		b = f = 0;
		list.BInsert(st);
	}

	fp.close();
}



template<class T>
void Student::SAllPrint(LinkedList<T> list)
{
	cout << fixed;
	cout.precision(2);
	system("cls");

	Node<T>* tmp = list._Temp->_Next;
	Student* st = tmp->TData;

	if (tmp == list._Tail)
	{
		cout << "����� �����Ͱ� �����ϴ�\n";
		return;
	}

	for (; tmp->_Next != nullptr; tmp = tmp->_Next, st = tmp->TData)
	{
		if (tmp == NULL)
		{
			return;
		}

		cout << "�̸�: " << st->name << endl;
		cout << "��������: " << st->Kor << endl;
		cout << "��������: " << st->Eng << endl;
		cout << "��������: " << st->Mat << endl;
		cout << "���� : " << st->Total << endl;
		cout << "��� ����: " << st->ever << endl;
	}


}



template<class T>
void Student::Search(LinkedList<T> list)
{

	char name[10];
	cout << "ã���ô� �̸� : "; cin >> name;

	Node<T>* tmp = list._Temp->_Next;
	Student* st = tmp->TData;
	if (st == nullptr)
	{
		cout << "�����Ͱ� �������� �ʽ��ϴ�.";
		return;
	}

	for (; tmp != list._Tail; tmp = tmp->_Next, st = tmp->TData)
	{
		if (strcmp(name, st->name) != 0 && tmp->_Next == list._Tail)
		{
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
			break;
		}
		if (strcmp(name, st->name) == 0)
		{
			Node<T>* newnode = new Node<T>;
			Node<T>* Next = tmp->_Next;
			tmp->_Next = newnode;
			newnode->_Prev = tmp;
			newnode->_Next = Next;
			Next->_Prev = newnode;
			newnode->TData = new Student;

			cout << fixed;
			cout.precision(2);

			char name[10];
			int kor, eng, mat, total;
			Student* st2 = newnode->TData;
			memset(st2, 0, sizeof(Student));


			cout << "�л� �̸� �Է�: "; cin >> name;
			st2->name = new char[strlen(name)];
			strcpy(st2->name, name);
			cout << "���� ����: "; cin >> kor;
			st2->Kor = kor;
			cout << "���� ����: "; cin >> eng;
			st2->Eng = eng;
			cout << "���� ����: "; cin >> mat;
			st2->Mat = mat;
			total = kor + eng + mat;
			st2->Total = total;
			st2->ever = (float)total / 3;
			list._icount++;

			return;
			
		}
	}

	//if (strcmp(name, st->name) != 0 && tmp->_Next == list._Tail)
	//{
	//	cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
	//	return;
	//}

}



template<class T>
void Student::SaveData(LinkedList<T> list)
{
	char name[10];
	int kor, eng, mat, total;
	float ever;

	Node<T>* tmp = list._Temp->_Next;
	Student* st = tmp->TData;

	fstream fp;
	fp << fixed;
	fp.precision(2);


	fp.open("data.txt", ios::out);

	if (!fp) { cout << "����" << endl; return; }

	for (; tmp!=list._Tail; tmp=tmp->_Next,st=tmp->TData)
	{
		fp << st->name << endl;
		fp << st->Kor << endl;
		fp << st->Eng << endl;
		fp << st->Mat << endl;
		fp << st->Total << endl;
		fp << st->ever << endl;
	}

	fp.close();


}



template<class T>
void Student::TotalStudent(LinkedList<T> list)
{
	system("cls");
	cout << "�� " << list._icount << "��" << endl;
}



template<class T>
void Student::FNewStudent(LinkedList<T> st2)
{
	cout << fixed;
	cout.precision(2);

	if (st2 == NULL)
	{
		return;
	}
	char name[10];
	int kor, eng, mat, total;

	
	Student* st = new Student;

	Node<T>* temp = st;
	memset(st, 0, sizeof(Student));


	cout << "�л� �̸� �Է�: "; cin >> name;
	strcpy(st->name, name);
	cout << "���� ����: "; cin >> kor;
	st->Kor = kor;
	cout << "���� ����: "; cin >> eng;
	st->Eng = eng;
	cout << "���� ����: "; cin >> mat;
	st->Mat = mat;
	total = kor + eng + mat;
	st->Total = total;
	st->ever = (float)total / 3;

	Node<T>* newdata = st2;
	Node<T>* Prev = newdata->_Prev;
	Node<T>* Next = newdata->_Next;

	newdata->_Next = temp;
	temp->_Prev = newdata;
	temp->_Next = Next;
	Next->_Prev = temp;

	st2._icount++;

}


template<class T>
void Student::SChange(LinkedList<T> list)
{
	char name[10];
	cout << "ã���ô� �̸� : "; cin >> name;

	Node<T>* tmp = list._Temp->_Next;
	Student* st = tmp->TData;
	if (st == nullptr)
	{
		cout << "�����Ͱ� �������� �ʽ��ϴ�.";
		return;
	}

	for (; tmp != list._Tail; tmp = tmp->_Next, st = tmp->TData)
	{
		if (strcmp(name, st->name) != 0 && tmp->_Next == list._Tail)
		{
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
			break;
		}
		if (strcmp(name, st->name) == 0)
		{
			Student* ch = tmp->TData;

			cout << fixed;
			cout.precision(2);

			char name[10];
			int kor, eng, mat, total;
			
			memset(ch, 0, sizeof(Student));


			cout << "�л� �̸� �Է�: "; cin >> name;
			ch->name= new char[strlen(name)];
			strcpy(ch->name, name);
			cout << "���� ����: "; cin >> kor;
			ch->Kor = kor;
			cout << "���� ����: "; cin >> eng;
			ch->Eng = eng;
			cout << "���� ����: "; cin >> mat;
			ch->Mat = mat;
			total = kor + eng + mat;
			ch->Total = total;
			ch->ever = (float)total / 3;
			list._icount++;

			return;

		}
	}

}



template<class T>
void Student::SPrint(LinkedList<T> list)
{
	char name[10];
	cout << "ã���ô� �̸� : "; cin >> name;

	Node<T>* tmp = list._Temp->_Next;
	Student* st = tmp->TData;
	if (st == nullptr)
	{
		cout << "�����Ͱ� �������� �ʽ��ϴ�.";
		return;
	}

	for (; tmp != list._Tail; tmp = tmp->_Next, st = tmp->TData)
	{
		if (strcmp(name, st->name) != 0 && tmp->_Next == list._Tail)
		{
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
			break;
		}
		if (strcmp(name, st->name) == 0)
		{
			Student* ch = tmp->TData;

			cout << fixed;
			cout.precision(2);
			cout << "�̸�: " << ch->name << endl;
			cout << "��������: " << ch->Kor << endl;
			cout << "��������: " << ch->Eng << endl;
			cout << "��������: " << ch->Mat << endl;
			cout << "���� : " << ch->Total << endl;
			cout << "��� ����: " << ch->ever << endl;
			

			return;

		}
	}


}





template<class T>
void Student::SDelete(LinkedList<T> list)
{

	char name[10];
	cout << "ã���ô� �̸� : "; cin >> name;

	Node<T>* tmp = list._Temp->_Next;
	Student* st = tmp->TData;
	if (st == nullptr)
	{
		cout << "�����Ͱ� �������� �ʽ��ϴ�.";
		return;
	}

	for (; tmp != list._Tail; tmp = tmp->_Next, st = tmp->TData)
	{
		if (strcmp(name, st->name) != 0 && tmp->_Next == list._Tail)
		{
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
			break;
		}
		if (strcmp(name, st->name) == 0)
		{
			Node<T>* Prev = tmp->_Prev;
			Node<T>* Next = tmp->_Next;

			delete tmp;

			Prev->_Next = Next;
			Next->_Prev = Prev;

			list._icount--;

			return;

		}
	}
}


//void LinkedList::ReSet()
//{
//
//	AllDelete();
//
//	int nResult = remove("data.txt");
//}
//
