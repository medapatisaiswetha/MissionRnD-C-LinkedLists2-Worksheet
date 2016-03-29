/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head)
{
	if (head == NULL)
		return -1;
	else
	{
		int count = 0;
		struct node* current = head;
		struct  node *first = head, *middle = head, *last = head;
		while (current != NULL)
		{
			count++;
			current = current->next;
		}
		if ((count % 2) != 0)
		{
			if (head != NULL)
			{
				while (last->next != NULL)
				{
					last = last->next->next;
					first = first->next;
				}
			}
			return first->num;
		}

		if ((count % 2) == 0)
		{
			if (head != NULL)
			{
				while (last != NULL)
				{
					last = last->next->next;
					middle = first;
					first = first->next;
				}
			}
			return ((middle->num) + (first->num)) / 2;
		}
	}
}
