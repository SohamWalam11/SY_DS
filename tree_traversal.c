#include<stdio.h>
#include<conio.h>

struct TreeNode *generateTree();
void inorder(struct TreeNode *root);
void postorder(struct TreeNode *root);
void preorder(struct TreeNode *root);


struct TreeNode{
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* generateTree(){

	int val;
	struct TreeNode *node;

	printf("\nEnter value: ");
	scanf("%d", &val);

	if(val == -1){
		return NULL;
	}

	node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->data = val;

	printf("\nEnter left child for Node %d", val);
	node->left = generateTree();

	printf("\nEnter right child for Node %d", val);
	node->right = generateTree();

	return node;
}

void inorder(struct TreeNode *root){

	if(root == NULL){
		return;
	}

	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

void preorder(struct TreeNode *root){

	if(root == NULL){
		return;
	}

	printf("%d ", root->data);
	postorder(root->left);
	postorder(root->right);

}

void postorder(struct TreeNode *root){

	if(root == NULL){
		return;
	}

	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);



}


void main(){
	struct TreeNode* root;

	clrscr();

	root = generateTree();
	printf("\nIn Order:");
	inorder(root);
	printf("\nPre Order: ");
	preorder(root);
	printf("\nPost Order: ");
	postorder(root);

	getch();
}