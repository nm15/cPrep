#include <stdio.h>
#include <Stdlib.h>
//Create linked list and reverse it

struct node
{
	int data;
	struct node *next;
};

void insertInLL(struct node **root, int data)
{
	struct node *head = (*root);
	struct node *new;
	new = (struct node *) malloc(sizeof(struct node));
	new -> data = data;
	new -> next = NULL;
	
	if(head == NULL)
	{
		*root = new;
		return;
	}
	else 
	{
		new -> next = head;
		*root = new;
		return;
	}
}

void printAll(struct node *root)
{
	if(root == NULL)
	return;
	
	while(root != NULL)
	{
		printf("%d ", root -> data);
		root = root -> next;
	}
	printf("\n \n");
	return;
}

void reverseLL(struct node **root)
{
	struct node *head = *root;
	struct node *prev = NULL,*temp = NULL;
	
	while(head != NULL)
	{
		prev = head -> next;
		head -> next = temp;
		temp = head;
		head = prev;
	}
	*root = temp; 
	return;
}

int main(int argc, char *argv[]) 
{
   struct node *root = NULL;
   for(int i = 0; i < 7; i++)
   insertInLL(&root, i);
   printAll(root);
   reverseLL(&root);
   printAll(root);
}