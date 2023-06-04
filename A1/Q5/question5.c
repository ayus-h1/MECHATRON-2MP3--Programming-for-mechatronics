#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

int LeapYearCheck (int n);

int main () {
    int test1 = LeapYearCheck (2000);
    printf("%u\n",test1);

    int test2 = LeapYearCheck (2021);
    printf("%u\n",test2);

    int test3 = LeapYearCheck (1752);
    printf("%u\n",test3);
    
    int test4 = LeapYearCheck (2100);
    printf("%u\n",test4);
};


int LeapYearCheck (int n){
    bool out = 1;
    if(
        (n % 4 == 0 && n % 100 != 0) || 
        (n % 100 == 0 && n % 400 == 0)
    ) {
        return out;
    }
    return !out;
}

