#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

struct node *insert(/*struct node *front,struct node *rear,*/ int val){
	struct node *new_node;
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = val;
	if(front == NULL){
		front = new_node;
		rear = new_node;
		front -> next = rear -> next = NULL;
	}
	else{
		rear -> next = new_node;
		rear = new_node;
		rear -> next = NULL;
	}
	//return ;
}

struct node *dequeue(/*struct node *front, struct node *rear*/){
	struct node *ptr;
	ptr = front;
	if(front == NULL){
		printf("\n Underflow");
	}
	else{
		front = front -> next;
		printf("\nThe value being deleted is: %d",ptr ->data);
		free(ptr);
	}
	//return 
}

struct node display(){
	struct node *ptr;
	ptr = front;
	if(ptr == NULL){
		printf("\n Queue is empty");
	}
	else{
		printf("\n");
		while(ptr != rear){
			printf("%d\t",ptr -> data);
			ptr = ptr -> next;
		}
		printf("%d\t",ptr -> data);
	}
}

int peek(){
	if(front == NULL){
		printf("\nQueue is empty");
		return -1;
	}
	else{
		return front -> data;
	}
}


int main(){
	int val, option;
	do{
		printf("\n\n *****MAIN MENU *****");
		printf("\n 1: Insert");
		printf("\n 2: Dequeue");
		printf("\n 3: Peek");
		printf("\n 4: Display");
		printf("\n 5: EXIT");
		printf("\n Enter your option:  ");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("\n Enter the number to be inserted in the queue: ");
				scanf("%d", &val);
				insert( val);
				break;
 			case 2:
 				dequeue();
 				break;
 			case 3:
 				val = peek();
 				if (val != -1){
 				printf("\n The value at the front of the queue is: %d", val);
 				}
 				break;
			case 4:
				display();
				break;
		}
	}while(option != 5);

	return 0;
}
