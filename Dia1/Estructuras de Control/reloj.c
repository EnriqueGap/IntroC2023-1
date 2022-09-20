/****************************************************************************************
* reloj. Programa que verifica el formato de tiempo  ingresado				*
* Autor: Enrique Galicia 								*
* Fecha:										*
* Uso: Ejecuta el programa, ingresa los minutos y segundos y espera el resultado	*
*****************************************************************************************/
#include<stdio.h>

int main(){
	//Variables para horas, minutos y segundos
	int h, min, seg;
	
	//Pedimos al usuario que ingrese los valores
	printf("Introduce las horas: ");
	scanf("%d",&h);
	printf("Introduce los minutos: ");
	scanf("%d",&min);
	printf("Introduce los segundos: ");
	scanf("%d",&seg);
	
	//Verificación del formato
	if(h<=23 && min<=59 && seg<=59){
		printf("El formato es correcto\n");
		printf("%d:%d:%d",h,min,seg);
	}else{
		printf("El formato es incorrecto :(\n");
	}
}

