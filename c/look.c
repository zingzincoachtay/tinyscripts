#include<stdio.h>
#include<string.h>

char search(char voc[1000])
{
	int comp;
	char chk[100],def[10000];
	FILE *search;
	search = fopen("DIC2001.txt","r");
	
	do {
		//delete char in chk and def
		fscanf(search,"\n%s /// %s",chk,def);
		//check if nothing matches
		comp = strcmp(voc,chk);
	} while (comp!=0);
	
	fclose(search);
	return def;
}

void main()
{
	int i,k;
	char voc[1000][100],def[1000][10000];
	
	FILE *read,*write;
	read = fopen("voc_list.txt","r");
	
	i=0;
	do {
		fscanf(read,"%s /// \n",voc[i]);
		def[i] = search(voc[i]);
		i++;
	} while (feof(read)!=0);
	fclose(read);
	
	write = fopen("def_list.txt","a");
	
	for (k=0;k<=i;k++) {
		fprintf(write,"%s /// %s\n",voc[k],def[k]);
	}
	
	fclose(write);
}
