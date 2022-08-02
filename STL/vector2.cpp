#include<iostream>
#include<vector>
using namespace std;
template<class T,class Q>
class Person
{
private:
	T name;
	Q age;
	
public:
	Person(T myname,Q myage):name(myname),age(myage)
	{

	}
	void ShowData()
	{
		cout << "�̸�: " << name<<endl;
		cout << "����: " << age << endl;
	}
	virtual ~Person()
	{

	}
};
template<class T, class Q>
class Worker :public Person<T, Q>
{
private:
	T job;
	Q care;

public:
	Worker(T myname,Q myage, T myjob, Q mycare):Person<T,Q>(myname,myage), job(myjob),care(mycare)
	{}

	void ShowWorker()
	{
		Person<T,Q>::ShowData();
	cout << "����: " << job << endl;
	cout << "���: " << care << endl;
	}

};

int main(void)
{

	vector<Person<string,int>*> per;
	per.push_back(new Person<string, int>("�̸�", 19));
	

	vector<Worker<string, int>*> wor;
	wor.push_back(new Worker<string, int>("�达", 30, "����", 5));
	
	wor[0]->ShowWorker();
	
	return 0;
}