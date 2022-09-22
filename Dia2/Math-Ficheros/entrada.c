/******************************************************************************
*  entrada imprime por terminal los datos leidos de otro archivo              *
*  Autor: Enrique Galicia						      *
*  Fecha:								      *
*  Uso: Ejecuta el programa, se mostrarán por terminal los datos de input.dat *
*******************************************************************************/
#include<stdio.h>
FILE *data;		//Declaración del fichero

int main(){
	data=fopen("input.dat", "r");	//Apertura del fichero data
	if(data==NULL){
		printf("ERROR en la lectura de los datos\n");
		return 1;
	}else{
	
		float x,y;
		//Leemos el archivo mientras haya datos qué leer
		while (feof(data)==0){
			fscanf(data,"%f\t%f\n",&x,&y);
			printf("%f\t%f\n",x,y);
		}
		fclose(data);			//Cierre del fichero
	}
}
