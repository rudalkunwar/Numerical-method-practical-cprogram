#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define f(x) 1/(1+x*x)
int main(){
	float a,b,h,i;
	int n,y=1;
	float sum1,sum2,sum3,sum4;
	printf("Enter lower limit");
	scanf("%f",&a);
	printf("Enter upper limit");
	scanf("%f",&b);
	printf("Enter step");
	scanf("%d",&n);
	h=(b-a)/n;
	i=a;
	while(i<=b)
	{
		if(i==a || i==b)
		{
			sum1 += f(i);
		}
		else if(y%3==0){
			sum2 += f(i);
			y++;
		}
		else
		{
			sum3  += f(i);
			y++;
		}
		i=i+h;
	}
	sum4 = (3*h/8)*(sum1+2*sum2+3*sum3);
	printf("THE VALUE OF INTEGRATION IS :%f",sum4);
}
