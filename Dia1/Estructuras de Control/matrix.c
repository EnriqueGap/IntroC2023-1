/* matrix.c programa para calcular la multiplicación de matrices por escalares
*  Autor: Enrique Galicia
*  Fecha:
*  Uso: Ejecuta el programa, inicializa la matriz y proporciona un escalar, mostrará el resultado por pantalla
*/

#include<stdio.h>

int main(){
	//Matriz y escalar
	float A[5][5], escalar=1;
	//Indices para acceder a cada entrada de la matriz
	int i, j;

	//Mensaje de bienvenida
	printf("Este programa calcula la multipĺicación por escalares de una matriz\n");

	//Ciclo for para inicializar la matriz
	for(i=0; i<5; i++){
		for(j=0; j<5; j++){
			printf("\n Introduce un valor para la entrada (%d, %d) de la matriz:  ", i+1,j+1);
			scanf("%f",&A[i][j]);
		}
	}

	//Pedimos al usuario el valor del escalar
	printf("\n Introduce el escalar a multiplicar la matriz: ");
	scanf("%f", &escalar);

	//Ciclo for para acceder a cada entrada de la matriz y hacer la multiplicacion
	for(i=0; i<5; i++){
		for(j=0; j<5; j++){
			//Realizamos la multiplicación y la mostramos por pantalla
			A[i][j]=escalar*A[i][j];
			printf("%f\t",A[i][j]);
		}
		printf("\n");
	}
}
