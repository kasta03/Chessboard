#include <stdio.h>
#include <stdlib.h>
#include <time.h>\



double d_rand(double min, double max){
	double r = (double) rand()/RAND_MAX;
	return r*(max-min) + min;
}
	
	
	int main(void)
	{
		srand(time(0)); // Inicjalizacja losowego ziarna
		
		
		int n;
		
		printf("Podaj liczbe losowan: ");
		scanf("%d", &n);
		
		int tab[10]={0};
		double x;
		
		for(int i=0; i<n; i++)
		{
			x=d_rand(0.0, 9.9999);
			if( x>=0 && x<1)
				tab[0]++;
			if( x>=1 && x<2)
				tab[1]++;
			if( x>=2 && x<3)
				tab[2]++;
			if( x>=3 && x<4)
				tab[3]++;
			if( x>=4 && x<5)
				tab[4]++;
			if( x>=5 && x<6)
				tab[5]++;
			if( x>=6 && x<7)
				tab[6]++;
			if( x>=7 && x<8)
				tab[7]++;
			if( x>=8 && x<9)
				tab[8]++;
				if( x>=9 && x<10)
				tab[9]++;
				
		}
		
		for(int j=0; j<10; j++)
		{
			printf("Przedzial [%d, %d): %d punktow.\n", j, j+1, tab[j]);
		}
		
			
			return 0;
	}