
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <omp.h>
#include <unistd.h>
#define righe 10
#define colonne 10
using namespace std;

void carica (int m[righe][colonne]);
void stampa (int m[righe][colonne]);
void ordina (int m[righe][colonne]);

int main()
{
	int matrice [righe][colonne];
	
#pragma omp parallel
	
	carica(matrice);
	stampa(matrice);
	cout<<endl<<endl;
	ordina(matrice);
	stampa(matrice);
	
	
	return 0;
}

void carica (int m[righe][colonne])
{
	srand(time(NULL));
	
	for(int i=0; i<righe ;i++)
	{
		for(int j=0; j<colonne; j++)
		{
			m[i][j]=rand()%100 +1;
		}
	}
}


void stampa(int m[righe][colonne])
{
	for(int i=0; i<righe; i++)
	{
		for(int j=0; j<colonne; j++)
		{
			cout<<m[i][j]<<" ";
		}
		cout<<endl<<endl;
	}
}

void ordina(int m[righe][colonne])
{
	for(int i=0; i<righe; i++)
	{
		for(int j=0; j<colonne; j++)
		{
			for(int z=0; z<colonne-1; z++)
			{
				if(m[i][z]>m[i][z+1])
				{
					int app= m[i][z];
					m[i][z]= m[i][z+1];
					m[i][z+1]= app;
				}
			}
		}
	}
}
	
