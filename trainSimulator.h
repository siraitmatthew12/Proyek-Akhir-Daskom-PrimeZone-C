#include <stdio.h>
#include <string.h>
//#include "APIStasiun.h"

struct apiStasiun{
	int jumlahStasiunKeUI;
};

void perhitunganPenumpangNaikTurun(
int jumlahStasiunYangDilewati, 
int	jumlahOrangKeluar,
int	jumlahOrangMasuk,
int	jumlahPenumpang);

void gpsLocator(int i);

void trainSimulator(){ //Potongan Program Untuk Masuk ke Game Train Simulator
	int jumlahOrangKeluar = 0, jumlahOrangMasuk = 0, i, jumlahPenumpang = 0;
	int jumlahStasiunYangDilewati = 0;
	char namaStasiun[50];
	
	printf("Selamat datang di permainan Simulator KRL menuju stasiun\n");
	printf("|><|><|><|><|><|><|><|><|><|><|><|><|><|><|><|><|><|><|><|\n");
	printf("                 UNIVERSITAS INDONESIA                     \n");
	printf("|><|><|><|><|><|><|><|><|><|><|><|><|><|><|><|><|><|><|><|\n");
	printf("==========================================================\n\n"); 
	
	printf("Masukkan dari stasiun mana Anda hendak berangkat : ");
	scanf("%255[^\n]s",&namaStasiun);
	fflush(stdin); //input stasiun
	
	while(jumlahStasiunYangDilewati == 0 || jumlahStasiunYangDilewati > 16){
		
		jumlahStasiunYangDilewati = jumlahStasiun(namaStasiun);
		
		if(jumlahStasiunYangDilewati == 0){
			printf("\nMaaf! Anda tidak bisa naik dan turun Stasiun Universitas Indonesia\n");
			
			printf("Masukkan kembali dari stasiun mana Anda hendak berangkat : ");
			scanf("%255[^\n]s",&namaStasiun);
			fflush(stdin); //input stasiun
		}
		else if(jumlahStasiunYangDilewati == 17){
			printf("\nMaaf! Harap memasukkan stasiun yang berada di jalur Jakarta Kota");
			printf(" menuju Bogor\n");
			
			printf("Masukkan kembali dari stasiun mana Anda hendak berangkat : ");
			scanf("%255[^\n]s",&namaStasiun);
			fflush(stdin); //input stasiun
		}
	}
	
	printf("\nJumlah stasiun yang dilewati adalah %d stasiun.\n", abs(jumlahStasiunYangDilewati));
	
	perhitunganPenumpangNaikTurun( //pemanggilan fungsi perhitungan jumlah penumpang
	jumlahStasiunYangDilewati, 
	jumlahOrangKeluar,
	jumlahOrangMasuk,
	jumlahPenumpang
	);
}

