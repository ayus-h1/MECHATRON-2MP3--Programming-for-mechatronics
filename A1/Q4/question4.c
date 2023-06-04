#include <stdio.h>
#include <assert.h>
#include <math.h>

float compoundInterest (float p, int a, int n);

int main () {
    float test1 =  compoundInterest(0.05, 20, 5);
    printf("%f\n", test1);

    float test2 =  compoundInterest(0.10, 910, 3);
    printf("%f\n", test2);

    float test3 =  compoundInterest(0.06, 800, 2);
    printf("%f\n", test3);
    return 0;
}

float compoundInterest (float p, int a, int n){
    float fvi = (pow((p + 1),n));
    float fv = a*fvi;
    return fv;
}

