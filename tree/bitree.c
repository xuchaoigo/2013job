#include <stdio.h>
#include <malloc.h> 
#define NODE_NUM  7

typedef struct node
{
	struct node * l_child;
	struct node * r_child;
	int value;
}node;

node * create_binary_tree()
{
	node * head;
	int i;
	head = (node *)malloc(NODE_NUM * sizeof(node));
	if(head == NULL)
		printf("malloc failed.\n");

	for(i = 0; i < NODE_NUM ; i++)
	{
		(head+i)->value = i;

		switch (i+1)
		{
			case 1:
				head->l_child = head+1;
				head->r_child = head+2;
				break;
			case 2:
				(head+i)->l_child = head+3;
				(head+i)->r_child = head+4;
				break;
			case 3:
				(head+i)->l_child = head+5;
				(head+i)->r_child = head+6;
				break;
			default:
				(head+i)->l_child = NULL;
				(head+i)->l_child = NULL;
				break;
		}
	}
	return head;
}

int lnr(node * head)
{
	if(head->l_child != NULL)
	{
		lnr(head->l_child);
	}
		printf("visit node %d.\n",head->value);
	
		if(head->l_child)
			printf("l:%d\n",head->l_child->value);
		else
			printf("l:NULL\n");
	
		if(head->r_child)
			printf("r:%d\n", head->r_child->value);
		else
			printf("r:NULL\n");
	if(head->r_child != NULL)
	{
		lnr(head->r_child);
	}
	return 0;
}


int nlr(node * head)
{
	
	printf("visit node %d.\n",head->value);
	if(head->l_child != NULL)
	{
		nlr(head->l_child);
	}
	
	if(head->r_child != NULL)
	{
		nlr(head->r_child);
	}
	return 0;
}


int main(void)
{
	node * bitree;
	int i;
	bitree = create_binary_tree();
	for(i = 0; i < NODE_NUM; i++)
		printf("value:%d\t",(bitree+i)->value);
	printf("\n");

/*	printf("0->%d,%d\n",bitree->l_child->value,bitree->r_child->value);*/
	
	printf("lnr:\n");
	lnr(bitree);
	printf("nlr:\n");
	nlr(bitree);
	
	return 0;
}

