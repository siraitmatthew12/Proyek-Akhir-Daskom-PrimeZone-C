//Printer Function
#include <stdio.h>
#include <conio.h>
#include "struct.c"
#include "PokeMap.c"
#include "shop.h"
#include <string.h>
#include <stdlib.h>


void printerMaze(char tujuan[0], struct Pokemons *arrofPokemon, int *checker);
void running(struct Pokemons *arrofPokemon);


int x=1;
int y=1;
int stopper;

void pokemon(){
	srand(time(NULL)); 
	Pokemon arrofPokemon[10]={
	Bulbasaur,Charmander,Squirtle,Caterpie,Rattata,Pidgey,Kyogre,Pikachu,Rayquaza,Mewtwo,
	};
	int i,j,checker=0;
	int uang=5000;
	char nama[50];
	char siap[20];
    char tujuan[1];
    printf("============================================================================================================\n");
	printf("              Welcome To Pokemon Game\n");
	printf("============================================================================================================\n");
    printf(" \nPanduan Permainan:\n");
    printf("1.Selamat Datang Anda Berada dalam Pokemon Game & Selamat Bermain dan Catch Em All\n");
    printf("2. Masukan w/a/s/d untuk berjalan\n");
 	printf("3. Ketik 'n' untuk mengakhiri game, ketik 'p' untuk membuka poke dex, ketik 'h' untuk help \n");
	printf("4. Daerah 'v' merupakan rumput dimana anda dapat menemukan uang atau pokemon\n");
	printf("5. Daerah '$' merupakan tempat shop anda berbelanja poke ball dan barang\n");
	printf("============================================================================================================\n");
	printf("Selamat Datang Petualang, Perkenalkan saya mr Evsu kembaran Profesor Oak");
//	scanf("%255[^\n]s", &nama);
//	fflush(stdin);
	printf("Apakah Anda Siap Bermain %s?? (Ya/Tidak)",nama);
	scanf("%s",&siap);
	
	while(!strcmp(siap, "Tidak")){
		
		printf("Baiklah aku akan Menunggu....\n");
		sleep(3);
		printf("Apakah Anda Siap Bermain %s?? (Ya/Tidak)",nama);
		scanf("%s",&siap);
		if(strcmp(siap, "Ya")==0){
			printf("Selamat Bertualang\n");
			break;
		}
	}
	
	printf("Loading... (5 sec)");
	sleep(5);
	system("CLS");
	
 	do{
 	checker=0;
 	printf("============================================================================================================\n");
	printf("              %s Journey's to catch em all'\n",nama);
	printf("============================================================================================================\n");
 	int angka = rand()%8;
 	for (i = 0; i <= 16; i++){
 		printf("\t\t");
        for (j = 0; j <= 35; j++){
			if(i==x && j==y){
				
				printf("o");
			}else{
				printf("%c", array[i][j]);
			}   	
        }
        printf("\n");
    }
   printf("============================================================================================================\n");
 	printf("Panduan Permainan\n");
 	printf("1.Selamat Datang Anda Berada dalam Pokemon Game\n");
 	printf("2. Masukan w/a/s/d untuk berjalan\n");
 	printf("3. Ketik 'n' untuk mengakhiri game, ketik 'p' untuk membuka poke dex, ketik 'h' untuk help \n");

 	printf("============================================================================================================\n");
	printf("Silahkan Masukkan Tujuan Anda:");
	tujuan[0]=getch();
//	scanf("%s", tujuan);
 	printerMaze(tujuan,arrofPokemon,&checker);
 	if(checker==1){}
 	else{
 		if(array[x][y]=='v'){
		if(angka==1){
			running(arrofPokemon);
    		printf("Loading...");
    		sleep(2);
		}if(angka==3 || angka==7){
			uang+=rand()%10*1000;
			printf("\n============================================================================================================\n");
			printf("Selamat Anda Ketemu Uang\n");
			printf("Wah aku ketemu uang sebesar %d\n",(rand()%10+1)*1000);
			printf("============================================================================================================\n");
			sleep(2);
		}
	}else if(array[x][y]=='$'){
		shop(&uang);
	}
	}

	system("cls");
 	}while(stopper!=1);
}

