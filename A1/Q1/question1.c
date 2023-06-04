#include <stdio.h>
#include <assert.h>
#include <math.h>

int minutes (int m, int h, int d);

int main () {
    int t1 = minutes (1, 1, 1);
    printf("test 1: %u\n", t1);

    int t2 = minutes (30, 15, 2);
    printf("test 3:%u\n", t2);

    int t3 = minutes (0, 0, 0);
    printf("test 3:%u\n", t3);
    return 0;
}

int minutes (int m, int h, int d) { 
    int minh = h*60;
    int mind = d*60*24;
    int mintotal = m + minh + mind; 
    return mintotal;
}

