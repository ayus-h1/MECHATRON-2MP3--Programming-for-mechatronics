#include <stdio.h>
#include <assert.h>
#include <math.h>


int bubblesort(int* x, int size);

int main () {
    int x[] = {548, 845, 731, 258, 809, 522, 73, 385, 906, 891, 988, 289, 808, 128};
    int swap1 = bubblesort(x,14);
    printf("%d\n",swap1);
    int y[] = {100};
    int swap2 = bubblesort(y,1);
    printf("%d",swap2);
    return 0;
}


int bubblesort(int* x, int size){
    //test
    int swaps = 0;
    int temp;
    for(int i=0;i<size;++i){
        for(int j=0; j<size-1;++j){
            if(x[j]>x[j+1]){
                temp = x[j+1];
                x[j+1] = x[j];
                x[j] = temp;
                swaps++;
            };
        };
    };
    return swaps;
};