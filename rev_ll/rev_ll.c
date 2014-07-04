#include <stdio.h>
#include <malloc.h>


typedef struct node
{
	int value;
	struct node * pNext;
}node;

void  add_node(node ** pHead, int value)
{
	node * pNew = (node *)malloc(sizeof(node));
	pNew->pNext = NULL;
	pNew->value = value;

	if(!(*pHead))
	{
		*pHead = pNew;	
	}
	else
	{
		node * pCur = *pHead;
		while(pCur->pNext)
		{
			pCur = pCur->pNext;
		}
		pCur->pNext = pNew;	
	}
	return ;
}

node * rev_ll(node * pHead)
{
	node * pPrev, *pCur, *pNex,* pNewhead;

	pPrev = NULL;
	pCur = pHead;
	pNex = pCur->pNext;
	pHead->pNext = NULL; // the sequence!!!!

	while( pNex->pNext)
	{
		pPrev = pCur;
		pCur = pNex;
		pNex = pCur->pNext;
		
		pCur->pNext = pPrev;
	}
	pNex->pNext = pCur;

	pNewhead = pNex;

	/*
	if(!pHead->pNext)
		return pHead;

	pPrev = NULL;
	pCur = pHead;
	pNex = pCur->pNext;
	pHead->pNext = NULL; // the sequence!!!!
	
	while(pNex->pNext)
	{
		printf("pcur=%d\n",pCur->value);

		pPrev = pCur;
		pCur = pNex;
		pNex = pNex -> pNext;
		pCur->pNext = pPrev;
	}
	pNex->pNext = pCur;
	pNewhead = pNex;

*/

	return pNewhead;
}



void printll(node * pHead)
{
	node * pCur = pHead;
	while(pCur)
	{
		printf("%d  ", pCur->value);
		pCur = pCur->pNext;
	}
	printf("\nend\n");
}


int main(void)
{
	node * pHead = NULL;
	add_node(&pHead, 2);
	add_node(&pHead, 4);
	add_node(&pHead, 5);
	add_node(&pHead, 7);

	printll(pHead);

	pHead = rev_ll(pHead);
	printll(pHead);
	return 0;
}
