#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int simpleParse(const char *exp){
    int size = strlen(exp);
    char expcpy[size];
    strcpy(expcpy,exp);

    char *tok_nums;
    tok_nums = strtok(expcpy, " /*%+-");

    char *ptr;
    int num;
    int nums[20];
    int num_arr_count = 0;
    int op_arr_count = 0;
    int final_arr_count = 0;

    for(int i=0; i<size+1; i++){ // counting size of operator array
        if(exp[i] == '/' || exp[i] == '*' || exp[i] == '%' || exp[i] == '+' || exp[i] == '-'){
            op_arr_count ++;
        }
    }

    //printf("op_arr_count(with all operators) = %d\n",op_arr_count);

    char operators[op_arr_count];  
    //printf("operators: ");
    int c1 = 0;
    for(int i=0; i<size+1; i++){ //storing the operators in order
        if(expcpy[i] == '/' || expcpy[i] == '*' || expcpy[i] == '%' || expcpy[i] == '+' || expcpy[i] == '-'){
            operators[c1] = expcpy[i];
            //printf("%c ",operators[c1]);
            c1++;
        }
    }

    for(int j=0; j<op_arr_count; j++){
        if(operators[j] == '+' || operators[j] == '-'){
            final_arr_count++;
        }
    }

    //printf("\nfinal_arr_count(with + or -) = %d\n",final_arr_count+1);

    char final_array[final_arr_count];
    int k1 = 0;
    //printf("final_array: ");
    for(int m=0; m<op_arr_count; m++){ 
        if(operators[m] == '+' || operators[m] == '-'){    
            final_array[k1] = operators[m];
            //printf("%c ",final_array[k1]);
            k1++;
        }
    }   

    //printf("\nnums: ");
    while (tok_nums != NULL) //storing integers 
    {   
        num = (int)strtol(tok_nums,&ptr,10);
        nums[num_arr_count] = num;
        //printf ("%ld ",nums[num_arr_count]);
        tok_nums = strtok (NULL, " /*%+-");
        num_arr_count++;
    }


  
    int operated_nums[final_arr_count+1];
    operated_nums[0] = nums[0];

    //So multiply/divide/modulo numbers until u hit a + or -, then assign that number to a new array
    int c = 0;
    int x = 0;
    int b = 0;
    for(int x=0; x<num_arr_count; x++){
        // printf("\noperated_nums[c] = %d, ",operated_nums[b]);
        // printf("nums[x+1] = %d\n",nums[x+1]);
        if(operators[c] == '*'){
            operated_nums[b] =  operated_nums[b] * nums[x+1];
        }
        else if(operators[c] == '/'){
            operated_nums[b] = operated_nums[b] / nums[x+1];
        }
        else if(operators[c] == '%'){
            operated_nums[b] = operated_nums[b] % nums[x+1];
        }
        else{
            b++;
            operated_nums[b] = nums[x+1];
        }
        c++;
    }

    //printf("\n");
    //printf("operated_nums: ");
    for(int i=0; i<final_arr_count+1; i++){
        //printf("%d ",operated_nums[i]);
    };

    int n = 0;
    int answer = operated_nums[0];
    
    for(int x=0; x<final_arr_count+1; x++){
        if(final_array[n] == '+'){
            answer = answer + operated_nums[x+1];
        }
        else if(final_array[n] == '-'){
            answer = answer - operated_nums[x+1];
        }
        n++;
    }

    return answer;

}

    
    
int main() {
    char exp1[] = "1 + 1";
    char exp2[] = "3 + 7 - 4 * 1";
    char exp3[] = "9 * 13 / 2 + 18 * 110 - 812 % 97 + 3";
    char exp4[] = "2 * 2 / 2 % 2";
    
    printf("%s = %d\n", exp1, simpleParse(exp1));
    printf("%s = %d\n", exp2, simpleParse(exp2));
    printf("%s = %d\n", exp3, simpleParse(exp3));
}

