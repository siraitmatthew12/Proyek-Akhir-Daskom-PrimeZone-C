#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void checker(int *arrwhack, int *mole, int pilihanUser, char *tabel);

void whackAMole()
{
    int arrwhack[10]={0};
    char tabel[10]={'0','1','2','3','4','5','6','7','8','9'};
    int mole[3]={0};
	int i,j,pilihanUser=0;   
	int attempt=0;
	int angka; 
	srand(time(NULL)); 
	//bagian menentukan letak mole
	for(i=0;i<3;i++){
		do{
			angka = (rand()%9)+1;
			mole[i]=angka;
		}while(angka==mole[i-2]||angka==mole[i-1]||angka==mole[i+1]||angka==mole[i+2]);
		
		printf("%d\n",mole[i]);
		arrwhack[angka]+=1;
	}	

		do{
	//		Meminta input user 
			printf("Ayo Pukul Para Mole Pengganggu Ini\n");
			printf("Kali Tebak:%d\n",attempt);
			printf("  %c  |  %c  |  %c  \n",tabel[1],tabel[2],tabel[3]);
			printf("_____|_____|_____\n");
			printf("     |     |     \n");
			printf("  %c  |  %c  |  %c  \n",tabel[4],tabel[5],tabel[6]);
			printf("_____|_____|_____\n");
			printf("     |     |     \n");
			printf("  %c  |  %c  |  %c  \n",tabel[7],tabel[8],tabel[9]);
			printf("     |     |     \n");
			
			printf("Silahkan Whack A Mole: ");
			scanf("%d",&pilihanUser);
			
			if (pilihanUser>9 || pilihanUser <=0){
				printf("\nMasukkan angka yang terdapat pada kotak\n");
				sleep(1);
				system("cls");
			}
			else {
			attempt+=1;
			printf("Anda Telah Menebak Sebanyak %d dari 5 kali percobaan\n",attempt);
			checker(arrwhack,mole,pilihanUser,tabel);
			sleep(1);
			system("cls");
		}
			
		}while(checkArrayWhack(arrwhack)==1 && attempt!=5);
		
		//  hasil akhir dari permainan
			printf("Terimakasih Telah Bermain\n");	
			printf("Berikut adalah hasil penemuan akhir anda\n");
			printf("  %c  |  %c  |  %c  \n",tabel[1],tabel[2],tabel[3]);
			printf("_____|_____|_____\n");
			printf("     |     |     \n");
			printf("  %c  |  %c  |  %c  \n",tabel[4],tabel[5],tabel[6]);
			printf("_____|_____|_____\n");
			printf("     |     |     \n");
			printf("  %c  |  %c  |  %c  \n",tabel[7],tabel[8],tabel[9]);
			printf("     |     |     \n");
			
		checkArrayWhack(arrwhack)==0?printf("Selamat Anda telah memenangkan permainan"):printf("Maaf Anda Kalah");
}




//function untuk menentukan hole dan mole
void checker(int *arrwhack, int *mole, int pilihanUser, char *tabel){
	int i;
	int j;
	int checker;
	
	if(arrwhack[pilihanUser]!=0 && (pilihanUser==mole[0] ||pilihanUser==mole[1]||pilihanUser==mole[2] )){
		arrwhack[pilihanUser]-=1;
		tabel[pilihanUser]=1;
		printf("Selamat Anda Telah Menemukan Mole\n");
	}else{
		if(tabel[pilihanUser]==1){
			printf("You Found A Mole\n");
		}else{
			tabel[pilihanUser]=5;
			printf("You Found A Hole\n");
		}
	}
}


//	function checkarray
int checkArrayWhack(int *arrwhack){
	int val=1;
	int i;
	for (i=0;i<=9;i++){
		if(arrwhack[i]!=0){
			val=1;
			break;		
		}else{
			val=0;
		}
	}
	return val;
}
