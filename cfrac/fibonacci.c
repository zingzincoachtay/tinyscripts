#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main(){
	int k,n,fib[3]={0,1,0};
	double gs[2];
	
	printf("n of Fibonacci numbers\nn=");
	scanf("%d",&n);
	
	for(k=1;k<=n;k++){
		printf("%d",fib[2]);
		fib[0]=fib[1];
		fib[1]=fib[2];
		fib[2]=fib[0]+fib[1];
		if(k<n){printf(",");}
	}
	//gs[0]=fib[2]/fib[1]; gs[1]=fib[1]/fib[2];
	//printf("\nGolden Section = %.16f, %.16f",gs[0],gs[1]);
	printf("\n\n");
	system("pause");
}
