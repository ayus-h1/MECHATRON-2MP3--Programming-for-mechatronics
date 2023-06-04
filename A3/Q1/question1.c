#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
/*Write 2 functions that manipulate strings through the use of 
pointers. The first function "reverse" takes in an array of characters 
 and reverses it.  The second function "count"
 takes in the same string and returns how many vowels are in the
 string (upper or lower case).
*/
void reverse(char* str);
int count(char* str);

int main () {
    char str[] = "AEIOu";
    reverse(str);
    int c = count(str);
    printf("\n%d", c);
    return 0;
}

void reverse(char* str){
    char *startptr, *endptr;
    char temp;
    //start pointer, end pointer , index 
    int length = strlen(str);
    startptr = str;
    endptr = str + length - 1;
    
    
    for(int i=0; i < length/2;i++){ 
        // comparing last and first elements and swaping them
        temp = *endptr;
        *endptr = *startptr;
        *startptr = temp;
        
        startptr++;  // moving start pointer to right
        endptr--;  // moving end pointer to left
    };
    printf("%s",str);

}

int count(char* str){
    char *ptr; //declaration
    int count = 0;
    ptr = str;
    
    int length = strlen(str);
    for(int i=0; i < length; i++){ 
        if(*ptr == 'A' || *ptr == 'E' || *ptr == 'I' || *ptr == 'O' || *ptr == 'U' || *ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u'){
            count++;
        };
        ptr++;
    };
    return count;
}

