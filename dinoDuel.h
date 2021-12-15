#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct dino { //untuk informasi mengenai masing-masing dino
	char name[50];
	int hp;
	int def;
	int att;
	int critDamage;
	float critChance;
};

void battleInfo (struct dino player, struct dino bot);//prototype function battleinfo

int random(int lower, int upper){ // function untuk randomize angka
    int num = (rand() % (upper - lower + 1)) + lower;
    
    return num;

}

void check(int player, int bot, struct dino *player1, struct dino *bot1); //prototype function check

void dinoDuel(){
	//deklarasi semua variabel
	int i;
	struct dino player;
	struct dino bot;
	int playerPick;
	char kondisi[10];
	int pilihanPlayer, pilihanBot;
	char kembali[10];
	
	//inisialisasi semua jenis dino
	struct dino trex = {
		"T-Rex", 1100, 100, 500, 300, 0.4
	};
	
	struct dino pteranodon = {
		"Pteranodon", 700, 50, 600, 440, 0.7
	};
	
	struct dino triceratop = {
		"Triceratop", 2000, 150, 200, 190, 0.5
	};
	
	struct dino angkylosaurus = {
		"Angkylosaurus", 1600, 125, 400, 250, 0.2
	};
	
	//enkapsulasi semua struct dino yang ada
	struct dino daftardino[4] = {trex, pteranodon, triceratop, angkylosaurus};
	
	do {//pengulangan game
			do {//pengulangan kesiapan pemain
				system("cls");
				printf("==================================================================\n");
				printf("               WELCOME TO DINOSAUR SUIT BATTLE\n");
				printf("==================================================================\n");
				for(i = 0; i < 4; i++){
					printf("%d. %s\t\n", i+1, daftardino[i].name);
					printf("   HP              : %d \n", daftardino[i].hp);
					printf("   Defence         : %d \n", daftardino[i].def);
					printf("   Attack          : %d \n", daftardino[i].att);
					printf("   Critical Damage : %d \n", daftardino[i].critDamage);
					printf("   Critical Chance : %.f %\%\n\n", daftardino[i].critChance * 100);
				}
	
				printf("==================================================================\n");
				printf("Pilihlah Dino favoritmu!\n(dari angka 1-4)\n\n");
				scanf("%d", &playerPick);
			
				srand(time(0));//dipakai agar setiap nilai yang dirandomize akan memiliki nilai yang berbeda
	
				player = daftardino[playerPick-1];//sesuai pilihan pemain
				bot = daftardino[random(0,3)];//sesuai hasil nilai random
		
				system("cls");
				battleInfo(player, bot);//menunjukkan info jenis dino yang digunakan pemain dan bot
				printf("Apakah anda sudah siap untuk bertarung?\n(Sudah/Belum)\n\n");
				scanf(" %255[^\n]s", &kondisi);
		
				if(strcmp(kondisi, "Sudah") == 0){//kondisi sudah siap untuk break untuk lanjut ke sesi selanjutnya yaitu permainan
					break;
				}
		
				else if(strcmp(kondisi, "Belum") == 0) {//kondisi belum untuk ditanyakan kembali mengubah pilihan atau tidak
					printf("Baik akan ditunggu selama 5 detik. Apakah anda ingin mengubah pilihan anda? (Ya/Tidak)");
					scanf(" %255[^\n]s", &kondisi);
					printf("Menunggu.....");
					if(strcmp(kondisi, "Tidak") == 0){
						printf("Menunggu.....");
						sleep(5);	
						break;
					}
					sleep(5);		
				}
		
				else{//error handling agar input yang dimasukkan benar
					printf("Maaf input yang anda masukkan salah, Apakah anda ingin mengubah pikiran anda:\n(Ya atau Tidak)\n\n");
					scanf(" %255[^\n]s", &kondisi);
					printf("Menunggu.....");
					sleep(5);
				}
			}
			while (strcmp(kondisi, "Ya") == 0);//agar kembali diulangi ke pemilihan apabila pemain ingin mengubah pikiran
			
			system("cls");
			
			//masuk ke dalam permainan
			while (player.hp > 0 && bot.hp > 0){//untuk pengkondisian dimana apabila darah menyentuh angka 0 game akan berakhir
					printf("==================================================================\n");
					printf("                          BATTLE INFO\n");
					printf("==================================================================\n");
					printf("Your HP: %d\n", player.hp);
					printf("Enemies HP: %d\n", bot.hp);
					printf("==================================================================\n");
					printf("                      SUIT BATTLE PLATFORM\n");
					printf("==================================================================\n");
					printf("Pilihan:\n1. Gunting\n2. Kertas\n3. Batu\n\n");
					printf("Masukkan pilihanmu: ");
					scanf("%d", &pilihanPlayer);
					srand(time(0));
					pilihanBot = random(1,3);//randomize pilihan dari bot
					check(pilihanPlayer, pilihanBot, &player, &bot);//pengecekan siapa yang menang
			}
			system("cls");
			if(player.hp > 0){
				printf("==================================================================\n");
				printf("Selamat Kamu Menang!\n");
			}
					
			else {
				printf("==================================================================\n");
				printf("Maaf kamu kalah!\n");
			}
			printf("==================================================================\n");
			printf("Apakah kamu ingin mencoba lagi?\n(Ya/Tidak)\n\n");
			scanf(" %255[^\n]s", kembali);//input kembali untuk pengulangan permainan
			
			while (strcmp(kembali, "Tidak")){//output == 1 apabila tidak sama dengan "Tidak" maka untuk error handling
				if(!strcmp(kembali, "Ya")){//pengecualian untuk Ya agar tidak terjadi looping kembali apabila input kembali == "Ya"
					printf("Menunggu.....");
					sleep(3);
					break;
				}
				
				printf("Maaf input salah, Apakah kamu ingin mencoba lagi?\n(Ya/Tidak)\n\n");
				scanf(" %255[^\n]s", kembali);
			}
	}
	while (!strcmp(kembali, "Ya"));//Pengulangan permainan
}

