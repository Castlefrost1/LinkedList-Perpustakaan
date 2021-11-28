// Aldi Julyan Sugiyarto - 2301852455
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef TREE_C
#define TREE_C

struct info_buku_BST{
	int Key;
	char Tajuk[3];
	struct info_buku_BST *left, *right;
	char Judul[100];
};

int keygen(char* dataJudul, int dataJudul_length){
	int sum = 0,i ;
	char title[100];
	for(i = 0; i < strlen(dataJudul); i++){
		title[i] = tolower(dataJudul[i]);
	}
	for (i = 0; i < strlen(title); i++){
//		printf("%d + %d\n",sum, title[i]);
		sum = sum + title[i];
//		printf("%d\n",sum);	
	}
	return sum;
}

struct info_buku_BST *newNode(int dataKey, char* dataTajuk, int dataTajuk_Length, char* dataJudul, int dataJudul_Length) 
{ 
	int i;
    struct info_buku_BST *temp =  (struct info_buku_BST *)malloc(sizeof(struct info_buku_BST)); 
    temp->Key = dataKey; 
    strcpy(temp->Tajuk,dataTajuk);
    strcpy(temp->Judul,dataJudul);
    temp->left = temp->right = NULL; 
    return temp; 
}   
   
struct info_buku_BST* insertBST(struct info_buku_BST* node, int dataKey, char* dataTajuk, int dataTajuk_length, char* dataJudul, int dataJudul_Length) 
{ 
    if (node == NULL) return newNode(dataKey, dataTajuk, dataTajuk_length, dataJudul, dataJudul_Length); 
    if (dataKey < node->Key) {
    	node->left  = insertBST(node->left, dataKey, dataTajuk, dataTajuk_length, dataJudul, dataJudul_Length);
	}
    else if (dataKey > node->Key){
    	node->right = insertBST(node->right, dataKey, dataTajuk, dataTajuk_length, dataJudul, dataJudul_Length);
	} 
    return node;
} 

void in_order(struct info_buku_BST *root) 
{ 
	int i;
    if (root != NULL) 
    { 
        in_order(root->left); 
        printf("\n-------------------------------------------");
        printf("\nJudul Buku      : %s",root->Judul);
        printf("\nTajuk Pengarang : %s",root->Tajuk);
        printf("\nID Buku         : %d",root->Key);
        printf("\n-------------------------------------------");
        in_order(root->right); 
        return;
    } 
} 

int searchNode(struct info_buku_BST* root, int dataKey){
	if (root->Key == dataKey){
		return 1;
	}
	else if (root == NULL){
		return 0;
	}
	if (root->left != NULL){
		if (root->Key > dataKey) { 
        searchNode(root->left, dataKey); 
    	} 
    }
    if (root->right != NULL){
        if (root->Key < dataKey) { 
        searchNode(root->right, dataKey); 
    	} 	
	}
}

struct info_buku_BST* deleteNode(struct info_buku_BST* root, int dataKey) 
{
    if (root == NULL) 
        return root; 
    if (root->Key > dataKey) { 
        root->left = deleteNode(root->left, dataKey); 
        return root; 
    } 
    else if (root->Key < dataKey) { 
        root->right = deleteNode(root->right, dataKey); 
        return root; 
    } 
    if (root->left == NULL) { 
        struct info_buku_BST* temp = root->right; 
        free(root); 
        return temp; 
    } 
    else if (root->right == NULL) { 
        struct info_buku_BST* temp = root->left; 
        free(root); 
        return temp; 
    } 
  
    else { 
        struct info_buku_BST* succParent = root; 
        struct info_buku_BST *succ = root->right; 
        while (succ->left != NULL) { 
            succParent = succ; 
            succ = succ->left; 
        } 
        if (succParent != root) 
            succParent->left = succ->right; 
        else
        root->Key = succ->Key; 
        free(root);          
        return root; 
    } 
} 
#endif
