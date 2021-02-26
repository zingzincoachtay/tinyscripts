#include<stdio.h>
#include<stdlib.h>

char strA[80] = "A string to be used for demonstration purposes";
char strB[80] = "12345678901234567890123456789012345678901234567890";

int countletters(char *str){
  int k = 0;
  while( *str!='\0' ){
    k++; *str++;
  }
  return k;
}

int main(){//argv,argc
  int k01 = 0;

printf("%d\n", k01 );

  int k02[] = {0,23,17,-4,5,100};
  int *ptr;
  ptr = k02;
  
int i01;
for(i01 = 0; i01 < 6; i01++){
  printf("k02[%d] = %d\t",i01,k02[i01]);
  //printf("ptr + %d = %d\n",i01,*(ptr+i01));
  printf("++ptr = %d\n",*(++ptr));
  //printf("ptr++ = %d\n",*ptr++);
}

printf("%d letters in strA.\n", countletters(strA) );
printf("%d letters in strB.\n", countletters(strB) );

char *pA;
char *pB;
puts(strA);
pA = strA;
puts(pA);
pB = strB;
putchar('\n');
while( *pA!='\0'){
  *pB++ = *pA++;
}
*pB = '\0';
puts(strB);

  return 0;
}
