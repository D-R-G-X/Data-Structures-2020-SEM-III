#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include <stdlib.h>

struct stack{
	int data;
	struct stack *next;
};
struct stack *top = NULL;
struct stack *push(struct stack *top, int num){
	struct stack *new_node;
	new_node = (struct stack *)malloc(sizeof(struct stack));
	new_node -> data = num;

	if (top == NULL)
	{
		new_node -> next = NULL;
		top = new_node;
	}
	else{
		new_node -> next = top;
		top = new_node;
	}
	return top;
}

struct stack *pop(struct stack *top){
	struct stack *ptr;
	ptr = top;
	if (top == NULL)
	{
		printf("\n Underflow");
	}
	else{
		top = top -> next;
		free(ptr);
	}
	return top;
}

struct stack *display(struct stack *top){
	struct stack *ptr;
	ptr = top;
	if(top == NULL){
		printf("\nStack Empty");
	}
	else{printf("\n");
		while(ptr != NULL){
			printf("%d\t",ptr -> data);
			ptr = ptr -> next;
		}
	}
	return top;
}
int peek(struct stack *top){
	if (top == NULL){
		return NULL;
	}
	else{
		return top -> data;
	}
}


int main(){
	int val, option;
	do{
		printf("\n\n *****MAIN MENU *****");
		printf("\n 1: Push");
		printf("\n 2: Pop");
		printf("\n 3: Peek");
		printf("\n 4: Display");
		printf("\n 5: EXIT");
		printf("\n Enter your option:  ");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("\n Enter the number to be pushed on stack: ");
				scanf("%d", &val);
				top = push(top, val);
				break;
 			case 2:
 				top = pop(top);
 				break;
 			case 3:
 				val = peek(top);
 				if (val != -1){
 				printf("\n The value at the top of stack is: %d", val);
 				}
 				else{
 				printf("\n STACK IS EMPTY");
 				}
 				break;
			case 4:
				top = display(top);
				break;
		}
	}while(option != 5);

	return 0;
}
