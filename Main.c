// Aldi Julyan Sugiyarto - 2301852455
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "Tree.c"
#include "DataInput.c"

void menu(){
	printf("\nPerpustakaan BST");
	printf("\nMenu :"); 
	printf("\n1. Pendaftaran Buku Baru");
	printf("\n2. Mencari Buku");
	printf("\n3. Pinjam Buku");
	printf("\n4. Kembalikan Buku");
	printf("\n5. Cek Daftar Buku yang Tersedia");
	printf("\n6. Cek Daftar Buku yang Dipinjam");
	printf("\n7. Hapus Data Buku");
	printf("\n0. Exit");
	printf("\nMasukkan pilihan anda : ");
}

int main (){
	struct info_buku_BST* root = NULL;
	struct info_buku_List* head = NULL;
	struct info_buku_List* harga;
	int sum = 0;
	char option = 'x';
	char Judul[100];
	char Tajuk[3];
	int dataKey, i, waktu;
	do {
		menu();
		option = getch();
		if (option == '1'){
			printf("\n\nInput Buku Baru");
			printf("\nMasukkan Judul Buku : ");
			scanf (" %[^\n]%*c", Judul);
			dataKey = keygen(Judul, sizeof Judul);
			printf("Masukkan Singkatan penulis (Max 3 karakter): ");
			scanf (" %[^\n]%*c", Tajuk);
			if (root == NULL){
				root = insertBST(root, dataKey, Tajuk, sizeof(Tajuk), Judul, sizeof(Judul));
			}
			else{
				insertBST(root, dataKey, Tajuk, sizeof(Tajuk), Judul, sizeof(Judul));
			}
		}
		else if (option == '2'){
			int hasil;
			if (root != NULL){
			printf("\n\nMenu Pencarian Buku");
			printf("\nMasukkan Judul Buku yang ingin dicari: ");
			scanf (" %[^\n]%*c", Judul);
			dataKey = keygen(Judul, sizeof Judul);
			
				hasil = searchNode(root,dataKey);
				if (hasil == 1){
					printf("Buku ada!\n");
				}
				else{
					printf("Buku Tidak ada!\n");
				}
			}
			else{
				printf("\n\nList Kosong!\n");
			}
		}
		
		else if (option == '3'){
			printf("\n\nMenu Peminjaman Buku");
			if (root != NULL){
			printf("\nMasukkan judul buku yang ingin dipinjam : ");
			scanf (" %[^\n]%*c", Judul);
			dataKey = keygen(Judul, sizeof Judul);
			
				if (searchNode(root,dataKey) == 1){
					printf("\nBuku ada!\n");
					if(head == NULL){
					head = Queue(root,head,dataKey);	
					}
					else{
					Queue(root,head,dataKey);	
					}
					root = deleteNode(root,dataKey);
				}
				else {
					printf("Buku Tidak ada!\n");
				}
			}
			else{
				printf("\nList Kosong!\n");
			}
		}
		else if (option == '4'){
			printf("\n\nMenu Pengembalian Buku");
			if (head != NULL){
			printf("\nMasukkan Judul buku yang ingin dikembalikan: ");
			scanf (" %[^\n]%*c", Judul);
			dataKey = keygen(Judul, sizeof Judul);	
				harga = searchList(head, dataKey);
				if (harga != NULL){
					if (harga->listKey == dataKey){
						printf("\nMasukkan lama waktu Peminjaman (dalam hari): ");
						scanf("%d",&waktu);
						sum = totalBiaya(harga, sum, waktu);
						printf("\nTotal biaya : Rp%d\n", sum);
						if(root == NULL){
							root = 	insertBST(root, dataKey, harga->listTajuk, sizeof(harga->listTajuk), harga->listJudul, sizeof(harga->listJudul));
						}
						else{
							insertBST(root, dataKey, harga->listTajuk, sizeof(harga->listTajuk), harga->listJudul, sizeof(harga->listJudul));
						}
							if(harga == head){
								head = deleteList(head, dataKey);
							}
					else{
						deleteList(head, dataKey);
						}
					}	
				}

				else {
					printf("\nTidak ada data peminjaman buku!");
				}
			}
			else{
				printf("\n\nBelum ada peminjaman!\n");
			}	
		}
		else if (option == '5'){
			printf("\n\nList Buku :");
			printf("\n===========================================");
			if (root != NULL){
				in_order(root);
				printf("\n===========================================");
			}
			else if (root == NULL){
				printf("\nList Kosong!");
				printf("\n===========================================");
			}
		}
		else if (option == '6'){
			printf("\n\nData Pinjaman Buku");
			printf("\n===========================================");
			if (head != NULL){
				printlist(head);
				printf("\n===========================================");
			}
			else{
				printf("\nList Kosong!");
				printf("\n===========================================");
			}
			
		}
		else if (option == '7'){
			printf("\n\nMenu Penghapusan data buku");
			if (root != NULL){
			printf("\nMasukkan Judul Buku yang ingin dihapus: ");
			scanf (" %[^\n]%*c", Judul);
			dataKey = keygen(Judul, sizeof Judul);
				if(searchNode(root,dataKey)==1){
					root = deleteNode(root,dataKey);
					printf("\nData Buku Dihapus!");
				}
				else{
					printf("\nBuku Tidak Ada!");
				}
			}
			else{
				printf("\n\nList Kosong!\n");
			}
		}
		else if (option == '0'){
			break;
		}
		else{
			printf("\nMasukkan pilihan yang benar!\n");
			continue;
		}
	}
	while (option != '0');
}