void printerMaze(char tujuan[0], struct Pokemons *arrofPokemon, int *checker){
	int pokedex;
	int i;
	switch(tujuan[0]) {
            case 'w':
            	if(x==1){
                	break;
				}else{
					x-=1;	
					break;
				}

            case 'a':
            	if(y==1){
                	break;
				}else{
					y-=1;
					break;	
				}
                
            case 's':
            	if(x==15){
                	break;
				}else{
					x+=1;
					break;	
				}
                
            case 'd':
                if(y==34){
                	break;
				}else{
					y+=1;
					break;	
				}
			case 'n':
                stopper=1;
				break;	
			case 'h':
				printf(" \nPanduan Permainan:\n");
 				printf("\t1.Selamat Datang Anda Berada dalam Pokemon Game & Selamat Bermain dan Catch Em All\n");
    			printf("\t2. Masukan w/a/s/d untuk berjalan\n");
 				printf("\t3. Ketik 'n' untuk mengakhiri game, ketik 'p' untuk membuka poke dex, ketik 'h' untuk help \n");
				printf("\t4. Daerah 'v' merupakan rumput dimana anda dapat menemukan uang atau pokemon\n");
				printf("\t5. Daerah '$' merupakan tempat shop anda berbelanja poke ball dan barang\n");
 				printf("8 Detik untuk kembali ke program...");
 				
 				sleep(8);
 				*checker=1;
 				break;
 			
			case 'p':
				printf(" \t\n-----------POKEDEX------------------\n");
 				printf("\tNama Pokemon\t\t\t\tHP\t\tPower\t\tRarity\t\tStatus\n");
				for(pokedex=0;pokedex<10;pokedex++){
 					if(arrofPokemon[pokedex].ketangkep==1){
 						printf("\t%d\t%s\t\t\t\t%d\t\t%d\t\t%d\t\t Tertangkap",pokedex+1,arrofPokemon[pokedex].name,arrofPokemon[pokedex].hp,arrofPokemon[pokedex].dificulty,arrofPokemon[pokedex].rarity);
					 }else{
					 	printf("\t%d\t???\t\t\t\t%d\t\t%d\t\t%d\t\t Belum Tertangkap",pokedex+1,arrofPokemon[pokedex].hp,arrofPokemon[pokedex].dificulty,arrofPokemon[pokedex].rarity);
					 }
 					printf("\n");
				 }
				 *checker=1;
				printf("Akan Kembali Ke Game dalam waktu 5 detik..");
 				sleep(5);
 				
 				break;
				  	
            default:
            	printf("Err\n");
                break;
        }
}

void running(struct Pokemons *arrofPokemon){
	int input=0;
	int caught=0;
	int angka = rand()%10;
	int hoki=(rand()%10)+1;
	int ketangkep;
	int pilihanPokeBall;
	printf("\n=============================================================================================\n");
	printf("Waduh Pokemon Tuhh..\n");
	printf("\n=============================================================================================\n");
	printf("Pokemon : %s\n",arrofPokemon[angka].name);
    printf("HP : %d\n",arrofPokemon[angka].hp);
    printf("Power : %d\n",arrofPokemon[angka].dificulty);
    printf("Rarity : %d\n",arrofPokemon[angka].rarity);
	printf("Ketik 1 untuk menangkap atau 2 untuk kabur: ");
	scanf("%d",&input);
	printf("\n=============================================================================================\n");
	while(caught==0){
		if(input==1){
			printf("\n=============================================================================================\n");
			printf("Silahkan Pilih Poke Ball Anda\n");
			printf("1. Pokeball(Anda Memiliki %d)\n",pokeball[0].inventory);
			printf("2. Greatball (Anda Memiliki %d)\n",pokeball[1].inventory);
			printf("3. Ultraball (Anda Memiliki %d)\n",pokeball[2].inventory);
			printf("4. Masterball (Anda Memiliki %d)\n",pokeball[3].inventory);
			printf("Anda Memilih: ");
			scanf("%d", &pilihanPokeBall);
			printf("\n=============================================================================================\n");
			printf("Kamu Telah Memilih %s\n",pokeball[pilihanPokeBall-1].nama);
			pokeball[pilihanPokeBall-1].inventory-=1;
			ketangkep=arrofPokemon[angka].rarity*hoki*pokeball[pilihanPokeBall-1].power;
			if(ketangkep>1000){
				printf("Pokemon Tertangkap !!!\n");
				arrofPokemon[angka].ketangkep=1;
				caught=1;
				break;
			}
      		else{
      			printf("Yah belum Tertangkap\n");
      			break;
			}
		}
    	else if(input==2){
    		printf("Sukses Kaburr..\n");
    		break;	
		}else{
			while(input<1 || input>2){
				printf("Ketik 1 untuk menangkap atau 2 untuk kabur: ");
				scanf("%d",&input);
			}
		}			
	}  	
}


