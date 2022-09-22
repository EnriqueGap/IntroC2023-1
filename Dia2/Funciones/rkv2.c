#define POS 0
#define VEL 1
#define N 2
#define NMAX 60
#include<stdio.h>
#include<math.h>
float  f(float x, float y[], int i);
void rk4( float x, float y[], float step);

FILE *data;

int main(){
	
	data=fopen("rk_ypp.dat", "w");
	
	//Vector solucion
	float y[N];
	//caracteristicas de la malla
	float aux, x, xi=0,xf=30, tpaso;
	tpaso=(xf-xi)/NMAX;
	
	//Condiciones iniciales
	y[POS]=10, y[VEL]=0;
	fprintf(data,"%f\t%f\t%f\n",xi,y[POS],y[VEL]);	
	
	for(int i=0; i<NMAX; i++){
		x=xi+i*tpaso;
		rk4(x,y,tpaso);
		aux=x+tpaso;
		fprintf(data,"%f\t%f\t%f\n",aux,y[POS],y[VEL]);
	}	
	
	fclose(data);
	
}

//Sistema de Ecuaciones a Resolver
//MAS amortiguado
float  f(float x, float y[], int i)
{
    float m=1, k=1, gamma=0.9;
    
    if (i==POS) 		return(y[VEL]); 			//dx/dt
    if (i==VEL) 		return( (-k*y[POS]-gamma*y[VEL])/m);	//dv/dt
}
//Métodos Runge Kutta
void rk4( float x, float y[], float step)
{
	int i;
	float h=0.5*step,	
		t1[N], t2[N], t3[N],		//Auxiliares para calcular k2,k3 y k4
		k1[N], k2[N], k3[N],k4[N];	//Variables del Rk4

	for (i=0;i<N;i++) t1[i] = y[i]+0.5*(k1[i]=step*f(x, y, i));
	for (i=0;i<N;i++) t2[i] = y[i]+0.5*(k2[i]=step*f(x+h, t1, i));
	for (i=0;i<N;i++) t3[i] = y[i]+    (k3[i]=step*f(x+h, t2, i));
	for (i=0;i<N;i++) k4[i] =		step*f(x+step, t3, i);
	
	for (i=0;i<N;i++) y[i]+=(k1[i]+2*k2[i]+2*k3[i]+k4[i])/6.0;
}
