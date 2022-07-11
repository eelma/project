#define _CRT_SECURE_NO_WARNINGS
#include"List.h"

int main(void)
{
	
	Node* node=new Node;
	node->SInit(node);
	node->NewStudent(node);
	node->NewStudent(node);
	node->Print(node);

	return 0;

}