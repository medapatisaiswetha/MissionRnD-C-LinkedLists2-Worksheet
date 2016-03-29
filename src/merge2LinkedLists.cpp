/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node
{
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2)
{
	if (head1 == NULL && head2 == NULL)
		return NULL;
	else if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	else
	{
		struct node *curr = NULL, *node = NULL, *temp1 = NULL, *temp = NULL, *prev = NULL;
		int k = 0;
		if (head1->num <= head2->num)
		{
			node = head1; curr = head2;
			k = 1;
		}
		else if (head1->num >= head2->num)
		{
			node = head2; curr = head1;
			k = 0;
		}
		while (node != NULL && curr != NULL)
		{
			if (node->num <= curr->num)
			{
				prev = node;
				node = node->next;
			}
			else
			{
				prev->next = curr;
				temp = curr->next;
				prev = curr;
				prev->next = node;
				curr = temp;
			}
		}
		if (curr != NULL)
		{
			prev->next = curr;
		}
		if (k == 1)
			return head1;
		else if (k == 0)
			return head2;
	}
}