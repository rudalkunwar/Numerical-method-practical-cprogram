#include <stdio.h>
#include <math.h>
#define f(x) 1/(1+x*x)
int main(){
	float a,b,h,i;
	int n;
	float sum1=0,sum2=0,sum3=0,sum4;
	printf("Enter lower limit");
	scanf("%f",&a);
	printf("Enter upper limit");
	scanf("%f",&b);
	printf("Enter step");
	scanf("%d",&n);
	h=(b-a)/n;
	i=a;
	int y=1;
	while(i<=b)
	{
		if(i==a || i==b){
			sum1 += f(i);
		}
		else if(y%2==0){
			sum3 += f(i);
			y++;
		}
		else{
			sum2 += f(i);
			y++;
		}
		i=i+h;
		
	}
	sum4 = (h/3)*(sum1+4*sum2+2*sum3);
	printf("THE VALUE OF INTEGRATION IS :%f",sum4);
}
