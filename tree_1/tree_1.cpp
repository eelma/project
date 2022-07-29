#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include < stdlib.h >
using namespace std;
class Node
{
public:
	int Data;
	int depth;
	Node* Child[2];
	Node* Parent;

public:
	Node() :Data(-1), depth(0)
	{
		for (int i = 0; i < 2; i++)
		{
			Child[i] = nullptr;
		}
		Parent = nullptr;
	}
	~Node()
	{

	}
};


void BinaryCreate(Node* node,int val)
{

	if(node->Data<=val)
	{
		if(node->Child[0]==nullptr)
		{
		node->Child[0] = new Node;
		node->Child[0]->Data = val;
		node->Child[0]->depth = node->depth + 1;
		node->Child[0]->Parent = node;
		}
		else
		{
			BinaryCreate(node->Child[0],val);
		}
	}
	else
	{
		if(node->Child[1]==nullptr)
		{
		node->Child[1] = new Node;
		node->Child[1]->Data = val;
		node->Child[1]->depth = node->depth + 1;
		node->Child[1]->Parent = node;
		}
		else
		{
			BinaryCreate(node->Child[1], val);
		}
	}
}


Node* BinarySearchTree(Node*node,int q)
{
	if (node == nullptr) { return nullptr; }
	if (node->Data == q) { return node; }
	if (node->Data > q)
		BinarySearchTree(node->Child[1],q);
	else
		BinarySearchTree(node->Child[0],q);
	
}
void Find(Node* node)
{
	if (node == nullptr)
	{
		cout << "없는 값입니다" << endl;
	}
	else
	{
		cout <<"값은 "<< node->Data << endl;
	}
}
void ShowLevelOrder(Node*node)
{



}

int main(void)
{
	int arr[] = { 55,75,65,71,68,65,24,2,4 ,123,24,35,36};
	Node* node = new Node;
	for (int i = 1; i < _countof(arr); i++)
	{
		BinaryCreate(node, arr[i]);
	}
	Find( BinarySearchTree(node, 71));
	return 0;
}