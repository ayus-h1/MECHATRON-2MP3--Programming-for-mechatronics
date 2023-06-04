#include <stdio.h>
#include <assert.h>
#include <math.h>

void mileage (void);

//distance/fuel used
int main () {
	mileage();
    return 0;
}

void mileage (void){
    float dist = 0 , gas = 0;
    float dist1, gas1;
    char character;
    float mileage;
    while(character != 'n'){

        printf("How much fuel have you used ? : ");
        scanf("%f", &gas1);  
        gas += gas1;
        printf("How far did you travel? : ");
        scanf("%f",&dist1);
        dist += dist1;
        printf("Do you have more data to enter ? ( y/n ) : ");
        scanf("\n%c",&character);
    };
    mileage = dist/gas;
    printf("Your gas mileage is %.4f",mileage);
};



