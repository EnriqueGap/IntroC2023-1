/******************************************************************************
*  derivada calcula el valor de una función y su derivada en una malla        *
*  Autor: Enrique Galicia						      *
*  Fecha:								      *
*  Uso: Ejecuta el programa, se escribirá un archivo con los datos calculados *
*******************************************************************************/
#define PI acos(-1)
#define NMAX 500
#include<stdio.h>
#include<math.h>

//declaración de funciones
float f(float x);
float derivadaCentral(float punto, float stepsize);

FILE *data;		//Declaración del fichero

int main(){

	data=fopen("output.dat", "w");
	/*Variables para los puntos en la malla,
	el valor de la funcion y la derivada */
	float x, xi=0, xf=2*PI, tpaso, y, yprima;
	tpaso=(xf-xi)/NMAX;
	
	//Calculamos los puntos de la función y su derivada
	for(int i=0; i<NMAX; i++){
		x=(xi+i*tpaso);
		y=f(x);
		yprima=derivadaCentral(x,tpaso);
		fprintf(data,"%f\t%f\t%f\n",x,y,yprima);
	}
	fclose(data);
}
//Derivada numérica "Central Differences"
float derivadaCentral(float punto, float stepsize)
{
	float forward, backward;
	forward=f(punto+stepsize), backward=f(punto-stepsize);
	return (forward-backward)/(2*stepsize);
}
//Funcion a derivar
float f(float x)
{
	return sin(x);
}
