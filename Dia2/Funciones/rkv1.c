#define NMAX 60
#include<stdio.h>
#include<math.h>
float  f(float x, float y);
float rk2( float x, float y, float step);
float rk3( float x, float y, float step);
float rk4( float x, float y, float step);

FILE *data;

int main(){
	data=fopen("rkmethods.dat", "w");
	float y2, y3, y4;
	float aux, x, xi=0,xf=6, tpaso;
	//Tamaño de paso
	tpaso=(xf-xi)/NMAX;
	//Condiciones iniciales
	y2=y3=y4=exp(-1);
	fprintf(data,"%f\t%f\t%f\t%f\n",xi,y2,y3,y4);
		
	for(int i=0; i<NMAX; i++){
		x=xi+i*tpaso;
		y2=rk2(x,y2,tpaso);
		y3=rk3(x,y2,tpaso);
		y4=rk4(x,y2,tpaso);
		aux=x+tpaso;
		fprintf(data,"%f\t%f\t%f\t%f\n",aux,y2,y3,y4);
	}
	
	fclose(data);
}

//Sistema de Ecuaciones a Resolver
float  f(float x, float y)
{
    return y*sin(x);
}
//Métodos Runge Kutta
float rk2( float x, float y, float step)
{
	float h=0.5*step,	
		t1,				//Auxiliares para calcular k2
		k1, k2;				//Variables del Rk2

	t1 = y+0.5*(k1=step*f(x, y));
	k2 = step*f(x+h, t1);

	return y+k2;
}

float rk3( float x, float y, float step)
{
	float h=0.5*step,	
		t1, t2,			//Auxiliares para calcular k2 y k3
		k1, k2, k3;		//Variables del Rk3

	t1 = y+0.5*(k1=step*f(x, y));
	k2 = step*f(x+h, t1);
	t2=y-k1+2*k2;
	k3=step*f(x+step, t2);

	return y+(k1+4*k2+k3)/6.0;
}

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
