/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node
{
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K)
{
	if (head == NULL || K <= 0)
		return NULL;
	else
	{
		struct  node *node = NULL, *temp1 = NULL, *temp = NULL, *node1 = NULL;

		int i = 1, j = 0;
		j = j + K;
		temp = head;
		int count = 0;
		struct node* current = head;
		while (current != NULL)
		{
			count++;
			current = current->next;
		}
		while (j <= count)
		{
			if (i <j)
			{
				temp = temp->next;
			}
			else
			{
				node1 = (struct node*)malloc(sizeof(struct node*));
				node1->num = K;
				temp1 = temp->next;
				temp->next = node1;
				node1->next = temp1;
				temp = temp1;
				j = j + K;
			}
			i++;
		}
		return head;
	}
}
