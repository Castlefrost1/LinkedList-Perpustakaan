// ALdi Julyan Sugiyarto - 2301852455
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree.c"
#ifndef DATAINPUT_C
#define DATAINPUT_C

struct info_buku_List{
	int listKey;
	int Jumlah;
	char listJudul[100];
	char listTanggal [11];
	char listPeminjam[100];
	char listTajuk[3];
	struct info_buku_List *next;
};

struct info_buku_List* append(struct info_buku_List* headList, int dataKey, int dataJumlah, char* dataJudul, int dataJudul_Length, char* dataTanggal, int dataTanggal_Length, char* dataPeminjam, int dataPeminjam_Length, char* dataTajuk, int dataTajuk_Length){
	int i;
	struct info_buku_List *new_node =  (struct info_buku_List *)malloc(sizeof(struct info_buku_List));
	struct info_buku_List *last = headList;
	new_node->listKey = dataKey;
	new_node->Jumlah = dataJumlah;
	strcpy(new_node->listJudul,dataJudul);	
	strcpy(new_node->listTanggal,dataTanggal);	
	strcpy(new_node->listPeminjam,dataPeminjam);	
	strcpy(new_node->listTajuk,dataTajuk);
	
	new_node->next = NULL;
	if (headList == NULL)
	{
		headList = new_node;
		return headList;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return headList;
}

void printlist(struct info_buku_List *headList){
	struct info_buku_List *temp = headList;
	while (temp != NULL){
		printf("\n-------------------------------------------");
		printf("\nJudul Buku         : %s", temp->listJudul);
		printf("\nPenulis            : %s", temp->listTajuk);
		printf("\nID Buku            : %d", temp->listKey);
		printf("\nDipinjam atas nama : %s", temp->listPeminjam);
		printf("\nTanggal Peminjaman : %s", temp->listTanggal);
		printf("\nJumlah Buku        : %d", temp->Jumlah);
		printf("\n-------------------------------------------");
		temp = temp->next;
	}
}

struct info_buku_List* deleteList(struct info_buku_List *headList, int dataKey){
	struct info_buku_List *ToDelete;
	struct info_buku_List *BeforeDel;
	struct info_buku_List *temp = headList;
	if (headList->listKey == dataKey){
		if (headList == NULL)
		{	
			printf("\nList is already empty");
		}
		else
		{
			ToDelete = headList;	
			headList = headList->next;
			free(ToDelete);
			return headList;
		}
	}
	while (temp != NULL){
		if (temp->next->listKey == dataKey){
			BeforeDel = temp;
			temp = temp -> next;
			break;
		}
		temp = temp -> next;
	}
	ToDelete = temp;
	BeforeDel->next = temp->next;
	free(ToDelete);
}

struct info_buku_List* searchList(struct info_buku_List *headList, int dataKey){
	struct info_buku_List *temp = headList;
	if (headList->listKey == dataKey){
		return headList;
	}
	while (temp != NULL){
		if (temp->listKey == dataKey){
			return temp;
		}
		if (temp->next != NULL){
			temp = temp -> next;
		}
		break;
	}
	return 0;
}

int totalBiaya(struct info_buku_List *harga, int totalHarga, int waktu){
	totalHarga = (((harga->Jumlah) * 1000)*waktu);
	return totalHarga;
}

struct info_buku_List* Queue(struct info_buku_BST* root, struct info_buku_List* headList, int dataKey){
	int dataJumlah;
	char dataTanggal[11];
	char dataPeminjam[100];
	if (root->Key == dataKey){
		printf("Masukkan jumlah buku yang dipinjam : ");
		scanf("%d", &dataJumlah);
		printf("Masukkan tanggal hari ini (format : tanggal/bulan/tahun): ");
		scanf (" %[^\n]%*c", dataTanggal);
		printf("Masukkan nama peminjam : ");
		scanf (" %[^\n]%*c", dataPeminjam);
		headList = append(headList, dataKey, dataJumlah, root->Judul, sizeof(root->Judul), dataTanggal, sizeof(dataTanggal), dataPeminjam, sizeof(dataPeminjam), root->Tajuk, sizeof(root->Tajuk));
		return headList;
	}
	if (root->left != NULL){
		if (root->Key > dataKey) { 
        Queue(root->left, headList, dataKey); 
    	} 
    }
    if (root->right != NULL){
        if (root->Key < dataKey) { 
        Queue(root->right, headList, dataKey); 
    	} 	
	}	
}
#endif
