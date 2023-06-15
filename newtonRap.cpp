#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define f(x) x*x-3*x+2
#define g(x) 2*x-3
#define e 0.001
int main(){
	float x0,x1,fx0,fx1,gx0;
	printf("Enter Initial Guess");
	scanf("%f",&x0);
	int i=1;
	printf("\n iteration \tRoot \tvalue of f(x)");
	do{
		fx0 = f(x0);
		gx0 = g(x0);
		x1 = x0 - (fx0/gx0);
		fx1 = f(x1);
		x0=x1;
		printf("\n %d \t%f \t%f ",i,x1,fx1);
		i++;
	}while(fabs(fx1)>e);
}
