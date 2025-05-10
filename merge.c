#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node* create_node(int data);
void create_list(struct node *temp);
void traverse_list(struct node *temp);
struct node* merge_list(struct node *head1, struct node *head2);

struct node{
	int data;
	struct node *nxt;
};


struct node *create_node(int data){
	struct node new_node = (struct node)malloc(sizeof(struct node));
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
	while(1){
		printf("%d->", temp->data);
		temp = temp->nxt;
		if(temp->nxt == NULL){
			return;
		};
	};
}

struct node* merge_list(struct node *head1, struct node *head2){

	struct node *temp1 = head1, *temp2 = head2;
	struct node *temp3 = NULL, *head3 = NULL;

	while(temp1 != NULL && temp2 != NULL){

		//new_node made from LL1
		struct node *new_node1 = create_node(temp1->data);
		//new_node made from LL2
		struct node *new_node2 = create_node(temp2->data);

		if(head3 == NULL){
			head3 = new_node1;
				temp3 = new_node1;
		}else{
			temp3->nxt = new_node1;
			temp3 = temp3->nxt;
		}
		new_node1->nxt = new_node2;
		temp3 = new_node2;

		temp1 = temp1->nxt;
		temp2 = temp2->nxt;
	};
	return head3;
};

void main(){
	struct node *head1 = create_node(0);
	struct node *head2 = create_node(0);
	struct node *head3;
	clrscr();
	printf("Initial List: ");
	create_list(head1);
	create_list(head2);
	printf("\nList1: ");
	traverse_list(head1);
	printf("\nList2:");
	traverse_list(head2);
	head3 = merge_list(head1, head2);
	printf("\nMerged List: ");
	traverse_list(head3);
	getch();

}