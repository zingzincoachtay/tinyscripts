#include<stdio.h>
#include<stdlib.h>

int main(void){
  // integer
  int N = 10,prod = 1,i;
  // integer pointer
  int *iptr, *tmp, *tmp1, *tmp2;
  // allocate memory
  iptr = (int *) malloc (N * N * sizeof(int));
  // check if memory is properly allocated
  if(iptr==NULL){
    printf("Unable to allocate memory. Program terminated.\n");
    return -1;
  }
  // integers
  for(i=0,tmp=iptr; i<N*N; i++,tmp++){
    // compute the product
    *tmp = i+1;
    if( (*tmp%10)==0 ){  printf("Entered: %d\n",*tmp);}
  }
  *iptr = 0;
  for(i=1,tmp1=iptr; i<N*N; i++,tmp1++){
    if( *tmp==0 ){next;}
    else{
      while( tmp2=iptr )
      if( (*tmp%))
    }
  }
  // display result
  printf("Sum: %d\n",prod);
  // free memory allocation
  free(iptr);

  return 0;
}
