#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct ball{
//	char nama[20];
//	int harga;
//};

void shop(int *uang){
	int pilihan = 0;
	char keluar[20];

	do{	
		system("cls");
		printf("======================================================\n");
		printf("              TOKO POKEBALL MAK AJIM\n");
		printf("======================================================\n");
		
		printf("Uang: %d\n", *uang);
		printf("======================================================\n");
		printf("Selamat datang di toko mak ajim, monggo mau beli apa?\n\n");
		printf("   press: 1. Pokeball (500$)\n          2. Greatball (600$)\n          3. Ultraball (800$)\n          4. Masterball (90000$)\n\n");
		printf("======================================================\n");
		printf("Monggo: ");
		scanf("%d", &pilihan);
		while (!(pilihan >= 1 && pilihan <= 4)){
			printf("======================================================");
			printf("\nMaaf input salah hanya bisa 1-4\nMasukkan kembali pilihan: ");
			scanf("%d", &pilihan);
		}
		
		switch (pilihan){
			case 1:
				if (*uang < pokeball[pilihan - 1].harga){
					printf("Maaf uang tidak mencukupi\n");
					break;
				}
				printf("Pembelian Berhasil!\n");
				*uang -= pokeball[pilihan - 1].harga;
				pokeball[pilihan - 1].inventory+=1;
				break;
			case 2:
				if (*uang < pokeball[pilihan - 1].harga){
					printf("Maaf uang tidak mencukupi\n");
					break;
				}
				printf("Pembelian Berhasil!\n");
				*uang -= pokeball[pilihan - 1].harga;
				pokeball[pilihan - 1].inventory+=1;
				break;
			case 3:
				if (*uang < pokeball[pilihan - 1].harga){
					printf("Maaf uang tidak mencukupi\n");
					break;
				}
				printf("Pembelian Berhasil!\n");
				*uang -= pokeball[pilihan - 1].harga;
				pokeball[pilihan - 1].inventory+=1;
				break;
			case 4:
				if (*uang < pokeball[pilihan - 1].harga){
					printf("Maaf uang tidak mencukupi\n");
					break;
				}
				printf("Pembelian Berhasil!\n");
				*uang-= pokeball[pilihan - 1].harga;
				pokeball[pilihan - 1].inventory+=1;
				break;
			default:
				break;
		}
		sleep(2);
		system("cls");
		printf("======================================================\n");
		printf("              TOKO POKEBALL MAK AJIM\n");
		printf("======================================================\n");
		
		printf("Uang: %d\n", *uang);
		printf("======================================================\n");
		printf("Selamat datang di toko mak ajim, monggo mau beli apa?\n\n");
		printf("   press: 1. Pokeball (500$)\n          2. Greatball (600$)\n          3. Ultraball (800$)\n          4. Masterball (90000$)\n\n");
		printf("======================================================\n");
		printf("Apakah kamu ingin membeli lagi?\n(Ya atau Tidak)\n\n");
		scanf(" %255[^\n]s", &keluar);
		while (strcmp(keluar, "Tidak") && strcmp(keluar, "Ya")){
			printf("Maaf input salah, Apakah kamu ingin membeli lagi?\n(Ya atau Tidak)\n\n");
			scanf(" %255[^\n]s", &keluar);
		}	
	} while (!strcmp(keluar, "Ya"));
	
}




