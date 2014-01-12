#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};
void InsertLinkedList(struct Node **head, int data, int position)
{
	int k = 1;
	struct Node *p, *q, *newNode;
	if(!newNode)
	{
		printf ("memory error");
	}
	newNode -> data = data;
	p = *head;
	if(position ==1) // insert at the beginning
	{
		newNode ->next = p; //point to old head
		*head = newNode;
	}
	else
	{
		while((p != NULL) && ( k < position-1))
		{
			k++;
			q = p;
			p = p -> next;
		}
		if(p==NULL) // insert at the end
		{
			q -> next = newNode;
			newNode -> next = NULL;
		}
		else // insert in the middle
		{
			q -> next = newNode;
			newNode -> next = p;
		}
	}
}
/** 
 * find the length of linkedlist
*/
int ListLength(struct Node *head)
{
		struct Node *current = head;
		int count = 0;
		while(current != NULL)
		{
			current = current -> next;
		}
		return count;
}
/**
 *  delete a node at position 
*/
void DeleteNode(struct Node **head, int position)
{
	int k = 1;
	struct Node *p, *q;
	if(*head = NULL)
	{
		cout << "empty list";
		return;
	}
	p = *head;
	if(position ==1)
	{
		p = *head;
		*head = p -> next;
		return;
	}
	else
	{
		while((p!=NULL) && (k < position -1))
		{
			k++;
			q = p;
			p = p -> next;	
		}
		if(p == NULL) // delete the last node
		{
			cout << "position does not exist";
			return;
		}
		else
		{
			q -> next = p -> next;
			return;
		}
	}
}

struct Node* reverse(struct Node** head)
{
	Node *parent = *head;
	Node *me = parent -> next;
	
}
/* main test 
*/
int main()
{
	struct Node *head;
	head->data = 0;
	head->next = NULL;
	InsertLinkedList(head,10,1);
	
	return 0;
}
