/*****************************************************************************************************
*  fibonacci calcula los primeros n términos de la serie de Fibonacci e imprime los impares	      *
*  Autor: Enrique Galicia									      *
*  Fecha:											      *
*  Uso: Ejecuta el programa e ingresa por terminal  el número de términos que quieres que se impriman *
*******************************************************************************************************/
#include<stdio.h>

int main(){
	//Variables para indicar los términos de la serie finales, actuales, iniciales
	int termino=10, fibonacci, f0, f1;
	//Primeros dos términos de la serie de fibonacci
	f0=0;
	f1=1;
	printf("(%d)\n",f0);
	printf("%d\n",f1);
	//Bucle para calcular los siguientes:
	for(int i=2; i<=termino; i++){
		fibonacci=f0+f1;
		//Verificar si el termino es impar e imprimirlo
		if(fibonacci%2==1){
			printf("%d\n", fibonacci);
		}else{
			printf("(%d)\n", fibonacci);
		}
		//Actualizamos términos
		f0=f1;
		f1=fibonacci;
	}
}
