/*#include<iostream>
using namespace std;

class List
{
public:
	List* Next;
	int a;
};

class Node
{

private:
	int _count;
	List* Head;
	List* Tail;
	List* _Temp;
public:
	void LInit();
	void LPrintAll();
	void LInsert();
	void LDelete();

};

void Node::LInit()
{
	Head = new List;
	Tail = new List;
	memset(Head, 0, sizeof(List));
	memset(Tail, 0, sizeof(List));

	Head->Next = Tail;

	_Temp = Head;
	_count = 0;
}
void Node::LInsert()
{
	int i;
	List* list = new List;
	cout << "숫자를 입력하세요:" << endl;
	cin >> i;
	list->a = i;

	List* next = Head->Next;

	_Temp->Next = list;
	list->Next = next;

	_count++;

}
void Node::LDelete()
{
	List* nl = Head->Next->Next;
	free(Head->Next);
	Head->Next = nl;

	_count--;
}

void Node::LPrintAll()
{
	List*temp = Head->Next;
	if (temp == NULL)
	{
		cout << "목록이 없습니다" << endl;
		return;
	}cout << endl;
	for ( ; temp->Next != NULL ; temp = temp->Next)
	{

		cout << temp->a << endl;

	}

	cout <<"총 개수: " << _count << endl;
}

int main(void)
{
	Node* node = new Node;
	node->LInit();
	node->LInsert();
	node->LInsert();
	node->LInsert();
	node->LInsert();
	node->LInsert();
	node->LDelete();
	node->LPrintAll();

}*/