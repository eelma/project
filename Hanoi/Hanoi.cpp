#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int i = 0;
void Hanoi(int t, char a, char b, char c)
{
	
	if (t > 0)
	{

	Hanoi(t - 1, a, c, b);
	cout << t<<"��°"<<a << "��" << b << "�� �̵�" << endl;
	Hanoi(t-1, b, a, c);

	}
}



int main(void)
{
	Hanoi(3, 'A', 'B', 'C');

	return 0;
}