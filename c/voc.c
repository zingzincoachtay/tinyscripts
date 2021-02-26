#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	int num,chk;
	char fname[20],filename[25],voc[31];
	
	FILE *voclist;
	
	system("cls");
	printf("type file name : ");
	gets(fname);
	
	strcat(fname,".txt");
	
	voclist = fopen(fname,"a");
	//'continue' mode
	if (voclist == NULL) {
		printf ("Can't open the file %s \n",filename);
	}
	
	num=0;
	do {
		num++;
		switch (num) {
			case 1:
				printf("type %dst vocabulary : ",num);
			break;
			case 2:
				printf("type %dnd vocabulary : ",num);
			break;
			case 3:
				printf("type %drd vocabulary : ",num);
			break;
			default:
				printf("type %dth vocabulary : ",num);
		}
		gets(voc);
		chk=strcmp("eol",voc);
		if (chk!=0) {
			fprintf(voclist,"%s /// \n",voc);
		}
		if ((num%20)==0) { system("cls"); }
	} while (chk!=0);
	
	fclose(voclist);
	
	printf("Today's vocabulary stocks are %d words.\n",num-1);
	
	system("pause");
}