/*
 * Program to implement queue using linked list.
 *
 * Compilation: gcc -o queue queue.c
 * Execution:./queue
 *
 * @Aniket , (1910990836) , 22/07/2021
 * Assignment 6-Linked_List
 */

#include<stdio.h>
#include<stdlib.h>

// declare linked list node
struct node {
    int data;
    struct node *next;
};

// intializing front and rear pointers
struct node *front = NULL;
struct node *rear = NULL;

// function to check queue is empty or not
int is_empty()
{
    if( front == NULL )
	return 1;
    else
	return 0;
}

// function to add element in queue
void enque(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    if(temp == NULL)
    {
        printf("OVERFLOW!!\n");
	exit(1);
    }
    else
    {
        temp -> data = item;
	// first insert
	if( front == NULL )
	{
            front = rear = temp ;
	    front -> next = NULL;
	    rear -> next = NULL;
	}
	else
	{
            rear -> next = temp;
	    rear = temp;
	    rear -> next = NULL;
	}
    }
}

// function to delete element from queue
void deque()
{
    struct node *p;
    if( is_empty() )
    {
        printf("UNDERFLOW");
	exit(1);
    }
    else
    {
        p = front;
	front = front -> next;
	free(p);
    }
}

void peek()
{
    if( front == NULL )
	printf("NULL\n");
    else
        printf("%d\n",rear -> data);
}

// function to print queue
void display()
{
    struct node *temp;
    temp = front;
    if( is_empty() )
	printf("Queue Empty!!\n");
    else
    {
        while(temp != NULL)
	{
            printf("%d->",temp -> data);
	    temp = temp -> next;
	}
	printf("NULL\n");
    }
}

int main()
{
    enque(10);
    enque(20);
    enque(30);
    peek();
    display();
    deque();
    deque();
    display();
    peek();
    deque();
    display();
    peek();
    deque();
}
