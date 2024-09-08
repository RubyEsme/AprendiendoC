#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){

    int arrayExample[] = {20,15,30,100,80,65,85};
    int getOut = 1;
    int number;
    bool isFound = false;

    do{
        printf("Please enter an integer to find it using linear search!:");
        scanf("%d", &number);

        int checkNumber = number / 2;

        if(!number || !checkNumber){
            printf("Please be kind to insert a number..\n");
        }else{
            for(int i= 0; i<7;i++){ //this is the part that resembles the linear search
                if(arrayExample[i] == number){
                    printf("Yep, found!\n");
                    isFound = true;
                }
            }
            if(!isFound){
                printf("Not found:(\n");
                }
            
        }
        printf("Wanna end this?: (1 = yes or 0 = no)\n ");
        scanf("%d", &getOut);
    }while(getOut == 0);

}