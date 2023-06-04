#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

/*Write a function "removeDups" that removes all
duplicates in a given array of type "int".

More specifically, the algorithm should only keep 
the first occurrence of each element in the array, in the
order they appear. In order to keep the array 
at the same length, we will replace the removed elements
with zeros, and move them to the end of the array.
*/

//for brute force 
//look at first element, see if thats there in other part of list
//replace them with zero 
//move the zero to end
//go to next element and repeat 

void removeDups(int* in, int size);

int main () {
    int in[] = {1,2,2,2,3,3,4,2,4,5,6,6};
    int size = sizeof(in)/sizeof(in[0]);
    removeDups(in,size); 
    return 0;
}

void removeDups(int* in, int size){
    int count=0;

    for(int i=0; i<size; i++){  // make all the duplicates zeros
        for(int j=i+1; j<size-1; j++){
            if(in[j] == in[i]){
                in[j] = 0;
            }
        }
    }

    for(int i=0; i<size; i++){ //move non zeros to front 
        if(in[i] != 0){
            in[count] = in[i];
            count++;
        }    
    }

    while(count<size){ // make all elements after non zeros in front zeros
        in[count] = 0;
        count++;
    }

    for(int i=0;i<size;i++){ //print the array
        printf("%d ", in[i]);
    }

}
