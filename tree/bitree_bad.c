#include <stdio.h>

#define NODE_NUM  7

typedef struct node
{
	struct node * l_child;
	struct node * r_child;
	int value;
}node;

node * create_binary_tree()
{
	node (* head)[NODE_NUM];  // array of pointers
 	int i;
	head[0] = (node *)malloc(NODE_NUM * sizeof(node));
	if(head[0] == NULL)
		printf("malloc failed.\n");

	for(i = 0; i < NODE_NUM ; i++)
	{
		head[i]->value = i;

		switch (i+1)
		{
			case 1:
				head[i]->l_child = head[1];
				head[i]->r_child = head[2];
			case 2:
				head[i]->l_child = head[3];
				head[i]->r_child = head[4];
			case 3:
				head[i]->l_child = head[5];
				head[i]->r_child = head[6];
			default:
				head[i]->l_child = NULL;
				head[i]->l_child = NULL;
		}
	}
	return head[0];
}

int mid(node * head)
{
	if(head->l_child != NULL)
	mid(head->l_child);
	
	printf("visit node %d.\n",head->value);
	
	mid(head->r_child);
	return 0;
}


int main(void)
{
	node (* bitree)[NODE_NUM];
	int i;
	bitree[0] = create_binary_tree();
	for(i = 0; i < NODE_NUM; i++)
		printf("value:%d\t",bitree[i]->value);
	printf("\n");

	printf("0->%d,%d\n",bitree[0]->l_child->value,bitree[0]->r_child->value);
	
	return 0;
}







