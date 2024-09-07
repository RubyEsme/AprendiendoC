#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main() 
{
    

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char ch;
    char s[10];
    char sen[32];
    
    printf("Ingrese un solo caracter: ");
    scanf("%c", &ch);
    
    printf("Ingrese un string: ");
    scanf("%s", s);
    
    //helps clean buffer
    getchar();

    printf("Ingrese una oracion: ");
    fgets(sen, 32, stdin);
    
    
    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s\n", sen);
    
    return 0;
}
