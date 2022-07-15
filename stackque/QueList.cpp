//#include<iostream>
//
//using namespace std;
//
//class List
//{
//public:
//	int a;
//	List* Prev;
//	List* Next;
//
//};
//
//class Node
//{
//
//private:
//	int _count;
//	List* Head;
//	List* Tail;
//	List* _Temp;
//
//public:
//	void LInit();
//	void LPrintAll();
//	void LInsert();
//	void LDelete();
//
//};
//
//void Node::LInit()
//{
//
//	Head = new List;
//	Tail = new List;
//
//	memset(Head,0,sizeof(List));
//	memset(Tail, 0, sizeof(List));
//
//	Head->Next = Tail;
//
//	Tail->Prev = Head;
//
//	_Temp = Head;
//	_count = 0;
//}
//
//void Node::LInsert()
//{
//	int i;
//	List* lt = new List;
//	cout << "숫자를 입력" << endl;
//	cin >> i;
//	lt->a = i;
//
//	List* prv = Tail->Prev;
//	
//	Tail->Prev = lt;
//	lt->Prev = prv;
//
//	prv->Next = lt;
//	lt->Next = Tail;
//	
//	_count++;
//
//}
//void Node::LDelete()
//{
//	List* nl = Head->Next;
//	List* nl2 = Head->Next->Next;
//	
//	free(nl);
//
//	Head->Next = nl2;
//	nl2->Prev = Head;
//
//	_count--;
//}
//
//void Node::LPrintAll()
//{
//	List* temp = Head->Next;
//	if (temp == NULL)
//	{
//		cout << "목록이 없습니다" << endl;
//		return;
//	}cout << endl;
//	for (; temp->Next != NULL; temp = temp->Next)
//	{
//
//		cout << temp->a << endl;
//
//	}
//
//	cout << "총 개수: " << _count << endl;
//}
//
//int main(void)
//{
//
//	Node* node = new Node;
//	node->LInit();
//	node->LInsert();
//	node->LInsert();
//	node->LInsert();
//	node->LInsert();
//	node->LInsert();
//	node->LDelete();
//	node->LPrintAll();
//
//
//}