#include <stdio.h>
#include <assert.h>
#include <math.h>


int insertionsort(int* x, int size);

int main() {
  int x[] = {100};
  int examinations = insertionsort(x,1);
  printf("\ncounts = %d",examinations);
};


int insertionsort(int* x, int size){ 
//i is unsorted part
//j is sorted part (j=i-1)
  int count = 0;
  for(int i=1;i<size;i++){
    int temp = x[i]; // first ele of the unsorted part
    int j = i-1; //index for the bgst/last ele of the sorted part
    while(0==0){ 
      if(j>=0) count++;
      if(x[j]>temp && j>=0){
        x[j+1] = x[j];
        j--;
      }
      else{
        x[j+1]=temp;
        break;
      }
    }
  }
  return count;
}