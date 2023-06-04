#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>


int insertionsort(int* x, int size, int (*compare)(int a, int b));
int ascending (int a, int b);
int descending (int a, int b);
void swap (int* num1, int* num2);


int main (){
    int x[] =   {548, 845, 731, 258, 809, 522, 73, 385, 906, 891, 988, 289, 808, 128};
    int size = sizeof(x)/sizeof(int);
    int y = insertionsort(x,size,ascending);
    printf("count = %d\n",y);
    for (int i = 0; i < size; i++) {
        printf("%d ", x[i]);
    }
    return 0;
}

int insertionsort(int* x, int size, int (*compare)(int a, int b)){
    int count = 0;
    for (int i = 1; i < size; i++) {
        int j = i;
        while(true){ 
            if(j>=1) count++;
            if(((*compare)(x[j],x[j-1]) == false) && j>0){ 
                swap(&x[j], &x[j - 1]);
                // Decrement j by 1
                j--;
            }
            else{
                break;
            }
        }
    }
    return count;
}

int ascending (int a, int b){
    // increasing
    if(a>b){ // if out of order return true
        return true;
    }
    else{
        return false;
    }
}

int descending (int a, int b){
    // decreasing
    if(a<b){ // if out of order return true
        return true;
    }
    else{
        return false;
    }
}

void swap (int* num1, int* num2){
    int temp; 
    temp = *num1; // *temp stores value of num1 (*num1) 
    *num1 = *num2; 
    *num2 = temp;
}


