#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//end is first memory cell after end of stack
//start is the pointer to which the stack’s memory will be allocated
//(end-1) is last stack memory cell
// what is end, *end and **end
// int top = 0;

int isEmpty (const long *start, const long *end);
void push (long **start, long **end, long value); //&start
long pop (long **start, long **end); // You don't have to implement this one.

int isEmpty (const long *start, const long *end){ //working
    if((start == NULL) || (end == NULL) || (start == end)){
        return 1;
    }
    else{
        return 0;
    }
}

void push (long **start, long **end, long value){
    static int top = 0;  
    if(isEmpty(*start, *end) == 1){ //*start is address of block
        *start = (long*)malloc(sizeof(long));
        (*start)[0] = value; //*(*(end)+0)  //*(end)
        *end = *start+1; //**(end+top) = *end[top] end[0] = *start[1]
        top++;
    }
    else{
        *start = (long*)realloc(*start,(top+1)*(sizeof(long)));
        (*start)[top] = value;
        top++;
        *end = *start+top;
            
    }
}

// This testing code has been provided curteousy of ACME Inc.
//   "Our products are perfectly capable of catching road runners."

void printStack(long **start, long **end) {
    printf("Stack --> [ ");
    if (!isEmpty(*start, *end)) {
        for (int i = 0; *start + i < *end; i++) {
            printf("%ld ", (*start)[i]);
        }
    } 
    printf("]\n");
}

int main () {



    printf("Starting...\n");
    long *start = NULL;
    long *stop = NULL;
    printStack(&start, &stop);
    push(&start, &stop, 1L);
    printStack(&start, &stop);
    push(&start, &stop, 2L);
    printStack(&start, &stop);
    push(&start, &stop, 3L);
    printStack(&start, &stop);
    push(&start, &stop, 4L);
    printStack(&start, &stop);
    push(&start, &stop, 5L);
    printStack(&start, &stop);
    
    long out = pop(&start, &stop);
    printf("popped %ld\n", out);
    printStack(&start, &stop);
    
    out = pop(&start, &stop);
    printf("popped %ld\n", out);
    printStack(&start, &stop);
    
    out = pop(&start, &stop);
    printf("popped %ld\n", out);
    printStack(&start, &stop);
    
    out = pop(&start, &stop);
    printf("popped %ld\n", out);
    printStack(&start, &stop);
    
    out = pop(&start, &stop);
    printf("popped %ld\n", out);
    printStack(&start, &stop);
    
    out = pop(&start, &stop);
    printf("popped %ld\n", out);
    printStack(&start, &stop);
    
/***Expected Output:****

Starting...
Stack --> [ ]
Stack --> [ 1 ]
Stack --> [ 1 2 ]
Stack --> [ 1 2 3 ]
Stack --> [ 1 2 3 4 ]
Stack --> [ 1 2 3 4 5 ]
popped 5
Stack --> [ 1 2 3 4 ]
popped 4
Stack --> [ 1 2 3 ]
popped 3
Stack --> [ 1 2 ]
popped 2
Stack --> [ 1 ]
popped 1
Stack --> [ ]
popped 0
Stack --> [ ]

**********************/
    
}