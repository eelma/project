#define _CRT_SECURE_NO_WARNINGS
#include"List.h"

int main(void)
{
	
	Node* node=new Node;
	node->SInit();
	
	node->NewStudent();
	node->SDelete();
	node->Print();

	return 0;

}
