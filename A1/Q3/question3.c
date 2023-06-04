#include <stdio.h>
#include <assert.h>
#include <math.h>

int multiples (int x, int y, int N);

int main () {
    int test1 = multiples (4, 10, 20);
    printf("%u\n", test1);

    int test2 = multiples (32, 14, 10);
    printf("%u\n", test2);

    int test3 = multiples (11, 15, 20);
    printf("%u\n", test3);
    return 0;
}

int multiples (int x, int y, int N){ 
    int sum = 0;
    for(int i = 0; i <= N; i++){
        if(i%x == 0 || i%y == 0){
            sum += i;
        }
    }
    return sum;
}

