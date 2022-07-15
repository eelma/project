//#include<iostream>
//using namespace std;
//
//#define MaX  10
//int arr[MaX];
//int Top;
//
//void Init()
//{
//
//	Top = -1;
//
//}
//
//void pop()
//{
//	if (Top <= 0)
//	{
//		cout << "언더플로우" << endl;
//		Top--;
//		return;
//	}
//
//	Top--;
//
//}
//
//void Push()
//{
//	int A;
//	if (Top >= MaX - 1)
//	{
//		cout << "오버플로우" << endl;
//		return;
//	}
//
//	cout << "1-9까지 원하는 숫자 입력" << endl;
//	cin >> A;
//	
//	arr[++Top] = A;
//	
//}
//void PrintAll()
//{
//	for (int i = Top; i >= 0; i--)
//	{
//		cout << arr[i] << endl;
//	}
//}
//
//int main(void)
//{
//	int val;
//	Init();
//	do {
//
//		cout << "1. push 2. pop 3. print    0,exit" << endl;
//	cin >> val;
//
//	switch (val)
//	{
//	case 1:
//		Push();;
//
//		break;
//	case 2:
//		pop();
//		break;
//	case 3:
//		PrintAll();
//		break;
//	case 0:
//		return 0;
//	}
//
//	} while (1);
//	
//	return 0;
//
//}