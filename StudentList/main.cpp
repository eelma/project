#define _CRT_SECURE_NO_WARNINGS
#include"List.h"

int main(void)
{

	Node* node = new Node;
	node->SInit();

	node->NewStudent();
	node->NewStudent();
	node->SDelete();
	node->SAllPrint();

	return 0;

}
