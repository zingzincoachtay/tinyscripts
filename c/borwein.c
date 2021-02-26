#include<stdio.h>
#include<math.h>

int main(void)
{
	int i,n;
	double a,a_old,b,b_old,p;

	printf("How many times?\t");
	scanf("%d",&n);
	a_old=sqrt(2);
	b_old=0;
	p=sqrt(2)+2;
	for(i=1;i<=n;i++){
		a=.5*(sqrt(a_old)+1/sqrt(a_old));
		b=(sqrt(a_old)*(1+b_old))/(a_old+b_old);
		p=p*b*(1+a)/(1+b);
	}
	printf("pai=%.16f",p);
	return 0;
}
