#include<stdio.h>
#include<stdlib.h>

void main(){
	int n,d,num,den,rem,prev;
	printf("gcd(N,D)\nN=");
	scanf("%d",&n);
	printf("D=");
	scanf("%d",&d);
	
	num=n; den=d; rem=1;
	while(rem!=0){
		prev=rem;
		rem=num % den;
		num=den;
		den=rem;
	}
	printf("The Greatest Common Divisor gcd(%d,%d)=%d\n",n,d,prev);
	printf("The Simplest form of %d / %d is \n",n,d);
	printf("%d / %d\n",n/prev,d/prev);
	
	system("pause");
}
