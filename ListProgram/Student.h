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
		delete[]name;
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


	template<class T>
	void sorting(LinkedList<T> list);

	template<class T>
	void ReSet(LinkedList<T> list);


};



Student* Student::NewStudent()
{
	char name[20];
	int len;
	int kor, eng, mat, total;
	//Student* temp = new Student;
	Student* st = new Student;
	//memset(st, 0, sizeof(Student));
	cout << "학생 이름 입력: "; cin >> name;
	len = strlen(name);
	st->name = new char[len] + 1;
	strcpy(st->name, name);
	cout << "국어 점수: "; cin >> kor;
	st->Kor = kor;
	cout << "영어 점수: "; cin >> eng;
	st->Eng = eng;
	cout << "수학 점수: "; cin >> mat;
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
	if (!fp) { cout << "로드 실패" << endl; return; }
	else
	{
		cout << "로드 성공" << endl;
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
	Student* st = tmp->Data;

	if (tmp == list._Tail)
	{
		cout << "저장된 데이터가 없습니다\n";
		return;
	}

	for (; tmp->_Next != nullptr; tmp = tmp->_Next, st = tmp->Data)
	{
		if (tmp == NULL)
		{
			return;
		}
		cout.setf(ios::left);
		cout << "이름: "; cout.width(5); cout << st->name;
		cout << "국어점수: "; cout.width(8); cout << st->Kor;
		cout << "영어점수: "; cout.width(8); cout << st->Eng;
		cout << "수학점수: "; cout.width(8); cout << st->Mat;
		cout << "총점 : "; cout.width(8); cout << st->Total;
		cout << "평균 점수: "; cout.width(8); cout << st->ever << endl;
	}


}



template<class T>
void Student::Search(LinkedList<T> list)
{

	char name[10];
	cout << "찾으시는 이름 : "; cin >> name;

	Node<T>* tmp = list._Temp->_Next;
	Student* st = tmp->Data;
	if (st == nullptr)
	{
		cout << "데이터가 존재하지 않습니다.";
		return;
	}

	for (; tmp != list._Tail; tmp = tmp->_Next, st = tmp->Data)
	{
		if (strcmp(name, st->name) != 0 && tmp->_Next == list._Tail)
		{
			cout << "잘못 입력하셨습니다." << endl;
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
			newnode->Data = new Student;

			cout << fixed;
			cout.precision(2);

			char name[10];
			int kor, eng, mat, total;
			Student* st2 = newnode->Data;
			memset(st2, 0, sizeof(Student));


			cout << "학생 이름 입력: "; cin >> name;
			st2->name = new char[strlen(name)];
			strcpy(st2->name, name);
			cout << "국어 점수: "; cin >> kor;
			st2->Kor = kor;
			cout << "영어 점수: "; cin >> eng;
			st2->Eng = eng;
			cout << "수학 점수: "; cin >> mat;
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
	//	cout << "잘못 입력하셨습니다." << endl;
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
	Student* st = tmp->Data;

	fstream fp;
	fp << fixed;
	fp.precision(2);


	fp.open("data.txt", ios::out);

	if (!fp) { cout << "실패" << endl; return; }

	for (; tmp != list._Tail; tmp = tmp->_Next, st = tmp->Data)
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
	cout << "총 " << list._icount << "명" << endl;
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


	cout << "학생 이름 입력: "; cin >> name;
	strcpy(st->name, name);
	cout << "국어 점수: "; cin >> kor;
	st->Kor = kor;
	cout << "영어 점수: "; cin >> eng;
	st->Eng = eng;
	cout << "수학 점수: "; cin >> mat;
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
	cout << "찾으시는 이름 : "; cin >> name;

	Node<T>* tmp = list._Temp->_Next;
	Student* st = tmp->Data;
	if (st == nullptr)
	{
		cout << "데이터가 존재하지 않습니다.";
		return;
	}

	for (; tmp != list._Tail; tmp = tmp->_Next, st = tmp->Data)
	{
		if (strcmp(name, st->name) != 0 && tmp->_Next == list._Tail)
		{
			cout << "잘못 입력하셨습니다." << endl;
			break;
		}
		if (strcmp(name, st->name) == 0)
		{
			Student* ch = tmp->Data;

			cout << fixed;
			cout.precision(2);

			char name[10];
			int kor, eng, mat, total;

			memset(ch, 0, sizeof(Student));


			cout << "학생 이름 입력: "; cin >> name;
			ch->name = new char[strlen(name)];
			strcpy(ch->name, name);
			cout << "국어 점수: "; cin >> kor;
			ch->Kor = kor;
			cout << "영어 점수: "; cin >> eng;
			ch->Eng = eng;
			cout << "수학 점수: "; cin >> mat;
			ch->Mat = mat;
			total = kor + eng + mat;
			ch->Total = total;
			ch->ever = (float)total / 3;


			return;

		}
	}

}



template<class T>
void Student::SPrint(LinkedList<T> list)
{
	char name[10];
	cout << "찾으시는 이름 : "; cin >> name;

	Node<T>* tmp = list._Temp->_Next;
	Student* st = tmp->Data;
	if (st == nullptr)
	{
		cout << "데이터가 존재하지 않습니다.";
		return;
	}

	for (; tmp != list._Tail; tmp = tmp->_Next, st = tmp->Data)
	{
		if (strcmp(name, st->name) != 0 && tmp->_Next == list._Tail)
		{
			cout << "잘못 입력하셨습니다." << endl;
			break;
		}
		if (strcmp(name, st->name) == 0)
		{
			Student* ch = tmp->Data;

			cout << fixed;
			cout.precision(2);
			cout << "이름: " << ch->name << endl;
			cout << "국어점수: " << ch->Kor << endl;
			cout << "영어점수: " << ch->Eng << endl;
			cout << "수학점수: " << ch->Mat << endl;
			cout << "총점 : " << ch->Total << endl;
			cout << "평균 점수: " << ch->ever << endl;


			return;

		}
	}


}



template<class T>
void Student::SDelete(LinkedList<T> list)
{

	char name[10];
	cout << "찾으시는 이름 : "; cin >> name;

	Node<T>* tmp = list._Temp->_Next;
	Student* st = tmp->Data;
	if (st == nullptr)
	{
		cout << "데이터가 존재하지 않습니다.";
		return;
	}

	for (; tmp != list._Tail; tmp = tmp->_Next, st = tmp->Data)
	{
		if (strcmp(name, st->name) != 0 && tmp->_Next == list._Tail)
		{
			cout << "잘못 입력하셨습니다." << endl;
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


template<class T>
void Student::sorting(LinkedList<T> list)
{
	int i = 0;
	clock_t sTime, eTime;
	sTime = clock();
	
	Node<T>* val = list._Head->_Next->_Next;
	Student* data1 = val->Data;

	Node<T>* Prev = val->_Prev;
	Student* data2 = Prev->Data;

	Node<T>* Next = val->_Next;

	if(val==NULL)
	{	
		cout << "곤란" << endl;
		return;
	}

	for(;val!=NULL&&data2!=NULL;)
	{
		if (data1->Total > data2->Total)
			{
				Prev = Prev->_Prev;
				data2 = Prev->Data;
			}
			else
			{
				Node<T>* tmp = val->_Prev;
				val->_Next = Prev;

				val->_Prev = Prev->_Prev;
				Prev->_Prev->_Next = val;

				Prev->_Prev = val;
		
				tmp->_Next = Next;
				Next->_Prev = tmp;

				if (val->_Prev == list._Head)
				{
					val = Next;
					data1 = val->Data;
				}
				Prev = val->_Prev;
				data2 = Prev->Data;
				Next = val->_Next;
				
				i++;
			}
		
	}


	cout << i<<endl;
	eTime = clock() - sTime;
	printf("\n\ttime => [%ld,%8.3f] => ", eTime, eTime / (double)CLK_TCK);

}

template<class T>
void Student::ReSet(LinkedList<T> list)
{
	list.AllDelete();
	remove("data.txt");


}



//void LinkedList::ReSet()
//{
//
//	AllDelete();
//
//	int nResult = remove("data.txt");
//}
//


/*Node<T>* mid = list._Head->_Next;
	Student* data1 = mid->Data;
	Student* data2 = mid->_Next->Data;
	if (mid == list._Tail)
		return;
	clock_t sTime, eTime;
	sTime = clock();
	for (int i = 0; i < list._icount; i++)
	{
		mid = list._Head->_Next;
		data1 = mid->Data;
		data2 = mid->_Next->Data;
		for (; mid->_Next->_Next != NULL; data1 = mid->Data, data2 = mid->_Next->Data)
		{
			if (data1->Total > data2->Total)
			{
				Node<T>* Next = mid->_Next;
				Node<T>* Prev = mid->_Prev;

				mid->_Next = Next->_Next;
				Next->_Next->_Prev = mid;
				Next->_Prev = Prev;
				Prev->_Next = Next;

				Next->_Next = mid;
				mid->_Prev = Next;

			}
			else
			{
				mid = mid->_Next;
			}
		}
	}
	eTime = clock() - sTime;
	printf("\n\ttime => [%ld,%8.3f] => ", eTime, eTime / (double)CLK_TCK);*/