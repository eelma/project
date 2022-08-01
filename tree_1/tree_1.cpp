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
	if (node->Data >= val)
	{	if(node->Child[0]==nullptr)
		{
		node->Child[0] = new Node;
		node->Child[0]->Data = val;
		node->Child[0]->depth = node->depth + 1;
		node->Child[0]->Parent = node;
		}
		else
		{
			BinaryCreate(node->Child[0], val);
		}
	}
	if (node->Data < val)
	{
		if (node->Child[1] == nullptr)
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
	if (node == nullptr) return nullptr;
	if (node->Data == q)
		return node;
	if (node->Data >= q)
	{
		BinarySearchTree(node->Child[0], q);
	}
	else
	{
		BinarySearchTree(node->Child[1], q);
	}
	
}
void Find(Node* node)
{
	
}
void ShowLevelOrder(Node*node)
{
	if (node == nullptr)return;
	cout << node->Data << endl;
	ShowLevelOrder(node->Child[0]);
	ShowLevelOrder(node->Child[1]);
	

}

int main(void)
{
	int arr[] = { 55,75,65,71,68,65,24,2,4};
	Node* node = new Node;
	node->Data = 55;
	for (int i = 1; i < _countof(arr); i++)
	{
		BinaryCreate(node, arr[i]);
	}
	ShowLevelOrder(node);
	return 0;
}