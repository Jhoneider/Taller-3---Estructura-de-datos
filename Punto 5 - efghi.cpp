#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

void menu();
void elevar_listas();
void agregar_A_Pilas();
void mostrar_Listas();
void sumar_listas();
void dividir_listas();
void copiar_listas();

struct Nodo {
	int dato;
	Nodo *siguiente;
}*Pila1=NULL,*Pila2=NULL;

int main(int argc, char *argv[]) {
	menu();
	return 0;
}

void menu(){
	int opc=0;
	
	do{
		system("cls");
		printf("PUNTO 5  TALLER 3 - EDII\n\n");
		printf("1. Agregar datos a las listas\n");
		printf("2. mostrar las listas\n");
		printf("3. sumar las listas\n");
		printf("4. dividir las listas\n");
		printf("5. elevar lista a la potencia de la otra\n");
		printf("6. copiar lista en la otra\n");
		printf("7. salir\n\n");
		
		printf("Elija una opcion : ");
		scanf("%d",&opc);
		
		switch(opc){
		case 1:
			agregar_A_Pilas();
			break;
		case 2:
			mostrar_Listas();
			break;
		case 3:
			sumar_listas();
			break;
		case 4:
			dividir_listas();
			break;
		case 5:
			elevar_listas();
			break;
		case 6:
			copiar_listas();
			break;
		case 7 :
			printf("Adios\n");
			break;
			
		default:
			printf("No es una opcion valida.\n");
		}
		
		system("pause");
		
	} while(opc!=7);
}


void agregar_A_Pilas(){
	Nodo*Nuevo = (Nodo*)malloc(sizeof(Nodo));
	if(Nuevo==NULL){
		printf("\nError. no se ha podido crear el nuevo dato, por favor intente de nuevo.\n");
	} else {
		printf("\n Ingrese el numero para agregar a la lista 1 : ");
		int a;
		scanf("%d",&a);
		Nuevo->dato=a;
		Nuevo->siguiente=Pila1;
		Pila1=Nuevo;
		printf("Dato agregado correctamente. \n");
	}
	
	Nodo*Nuevo2 = (Nodo*)malloc(sizeof(Nodo));
	if(Nuevo2==NULL){
		printf("\nError. no se ha podido crear el nuevo dato, por favor intente de nuevo.\n");
	} else {
		printf("\n Ingrese el numero para agregar a la lista 2 : ");
		int a;
		scanf("%d",&a);
		Nuevo2->dato=a;
		Nuevo2->siguiente=Pila2;
		Pila2=Nuevo2;
		printf("Dato agregado correctamente. \n");
	}
}

void mostrar_Listas(){
	printf("\n**Lista 1**\n\n");
	Nodo*Aux1=Pila1;
	while(Aux1!=NULL){
		printf("%d\n",Aux1->dato);
		Aux1=Aux1->siguiente;
	}
	
	printf("\n\n**Lista 2**\n\n");
	Nodo*Aux2=Pila2;
	while(Aux2!=NULL){
		printf("%d\n",Aux2->dato);
		Aux2=Aux2->siguiente;
	}
}

void sumar_listas(){
	printf("\n\n**Sumatoria de las 2 listas**\n\n");
	Nodo*Aux2=Pila2;
	Nodo*Aux1=Pila1;
	while(Aux2!=NULL){
		int sum = Aux1->dato + Aux2->dato;
		printf("%d\n",sum);
		Aux2=Aux2->siguiente;
		Aux1=Aux1->siguiente;
	}
}

void dividir_listas(){
	printf("\n\n**division de las 2 listas**\n\n");
	Nodo*Aux2=Pila2;
	Nodo*Aux1=Pila1;
	while(Aux2!=NULL){
		int div = Aux1->dato / Aux2->dato;
		printf("%d\n",div);
		Aux2=Aux2->siguiente;
		Aux1=Aux1->siguiente;
	}
}

void copiar_listas(){
	printf("\n\n**copiar listas**\n\n");
	Nodo*Aux2=Pila2;
	Nodo*Aux1=Pila1;
	while(Aux2!=NULL){
		int div = Aux1->dato;
		Aux1->dato=Aux2->dato;
		Aux2->dato=div;
		Aux2=Aux2->siguiente;
		Aux1=Aux1->siguiente;
	}
	printf("\nLa lista 1 se ha copiado a la 2, y la 2 a la 1 correctamente.\n");
}


void elevar_listas(){
	printf("\n\n**elevar lista 1 a la lista 2**\n\n");
	Nodo*Aux2=Pila2;
	Nodo*Aux1=Pila1;
	while(Aux2!=NULL){
		float div = pow(Aux1->dato,Aux2->dato);
		printf("%f\n",div);
		Aux2=Aux2->siguiente;
		Aux1=Aux1->siguiente;
	}
}
