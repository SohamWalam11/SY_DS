#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node* create_node(int data);
void create_list(struct node *temp);
void traverse_list(struct node *temp);
void insert_beginning(struct node *head, int data);
void insert_after_index(struct node *head, int data, int index);
void delete_at_beginning(struct node *head);
void delete_element(struct node *head, int element);

struct node{
	int data;
	struct node *nxt;
};

struct node *create_node(int data){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->nxt = NULL;
	return new_node;
};

void create_list(struct node *temp){
	int i;
	for(i=1;i<10;i++){
		struct node *new_node = create_node(i*10);

		temp->nxt = new_node;
		temp = new_node;
		}
		temp->nxt = NULL;
}

void traverse_list(struct node* temp){

	int i;

	if(temp->nxt == NULL){
		printf("List is empty!");
		return;
	};
//	for(i=0;i<10;i++){
//	while(temp->nxt != NULL){
	while(1){
		printf("%d->", temp->data);
		temp = temp->nxt;
		if(temp->nxt == NULL){
			return;
		};
	};
}

void insert_beginning(struct node *head, int data){

	struct node *new_node = create_node(data);
	new_node->nxt = head->nxt;
	head->nxt = new_node;
};

void insert_after_index(struct node *head, int data, int index){

	struct node * temp = head;
	struct node *new_node = create_node(data);

	//Traverse till index
	while(temp->data != index){
//	  printf("%d->",temp->data);
	  temp = temp->nxt;
	};

	new_node->nxt = temp->nxt;
	temp->nxt = new_node;
};

void delete_at_beginning(struct node *head){

	struct node *temp = head->nxt;
	head->nxt = temp->nxt;
	free(temp);
};

void delete_element(struct node *head, int element){

	struct node *temp = head;
	struct node *actual_element;


	//Traverse before reaching element
	while((temp->nxt)->data != element){
		temp = temp->nxt;
	};

	actual_element = temp->nxt;
	temp->nxt = actual_element->nxt;
	free(actual_element);


};




void main(){
	struct node* head = create_node(0);
	clrscr();
	printf("Initial List: ");
	create_list(head);
	traverse_list(head);
	printf("\nInsert at beginning 999: ");
	insert_beginning(head,999);
	traverse_list(head);
	printf("\nInsert after index 666: ");
	insert_after_index(head, 666, 70);
	traverse_list(head);
	printf("\nDelete at beginning: ");
	delete_at_beginning(head);
	traverse_list(head);
	printf("\nDelete element 50: ");
	delete_element(head, 50);
	traverse_list(head);



	getch();

}

