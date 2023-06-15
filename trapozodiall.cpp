#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define f(x) x*x/(1+x*x*x)
int main(){
	float a,b,h,i;
	int n;
	float sum1=0,sum2=0,sum3;
	printf("Enter lower limit");
	scanf("%f",&a);
	printf("Enter upper limit");
	scanf("%f",&b);
	printf("Enter step");
	scanf("%d",&n);
	h=(b-a)/n;
	i=a;
	while(i<=b){
		if(i==a || i==b)
		{
			sum1 += f(i);
		}else{
			sum2 +=2 *f(i);
		}
		i=i+h;
	}
	sum3 = (h/2)*(sum1+sum2);
	printf("THE VALUE OF INTEGRATION IS :%f",sum3);
}
