/*
 * Program to implement stack using linked list.
 *
 * Compilation: gcc -o stack stack.c
 * Execution:./stack
 *
 * @Aniket , (1910990836) , 22/07/2021
 * Assignment 6-Linked_List
 */

#include<stdio.h>
#include<stdlib.h>

//declare linked list node
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

//function to check list is empty or not
int is_empty()
{
    if( head == NULL )
	return 1;
    else
	return 0;
}

// function to insert an element in stack
void push(int item)
{
    //creating new node
    struct node *new_node = malloc(sizeof(struct node));
    
    //checking if memory is allocated or not
    if(new_node == NULL)
    {
        printf("Memory not allocated!!\n");
	exit(1);
    }
    
    new_node -> data = item;
    
    //linking head and new node
    new_node -> next = head;

    // making new node as head
    head = new_node;
}

// function to delete element from top of the stack
void pop()
{
    struct node *temp;
    if(is_empty())
	printf("Stack Empty!!\n");
    else
    {
        printf("Popped Element : %d\n", head -> data);
        
        temp = head;

	//assign second node to top
	head = head -> next;

	//break link between first and second node
	temp -> next = NULL;

	// free popped node's memory
	free(temp);
	
    }
}

// function to return topmost element in the stack
void peek()
{
    if(head == NULL)
	printf("NULL\n");
    else
	printf("%d\n",head -> data);
}

//function to print the elements in stack
void display()
{
    struct node *temp = head;

    while(temp != NULL)
    {
        printf("%d->",temp -> data);
	temp = temp -> next;
    }
    printf("NULL\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    peek();
    display();
    pop();
    pop();
    display();
    pop();
    display();
    peek();
    pop();
}
