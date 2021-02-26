#include<stdio.h>
#include<math.h>

int main()
{
	int i,n;
	double a,a_old,b,b_old,s,t;
	
	printf("How many times?");
	scanf("%d",n);
	a_old=sqrt(2)*.5;
	b_old=s=1;
	t=4;
	for(i=1;i<=n;i++){
		a=sqrt(a_old*b_old);
		b=(a_old+b_old)*.5;
		s=s-t*(b-b_old)*(b-b_old);
		t=2*t;
		a_old=a;
		b_old=b;
	}
	printf("pai=%.16f",(a+b)*(a+b)/s);
	return 0;
}