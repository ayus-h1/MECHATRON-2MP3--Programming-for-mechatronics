#include <stdio.h>
#include <assert.h>
#include <math.h>

float onethird (int n);

int main () {
    float test1 = onethird (1);
    printf("test1 :%lf\n", test1);
    float test2 = onethird (10);
    printf("test2 :%lf\n", test2);
    float test3 = onethird (37);
    printf("test3 :%lf\n", test3);
};

float onethird (int n){
    float sum = 0;
    for(int i = 1; i<=n ; i++){
        sum = sum + (i*i);
    };
    return sum/pow(n,3);
}

