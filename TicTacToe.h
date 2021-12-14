#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
int pemenang();
void tabel();

void tictactoe(){
	int pemain = 1;
	int i, pilihan;
	char mark;
	do {
		tabel();
		pemain = (pemain % 2) ? 1 : 2;
		printf("Pemain %d : ",pemain);
		scanf("%d", &pilihan);
		
		mark = (pemain == 1) ? 'X' :  'O';
		if (pilihan == 1 && square[1]=='1'){
			square[1]= mark;
		}
		else if (pilihan == 2 && square[2]=='2'){
			square[2]= mark;
		}
		else if (pilihan == 3 && square[3]=='3'){
			square[3]= mark;
		}
		else if (pilihan == 4 && square[4]=='4'){
			square[4]= mark;
		}
		else if (pilihan == 5 && square[5]=='5'){
			square[5]= mark;
		}
		else if (pilihan == 6 && square[6]=='6'){
			square[6]= mark;
		}
		else if (pilihan == 7 && square[7]=='7'){
			square[7]= mark;
		}
		else if (pilihan == 8 && square[8]=='8'){
			square[8]= mark;
		}
		else if (pilihan == 9 && square[9]=='9'){
			square[9]= mark;
		}
		else {
			printf("Input salah ");
			pemain--;
			getch();
		}
		i = pemenang();
		pemain++;
	}while (i== -1);
	
	tabel();
	
	if(i==1){
		printf("Pemain %d adalah pemenangnya ", --pemain);
	}
	else {
		printf("Permainan Seri !");
	}
	getch ();
}

int pemenang(){
	if (square[1]==square[2] &&square[2]==square[3]){
	return 1;
	}
	else if (square [4]==square[5] && square [5]==square[6]){
	return 1;
	}	
	else if (square [7]==square[8] && square [8]==square[9]){
	return 1;
	}
	else if (square [1]==square[4] && square [4]==square[7]){
	return 1;
	}	
	else if (square [2]==square[5] && square [5]==square[8]){
	return 1;
	}	
	else if (square [3]==square[6] && square [6]==square[9]){
	return 1;
	}	
	else if (square [1]==square[5] && square [5]==square[9]){
	return 1;
	}
	else if (square [3]==square[5] && square [5]==square[7]){
	return 1;
	}	
	else if (square[1]!='1' && square[2]!='2' && square[3]!='3' && square[4]!='4' && square[5]!='5' && square[6]!='6' && square[7]!='7' && square[8]!='8' && square[9]!='9'){
		return 0;
	}
	else 
	return -1;
}

void tabel (){
	system ("cls");
	printf("\n TIC TAC TOE \n");
	printf("Player 1 = X, Player 2 = O\n");

	printf("----------------------------\n");
	printf("|\t%c|\t%c|\t%c|\n",square[1],square[2],square[3]);
	printf("|\t |\t |\t |\n");
	printf("----------------------------\n");
	printf("|\t%c|\t%c|\t%c|\n",square[4],square[5],square[6]);
	printf("|\t |\t |\t |\n");
	printf("----------------------------\n");
	printf("|\t%c|\t%c|\t%c|\n",square[7],square[8],square[9]);
	printf("|\t |\t |\t |\n");
	printf("----------------------------\n");

}
