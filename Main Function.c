#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "dinoDuel.h"
#include "TebakAngka.h"
#include "whackAMole.h"
#include "trainSimulator.h"
#include "pubgMaze.h"
#include "MainPokemon.h"
#include "TicTacToe.h"

int main(){
    srand(time(NULL)); 
    int saldo = 0, angkaPilihanSaldo, pilihanGame, pilihanMenu = 0;
	  printf("=========PrimeZone C====PrimeZone C===========\n");	
	  printf("=========PrimeZone C====PrimeZone C===========\n");	
	  printf("=========PrimeZone C====PrimeZone C===========\n");	
    
	  printf("\n");
	
	do{
    	printf("Menu 	:\n\n");
    	printf("\t 1. Main Games	\n");
    	printf("\t 2. Petunjuk Penggunaan Program 	\n");
    	printf("\t 3. Pengisian Saldo\n");
      printf("\t 4. Keluar\n");
      printf("Saldo Anda sekarang berjumlah Rp%d.000,00\n", saldo/1000);
    	printf("Silahkan Pilih Operasi yang Diinginkan   ");
    	printf("\n>> ");
    	scanf("%d", &pilihanMenu);
    	
    	system("CLS");
    	
    	switch(pilihanMenu){
        case 1:
          printf("Anda memilih untuk bermain game");

          printf("\n\nAnda memiliki saldo Rp%d.000,00", saldo/1000);

          printf("\n\nBerikut adalah gamenya");
          printf("\n1. Tebak Angka (Rp2.000,00)");
          printf("\n2. Whack A Mole (Rp3.000,00)");
          printf("\n3. Train Simulator ke UI (Rp4.000,00)");
          printf("\n4. Pokemon (Rp5.000,00)");
          printf("\n5. Dino Duel (Rp6.000,00)");
          printf("\n6. TicTacToe (Rp7.000,00)");
          printf("\n7. PUBGMaze (Rp8.000,00)");

          printf("\n\nMasukkan angka game pilihan anda");
          printf("\n>> ");
          scanf("%d", &pilihanGame);

          switch(pilihanGame){
            case 1:
              //Tebak Angka
              printf("Main 1\n");
              saldo -= 2000;
              if(saldo < 0){
              	printf("\nSaldo Anda kurang, silakan top up di loket terlebih dahulu.\n");
              	saldo += 2000;
              	sleep(3);
              	break;
			  }
              printf("Selamat bermain, game akan dimulai 5 detik lagi");
              printf("\nSaldo anda tersisa Rp%d.000,00\n", saldo/1000);
              sleep(5);
              system("CLS");
              tebakAngka(); //game di sini
              break;
            case 2:
              //WhackAMole
              printf("Main 2\n");
              saldo -= 3000;
              if(saldo < 0){
              	printf("\nSaldo Anda kurang, silakan top up di loket terlebih dahulu.\n");
              	saldo += 3000;
              	sleep(3);
              	break;
			  }
              printf("Selamat bermain, game akan dimulai 5 detik lagi");
              printf("\nSaldo anda tersisa Rp%d.000,00\n", saldo/1000);
              sleep(5);
              system("CLS");
              whackAMole(); //game di sini
              break;
            case 3:
              //TrainSimulatorkeUI
              printf("Main 3\n");
              saldo -= 4000;
              if(saldo < 0){
              	printf("\nSaldo Anda kurang, silakan top up di loket terlebih dahulu.\n");
              	saldo += 4000;
              	sleep(3);
              	break;
			  }
              printf("Selamat bermain, game akan dimulai 5 detik lagi");
              printf("\nSaldo anda tersisa Rp%d.000,00\n", saldo/1000);
              sleep(5);
              system("CLS");
              trainSimulator();//game di sini
              break;
            case 4:
              //Pokemon
              printf("Main 4\n");
              saldo -= 5000;
              if(saldo < 0){
              	printf("\nSaldo Anda kurang, silakan top up di loket terlebih dahulu.\n");
              	saldo += 5000;
              	sleep(3);
              	break;
			  }
              printf("Selamat bermain, game akan dimulai 5 detik lagi");
              printf("\nSaldo anda tersisa Rp%d.000,00\n", saldo/1000);
              sleep(5);
              system("CLS");
              pokemon(); //game di sini
              break;
            case 5:
              //DinoDuel
              printf("Main 5\n");
              saldo -= 6000;
              if(saldo < 0){
              	printf("\nSaldo Anda kurang, silakan top up di loket terlebih dahulu.\n");
              	saldo += 6000;
              	sleep(3);
              	break;
			  }
              printf("Selamat bermain, game akan dimulai 5 detik lagi");
              printf("\nSaldo anda tersisa Rp%d.000,00\n", saldo/1000);
              sleep(5);
              system("CLS");
              dinoDuel(); //game di sini
              break;
            case 6:
              //TicTacToe
              printf("Main 6\n");
              saldo -= 7000;
              if(saldo < 0){
              	printf("\nSaldo Anda kurang, silakan top up di loket terlebih dahulu.\n");
              	saldo += 7000;
              	sleep(3);
              	break;
			  }
              printf("Selamat bermain, game akan dimulai 5 detik lagi");
              printf("\nSaldo anda tersisa Rp%d.000,00\n", saldo/1000);
              sleep(5);
              system("CLS");
              tictactoe(); //game di sini
              break;
            case 7:
              //PUBG
              printf("Main 7\n");
              saldo -= 8000;
              if(saldo < 0){
              	printf("\nSaldo Anda kurang, silakan top up di loket terlebih dahulu.\n");
              	saldo += 8000;
              	sleep(3);
              	break;
			  }
              printf("Selamat bermain, game akan dimulai 5 detik lagi");
              printf("\nSaldo anda tersisa Rp%d.000,00\n", saldo/1000);
              sleep(5);
              system("CLS");
              pubgMaze();//game di sini
              break;
            default:
              printf("\n\nGame yang anda pilih tidak tersedia\n");
              break;
          }

			    break;
      
        case 2:
                printf("-----Petunjuk Program PrimeZone C------\n");
                printf("1. Anda harus mengisi saldo terlebih dahulu untuk bermain \n");
                printf("2. Terdapat sejumlah paket saldo \n");
                printf("3. Masing-masing game hanya bisa dimainkan sekali untuk sekali pengurangan saldo\n");
                printf("4. Selamat bermain!\n");
                printf("---------TEKAN TOMBOL APAPUN UNTUK KEMBALI----------\n");
                getch();
        break;
    case 3:
      printf("\nSelamat datang di booth pengisian saldo.");
      printf("\n\nPengisian saldo dapat dipilih di bawah ini");
      printf("\n1. Rp50.000,00");
      printf("\n2. Rp75.000,00");
      printf("\n3. Rp100.000,00");
      printf("\n4. Rp125.000,00");
      printf("\n5. Rp150.000,00");
      printf("\n\nPilihan Anda");
      printf("\n>> ");
      scanf("%d", &angkaPilihanSaldo);
      
      switch(angkaPilihanSaldo){
        case 1:
          printf("\nSaldo Anda sekarang adalah Rp50.000,00");
          saldo += 50000;
          break;
        case 2:
          printf("\nSaldo Anda sekarang adalah Rp75.000,00");
          saldo += 75000;
          break;
        case 3:
          printf("\nSaldo Anda sekarang adalah Rp100.000,00");
          saldo += 100000;
          break;
        case 4:
          printf("\nSaldo Anda sekarang adalah Rp125.000,00");
          saldo += 125000;
          break;
        case 5:
          printf("\nSaldo Anda sekarang adalah Rp150.000,00");
          saldo += 150000;
          break;
        default:
          printf("Anda harus memilih salah satu paket yang tertera.");
          break;
      }
      break;
    case 4:
      printf("Terima kasih telah bermain, Sampai Jumpa");
    default:
      printf("Maaf Input Menu anda salah ");
	}
  system("CLS");
}
	while(pilihanMenu != 4);
      printf("Terima kasih telah bermain, Sampai Jumpa");
      sleep(10);
      system("CLS");
	return 0;
}

