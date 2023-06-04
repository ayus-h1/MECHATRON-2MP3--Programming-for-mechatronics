#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

/*
Write a function in C which implements the shellsort algorithm.
 The recommended approach is to create an array of sub arrays 
 using dynamic memory allocation, sort those sub-arrays, and replace them
in the array. This is achievable through the use of double pointers.
*/

int shellsort (int *array, int size, int *h_gaps, int (*subsort)(int* array, int size));
int bubblesort(int* x, int size);

//array[i][j] = *(*(array+i)+j)
int shellsort (int *array, int size, int *h_gaps, int (*subsort)(int* array, int size)){
    //for loop for hvalues
    int hsize = sizeof(h_gaps)/sizeof(h_gaps[0]);
    for(int h=0; h<hsize; h++){ // looping h values for the h_gaps
        int size2 = size/h_gaps[h];
        int arr[size2]; // subarray
        int temp[size];
        int *array2= (int*)malloc(sizeof(int)*size2);
        int idx=0;
            for(int j=0;j<size;j+=h_gaps[h]){
                array2[idx] = array[j];
                temp[idx]=j;
                idx++;
            }
            int swaps = (*subsort)(array2,idx);
            for (int i = 0; i < size2; i++)
            {
                array[temp[idx]] = array2[idx];
            }
            


        }
    return 0;
}



int bubblesort(int* x, int size) {
    int temp;
    int swaps = 0;
    for (int i = 0; i < size; i ++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (x[j] > x[j+1]) {
                temp = x[j];
                x[j] = x[j + 1];
                x[j+1] = temp;
                swaps ++;
            }
        }
    }
    return swaps;
}


int main () {
    int array[] = {44, 79, 8, 53, 93, 21, 70, 79, 82, 49, 25, 2, 62, 26, 29, 54, 89, 57, 74, 39};
    int size = sizeof(array)/sizeof(array[0]);
    int h_gaps = {10, 4, 1};
    shellsort(array,size,h_gaps,bubblesort);
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}


    // int h = 0;
    // int h_gap = 0;
    // int sizeh = sizeof(h_gaps)/sizeof(h_gaps[0]);
    // for(int index = 0; index < size; index++){
    // for(int i = 0; i<sizeh ;i++) 
    //     h_gap = h_gaps[i];
    //     int array_2_size = size/h_gap;
    //     int *array_2 = (int*)malloc(array_2_size*sizeof(int));
    //     for (int j = 0; j < size ; j++) { // h_gaps 
    //         for (int k=j; k<size; k+=h+gap+1){
    //             array_2[index]=array[k];
    //             for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
    //                 array[j] = array[j - interval];
    //             }
    //         array[j] = temp;
    //         }
    //     }
    
    //    int hsize = sizeof(h_gaps)/sizeof(h_gaps[0]);
    // int gapcounter=0;
    // while(h_gaps[gapcounter]!=1){
    //     int s=0; //subarray counter 
    //     int hval = h_gaps[gapcounter];
    //     for(int j=0; j<size; j++){
    //             int subarray[j] = (int*)malloc(hval*sizeof(int));
    //         for(int i=0;i<size; i+=hval){
    //             int (*subarray)[s] = (int**)malloc((i+1)*sizeof(int*));
    //             int (*subarray)[s] = *(subarray+i);            
    //             s++;
    //         }
    //     }
    //     gapcounter++;
    // }

