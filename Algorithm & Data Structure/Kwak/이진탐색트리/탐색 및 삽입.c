#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode{
	element key;
	struct TreeNode *left, *right;
}TreeNode;

TreeNode* search(TreeNode *node, int key){
	if(node==NULL) return NULL;
	if(key==node->key) return node;
	else if(key<node->key) return search(node->left, key);
	else return search(node->right, key);
}

TreeNode* newNode(int item){
	TreeNode *temp=(TreeNode*)malloc(sizeof(TreeNode));
	temp->key=item;
	temp->left=temp->right=NULL;
	return temp;
}

TreeNode* insertNode(TreeNode *node, int key){
	if(node==NULL) return newNode(key);
	else if(key<node->key) node->left=insertNode(node->left, key);
	else if(key>node->key) node->right=insertNode(node->right, key);
	return node;
}

TreeNode* minNode(TreeNode *node){
	TreeNode *cur=node;
	while(cur->left!=NULL) cur=cur->left;
	return cur;
}

TreeNode* deleteNode(TreeNode *root, int key){
	if(root==NULL) return root;
	if(key<root->key) root->left=deleteNode(root->left, key);
	else if(key>root->key) root->right=deleteNode(root->right, key);
	else if(key==root->key){
		if (root->left==NULL){
			TreeNode *temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			TreeNode *temp=root->left;
			free(root);
			return temp;
		}
		TreeNode *temp=minNode(root->right);
		root->key=temp->key;
		root->right=deleteNode(root->right, temp->key);
	}
	return root;
}

void inorder(TreeNode *root){
	if (root!=NULL){
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}

int main() {
	TreeNode *root=NULL;
	TreeNode *tmp=NULL;
	int n;
	root=insertNode(root, 35);
	root=insertNode(root, 18);
	root=insertNode(root, 68);
	root=insertNode(root, 7);
	root=insertNode(root, 26);
	root=insertNode(root, 99);
	root=insertNode(root, 3);
	root=insertNode(root, 12);
	root=insertNode(root, 22);
	root=insertNode(root, 30);
	printf("이진탐색트리 중위순회 결과 출력\n");
	inorder(root);
	printf("\n삭제할 숫자를 입력하세요\n");
	scanf("%d", &n);
	deleteNode(root, n);
	printf("이진탐색트리 중위순회 결과 출력\n");
	inorder(root);
	return 0;
}

