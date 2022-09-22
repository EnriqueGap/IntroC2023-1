/******************************************************************************
*  entrada imprime por terminal los datos leidos de otro archivo              *
*  Autor: Enrique Galicia						      *
*  Fecha:								      *
*  Uso: Ejecuta el programa, se mostrarán por terminal los datos de input.dat *
*******************************************************************************/
#include<stdio.h>
//declaracion de funciuones
void receiveData(float x[], float y[]);
void printData(float x[], float y[]);

int main(){
	float x[9],y[9];
	receiveData(x,y);
	printData(x,y);
}
//Lee los datos de otro archivo
void receiveData(float x[], float y[])
{
	FILE *data;					//Declaración del fichero
	int i=0;
	data=fopen("../Math-Ficheros/input.dat", "r");	//Apertura del fichero data
	while (feof(data)==0){
		fscanf(data,"%f\t%f\n",&x[i],&y[i]);
		i++;
	}
	fclose(data);					//Cierre del fichero	
}
//Imprime por terminal lo guardado en x,y
void printData(float x[], float y[])
{
	for(int i=0; i<9; i++){
		printf("%f\t%f\n",x[i],y[i]);
	}	
}
