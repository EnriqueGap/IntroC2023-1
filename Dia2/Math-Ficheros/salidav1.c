/***************************************************************************************************
*  salida guarda en un archivo los calculos de seno y coseno de 0 a 3pi en una malla de 500 puntos *
*  Autor: Enrique Galicia									   *
*  Fecha:											   *
*  Uso: Ejecuta el programa, se creará el archivo output.dat con los cálculos realizados           *
****************************************************************************************************/
#define PI acos(-1)	//Macro para la constante pi
#include<stdio.h>	//Librerías a utilizar
#include<math.h>

FILE *data;		//Declaración del fichero

int main(){
	data=fopen("output.dat", "w");	//Apertura del fichero data
		
	int i, max=500;
	float xi=0, xf=3, tpaso=(xf-xi)/max, x, y1, y2;

	for(i=0; i<max; i++){
		//Calculamos la posición en la malla
		x=PI*(xi+tpaso*i);
		//Calculamos y1, y2
		y1=sin(x);
		y2=cos(x);
		//Escribimos en output.dat (i, x, y1, y2)
		fprintf(data,"%i\t%f\t%f\t%f\n",i,x,y1,y2);
	}
	fclose(data);			//Cierre del fichero
}
