#include <stdio.h>
#include <assert.h>
#include <math.h>

int FactorialWhile (int n);
int FactorialDoWhile (int n);

int main () {
    int test1 = FactorialWhile (3);
    printf("test1: %u\n", test1);

    int test1d = FactorialDoWhile (3);
    printf("test1d: %u\n",test1d);

    int test2 = FactorialWhile (0);
    printf("test2: %u\n", test2);

    int test2d = FactorialDoWhile (0);
    printf("test2d: %u\n",test2d);

    int test3 = FactorialWhile (10);
    printf("test3: %u\n", test3);

    int test3d = FactorialDoWhile (10);
    printf("test3d: %u\n",test3d);
 
};

int FactorialWhile (int n){
    int i=1,factorial=1;
    while(i<=n){
        if (n == 0 || n == 1){
            return 1;
        };     
        factorial=factorial*i;
        i++;
    };
    return factorial;
};

int FactorialDoWhile (int n){
    int i=1,factorial=1;
    do{
        if (n == 0 || n == 1){
            return 1;
        };
        factorial=factorial*i;
        i++;

    }
    while(n >= i);
    return factorial;
};

