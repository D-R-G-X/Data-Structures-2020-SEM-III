#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
};

struct node *start = NULL;
struct node *create_cll(struct node *start){
	struct node *new_node,*ptr;
	int num;
	printf("\nEnter -1 to end\nEnter data: ");
	scanf("%d",&num);

	while(num != -1){
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node -> data = num;
		if (start == NULL){
			new_node -> next = new_node;
			start = new_node;
		}
		else{
			ptr = start;
			while(ptr -> next != start){
				ptr = ptr -> next;
			}
			ptr -> next = new_node;
			new_node -> next = start;
		}
		printf("\nEnter the data: ");
		scanf("%d",&num);
	}
	return start;
}

struct node *display(struct node *start){
	struct node *ptr;
	ptr = start;
	printf("\n");
	while(ptr -> next != start){
		printf("%d   ->", ptr -> data);
		ptr = ptr -> next;
	}
	printf("START");
	return start;
}

struct node *insert_beg(struct node* start){
	struct node *new_node,*ptr;
	int num;
	printf("\nEnter Data:");
	scanf("%d",&num);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	ptr = start;
	while(ptr -> next != start){
		ptr = ptr -> next;
	}
	ptr -> next = new_node;
	new_node -> next = start;
	start = new_node;

	return start; 
}

struct node *insert_end(struct node *start){
	struct node *new_node,*ptr;
	int num;
	printf("\nEnter data: ");
	scanf("%d",&num);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	ptr = start;
	while(ptr -> next != start){
		ptr = ptr -> next;
	}
	ptr -> next = new_node;
	new_node -> next = start;

	return start;
}

struct node *insert_before(struct node *start){
	struct node *ptr, *new_node, *preptr;
	int num,val;
	printf("\nEnter Data: ");
	scanf("%d",&num);
	printf("\nEnter the Value before which the data is to be inserted: ");
	scanf("%d",&val);
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node -> data = num;

	ptr = start;

	while(ptr -> data != val){
		preptr = ptr;
		ptr = ptr ->next;
	}
	preptr -> next = new_node;
	new_node -> next = ptr;

	return start;
}

struct node *insert_after(struct node *start){
	struct node *ptr, *new_node, *preptr;
	int num,val;
	printf("\nEnter Data: ");
	scanf("%d",&num);
	printf("\nEnter the Value after which the data is to be inserted: ");
	scanf("%d",&val);
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node -> data = num;

	ptr = start;

	while( preptr -> data != val){
		preptr = ptr;
		ptr = ptr -> next;
	}
	preptr -> next = new_node;
	new_node -> next = ptr;

	return start;
}

struct node *delete_beg(struct node *start){
	struct node *ptr;
	ptr = start;
	while(ptr -> next != start){
		ptr = ptr -> next;
	}
	ptr -> next = start -> next;
	free(start);
	start = ptr -> next;

	return start;
}

struct node *delete_end(struct node *start){
	struct node *ptr,*preptr;
	ptr = start;
	preptr = ptr;
	while( ptr -> next != start){
		preptr = ptr;
		ptr = ptr -> next;
	}
	preptr -> next = ptr -> next;
	free(ptr);

	return start;
}

struct node *delete_after(struct node *start){
	struct node *ptr, *preptr,*temp;
	int num;
	printf("\nEnter the data: ");
	scanf("%i",&num);
	ptr = start;
	preptr = ptr;
	while(preptr -> data != num){
		preptr = ptr;
		ptr = ptr -> next;
	}
	preptr -> next = ptr -> next;
	if( ptr == start){
		start = preptr -> next;
	}
	free(ptr);
}

struct node *delete_before(struct node *start){
	struct node *ptr,*preptr,*pre_preptr;
	int num;
	printf("\nEnter the data: ");
	scanf("%i",&num);
	ptr = start;
	preptr = ptr;
	while(ptr -> data != num){
		pre_preptr = preptr;
		preptr = ptr;
		ptr = ptr -> next;
	}
	pre_preptr -> next = ptr;
	free(preptr);
	return start;
}

struct node *delete_node(struct node *start){
	struct node *ptr, *preptr;
	int num;
	printf("\nEnter the data: ");
	scanf("%i",&num);
	ptr = start;
	preptr = ptr;
	while(ptr -> data != num){
		preptr = ptr;
		ptr = ptr -> next;
	}
	preptr -> next = ptr -> next;
	free(ptr);
	return start;
}

struct node *delete_list(struct node *start){
	struct node *ptr;
	if(start != NULL){
		ptr = start;
		while(ptr -> next != start){
			printf("\n %d is to be deleted next", ptr -> data);
			start = delete_end(ptr);
			ptr =start;
		}
	}
	free(start);
	printf("\nLinked list deleted");
	return start;
}

struct node *search_node(struct node *start){
	struct node *ptr;
	int num, count =0;
	printf("\nEnter the data: ");
	scanf("%i",&num);
	ptr =start;
	while(ptr -> data != num){
		count++;
		ptr = ptr -> next;
	}
	printf("\nValue is present at %d position", count+1);
	return start;
}


int main(){
	int option;
	do{
		printf("\n\n *****MAIN MENU *****");
	 	printf("\n 1: Create a circular linked list");
	 	printf("\n 2: Display the list");
	 	printf("\n 3: Add a node at the beginning");
	 	printf("\n 4: Add a node at the end");
	 	printf("\n 5: Add a node before a given node");
	 	printf("\n 6: Add a node after a given node");
	 	printf("\n 7: Delete a node from the beginning");
		printf("\n 8: Delete a node from the end");
		printf("\n 9: Delete a given node");
		printf("\n 10: Delete a node after a given node");
		printf("\n 11: Delete a node before a given node");
		printf("\n 12: Delete the entire list");
		printf("\n 13: Search an element");
		printf("\n 14: EXIT");
		printf("\n\n Enter your option : ");
		scanf("%d", &option);

		switch(option){
			case 1: start = create_cll(start);
					printf("\n Circular Linked list Created");
					break;
			case 2: start = display(start);
					break;
			case 3: start = insert_beg(start);
					break;
			case 4: start = insert_end(start);
					break;
			case 5: start = insert_before(start);
					break;
			case 6: start = insert_after(start);
					break;
			case 7: start = delete_beg(start);
					break;
			case 8: start = delete_end(start);
					break;
			case 9: start = delete_node(start);
					break;
			case 10: start = delete_after(start);
					break;
			case 11: start = delete_before(start);
					break;
			case 12: start = delete_list(start);
					break;
			case 13: start = search_node(start);
					break;
		}
	}while(option != 14);
	getch();
	return 0;
}
