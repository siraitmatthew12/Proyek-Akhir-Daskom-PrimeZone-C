#include<stdio.h>

void petaErrangel(void);

void pubgMaze(){
    int pilihanMap;
    
    printf("Selamat datang di PUBG MAZE Game\n");
    printf("\nPilihlah peta yang ingin anda mainkan");
    printf("\n1. Errangel");
    printf("\n2. Miramar");
    printf("\nPilihan Anda : ");
    printf("\n>> ");
    scanf("%d", &pilihanMap);
    
    switch (pilihanMap)
    {
    case 1:
        petaErrangel();
        break;
    
    default:
    	printf("\nKarena peta yang tersedia baru errangel, harap menekan tombol nomor 1\n");
        break;
    }
}

void petaErrangel(void){
	system("CLS");
    int errangelMap[20][15] = 
	{
	{ 8, 8, 111, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
    { 8, 8, 2, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
    { 8, 8, 111, 111, 111, 111, 8, 8, 8, 8, 8, 8, 8, 8, 8},
    { 8, 8, 8, 8, 8, 111, 8, 8, 8, 8, 8, 8, 8, 8, 8},
    { 8, 8, 8, 8, 111, 111, 8, 8, 8, 8, 8, 8, 8, 8, 8},
    { 8, 8, 8, 8, 111, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
    { 8, 8, 8, 8, 111, 111, 111, 111, 111, 111, 111, 111, 8, 8, 8},
    { 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 111, 8, 8, 8},
    { 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 111, 8, 8, 8},
    { 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 111, 8, 8, 8},
    { 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 111, 8, 8, 8},
    { 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 111, 8, 8, 8},
    { 8, 8, 8, 8, 8, 8, 8, 8, 8, 111, 111, 111, 8, 8, 8},
    { 8, 8, 8, 8, 8, 8, 8, 8, 8, 111, 8, 8, 8, 8, 8},
    { 8, 8, 8, 8, 8, 8, 8, 8, 111, 111, 8, 8, 8, 8, 8},
    { 8, 8, 8, 8, 8, 8, 8, 8, 111, 8, 8, 8, 8, 8, 8},
    { 8, 111, 111, 111, 111, 111, 111, 111, 111, 8, 8, 8, 8, 8, 8},
    { 8, 111, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
    { 8, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 8},
    { 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 111, 8}
	};
	
	char arah;
	int i, j;
    
    while(errangelMap[19][13]!=2){
    	
    	system("CLS");
    	
    	for(i = 1; i < 20; i++)
		{
			for(j = 0; j < 15; j++){
//				printf("%d\t", errangelMap[i][j]);
				if(errangelMap[i][j]==8){
					printf("tembok\t");
				}
				if(errangelMap[i][j]==2){
					printf("ular\t");
				}
				if(errangelMap[i][j]==111){
					printf("___\t");
				}
			}
			printf("\n");
		}
    	
	    printf("\n\nKetik salah satu dari WASD untuk bergerak!");
	    printf("\n1. w untuk ke atas");
	    printf("\n2. a untuk ke kiri");
	    printf("\n3. s untuk ke bawah");
	    printf("\n4. d untuk ke kanan");
	    printf("\nArah Anda >> ");
	    scanf("%s", &arah);
	    
	    	if(arah == 'w')
			{
	    		for(i = 0; i < 20; i++)
			    {
			    	for(j = 0; j < 15; j++)
			    	{
			    		if(errangelMap[i-1][j] == 8){
			    			continue;
						}
			    		else if(errangelMap[i][j] == 2)
			    		{
//			    			printf("\n%d\n", errangelMap[i][j]);
			    			errangelMap[i-1][j] -= 109;
			    			errangelMap[i][j] += 109;
						}
					}
				}	
			}
			
			else if(arah == 'a')
			{
	    		for(i = 0; i < 20; i++)
			    {
			    	for(j = 0; j < 15; j++)
			    	{
			    		if(errangelMap[i][j-1] == 8){
			    			continue;
						}
			    		else if(errangelMap[i][j] == 2)
			    		{
//			    			printf("\n%d\n", errangelMap[i][j]);
			    			errangelMap[i][j-1] -= 109;
			    			errangelMap[i][j] += 109;
						}
					}
				}
			}
				
			else if(arah == 's')
			{
	    		for(i = 0; i < 20; i++)
			    {
			    	for(j = 0; j < 15; j++)
			    	{
			    		if(errangelMap[i][j] == 8){
			    			continue;
						}
			    		else if(errangelMap[i-1][j] == 2 && errangelMap[i][j] == 111)
			    		{
//			    			printf("\n%d\n", errangelMap[i][j]);
			    			errangelMap[i-1][j] += 109;
			    			errangelMap[i][j] -= 109;
						}
					}
				}
			}
				
			else if(arah == 'd')
			{
	    		for(i = 0; i < 20; i++)
			    {
			    	for(j = 0; j < 15; j++)
			    	{
			    		if(errangelMap[i][j] == 8){
			    			continue;
						}
			    		else if(errangelMap[i][j-1] == 2 && errangelMap[i][j] == 111)
			    		{
//			    			printf("\n%d\n", errangelMap[i][j]);
			    			errangelMap[i][j-1] += 109;
			    			errangelMap[i][j] -= 109;
						}
					}
				}
			}
			
			else
			{
				printf("\nAnda menekan tombol yang salah, mohon menekan salah satu dari w, a, s, d\n\n");
			}
	}
	system("CLS");
	printf("\nSelamat! Anda telah memenangi pertandingan.");
	sleep(3);
}


