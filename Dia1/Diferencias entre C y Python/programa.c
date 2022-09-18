#include<stdio.h>

int main()
{
	int a;
	float x;
	double y=3.141592653589;
	
	for(int i=0; i<10; i++)
	{
		a=i;
		if(a==5)
		{
			printf("\nEstamos en el paso No. 5\n");
			x=a*i;
		}
	}
}
