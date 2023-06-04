#include <stdio.h>
#include <assert.h>
#include <math.h>


int binsearch(int* x, int y, int size);

int main () {
    int x[] = {100};
    int y = 100;
    int size = sizeof(x)/sizeof(x[0]);
    int bin = binsearch(x,y,size);
    printf("%d",bin);
    return 0;
}

// y : ele to be searched, x : arr
int binsearch(int* x, int y, int size){
    int count=0;
    int a=0,b=size-1;
    while(a<=b){
        int m = (a+b)/2;
        if(x[m] == y){
            count++;
            return count;
        }
        else if(x[m]<y){
            count++;
            a=m+1; // first element right array
        }
        else if(x[m]>y){
            count++;
            b=m-1; //last element of left array
        }
    }
    return -1;
}