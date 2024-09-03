#include <stdio.h>

int main()
{
    int j = 4;
    for(int i=2;i<=5;i++){
        for(j; j<=4; ++j){
            printf("*");  
        }
        j -= i ;
        printf("\n");
    }
    return 0;
}