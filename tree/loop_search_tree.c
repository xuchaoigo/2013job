#include <stdio.h>
#include <malloc.h> 
#define NODE_NUM  7

typedef struct node
{
	struct node * l_child;
	struct node * r_child;
	int value;
}node;

node * add_node(node * pcurrent, int value) 
{
	node * pnewnode = (node *)malloc(sizeof(node));
	pnewnode->l_child = NULL;
	pnewnode->r_child = NULL;
	pnewnode->value = value;

	if(NULL == pcurrent)
	{
		return pnewnode;
	}

	while(1)
	{
		if(value <=  pcurrent->value)
		{
			if(pcurrent->l_child != NULL)
			{
				pcurrent = pcurrent->l_child;
				continue;
			}
			else
			{
				pcurrent->l_child = pnewnode;
				return NULL;
			}
		}
		else if(value > pcurrent->value)
		{
			if(pcurrent->r_child != NULL)
			{
				pcurrent = pcurrent->r_child;
				continue;
			}
			else
			{
				pcurrent->r_child = pnewnode;
				return NULL;
			}
		}
	}
}

int lnr(node * head)
{
	if(head->l_child != NULL)
	{
		lnr(head->l_child);
	}
		printf("\nvisit node %d.\n",head->value);
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
	node * root= NULL;
	
	root = add_node(NULL,7 );
	add_node(root, 3);
	add_node(root, 9);
	add_node(root, 8);
	add_node(root, 4);
	add_node(root, 5);

	printf("lnr:\n");
	lnr(root);
	printf("nlr:\n");
	nlr(root);
	
	return 0;
}

