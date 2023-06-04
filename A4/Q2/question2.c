#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DMY_MonthDY(char *buffer, const char *str){
    char *mon_list[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November","December"};
    char date[19];
    strcpy(date,str);
    char *ptr;
    
    //breaking date into pieces 
    char *tok_day = strtok(date,"/");
    char *tok_month = strtok(NULL,"/");
    char *tok_year = strtok(NULL,"/");

    //converting pieces to required format
    int int_day = (int)strtol(tok_day, &ptr, 10);
    int int_month = (int)strtol(tok_month, &ptr, 10);
    char str_month[10];
    strcpy(str_month,mon_list[int_month-1]); //strcpy take pointer to array of string as arguments
    int int_year = (int)strtol(tok_year, &ptr, 10);

    snprintf(buffer,20,"%-10s%2d,%5d",str_month,int_day,int_year); //%-10 gives 10 spaces to right
} 

void MonthDY_DMY(char *buffer, const char *str){
    char *mon_list[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November","December"};
    char date[19];
    strcpy(date,str);
    char *ptr;
    
    // break the date format into pieces 
    char *tok_month = strtok(date, " "); 
    char *tok_day = strtok(NULL, ",");
    char *tok_year = strtok(NULL, "\0");

    // convert those pieces to required format (i.e. int)
    int int_day = (int)strtol(tok_day,&ptr,10);
    int int_month;
    for(int i=0; i<12; i++){
        if(*tok_month == *mon_list[i]){
            int_month = i;
            break;
        }
    }
    int_month++;
    int int_year = (int)strtol(tok_year,&ptr,10);

    //printing out in right format
    snprintf(buffer,12,"%.2ld/%.2ld/%.4ld",int_day,int_month,int_year);

}



int main(){
char format1[12][11] = { "01/01/1970"
                       , "10/02/1763"
                       , "15/03/0044"
                       , "18/04/1982"
                       , "05/05/1789"
                       , "06/06/1944"
                       , "01/07/1867"
                       , "03/08/1492"
                       , "02/09/1945"
                       , "24/08/1917"
                       , "11/11/1918"
                       , "08/12/1980"
                       };
char format2[12][19] = { "January    1, 1970" // First Day of History (according to computers)
                       , "February  10, 1763" // France cedes Canada to England
                       , "March     15,   44" // Assassination of Julius Caesar
                       , "April     18, 1982" // Canada Achieves Sovereignty 
                       , "May        5, 1789" // French Revolution
                       , "June       6, 1944" // D-Day Landings of WWII
                       , "July       1, 1867" // Confederation of Canada
                       , "August     3, 1492" // Christopher Columbus Sets Sail for the Americas
                       , "September  2, 1945" // WWII Surrender of Japan
                       , "October   24, 1917" // October Revolution (Julian Calendar)
                       , "November  11, 1918" // WWI Armistice
                       , "December   8, 1980" // Murder of John Lennon
                       };                                                                                                
    
    char buffer1[12][11];
    char buffer2[12][19];
    // char buffer2[12];

    // char str[] = "01/01/1970";
    
    printf ("-- DD\\MM\\YY to Month DD, YYYY\n");
    for (int i = 0; i < 12; i++) {
        printf("%s\n", format1[i]);
        DMY_MonthDY(buffer2[i], format1[i]);
        printf("-> \"%s\"\n", buffer2[i]);
    }
    
    //DMY_MonthDY(buffer2,str);
    
    printf ("\n\n-- Month DD, YYYY to DD\\MM\\YY\n");
    for (int i = 0; i < 12; i++) {
        printf("%s\n", format2[i]);
        MonthDY_DMY(buffer1[i], format2[i]);
        printf("-> \"%s\"\n", buffer1[i]);
    }
}