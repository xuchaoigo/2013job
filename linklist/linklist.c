#include <stdio.h>


struct Lnode
{
	int data;
	struct Lnode *next;
};
typedef struct Lnode Lnode;

Lnode * InitLinkList(void)
{
	Lnode *head= NULL;
	Lnode *a1, *a2; 
	a1  = (Lnode *) malloc(sizeof(Lnode));
	a2  = (Lnode *) malloc(sizeof(Lnode));

	head = a1;
	a1->data = 1;
	a1->next = a2;
	a2->data = 2;
	a2->next = NULL;

	return head;	
}

int PrintLinkList(Lnode *head)
{
	printf("\nPrintLinkList:\n");
	int i = 0;
	while(1)
	{
		printf("No.%d: %d\n",i+1, head->data);	
		i++;
		if(head->next != NULL)
			head = head->next;
		else break;
	}
}

int AddLinkList(Lnode *head,int node_value)
{
	printf("AddLinkList\n");
	Lnode *a; 
	a  = (Lnode *) malloc(sizeof(Lnode));

	/*move to the last*/
	while(head->next != NULL)
	{
		head = head->next;
	}
	head->next = a;

	a->data = node_value;
	a->next = NULL;
}

Lnode * DeleteLinkList(Lnode *head, int number)
{
	printf("DeleteLinkList No.%d\n",number);	
	int i;
	Lnode *newhead;
	newhead = head;

	if (number == 1)
	{
		newhead = head->next;
		free(head);
	}
	else
	{
		for(i=0; i<number-2; i++)  //move to the ahead one
			head = head->next;

		free(head->next);
		head->next = head->next->next;

	}

	return newhead;
}

Lnode *InsertLinkList(Lnode *head, int number, int value)
{
	printf("InsertLinkList No.%d, value %d\n",number,value);
	int i;
	Lnode *a, *newhead;
	newhead = head;

	a = (Lnode *)malloc(sizeof(Lnode));
	a->data = value;
	a->next = NULL;

	for(i=0; i<number-2; i++)
		head = head->next;

	a->next = head->next;
	head->next = a;

	return newhead;
}


int main(void)
{
	Lnode *head;
	head = InitLinkList();
	PrintLinkList(head);
	/*
	   int node_value = 666;
	   InsertLinkList(head, node_value);

	   node_value =777;
	   InsertLinkList(head, node_value);

	   PrintLinkList(head);
	 */
	int i;
	for(i=0; i<10; i++)
		AddLinkList(head, i+3);
	PrintLinkList(head);

	DeleteLinkList(head, 3);
	PrintLinkList(head);

	DeleteLinkList(head, 6);
	PrintLinkList(head);

	InsertLinkList(head, 3,3);
	PrintLinkList(head);
	InsertLinkList(head, 7,7);
	PrintLinkList(head);

	char cmd[256];
	sprintf(cmd, "pwd"); 
	system(cmd);


}
