#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node{
    int value;
    struct node* prev;
    struct node* next;
};

struct node *element(struct node *dll, int i){
    struct node* ptrx = dll;
    if(i<0) return NULL;
    for(int j=0; j<i; j++){
        if(ptrx == NULL) return NULL;     
        ptrx = ptrx->next;
    }   
    return ptrx;
};

// i is negative -> put new node at the end 
// node at i is not there -> put new node at the end 
// node at i is there -> put new node before node at i
struct node *add(struct node *dll, int i, int value){
    struct node* new_node = malloc(sizeof(struct node));
    new_node->value = value;
    struct node* ptrp = element(dll, i);
    struct node* ptr1 = element(dll, i-1);

    //adding at the beginning of the list
    if (i == 0){
        ptr1 = dll;
        ptr1->prev = new_node;
        new_node->prev = NULL;
        new_node->next = ptr1;
    }
    // node at i is not there -> put new node at the end 
    if(ptrp == NULL || i<0){
        ptr1 = dll;
        while(ptr1->next != NULL){
            ptr1 = ptr1->next;
        }
        ptr1->next = new_node;
        new_node->prev = ptr1;
        new_node->next = NULL;
    }else{
        //node at i is there -> put new node before node at i
        ptr1->next = new_node;
        new_node->prev = ptr1;
        new_node->next = ptrp;   
    }
    return dll;
} 



struct node *delete(struct node *dll, int i){
    struct node* temp = dll;
    struct node* del = element(dll, i); // got to node at i
    int counter = 0;
    while(temp->next!=NULL){
        counter++;
        temp=temp->next;
    }
    //printf("counter = %d", counter);
    temp = dll;
    if(del == NULL || i<0 || i>counter || dll == NULL) return;
    //delete head node
    if(i == 0) dll = temp->next;
    
    //node at i
    if(del->next != NULL) del->next->prev = del->prev;    
    if(del->prev != NULL) del->prev->next = del->next;    
    return dll;
}

void printNode (struct node *dll) {
    if (dll != NULL) {
        printf("< This: %p - %d - P : %p - N : %p >\n", dll, dll->value, dll->prev, dll->next);
    } else {
        printf("Null Pointer");
    }
}


void printLL (struct node *dll) {
    struct node* ptr = dll;
    printf("---\n");
    while (ptr != NULL) {
        printNode(ptr);
        ptr = ptr->next;
    }
    printf("---\n\n");
}

int main () {
    //Testing code! 
    struct node *dll = malloc(sizeof(struct node));
    struct node *x = malloc(sizeof(struct node));
    dll->next = NULL;
    dll->prev = NULL;
    dll->value = 1;
    printLL(dll);
    dll = add(dll, -1, 3);
    printLL(dll);
    dll = add(dll, -1, 4);
    printLL(dll);
    dll = add(dll, 1, 2);
    printLL(dll);
    dll = add(dll, 2, 7);
    printLL(dll);
    dll = add(dll, 9, -1);
    printLL(dll);
    dll = delete(dll, 2);
    printLL(dll);
    dll = delete(dll, 0);
    printLL(dll);
    dll = delete(dll, 4);
    printLL(dll);
    dll = delete(dll, 0);
    dll = delete(dll, 0);
    dll = delete(dll, 0);
    dll = delete(dll, 0);
    printLL(dll); 
}

/* Expected Output: 

---
< This: 0x1cf8590 - 1 - P : (nil) - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8590 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8590 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf85f0 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf8610 >
< This: 0x1cf8610 - 7 - P : 0x1cf85f0 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8610 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf85f0 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

*/ 


//    if(ptrd->next == NULL){
//         ptrd->prev->next = NULL;
//     }else{
//         ptrd->next->prev = ptrd->prev->next;
//         ptrd->prev->next = ptrd->next->prev;
//         ptrd->next = NULL;
//         ptrd->prev = NULL;    
//     }

    // while(temp->next!=NULL){
    //     counter++;
    //     temp=temp->next;
    // }
    // temp = dll;
    // if(i>counter || i<0){
    //     return;
    // }