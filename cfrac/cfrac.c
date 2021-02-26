#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i;
	double x,y,b;
	
	x=y=b=1;
	for(i=0;i<100;i++){
		y=b/(x+y);
		if(i%5==0){
			printf("%.16f\t%.16f\n",1/y,y);
			}
	}
	
	printf("\n");
	system("pause");
}

