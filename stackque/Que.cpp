//#include<iostream>
//#define MAX 10
//int arr[MAX];
//int front, rear;
//using namespace std;
//void Init()
//{
//
//	front = 0;
//	rear = 0;
//
//}
//void put()
//{
//	int a;//10 20 30 40 50 60 70 80 90 00(9/0) pop하면 0 삭제(0-8) 1-9까지  
//	cout << endl;
//	if ((rear + 1) % MAX == front)
//	{
//		cout << "오버 플로우" << endl;
//		return;
//	}
//	cin >> a;
//	arr[rear] = a;
//	rear =++rear %MAX;
//
//
//}
//void pop()
//{
//	cout << endl;
//	if (front==rear)
//	{
//		cout << "언더플로우" << endl;
//	}
//	front=++front%MAX;
//
//
//}
//void clearQue()
//{
//	
//	Init();
//
//}
//void printAll()
//{
//
//	cout << endl;
//	for (int i = front ; i != rear; ++i=i%MAX)
//	{
//		cout << arr[i] << endl;
//	}
//
//
//}
//
//
//int main(void)
//{
//	int val;
//		Init();
//		do {
//	
//			cout << "1. put\t2. pop\t3. print\t4. clear\t0,exit" << endl << endl;
//		cin >> val;
//	
//		switch (val)
//		{
//		case 1:
//			put();;
//	
//			break;
//		case 2:
//			pop();
//			break;
//		case 3:
//			printAll();
//			break;
//		case 4:
//			clearQue();
//			break;
//
//		case 0:
//			return 0;
//		}
//	
//		} while (1);
//		
//		return 0;
//}