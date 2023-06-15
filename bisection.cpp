#include <stdio.h>
#include <math.h>
#define f(x) x*x*x-2*x-5
#define e 0.0001
int main(){
	float a,b,c,fa,fb,fc;
	int i=0,n;
	printf("Enter the initial interval\n");
	scanf("%f %f",&a,&b);
	printf("\nEnter No of Iteration\n");
	scanf("%d",&n);
	printf("\n\t\t****--BISECTION METHOD--****");
	printf("\nIteration \tInterval \tMidpoint \tf(a) \t\tf(b) \t\tValue at Midpoint\n");
	do{
		c = (a+b)/2;
		fc = f(c);
		fa = f(a);
		fb =f(b);
		printf("\n%d \t(%f,%f) \t%f \t%f \t%f \t%f\n",i,a,b,c,fa,fb,fc);
		if(fa*fc>0){
			a=c;
		}
		else{
			b=c;
		}
		i++;
	}while(fabs(fc)>e && i<=n);
}
