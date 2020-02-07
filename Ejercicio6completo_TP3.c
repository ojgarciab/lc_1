/*Genera una lista de N nº aleatorios en el rango [A,B](A y B naturales),
mostrar aquellos que no son deficientes,
y a la vez, tengan un amigo en ese intervalo.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef int Vector[50];

void Determinar_Num_Natural(float *Num);
int Genera_Numeros(int A, int B);
void Ingresa_Numeros(float *N, float *A, float *B);
void Buscar_Deseados(Vector Lista, int M);

int main() {
	srand(time(NULL));
	Vector Lista;
	float N, A, B;
	int M, C, D;
	Ingresa_Numeros(&N, &A, &B);
	M=N;
	C=A;
	D=B;
	printf("\nNúmeros ingresados: %d, %d, %d.", M, C, D);
	int I;
	for (I=1; I<=M; I++)
		Lista[I]=Genera_Numeros(C, D);
	printf("\nLista Generada: ");
	for (I=1; I<=M; I++)
		printf("\n%d", Lista[I]);
	Buscar_Deseados(Lista, M);
	return 0;
}

void Determinar_Num_Natural(float *Num){
	scanf("%f", Num);
	while (*Num<=0 || *Num!=trunc(*Num)){
		printf("\nNúmero inválido. Intente de nuevo: ");
		scanf ("%f", Num);
	}
}
	
void Ingresa_Numeros(float *N, float *A, float *B){
	printf("\nIngrese la cantidad de datos a analizar: ");
	Determinar_Num_Natural(N);
	printf("\nIngrese un número natural: ");
	Determinar_Num_Natural(A);
	printf("\nIngrese otro número natural: ");
	Determinar_Num_Natural(B);
	while(*A>*B){
			printf ("\n\tDatos inválidos. Reingrese de nuevo los dos últimos números.\n");
			printf("\nIngrese un número natural: ");
			Determinar_Num_Natural(A);
			printf("\nIngrese otro número natural: ");
			Determinar_Num_Natural(B);
	}
}

int Genera_Numeros(int C, int D){
	int X;
	X=rand()%(D-C+1)+C;
	return X;
}

int Suma_Divisores(Vector Lista, int I){
	int Pd=2, Sum=1;
	while(Pd<=Lista[I]/2){
		if(Lista[I]%Pd==0) 
			Sum=Sum+Pd;
		Pd++;
	}
	return Sum;
}
int Naturaleza_Numero (Vector Lista, int I){
	int Num2=Suma_Divisores(Lista, I);
	if (Lista[I]==Num2) 
		return 1;
	else { 
		if (Lista[I]>Num2) 
			return 0;
		else 
			return 1;
	}
}

int Amistad(Vector Lista, int I, int J){
	int sumA=Suma_Divisores(Lista, I);
	int sumB=Suma_Divisores(Lista, J);
	if(sumA==Lista[J] && sumB==Lista[I]) return 1;
	else return 0;
}

void Buscar_Deseados(Vector Lista, int M){
	int I, H, B=1;
	for(I=1; I<=M; I++){
		H=Naturaleza_Numero(Lista, I);
		if (H){
			int J;
			for(J=I+1; J<=M; J++){
				int K=Amistad(Lista, I, J);
				if (K){
					printf("\nNúmero no Deficiente y Amigo de otro: %d", Lista[I]);
					B=0;
				}
			}
		}
	}
	if(B)
		printf("\nNo hay números que cumplan la condición.");
}
