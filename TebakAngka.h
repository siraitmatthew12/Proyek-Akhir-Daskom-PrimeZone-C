#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void tebakAngka(){
   srand(time(NULL)); 
    int angka = rand()%100;
    int tebakan, kaliTebak=0;
    int operasi;	
	printf("--Selamat datang dalam Program Tebak Angka--\n");	
	printf("\n");
	
	do{
    	printf("Menu 	:\n");
    	printf("\t 1. Main Games	\n");
    	printf("\t 2. Petunjuk Penggunaan Program 	\n");
    	printf("\t 3. Keluar 	\n");
    	printf("Silahkan Pilih Operasi yang Diinginkan   ");
    	scanf("%d",&operasi);
    	switch(operasi){
        case 1:
		do{
			do{	
				printf("Silahkan masukkan Input angka tebakan anda (1-100)");
				scanf("%d",&tebakan);	
			}
			while(tebakan>100 || tebakan<1);
			
			if(tebakan<angka){
				printf("Angka Anda terlalu Kecil\n");
				kaliTebak+=1;
			}else if(tebakan>angka){
				printf("Angka Anda terlalu Besar\n");
				kaliTebak+=1;
			}
			printf("Anda Telah Menebak Sebanyak %d kali dari 10 kali percobaan\n", kaliTebak);
			printf("\n");	
		} while(tebakan!=angka && kaliTebak!=10);
		    kaliTebak!=10 ? printf("Selamat Anda Telah Menang\n==========================================\n") : printf("Maaf Anda Telah Kalah Coba Lagi!!\n==========================================\n");	
			kaliTebak=0;
			break;
	 	case 2:
            printf("-----Petunjuk Program Tebak Angka------\n");
            printf("1. Program akan menentukan angka acak dari 1-100 \n");
            printf("2. Masukkan Tebakkan Anda \n");
            printf("3. Silahkan Menunggu Hasil Clue Program\n");
            printf("4. Tebaklah Max 5 kali untuk memenangkan permainan\n");
			printf("\n\nAnda akan kembali ke program awal dalam waktu 5 detik\n");
			sleep(5);
			break;
        case 3:
        	printf("Terimakasih Telah Bermain Sampai Jumpa");
            break;
        default:
            printf("Maaf Input Menu anda salah ");
	}
	system("CLS");
}
	while(operasi!=3);
	
}