void perhitunganPenumpangNaikTurun(
int jumlahStasiunYangDilewati, 
int	jumlahOrangKeluar,
int	jumlahOrangMasuk,
int	jumlahPenumpang)
{
	int jumlahPenumpangAwal, i, bisaTidak;
	float  totalRevenueKereta = 0;
	printf("\nHitunglah berapa orang yang berada di gerbong!");
	
	printf("\nApakah anda bisa berhitung? 1 untuk bisa dan 0 untuk tidak\n");
	printf(">> ");
	scanf("%d", &bisaTidak);
	
	while(bisaTidak > 1 || bisaTidak < 0){
		printf("\nHarap memilih salah satu dari kedua pilihan di atas");
		printf("\nApakah anda bisa berhitung? 1 untuk bisa dan 0 untuk tidak\n");
		printf(">> ");
		scanf("%d", &bisaTidak);
	}
	
	bisaTidak == 1 ? printf("\nHasil Perhitungan Anda : ")	:	printf("\nPerkiraan Jumlah Penumpang : ") ;
	scanf("%d", &jumlahPenumpang);
	totalRevenueKereta += 3*jumlahPenumpang;
	
	if(jumlahStasiunYangDilewati > 0){
		for(i=jumlahStasiunYangDilewati; i>0; i--){
			gpsLocator(i);
			printf("\nMasukkan berapa orang yang hendak keluar dari gerbong \n");
			printf(">> ");
			scanf("%d", &jumlahOrangKeluar);
			
			while(jumlahPenumpang < jumlahOrangKeluar){ //error handling saat pemain transit di sejumlah stasiun
				printf("\nMaaf! Penumpang gerbong adalah manusia dan bukan hantu\n");
				printf("Jumlah penumpang saat ini adalah %d\n", jumlahPenumpang);
				printf("\nMasukkan kembali berapa orang yang hendak keluar dari gerbong \n");
				printf(">> ");
				scanf("%d", &jumlahOrangKeluar);
			}
			
			jumlahPenumpang -= jumlahOrangKeluar;
			
			printf("Masukkan berapa orang yang hendak masuk ke dalam gerbong\n");
			printf(">> ");
			scanf("%d", &jumlahOrangMasuk);
			
			totalRevenueKereta += 3*jumlahOrangMasuk;
			jumlahPenumpang += jumlahOrangMasuk;
		}
	}
	
	else if(jumlahStasiunYangDilewati < 0){
		for(i=jumlahStasiunYangDilewati; i<0; i++){
			gpsLocator(i);
			printf("\nMasukkan berapa orang yang hendak keluar dari gerbong");
			printf("\n>> ");
			scanf("%d", &jumlahOrangKeluar);
				
			while(jumlahPenumpang < jumlahOrangKeluar){ //error handling saat pemain transit di sejumlah stasiun
				printf("\nMaaf! Penumpang kereta adalah manusia dan bukan hantu\n");
				printf("Jumlah penumpang saat ini adalah %d\n", jumlahPenumpang);
				printf("Masukkan kembali berapa orang yang hendak keluar dari gerbong");
				printf("\n>> ");
				scanf("%d", &jumlahOrangKeluar);
			}

			jumlahPenumpang = jumlahPenumpang - jumlahOrangKeluar;
			
			printf("Masukkan berapa orang yang hendak masuk ke dalam gerbong\n");
			printf(">> ");
			scanf("%d", &jumlahOrangMasuk);
			
			totalRevenueKereta += 3*jumlahOrangMasuk;
			jumlahPenumpang += jumlahOrangMasuk;
		}
	}
	
	printf("\nSelamat Datang di Universitas Indonesia!\n"); 
	printf("Saat sampai di Universitas Indonesia, jumlah penumpang yang berada di dalam gerbong ada %d orang.\n", jumlahPenumpang);
	if(totalRevenueKereta<1000){
		printf("Revenue dari gerbong ketika anda berada di dalam kereta adalah Rp%.0f.000,00", totalRevenueKereta);
	}else if(totalRevenueKereta<10000){
		totalRevenueKereta/=1000;
		printf("Revenue dari gerbong ketika anda berada di dalam kereta adalah Rp%.3f.000,00", totalRevenueKereta);
	}else if(totalRevenueKereta<100000){
		totalRevenueKereta/=1000;
		printf("Revenue dari gerbong ketika anda berada di dalam kereta adalah Rp%.3f.000,00", totalRevenueKereta);
	}
	
	sleep(5);
}

void gpsLocator(int i){ //gps penentu pemain sedang berada di titik lokasi
	switch(i){
		case 16:
			printf("\nSekarang Anda Berada di Stasiun Jakarta Kota.");
			break;
		case 15:
			printf("\nSekarang Anda Berada di Stasiun Jayakarta.");
			break;
		case 14:
			printf("\nSekarang Anda Berada di Stasiun Mangga Besar.");
			break;
		case 13:
			printf("\nSekarang Anda Berada di Stasiun Sawah Besar.");
			break;
		case 12:
			printf("\nSekarang Anda Berada di Stasiun Juanda.");
			break;
		case 11:
			printf("\nSekarang Anda Berada di Stasiun Gondangdia.");
			break;
		case 10:
			printf("\nSekarang Anda Berada di Stasiun Cikini.");
			break;
		case 9:
			printf("\nSekarang Anda Berada di Stasiun Manggarai.");
			break;
		case 8:
			printf("\nSekarang Anda Berada di Stasiun Tebet.");
			break;
		case 7:
			printf("\nSekarang Anda Berada di Stasiun Cawang.");
			break;
		case 6:
			printf("\nSekarang Anda Berada di Stasiun Duren Kalibata.");
			break;
		case 5:
			printf("\nSekarang Anda Berada di Stasiun Pasar Minggu Baru.");
			break;
		case 4:
			printf("\nSekarang Anda Berada di Stasiun Pasar Minggu.");
			break;
		case 3:
			printf("\nSekarang Anda Berada di Stasiun Tanjung Barat.");
			break;
		case 2:
			printf("\nSekarang Anda Berada di Stasiun Lenteng Agung.");
			break;
		case 1:
			printf("\nSekarang Anda Berada di Stasiun Universitas Pancasila.");
			break;
		case 0:
			printf("\nSekarang Anda Berada di Stasiun Universitas Indonesia.");
			break;
		case -1:
			printf("\nSekarang Anda Berada di Stasiun Pondok Cina.");
			break;
		case -2:
			printf("\nSekarang Anda Berada di Stasiun Depok Baru.");
			break;
		case -3:
			printf("\nSekarang Anda Berada di Stasiun Depok.");
			break;
		case -4:
			printf("\nSekarang Anda Berada di Stasiun Citayam.");
			break;
		case -5:
			printf("\nSekarang Anda Berada di Stasiun Bojong Gede.");
			break;
		case -6:
			printf("\nSekarang Anda Berada di Stasiun Cilebut.");
			break;
		case -7:
			printf("\nSekarang Anda Berada di Stasiun Bogor.");
			break;
	}
}

