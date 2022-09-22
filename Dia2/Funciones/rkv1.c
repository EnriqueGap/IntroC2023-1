#define NMAX 60
#include<stdio.h>
#include<math.h>
float  f(float x, float y);
float rk4( float x, float y, float step);

FILE *data;

int main(){
	data=fopen("rk_yp.dat", "w");
	float aux, x, xi=0,xf=6, y, tpaso;
	//Tamaño de paso
	tpaso=(xf-xi)/NMAX;
	//Condiciones iniciales
	y=exp(-1);
	fprintf(data,"%f\t%f\n",xi,y);
		
	for(int i=0; i<NMAX; i++){
		x=xi+i*tpaso;
		y=rk4(x,y,tpaso);
		aux=x+tpaso;
		fprintf(data,"%f\t%f\n",aux,y);
	}
	
	fclose(data);
}

//Sistema de Ecuaciones a Resolver
float  f(float x, float y)
{
    return y*sin(x);
}
//Métodos Runge Kutta
float rk4( float x, float y, float step)
{
	float h=0.5*step,	
		t1, t2, t3,		//Auxiliares para calcular k2,k3 y k4
		k1, k2, k3,k4;	//Variables del Rk4

	t1 = y+0.5*(k1=step*f(x, y));
	t2 = y+0.5*(k2=step*f(x+h, t1));
	t3 = y+(k3=step*f(x+h, t2));
	k4 = step*f(x+step, t3);
	
	return y+(k1+2*k2+2*k3+k4)/6.0;
}