void battleInfo (struct dino player, struct dino bot) {//menampilkan info dino yang digunakan pemain dan yang digunakan lawan
	printf("==================================================================\n");
	printf("Berikut adalah pilihanmu:\n");
	printf("%s\t\n", player.name);
	printf("   HP              : %d \n", player.hp);
	printf("   Defence         : %d \n", player.def);
	printf("   Attack          : %d \n", player.att);
	printf("   Critical Damage : %d \n", player.critDamage);
	printf("   Critical Chance : %.f %\%\n\n", player.critChance * 100);
	printf("==================================================================\n");
	printf("Berikut adalah lawanmu:\n");
	printf("%s\t\n", bot.name);
	printf("   HP              : %d \n", bot.hp);
	printf("   Defence         : %d \n", bot.def);
	printf("   Attack          : %d \n", bot.att);
	printf("   Critical Damage : %d \n", bot.critDamage);
	printf("   Critical Chance : %.f %\%\n\n", bot.critChance * 100);
	printf("==================================================================\n");
}

void check(int player, int bot, struct dino *player1, struct dino *bot1){//fungsi untuk mengecek siapa yang memenangkan permainan dan komputasi damage
	float playerChance = player1->critChance * 10;
	int playerDamage = player1->att + player1->critDamage;
	float botChance = bot1->critChance * 10;
	int botDamage = bot1->att + bot1->critDamage;
	
	if(player == bot){//apabila pilihan player dan bot sama
		if (player == 1){
			printf("\nPlayer dan bot sama-sama memilih Gunting\nLoading...");
			sleep(2);
			system("cls");
		}
		else if (player == 2){
			printf("\nPlayer dan bot sama-sama memilih Kertas\nLoading...");
			sleep(2);
			system("cls");
		}
		else if (player == 3){
			printf("\nPlayer dan bot sama-sama memilih Batu\nLoading...");
			sleep(2);
			system("cls");
		}
	}

	else if (player == 1){//apabila player memilih gunting
		if(bot == 2){//bot pilih kertas
			printf("==================================================================\n");
			printf("Kamu: Gunting\nLawan: Kertas\n");
			
			printf("==================================================================\n");
			printf("Selamat anda menang!\nKamu akan menyerang >:)\nLoading...");
			sleep(2);
			system("cls");
			
			if(playerChance > random(1, 10)){//aktualisasi dari kemungkinan critical hit
				bot1->hp = (bot1->hp + bot1->def) - playerDamage;
				printf("==================================================================\n");
				printf("Penyerangan berhasil.. CRITICAL HIT!\nDamage sebesar %d telah terakumulasi\n", playerDamage - bot1->def);
			}
			
			else {//aktualisasi damage tanpa critical
				bot1->hp = (bot1->hp + bot1->def) - player1->att;
				printf("==================================================================\n");
				printf("Penyerangan berhasil..\nDamage sebesar %d telah terakumulasi\n", player1->att - bot1->def);				
			}
		}
		else {//bot pilih batu
			printf("==================================================================\n");
			printf("Kamu: Gunting\nLawan: Batu\n");
			
			printf("==================================================================\n");
			printf("Wah kamu kalah!\nBersiaplah diserang :(\nLoading...");
			sleep(2);
			system("cls");
			
			if(botChance > random(1, 10)){
				player1->hp = (player1->hp + player1->def) - botDamage;
				printf("==================================================================\n");
				printf("Penyerangan berhasil.. CRITICAL HIT!\nNyawa kamu berkurang sebesar %d\n", botDamage - player1->def);
			}
			
			else {
				player1->hp = (player1->hp + player1->def) - bot1->att;
				printf("==================================================================\n");
				printf("Penyerangan berhasil..\nNyawa kamu berkurang sebesar %d\n", bot1->att - player1->def);				
			}
		}
	}
	
	else if (player == 2){//player memilih Kertas
		if(bot == 3){//bot memilih batu
			printf("==================================================================\n");
			printf("Kamu: Kertas\nLawan: Batu\n");
			
			printf("==================================================================\n");
			printf("Selamat anda menang!\nKamu akan menyerang >:)\nLoading...");
			sleep(2);
			system("cls");
			
			if(playerChance > random(1, 10)){
				bot1->hp = (bot1->hp + bot1->def) - playerDamage;
				printf("==================================================================\n");
				printf("Penyerangan berhasil.. CRITICAL HIT!\nDamage sebesar %d telah terakumulasi\n", playerDamage - bot1->def);
			}
			
			else {
				bot1->hp = (bot1->hp + bot1->def) - player1->att;
				printf("==================================================================\n");
				printf("Penyerangan berhasil..\nDamage sebesar %d telah terakumulasi\n", player1->att - bot1->def);				
			}
			
		}
		else {//bot memilih gunting
			printf("==================================================================\n");
			printf("Kamu: Kertas\nLawan: Gunting\n");
			
			printf("==================================================================\n");
			printf("Wah kamu kalah!\nBersiaplah diserang :(\nLoading...");
			sleep(2);
			system("cls");
			
			if(botChance > random(1, 10)){
				player1->hp = (player1->hp + player1->def) - botDamage;
				printf("==================================================================\n");
				printf("Penyerangan berhasil.. CRITICAL HIT!\nNyawa kamu berkurang sebesar %d\n", botDamage - player1->def);
			}
			
			else {
				player1->hp = (player1->hp + player1->def) - bot1->att;
				printf("==================================================================\n");
				printf("Penyerangan berhasil..\nNyawa kamu berkurang sebesar %d\n", bot1->att - player1->def);				
			}
		}
	}
	
	else if (player == 3){//player memilih batu
		if(bot == 1){//bot memilih gunting
			printf("==================================================================\n");
			printf("Kamu: Batu\nLawan: Gunting\n");
			
			printf("==================================================================\n");
			printf("Selamat anda menang!\nKamu akan menyerang >:)\nLoading...");
			sleep(2);
			system("cls");
			
			if(playerChance > random(1, 10)){
				bot1->hp = (bot1->hp + bot1->def) - playerDamage;
				printf("==================================================================\n");
				printf("Penyerangan berhasil.. CRITICAL HIT!\nDamage sebesar %d telah terakumulasi\n", playerDamage - bot1->def);
			}
			
			else {
				bot1->hp = (bot1->hp + bot1->def) - player1->att;
				printf("==================================================================\n");
				printf("Penyerangan berhasil..\nDamage sebesar %d telah terakumulasi\n", player1->att - bot1->def);
			}
		}
		
		else {//bot memilih kertas
			printf("==================================================================\n");
			printf("Kamu: Batu\nLawan: Kertas\n");
			
			printf("==================================================================\n");
			printf("Wah kamu kalah!\nBersiaplah diserang :(\nLoading...");
			sleep(2);
			system("cls");
			
			if(botChance > random(1, 10)){
				player1->hp = (player1->hp + player1->def) - botDamage;
				printf("==================================================================\n");
				printf("Penyerangan berhasil.. CRITICAL HIT!\nNyawa kamu berkurang sebesar %d\n", botDamage - player1->def);
			}
			
			else {
				player1->hp = (player1->hp + player1->def) - bot1->att;
				printf("==================================================================\n");
				printf("Penyerangan berhasil..\nNyawa kamu berkurang sebesar %d\n", bot1->att - player1->def);				
			}
		}
	}
	
	else {//error handling untuk input angka suit
		printf("==================================================================\n");
		printf("INPUT SALAH!! UBAHLAH MENJADI ANGKA 1 - 3\n");
		printf("==================================================================\n");
		sleep(2);
		system("cls");
	}
}
