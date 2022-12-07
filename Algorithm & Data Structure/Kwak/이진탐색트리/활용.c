#include<stdio.h> 
#include<stdlib.h> 

typedef char element;
typedef struct TreeNode{
		char key; 
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
TreeNode* deleteNode(TreeNode* root, int key){
	printf("delete 주소=%p, key =%d\n",root,key);
	if(root == NULL) return root;
	if(key < root->key) root->left = deleteNode(root->left, key);
	else if(key > root->key) root->right = deleteNode(root->right, key);
	else{
		if(root->left == NULL){
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL){
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		TreeNode *temp=minNode(root->right);
		root->key=temp->key;
		root->right=deleteNode(root->right,temp->key);
	}
	return root;
}
void inorder(TreeNode *root){
	if(root!=NULL){
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}

void menu(){
	printf("\n*-----------------------*\n");
	printf("\n\t1 : 트리 출력\n");
	printf("\n\t2 : 문자 삽입\n");
	printf("\n\t3 : 문자 삭제\n");
	printf("\n\t4 : 문자 검색\n");
	printf("\n\t5 : 종료\n");
	printf("\n*-----------------------*\n");
	printf("\n메뉴 입력 >> ");
}

int main(){	 
	TreeNode *root=NULL;	  
	TreeNode *foundedNode=NULL; 
	char choice, key;	       
	root=insertNode(root, 'G');
	insertNode(root, 'I');
	insertNode(root, 'H');
	insertNode(root, 'D');
	insertNode(root, 'B');
	insertNode(root, 'M');
	insertNode(root, 'N');
	insertNode(root, 'A');
	insertNode(root, 'J');
	insertNode(root, 'E');
	insertNode(root, 'Q');
	while( 1 ){
		menu();
		scanf(" %c", &choice);
		switch(choice - '0'){
			case 1 : printf("\t[이진 트리 출력] ");
				inorder(root);
				printf("\n");
				break;
			case 2 : printf("삽입할 문자를 입력하세요 : ");
				scanf(" %c", &key);
				insertNode(root, key);
				break;
			case 3 : printf("삭제할 문자를 입력하세요 : ");
				scanf(" %c", &key);
				deleteNode(root, key);
				break;
			case 4 : printf("찾을 문자를 입력하세요 : ");
				scanf(" %c", &key);
				foundedNode = search(root, key);
				if(foundedNode!=NULL) printf("\n %c를 찾았습니다! \n", foundedNode->key);
				else printf("\n 문자를 찾지 못했습니다. \n");
				break;
			case 5 : return 0;
			default : printf("없는 메뉴입니다. 메뉴를 다시 선택하세요!\n");
				break;
		}
	}
} 
