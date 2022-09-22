/******************************************************************************
*  lagrange realiza una interpolación con datos leidos de otro archivo        *
*  Autor: Enrique Galicia						      *
*  Fecha:								      *
*  Uso: Ejecuta el programa, los calculos se guardarán en output.dat          *
*******************************************************************************/
#define N 9	//Dimensión del arreglo
#include<stdio.h>
//declaracion de funciones
void receiveData(float x[], float y[]);
float lagrangePolynomial(float punto, float x[], float y[], int index);
void lagrangeInterpolation(float x[], float y[], int puntos);

int main(){
	float x[N],y[N];			//Declaramos los arreglos
	receiveData(x,y);			//Recibimos los datos
	lagrangeInterpolation(x,y,500);		//Realizamos la interpolación
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
//Calcula el iésimo Polinomio de Lagrange en un punto
float lagrangePolynomial(float punto, float x[], float y[], int index)
{
	float producto=1;

	for(int i=0; i<N; i++){
		if(i!=index){
			//Calculamos el producto (x-xi)/(xj-xi)
			producto*=(punto-x[i])/(x[index]-x[i]);
		}
	}

	return producto*y[index]; //Multiplicamos por yi
}
//Realiza la interpolación y la escribe en un fichero
void lagrangeInterpolation(float x[], float y[], int puntos)
{
	FILE *inter;					//Declaración del fichero
	inter=fopen("lagrange.dat", "w");		//Apertura del fichero
	//Variables para la malla y el valor a interpolar
	float xi, xf, xactual, valor, tpaso;
	xi=x[0], xf=x[N-1], tpaso=(xf-xi)/puntos;

	//Calculo de la interpolación
	for(int i=0; i<puntos; i++){
		//Calculamos x
		xactual=xi+i*tpaso;
		valor=0;
		for(int j=0; j<N; j++){
			//Sumamos los valores de Pj(x) para cada j
			valor+=lagrangePolynomial(xactual,x,y,j);
		}
		//Escribimos en el fichero
		fprintf(inter,"%f\t%f\n",xactual, valor);
	}

	fclose(inter);					//Cierra del fichero
}
