#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef struct linkedList
{
	int val;
	struct linkedList *next;
}node;

int main()
{
	node *_head = (node *)malloc(sizeof(node));
	for (int i = 1; i <= 3; i++) //链表长度为3
	{
		node *p1, *p2;
		p1 = (node *)malloc(sizeof(node));
		(*p1).val = i;
		if (i == 1)
		{
			_head = p2 = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
	}
	return 0;
}