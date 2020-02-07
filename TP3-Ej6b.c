#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Es_Natural(float *Num);
int Num_Aleatorio(int A, int B);
short Amistad(int A, int B);
short Num_Tipo(int Num);

int main(){
	float A, B, N;
	int I, Ban2=0, Ban=0, Num, Aux;
	srand(time(NULL));
	printf("\nIngrese un número natural cualquiera: ");
	scanf("%f", &N);
	Es_Natural(&N);
	printf("\nIngrese otros dos naturales para la generación aleatoria de números: ");
	printf("\nPrimer número: ");
	scanf("%f", &A);
	Es_Natural(&A);
	printf("\nSegundo número: ");
	scanf("%f", &B);
	Es_Natural(&B);
	while(A>=B){
		printf("\nNúmeros inválidos. Reintente: ");
		scanf("%f", &A);
		Es_Natural(&A);
		scanf("%f", &B);
		Es_Natural(&B);
	}
	for(I=1; I<=N; I++){
		Num=Num_Aleatorio(A, B);
		if(Ban==1){
			if(Num_Tipo(Num)!=1){
				if(Amistad(Num, Aux)==1){
					printf("\nNúmeros no Deficientes y Amigos: %d y %d ", Aux, Num);
					Ban2=1;
				}
				else{
					Aux=Num;
					Ban=0;
				}
			}
			else
			   Ban=0;
		}
		else{
			if(Num_Tipo(Num)!=1){
				Aux=Num;
				Ban=0;
			}
		}
	}
	if(Ban2==0)
		printf("\nNo hubo números que cumplieron la condición.");
	return 0;
}
	
void Es_Natural(float *Num){
	while((*Num)<=0 || (int)(*Num)!=(*Num)){
		printf("\nNúmero inválido. Reintente: ");
		scanf("%f", Num);
	}
}

int Num_Aleatorio(int A, int B){
	int X;
	X=rand()%(B-A+1)+A;
	return X;
}

short Amistad(int A, int B){
	int Div, Sum1=0, Sum2=0;
	short Res;
	Div=1;
	while(Div<=A/2){
		if(A%Div==0)
			Sum1=Sum1+Div;
		Div++;
	}
	if(Sum1==B){
		Div=1;
		while(Div<=B/2){
			if(B%Div==0)
				Sum2=Sum2+Div;
			Div++;
		}
	}
	else
		Res=0;
	if(Sum2==A)
		Res=1;
	else
		Res=0;
	return Res;
}

short Num_Tipo(int Num){
	int Div, Sum=0;
	short Res;
	Div=1;
	while(Div<=Num/2){
		if(Num%Div==0)
			Sum=Sum+Div;
		Div++;
	}
	if(Sum<Num)
		Res=1;
	else{
		if(Sum>Num)
			Res=2;
		else
			Res=3;
	}
	return Res;
}
