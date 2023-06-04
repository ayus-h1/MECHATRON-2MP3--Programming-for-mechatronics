#include <stdio.h>
#include <assert.h>
#include <math.h>

int juggler(int n);

int main () {
    int c1 = juggler(4);
    printf("%d\n",c1);

    int c2 = juggler(10000);
    printf("%d\n",c2);

    int c3 = juggler(37);
    printf("%d\n",c3);
    
    return 0;
}

int juggler(int n){
    int count = 0;
    if(n==1){
        return 0;
    }else if(n%2 == 0){
        n = floor(sqrt(n));
    }else if(n>1){
        n = floor(n*sqrt(n));
    };
    count+=juggler(n); 
    return count+=1;
}

