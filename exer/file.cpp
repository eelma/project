#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

class taglnfo
{
public:
	char* Name;
	int Kor, Eng, Math;
	taglnfo()
	{
		Name = NULL;
		Kor = 0;
		Eng = 0;
		Math = 0;
	}
	/**/taglnfo(const char* name, int kor, int eng, int math)
	{
		int len = strlen(name) + 1;
		Name = new char[len];
		strcpy(Name, name);
		Kor = kor;
		Eng = eng;
		Math = math;
	}
	void SetInfo(char*name,int kor,int eng,int math)
	{

		Name = name;
		Kor = kor;
		Eng = eng;
		Math = math;

	}
	~taglnfo()
	{
		delete[]Name;
	}
};

int main(void)
{

	taglnfo PT[3];
	char name[10];
	char* tname;
	int kor, eng, mat;
	
	
	
	
	for(int i=0;i<3;i++)
	{ 
		cout << "�̸� ���� ���� ���� ������ �����ʼ�"<<endl;
		cin >> name;
		cin >> kor;
		cin >> eng;
		cin >> mat;

		int tlen = strlen(name) + 1;
		tname = new char[tlen];
		strcpy(tname, name);
		PT[i].SetInfo(tname,kor,eng,mat);
	
	}
	for (int i = 0; i < 3; i++)
	{

		cout << "�̸�: " << PT[i].Name << endl;
		cout << "����: " << PT[i].Kor << endl;
		cout << "����: " << PT[i].Eng << endl;
		cout << "����: " << PT[i].Math << endl;

	}

	fstream fp;
	fp.open("data.txt", ios::out);

	for (int i = 0; i < 3; i++)
	{
		fp << PT[i].Name<<endl;
		fp << PT[i].Kor << endl;
		fp << PT[i].Eng << endl;
		fp << PT[i].Math << endl;

	}

	fp.close();

	
}
