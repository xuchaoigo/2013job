#include <stdio.h>
#include <malloc.h> 
#define NODE_NUM  7

typedef struct node
{
	struct node * l_child;
	struct node * r_child;
	int value;
}node;

void add_node(node ** pcurrent, int value) 
{

	if(NULL == *pcurrent)
	{
		node * pnewnode = (node *)malloc(sizeof(node));
		pnewnode->l_child = NULL;
		pnewnode->r_child = NULL;
		pnewnode->value = value;
		*pcurrent = pnewnode;
	}
	else if(value <=  (*pcurrent)->value)
	{
		if((*pcurrent)->l_child != NULL)
		{
			add_node(&((*pcurrent)->l_child), value);
		}
		else
		{
			node * pnewnode = (node *)malloc(sizeof(node));
			pnewnode->l_child = NULL;
			pnewnode->r_child = NULL;
			pnewnode->value = value;

			(*pcurrent)->l_child = pnewnode;
		}
		return;
	}
	else if(value > (*pcurrent)->value)
	{
		if((*pcurrent)->r_child != NULL)
		{
			add_node(&((*pcurrent)->r_child), value);
		}
		else
		{
			node * pnewnode = (node *)malloc(sizeof(node));
			pnewnode->l_child = NULL;
			pnewnode->r_child = NULL;
			pnewnode->value = value;

			(*pcurrent)->r_child = pnewnode;
		}
		return;
	}

}

/*
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
*/
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
	
	add_node(&root, 7);
	add_node(&root, 3);
	add_node(&root, 9);
	add_node(&root, 8);
	add_node(&root, 4);
	add_node(&root, 5);
	add_node(&root, 1);
	add_node(&root, 10);

	printf("lnr:\n");
	lnr(root);
	printf("nlr:\n");
	nlr(root);
	
	return 0;
}

