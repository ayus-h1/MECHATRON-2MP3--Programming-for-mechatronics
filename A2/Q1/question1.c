#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

double mean(int* x, int size);
double median(int* x, int size);
int mode(int* x, int size);

int main () {
    int x[]  = {1,1,2,3,4};
    int size = 4;
    double mean1 = mean(x,5);
    double median1 = median(x,5);
    int mode1 = mode(x,5);
    printf("%lf\n",mean1);
    printf("%lf\n",median1);
    printf("%d",mode1);
    return 0;
}

double mean(int* x, int size){
    double sum = 0;
    for(int i=0;i<size;i++){
        sum = sum + x[i];
    };
    double mean = sum / size;
    return mean;    
};

double median(int* x, int size){
    double median;
    if (size%2 == 0){
        median = ((x[(size-1)/2]) + (x[(size)/2]))/2.0;
    }else{
        median = x[size/2];
    };
    return median;
}


int mode(int* x, int size){
    int max = 0;
    int maxNum = 0;
    for(int i=0;i<size;i++){
        int count = 0;
        for(int j=0;j<size;j++){
            if(x[j] == x[i]){
                count++;
            };
            if(count>max){
                max = count;
                maxNum = x[i];
            };
        };    
    };
    if(max == 1){
        return -1;
    };
    return maxNum;
}

