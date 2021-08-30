/*
 * Program to implement deque using linked list.
 *
 * Compilation: gcc -o deque deque.c
 * Execution:./deque
 *
 * @Aniket , (1910990836) , 22/07/2021
 * Assignment 6-Linked_List
 */ 

#include<stdlib.h>
#include<stdio.h>

// declare node
struct list{
    int data;
    struct list* next;
}*ptr = NULL, *temp = NULL, *rear = NULL, *front = NULL;

// function to make a new node
struct list* NewNode()
{
    struct list* node;
    node = (struct list*)malloc(sizeof(struct list));
    node -> data = 0;
    node -> next = NULL;
    if(node != NULL)
        return node;
    else
    {
	printf("\nStack Overflow");
	exit(1);
    }
}
	
// function to delete element from front
int delete_front()  
{
    int item;
    if(front == NULL)
    {
	printf("\nQueue Underflow");
	exit(1);
    }
    temp = front;
    item = temp -> data;
    front = front -> next;
    free(temp);
    return item;
}
	
// function to insert element at front
void insert_front(int item)  
{
    struct list* node = NewNode();
    node -> data = item;
    if(front == NULL)
    {
	front = node;
	rear = node;
		
    }
    else
    {
	rear -> next = node;
	rear = node;
    }
}
	
// function to delete element from last
int delete_last()     
{
    struct list* temp;
    ptr = front;
    if(front == rear)
    {
        free(front);
    	front = NULL;
 	rear = NULL;
    }
    while(ptr -> next != rear)
    {
	ptr = ptr-> next;
    }
    temp = rear;
    rear = ptr;
    ptr->next=NULL;
    free(temp);
}
	
// function to insert element at last
void insert_last(int item)
{
    struct list* node = NewNode();
    node -> data = item;
    if(front==NULL)
    {
        front = node;
	rear = node;
	return;
    }
    node -> next = front;
    front = node;
}
	
// function to print deque
void print()
{
    if(front == NULL)
    {
        printf("\nQueue is empty\n");
	return;
    }
    ptr = front;
    printf("\n\nPrinting Deque\n\n");
    while(ptr)
    {
	printf("%d->",ptr -> data);
	ptr = ptr -> next;
    }
    printf("NULL\n");
}

int main()
{
    insert_front(10);
    insert_front(20);
    insert_front(30);
    print();
    delete_front();
    print();
    insert_last(40);
    insert_last(50);
    delete_last();
    print();
}
