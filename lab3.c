#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

int N,M,u=0;
double S = 0;

printf("Введите кол-во строк: ");
scanf("%i",&N);
printf("Введите кол-во столбцов: ");
scanf("%i",&M);
int *Msum =  (int *)malloc(M*sizeof(int));
int *Matr =  (int *)malloc(N*M*sizeof(int));
for (int i=0;i<N;i++){
	for (int j=0,k;j<M;j++){
		printf("Введите эл. матрицы на %i стр %i стлб: ",i+1,j+1);
		scanf("%i",&k);
		Matr[i*M+j]=k;
	}
}

for (int i=0;i<N;i++){
	for (int j=0;j<M;j++){
		printf("| %i |", Matr[i*M+j]); //Выводит матрицу для проверки
		if ((j+1)%M==0){
			printf("\n");
			}
		}
	}

for (int j=0;j<M;j++){
	for (int i=0;i<N;i++){
		u += Matr[i*M+j];
	}
	Msum[j]=u;
	u=0;
}

for (int j=0;j<M;j++){					//Вывод одномерного массива
	printf("| %i |",Msum[j]);
}
printf("\n");

for (int i=0;i<M;i++){
	S+=pow(5+(2*i*pow(Msum[i], 2))/10, 3);
}
printf("%f \n",S);

free(Msum);
free(Matr);
return 0;
}