int jumlahStasiun(char *namaStasiun){ //kumpulan informasi stasiun
	
	int totalStasiun;
	
	struct apiStasiun JakartaKota = {16};
	struct apiStasiun Jayakarta = {15};
	struct apiStasiun ManggaBesar = {14};
	struct apiStasiun SawahBesar = {13};
	struct apiStasiun Juanda = {12};
	struct apiStasiun Gondangdia = {11};
	struct apiStasiun Cikini = {10};
	struct apiStasiun Manggarai = {9};
	struct apiStasiun Tebet = {8};
	struct apiStasiun Cawang = {7};
	struct apiStasiun DurenKalibata = {6};
	struct apiStasiun PasarMingguBaru = {5};
	struct apiStasiun PasarMinggu = {4};
	struct apiStasiun TanjungBarat = {3};
	struct apiStasiun LentengAgung = {2};
	struct apiStasiun UniversitasPancasila = {1};
	struct apiStasiun UniversitasIndonesia = {0};
	struct apiStasiun PondokCina = {-1};
	struct apiStasiun DepokBaru = {-2};
	struct apiStasiun Depok = {-3};
	struct apiStasiun Citayam = {-4};
	struct apiStasiun BojongGede = {-5};
	struct apiStasiun Cilebut = {-6};
	struct apiStasiun Bogor = {-7};
	struct apiStasiun stasiunTidakDikenal = {17};
	
	if(strcmp(namaStasiun, "Jakarta Kota") == 0){
		totalStasiun =  JakartaKota.jumlahStasiunKeUI;
	}else if(strcmp(namaStasiun, "Jayakarta") == 0){
		totalStasiun = Jayakarta.jumlahStasiunKeUI;
	}else if(strcmp(namaStasiun, "Mangga Besar") == 0){
		totalStasiun = ManggaBesar.jumlahStasiunKeUI;
	}else if(strcmp(namaStasiun, "Sawah Besar") == 0){
		totalStasiun = SawahBesar.jumlahStasiunKeUI;
	}else if(strcmp(namaStasiun, "Juanda") == 0){
		totalStasiun = Juanda.jumlahStasiunKeUI;
	}else if(strcmp(namaStasiun, "Gondangdia") == 0){
		totalStasiun = Gondangdia.jumlahStasiunKeUI;
	}else if(strcmp(namaStasiun, "Cikini") == 0){
		totalStasiun = Cikini.jumlahStasiunKeUI;
	}else if(strcmp(namaStasiun, "Manggarai") == 0){
		totalStasiun = Manggarai.jumlahStasiunKeUI;
	}else if(strcmp(namaStasiun, "Tebet") == 0){
		totalStasiun = Tebet.jumlahStasiunKeUI;
	}else if(strcmp(namaStasiun, "Cawang") == 0){
		totalStasiun = Cawang.jumlahStasiunKeUI;
	}else if(strcmp(namaStasiun, "Duren Kalibata") == 0){
		totalStasiun = DurenKalibata.jumlahStasiunKeUI;
	}else if(strcmp(namaStasiun, "Pasar Minggu Baru") == 0){
		totalStasiun = PasarMingguBaru.jumlahStasiunKeUI;
	}else if(strcmp(namaStasiun, "Pasar Minggu") == 0){
		totalStasiun = PasarMinggu.jumlahStasiunKeUI;
	}else if(strcmp(namaStasiun, "Tanjung Barat") == 0){
		totalStasiun = TanjungBarat.jumlahStasiunKeUI;
	}else if(strcmp(namaStasiun, "Lenteng Agung") == 0){
		totalStasiun = LentengAgung.jumlahStasiunKeUI;
	}else if(strcmp(namaStasiun, "Universitas Pancasila") == 0){
		totalStasiun = UniversitasPancasila.jumlahStasiunKeUI;
	}else if(strcmp(namaStasiun, "Universitas Indonesia") == 0){
		totalStasiun = UniversitasIndonesia.jumlahStasiunKeUI;
	}else if(strcmp(namaStasiun, "Pondok Cina") == 0){
		totalStasiun = PondokCina.jumlahStasiunKeUI;
	}else if(strcmp(namaStasiun, "Depok Baru") == 0){
		totalStasiun = DepokBaru.jumlahStasiunKeUI;
	}else if(strcmp(namaStasiun, "Depok") == 0){
		totalStasiun = Depok.jumlahStasiunKeUI;
	}else if(strcmp(namaStasiun, "Citayam") == 0){
		totalStasiun = Citayam.jumlahStasiunKeUI;
	}else if(strcmp(namaStasiun, "Bojong Gede") == 0){
		totalStasiun = BojongGede.jumlahStasiunKeUI;
	}else if(strcmp(namaStasiun, "Cilebut") == 0){
		totalStasiun = Cilebut.jumlahStasiunKeUI;
	}else if(strcmp(namaStasiun, "Bogor") == 0){
		totalStasiun = Bogor.jumlahStasiunKeUI;
	}else{
		totalStasiun = stasiunTidakDikenal.jumlahStasiunKeUI;
	}
	
	return totalStasiun;
}


