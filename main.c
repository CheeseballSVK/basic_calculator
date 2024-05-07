#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include "calculator.h"
int main() {
    int i=0;
    int j=0;
    char input_string[1000]; 
    int error=0;
    printf("        /SYNTAX/ \n");
    printf("- Sinus -> sinX\n- Cosinus -> cosX\n- Square root -> [Y]rootX\n- Power -> Y^X\n- Logaritmus ->log[Y]X\n");
    printf("Enter your string with problem: ");
    
    scanf("%999[^\n]", input_string);
    printf("You entered: %s\n", input_string);
    
    for (i = 0, j = 0; i < strlen(input_string); i++) {

        if (input_string[i] != ' ') {
            input_string[j] = input_string[i]; 
            j++; 
        }
    }
    input_string[j] = '\0'; 
    
    for(i=0;i<strlen(input_string);i++){
        if(input_string[i]=='('){ 
        brackets(input_string,&error);
        break;
        }
    }
    for(i=0;i<strlen(input_string);i++){
        if(input_string[i]=='r'&&input_string[i+1]=='o'&&input_string[i+2]=='o'&&input_string[i+3]=='t'){ 
        root(input_string,&error);
        break;
        }
    }
    for(i=0;i<strlen(input_string);i++){
        if(input_string[i]=='s'&&input_string[i+1]=='i'&&input_string[i+2]=='n'){ 
        sinus(input_string,&error);
        break;
        }
    }
    for(i=0;i<strlen(input_string);i++){
        if(input_string[i]=='c'&&input_string[i+1]=='o'&&input_string[i+2]=='s'){ 
        cosinus(input_string,&error);
        break;
        }
    }
    for(i=0;i<strlen(input_string);i++){
        if(input_string[i]=='^'){ 
        exponentiation(input_string,&error);
        break;
        }
    }
    for(i=0;i<strlen(input_string);i++){
        if(input_string[i]=='l'&&input_string[i+1]=='o'&&input_string[i+2]=='g'){ 
        logaritm(input_string,&error);
        break;
        }
    }
    for(i=0;i<strlen(input_string);i++){
        if(input_string[i]=='*'){ 
        multiplication(input_string,&error);
        break;
        }
    }
    for(i=0;i<strlen(input_string);i++){
        if(input_string[i]=='/'){ 
        devide(input_string,&error);
        break;
        }
    }
    for(i=0;i<strlen(input_string);i++){
        if(input_string[i]=='+'){ 
        plus(input_string,&error);
        break;
        }
    }
    for(i=0;i<strlen(input_string);i++){
        if(input_string[i]=='-'){ 
        minus(input_string,&error);
        break;
        }
    }
    if(error==1){
        printf("Something Went Wrong\nTry to rewrite your prompt according to syntax of this app\n");
        return 0;
    }else{
        printf("Sum: %s\n",input_string);
    }
    
        


    
    
    return 0;
    }
