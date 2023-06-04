#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/******************The binary tree***********************
 * The following is an illustration of the binary tree
 * I *highly* recommend you test your algorithm on.
 ********************************************************
 *                        Nicholas
 *                        /      \
 *                     Mark      Parker
 *                    /          /     \
 *                Swaleh     Soroush   Other Mark
 *                                 \
 *                                 Ana
 *                                 /
 *                             Bassel
 *
 *
 * (where "/" indicates a left branch, 
 *    and "\" indicates a right branch)
 *
 */ 
typedef struct node{
    struct node* left;
    struct node* right;
    char *name;
    char *tea;      
}Node;

int depth(Node* root){
    Node *bt = root;
    if(bt == NULL) return 0;
    else{
        int l = depth(bt->left);
        int r = depth(bt->right);
    
        if(l > r) return l+1;
        else return r+1;
    }
};

bool check_existance(Node* rootf, char *namef){
    if(rootf == NULL) return false;    
    if(rootf->name == namef) return true;
    bool l = check_existance(rootf->left, namef);
    bool r = check_existance(rootf->right, namef);
    if(l) return true;
    else if(r) return true;
    else return false;
}

int dfs(Node* root, char *name_find){    
    Node *temp = root;
    static int result = 0;
    static int examinations = 0;
    //int c = 1;
    static int flag = 0; 
    if (temp == NULL) return -1;
    else{
        examinations++;
        if(temp->name == name_find){
            flag = 1;
            result = examinations;
            return result;
            //return c;
        }
        if(temp->name != name_find && temp->left != NULL){
            //c+=dfs(temp->left, name_find);
            //printf("counter_left = %d\n", c);
            dfs(temp->left, name_find);
            result = examinations;
            if(flag == 1) return result;
            //if(flag == 1) return c;
        }
        if(temp->name != name_find && temp->right != NULL){
            //c+=dfs(temp->right, name_find);
            //printf("counter_right = %d\n", c);
            dfs(temp->right, name_find);
            result = examinations;
            if(flag == 1) return result;
            //if(flag == 1) return c;
        }    
    }
    //return c;    
}

int main() {
    //Testing code ^_^
    Node *root = malloc(sizeof(Node));
    root->name = "Nicholas";
    root->tea = "Orange Pekoe with Lemon";
    root->left = malloc(sizeof(Node));
    root->left->left = malloc(sizeof(Node));
    root->left->right = NULL;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->right = malloc(sizeof(Node));
    root->right->left = malloc(sizeof(Node));
    root->right->right = malloc(sizeof(Node));
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    root->right->left->left = NULL;
    root->right->left->right = malloc(sizeof(Node));
    root->right->left->right->left = malloc(sizeof(Node));
    root->right->left->right->right = NULL;
    root->right->left->right->left->left = NULL;
    root->right->left->right->left->right = NULL;
    
    root->left->name = "Mark";
    root->left->tea = "Green";
    
    root->right->left->name = "Soroush";
    root->right->left->tea = "Oolong";
    
    root->right->name = "Parker";
    root->right->tea = "Rooibos";
    
    root->right->right->name = "Other Mark";
    root->right->right->tea = "Sencha";
    
    root->left->left->name = "Swaleh";
    root->left->left->tea = "White";
    
    root->right->left->right->name = "Ana";
    root->right->left->right->tea = "Hibiscus";
    
    root->right->left->right->left->name = "Bassel";
    root->right->left->right->left->tea = "Matcha";
    
    printf("The depth of the tree is: %d\n", depth(root));
    // expected result is 5.
    
    // printf("Depth First Search for : Nicholas\n");
    // printf("result: %d\n", dfs(root, "Nicholas"));
    // printf("expected result = 1\n");
    // // expected result is 1
    
    // printf("Depth First Search for : Other Mark\n");
    // printf("result: %d\n", dfs(root, "Other Mark"));
    // printf("expected result = 8\n");
    // // expected result is 8
    
    // printf("Depth First Search for : Parker\n");
    // printf("result: %d\n", dfs(root, "Parker"));
    // printf("expected result = 4\n");
    //expected result is 4
    
    // printf("Depth First Search for : Julius Ceasar\n");
    // printf("result: %d\n", dfs(root, "Julius Ceasar"));
    // printf("expected result = -1\n");
    //expected result is -1

    // test case not provided 

    // printf("Depth First Search for : Mark\n");
    // printf("result: %d\n", dfs(root, "Mark"));
    // printf("expected result = 2\n");
    // // expected result is 2

    // printf("Depth First Search for : Swaleh\n");
    // printf("result: %d\n", dfs(root, "Swaleh"));
    // printf("expected result = 3\n");
    // // expected result is 3

    // printf("Depth First Search for : Ana\n");
    // printf("result: %d\n", dfs(root, "Ana"));
    // printf("expected result = 6\n");

    // printf("Depth First Search for : Bassel\n");
    // printf("result: %d\n", dfs(root, "Bassel"));
    // printf("expected result = 7\n");

    printf("Depth First Search for : Soroush\n");
    printf("result: %d\n", dfs(root, "Soroush"));
    printf("expected result = 5\n");

    // printf("result for existance: %d\n", check_existance(root, "Parker"));
    // printf("expected result = -1\n");
    
    // free(root->right->left->right->left);
    // free(root->right->left->right);
    // free(root->right->left);
    // free(root->right->right);
    // free(root->right);
    // free(root->left->left);
    // free(root->left);
    // free(root);
}
