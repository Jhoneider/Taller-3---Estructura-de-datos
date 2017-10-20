#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void menu();
void inicializar_pila(); //opcion que inicia una instancia, pero es inecesaria profe
void vaciar_pila(); //arrasa con los datos de la pila
void agregar_A_Pila(); //agrega un dao a la pila
void Quitar_De_pila(); //Quitar dato de pila

struct Nodo {
	int dato;
	Nodo *siguiente;
}*Pila=NULL;

int main(int argc, char *argv[]) {
	menu();
	return 0;
}

void menu(){
	int opc=0;
	
	do{
		system("cls");
		printf("PUNTO 5  TALLER 3 - EDII\n\n");
		printf("1. Inicilizar pila\n");
		printf("2. vaciar pila\n");
		printf("3. agregar dato a pila\n");
		printf("4. retirar dato de pila\n");
		printf("5. salir\n\n");
		
		printf("Elija una opcion : ");
		scanf("%d",&opc);
		
		switch(opc){
		case 1:
			inicializar_pila();
			break;
		case 2:
			vaciar_pila();
			break;
		case 3:
			agregar_A_Pila();
			break;
		case 4:
			Quitar_De_pila();
			break;
		case 5:
			printf("Adios\n");
			break;
		default:
			printf("No es una opcion valida.\n");
		}
		
		system("pause");
		
	} while(opc!=5);
}


void inicializar_pila(){
	Nodo *AuxPila = NULL;
	printf("\nPila inicializada correctamente.\n");
}
void vaciar_pila(){
	
	if(Pila==NULL){
		printf("\nla pila no contiene elementos.\n");
		return;
	}
	
	Nodo*Aux=Pila;
	while(Aux!=NULL){
		Pila=Aux->siguiente;
		free(Aux);
		Aux=Pila;
	}
	
	printf("\nPila borrada correctamente.\n");
}

void agregar_A_Pila(){
	Nodo*Nuevo = (Nodo*)malloc(sizeof(Nodo));
	if(Nuevo==NULL){
		printf("\nError. no se ha podido crear el nuevo dato, por favor intente de nuevo.\n");
	} else {
		printf("\n Ingrese el numero para agregar : ");
		int a;
		scanf("%d",&a);
		Nuevo->dato=a;
		Nuevo->siguiente=Pila;
		Pila=Nuevo;
		printf("Dato agregado correctamente. \n");
	}
	
}
void Quitar_De_pila(){
	
		if(Pila==NULL){
			printf("\nla pila no contiene elementos.\n");
			return;
		}
	
		Nodo*Aux=Pila;
		int dat = Aux->dato;
		Pila=Aux->siguiente;
		free(Aux);
		Aux=Pila;
		
		printf("\nEl dato %d , se ha quitado correctamente.\n",dat);
}
