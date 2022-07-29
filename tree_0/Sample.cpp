#include "Sample.h"
#include<iostream>
using namespace std;
class Node
{
public:
	int index;
	int depth;
	Node* Child[2];
	Node* Parent;

public:
	Node() :index(-1), depth(0)
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

Node* MNode = nullptr;
int Counter = 0;
int MaxDepth = 2;


Node* CreateNode(Node*par)
{
	Node* newnode = new Node();
	newnode->index = Counter++;
	if(par!=nullptr)
	{
	newnode->depth = par->depth+1;
	newnode->Parent = par;
	}

	return newnode;

}


void Build(Node*par)
{
	if (par->depth >= MaxDepth) { return; }


	par->Child[0] = CreateNode(par);
	par->Child[1] = CreateNode(par);

	Build(par->Child[0]);
	Build(par->Child[1]);

}

void Print(Node*par)
{
	if (par == nullptr) { return; }
	

	Print(par->Child[0]);
	cout << " " << par->index;

	Print(par->Child[1]);
	
	
}

void deleteAll(Node*par)
{
	if (par == nullptr) { return; }

	deleteAll(par->Child[0]);
	deleteAll(par->Child[1]);

	delete par;
	par = nullptr;

}


int main(void)
{
	MNode = CreateNode(nullptr);
	Build(MNode);
	Print(MNode);
	deleteAll(MNode);

	return 0;
}