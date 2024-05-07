#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include "calculator.h"
int j=0;
int i=0;
int k=0;
int l=0;
int p=0;

int startbracket=0;
int endingbracket=0;
int lastcharacterroot=0;
int lastcharactersinus=0;
int lastcharactercosinus=0;
bool isdone=false;

void sinus(char input_string[],int *error){
    char leftover[1000];
    char sinus_string[1000];
    char sinus_input_string[1000];
    int sinusnumber=0;

    for(i=0;i<strlen(input_string);i++){
        if(input_string[i]=='s'&&input_string[i+1]=='i'&&input_string[i+2]=='n'){   
            break;
        }

    }
    for(j=i+3;j<strlen(input_string)+1;j++){            
        if(input_string[j]=='+'||input_string[j]=='-'||input_string[j]=='*'||input_string[j]=='/'||input_string[j]=='\0'||input_string[i]=='('||input_string[i]==')'){
                break;
            }
            sinus_string[sinusnumber]=input_string[j];
            sinusnumber++;
            lastcharactersinus=j;
            
                    
                    
    }
    sinus_string[sinusnumber]='\0';
    float number = atof(sinus_string);
    float radians = number * (3.14 / 180.0);
    float calculatedsinus = sin(radians);
    sprintf(sinus_input_string, "%.2f", calculatedsinus);
    
    for(l=0;l<i;l++){
        leftover[l]=input_string[l];
    }
    for(k=0;k<strlen(sinus_input_string);k++){
        leftover[l]=sinus_input_string[k];
        l++;
    }
    leftover[l]='\0';
    
    for(p=j;p<=strlen(input_string);p++){
        leftover[l]=input_string[p];
        l++;
    }
    input_string[0]='\0';
    for(p=0;p<=strlen(leftover);p++){
        input_string[p]=leftover[p];
    }
    for(i=0;i<strlen(input_string);i++){
        if(input_string[i]=='s'&&input_string[i+1]=='i'&&input_string[i+2]=='n'){ 
        sinus(input_string,error);
        break;
        }
    }
}
void cosinus(char input_string[],int *error){
    char leftover[1000];
    char cosinus_string[1000];
    char cosinus_input_string[1000];
    int cosinusnumber=0;
    for(i=0;i<strlen(input_string);i++){
        if(input_string[i]=='c'&&input_string[i+1]=='o'&&input_string[i+2]=='s'){ 
            break;
        }

    }
    for(j=i+3;j<strlen(input_string)+1;j++){            
        if(input_string[j]=='+'||input_string[j]=='-'||input_string[j]=='*'||input_string[j]=='/'||input_string[j]=='\0'||input_string[i]=='('||input_string[i]==')'){
                break;
            }
            cosinus_string[cosinusnumber]=input_string[j];
            cosinusnumber++;
            lastcharactercosinus=j;
            
                    
                    
    }
    cosinus_string[cosinusnumber]='\0';
    float number = atof(cosinus_string);
    float radians = number * (3.14 / 180.0);
    float calculatedcosinus = cos(radians);
    sprintf(cosinus_input_string, "%.2f", calculatedcosinus);
    
    for(l=0;l<i;l++){
        leftover[l]=input_string[l];
    }
    for(k=0;k<strlen(cosinus_input_string);k++){
        leftover[l]=cosinus_input_string[k];
        l++;
    }
    leftover[l]='\0';
    
    for(p=j;p<=strlen(input_string);p++){
        leftover[l]=input_string[p];
        l++;
    }
    input_string[0]='\0';
    for(p=0;p<=strlen(leftover);p++){
        input_string[p]=leftover[p];
    }
    for(i=0;i<strlen(input_string);i++){
        if(input_string[i]=='c'&&input_string[i+1]=='o'&&input_string[i+2]=='s'){ 
        cosinus(input_string,error);
        break;
        }
    }
}
void exponentiation(char input_string[],int *error){
    int zaciatokexp=0;
    int koniecexp=0;
    for(i=0;i<strlen(input_string);i++){
            if(input_string[i]=='^'){
                // SYNTAX ERROR '^'
                if(i==0||!isdigit(input_string[i-1])||!isdigit(input_string[i + 1])){
                    printf("Invalid Syntex of Exponentiation\n");
                    *error=1;
                    break;
                }
                break;
                
            }
            
    }
    bool isfirstnumber=true;
    for(k=i-1;k>=0;k--){
        if(!isdigit(input_string[k])){
            k=k+1;
            isfirstnumber=false;
            break;
        }
        
    }
    zaciatokexp=k;
    //fist EXP
    if(isfirstnumber==true){
        k=0;
    }
    char firstexpnumber[100];
    p=0;
    for(l=k;l<=i-1;l++){
        firstexpnumber[p]=input_string[k++];
        p++;
    }
    firstexpnumber[p]='\0';

    //2ND EXP
    for(j=i;j<=strlen(input_string);j++){
       if(input_string[j]=='+'||input_string[j]=='-'||input_string[j]=='*'||input_string[j]=='/'||input_string[j]=='\0'||input_string[i]=='('||input_string[i]==')'){
        break;


       }
    }
    char secexpnumber[100];
    p=0;
    for(l=i+1;l<j;l++){
        secexpnumber[p]=input_string[l];
        p++;
    }
    secexpnumber[p]='\0';
    koniecexp=j;

    char exp_input_string[1000];
    float number1 = atof(firstexpnumber);
    float number2 = atof(secexpnumber);
    float result = pow(number1,number2);
    sprintf(exp_input_string, "%.2f", result);
    
    char leftover[1000];
    if(zaciatokexp==-1){
        zaciatokexp=0;
    }
    for(i=0;i<=zaciatokexp-1;i++){
        leftover[i]=input_string[i];
    }
    leftover[i]='\0';
    l=0;
    for(p=0;p<=strlen(exp_input_string);p++){
        leftover[i]=exp_input_string[l++];
        i++;
    }
    leftover[i]='\0';
    i--;
    for(p=koniecexp;p<=strlen(input_string);p++){
        //printf("TUSOM\n");
        leftover[i]=input_string[p];
        i++;
    }
    input_string[0]='\0';
    for(p=0;p<=strlen(leftover);p++){
        input_string[p]=leftover[p];
    }
    for(i=0;i<strlen(input_string);i++){
        if(input_string[i]=='^'){ 
        exponentiation(input_string,error);
        break;
        }
    }

}
void logaritm(char input_string[],int *error){
    for(i=0;i<strlen(input_string);i++){
        if(input_string[i]=='l'&&input_string[i+1]=='o'&&input_string[i+2]=='g'){ 
        break;
        }
    }
    int zaciatoklog=i;
    if(input_string[i+3]!='['){
        *error=1;
    }
    int zaciatoknakolko=i+3;
    for(i=zaciatoknakolko;i<strlen(input_string);i++){
        if(input_string[i]==']'){ 
        break;
        }
    }
    int koniecnakolko=i;
    char charnakolko[100];
    l=0;
    for(i=zaciatoknakolko+1;i<koniecnakolko;i++){
        charnakolko[l]=input_string[i];
        l++;
    }
    charnakolko[l]='\0';
    float number1 = atof(charnakolko);
    for(j=koniecnakolko;j<=strlen(input_string);j++){
       if(input_string[j]=='+'||input_string[j]=='-'||input_string[j]=='*'||input_string[j]=='/'||input_string[j]=='\0'){
        break;


       }
    }
    int koniecvsetkeho=j;
    char charlogu[100];
    l=0;
    for(i=koniecnakolko+1;i<koniecvsetkeho;i++){
        charlogu[l]=input_string[i];
        l++;
    }
    charlogu[l]='\0';
    float number2 = atof(charlogu);
    float result = log(number2) / log(number1);
    char log[1000];
    sprintf(log, "%.2f", result);

    char leftover[1000];
    for(i=0;i<=zaciatoklog-1;i++){
        leftover[i]=input_string[i];
    }
    leftover[i]='\0';
    l=0;
    for(p=0;p<=strlen(log);p++){
        leftover[i]=log[l++];
        i++;
    }
    leftover[i]='\0';
    i--;
    for(p=koniecvsetkeho;p<=strlen(input_string);p++){
        //printf("TUSOM\n");
        leftover[i]=input_string[p];
        i++;
    }
    input_string[0]='\0';
    for(p=0;p<=strlen(leftover);p++){
        input_string[p]=leftover[p];
    }
    for(i=0;i<strlen(input_string);i++){
        if(input_string[i]=='l'&&input_string[i+1]=='o'&&input_string[i+2]=='g'){ 
            logaritm(input_string,error);
            break;
        }
    }
}
void multiplication(char input_string[],int *error){
    for(i=0;i<strlen(input_string);i++){
        if(input_string[i]=='*'){
            break;
        }
    }
    int multichar=i;
    for(i=multichar-1;i>=0;i--){
        if(input_string[i]=='+'||input_string[i]=='-'||input_string[i]=='*'||input_string[i]=='/'||input_string[i]=='('||input_string[i]==')'){
        break;
       }
       if(i==0){
        break;
       }
    }
    int zaciatokmulti=i;
    if(zaciatokmulti!=0){
        zaciatokmulti++;
    }
    l=0;
    char firstnumber[1000];
    for(i=zaciatokmulti;i<multichar;i++){
        firstnumber[l]=input_string[i];
        l++;
    }
    firstnumber[l]='\0';
    for(i=multichar+1;i<=strlen(input_string);i++){
        if(input_string[i]=='+'||input_string[i]=='-'||input_string[i]=='*'||input_string[i]=='/'||input_string[i]=='('||input_string[i]==')'||input_string[i]=='\0'){
        break;
       }
    }
    l=0;
    int koniecceleho=i;
    char secnumber[1000];
     for(i=multichar+1;i<koniecceleho;i++){
        secnumber[l]=input_string[i];
        l++;
    }
    secnumber[l]='\0';
    float number1 = atof(firstnumber);
    float number2 = atof(secnumber);
    float result = number1 * number2;
    char multi[1000];
    sprintf(multi, "%.2f", result);

    char leftover[1000];
    for(i=0;i<=zaciatokmulti-1;i++){
        leftover[i]=input_string[i];
    }
    leftover[i]='\0';
    l=0;
    for(p=0;p<=strlen(multi);p++){
        leftover[i]=multi[l++];
        i++;
    }
    leftover[i]='\0';
    i--;
    for(p=koniecceleho;p<=strlen(input_string);p++){
        //printf("TUSOM\n");
        leftover[i]=input_string[p];
        i++;
    }
    input_string[0]='\0';
    for(p=0;p<=strlen(leftover);p++){
        input_string[p]=leftover[p];
    }
    for(i=0;i<strlen(input_string);i++){    
        if(input_string[i]=='*'){
            multiplication(input_string,error);
            break;
        }
    }

    
}
void devide(char input_string[],int *error){
    for(i=0;i<strlen(input_string);i++){
        if(input_string[i]=='/'){
            break;
        }
    }
    int multichar=i;
    for(i=multichar-1;i>=0;i--){
        if(input_string[i]=='+'||input_string[i]=='-'||input_string[i]=='*'||input_string[i]=='/'||input_string[i]=='('||input_string[i]==')'){
        break;


       }
       if(i==0){
        break;
       }
    }
    int zaciatokmulti=i;
    if(zaciatokmulti!=0){
        zaciatokmulti++;
    }
    l=0;
    char firstnumber[1000];
    for(i=zaciatokmulti;i<multichar;i++){
        firstnumber[l]=input_string[i];
        l++;
    }
    firstnumber[l]='\0';
    for(i=multichar+1;i<=strlen(input_string);i++){
        if(input_string[i]=='+'||input_string[i]=='-'||input_string[i]=='*'||input_string[i]=='/'||input_string[i]=='('||input_string[i]==')'||input_string[i]=='\0'){
        break;


       }
    }
    l=0;
    int koniecceleho=i;
    char secnumber[1000];
     for(i=multichar+1;i<koniecceleho;i++){
        secnumber[l]=input_string[i];
        l++;
    }
    secnumber[l]='\0';
    float number1 = atof(firstnumber);
    float number2 = atof(secnumber);
    float result = number1 / number2;
    char multi[1000];
    sprintf(multi, "%.2f", result);

    char leftover[1000];
    for(i=0;i<=zaciatokmulti-1;i++){
        leftover[i]=input_string[i];
    }
    leftover[i]='\0';
    l=0;
    for(p=0;p<=strlen(multi);p++){
        leftover[i]=multi[l++];
        i++;
    }
    leftover[i]='\0';
    i--;
    for(p=koniecceleho;p<=strlen(input_string);p++){
        //printf("TUSOM\n");
        leftover[i]=input_string[p];
        i++;
    }
    input_string[0]='\0';
    for(p=0;p<=strlen(leftover);p++){
        input_string[p]=leftover[p];
    }
    for(i=0;i<strlen(input_string);i++){    
        if(input_string[i]=='/'){
            devide(input_string,error);
            break;
        }
    }

    
}
void plus(char input_string[],int *error){
    for(i=0;i<strlen(input_string);i++){
        if(input_string[i]=='+'){
            break;
        }
    }
    int multichar=i;

    for(i=multichar-1;i>=0;i--){
        if(input_string[i]=='+'||input_string[i]=='-'||input_string[i]=='*'||input_string[i]=='/'||input_string[i]=='('||input_string[i]==')'){
        break;


       }
       if(i==0){
        break;
       }
    }
    int zaciatokmulti=i;
    if(zaciatokmulti!=0){
        zaciatokmulti++;
    }
    l=0;
    char firstnumber[1000];
    for(i=zaciatokmulti;i<multichar;i++){
        firstnumber[l]=input_string[i];
        l++;
    }
    firstnumber[l]='\0';

    for(i=multichar+1;i<=strlen(input_string);i++){
        if(input_string[i]=='+'||input_string[i]=='-'||input_string[i]=='*'||input_string[i]=='/'||input_string[i]=='('||input_string[i]==')'||input_string[i]=='\0'){
        break;


       }
    }
    l=0;
    int koniecceleho=i;
    char secnumber[1000];
     for(i=multichar+1;i<koniecceleho;i++){
        secnumber[l]=input_string[i];
        l++;
    }
    secnumber[l]='\0';
    float number1 = atof(firstnumber);
    float number2 = atof(secnumber);
    float result = number1 + number2;
    char multi[1000];
    sprintf(multi, "%.2f", result);





    char leftover[1000];
    for(i=0;i<=zaciatokmulti-1;i++){
        leftover[i]=input_string[i];
    }
    leftover[i]='\0';
    l=0;
    for(p=0;p<=strlen(multi);p++){
        leftover[i]=multi[l++];
        i++;
    }
    leftover[i]='\0';
    i--;
    for(p=koniecceleho;p<=strlen(input_string);p++){
        //printf("TUSOM\n");
        leftover[i]=input_string[p];
        i++;
    }

    input_string[0]='\0';
    for(p=0;p<=strlen(leftover);p++){
        input_string[p]=leftover[p];
    }
    for(i=0;i<strlen(input_string);i++){    
        if(input_string[i]=='+'){
            plus(input_string,error);
            break;
        }
    }

}
void minus(char input_string[],int *error){
    for(i=0;i<strlen(input_string);i++){
        if(input_string[i]=='-'){
            break;
        }
    }
    int multichar=i;

    for(i=multichar-1;i>=0;i--){
        if(input_string[i]=='+'||input_string[i]=='-'||input_string[i]=='*'||input_string[i]=='/'||input_string[i]=='('||input_string[i]==')'){
        break;


       }
       if(i==0){
        break;
       }
    }
    int zaciatokmulti=i;
    if(zaciatokmulti!=0){
        zaciatokmulti++;
    }
    l=0;
    char firstnumber[1000];
    for(i=zaciatokmulti;i<multichar;i++){
        firstnumber[l]=input_string[i];
        l++;
    }
    firstnumber[l]='\0';

    for(i=multichar+1;i<=strlen(input_string);i++){
        if(input_string[i]=='+'||input_string[i]=='-'||input_string[i]=='*'||input_string[i]=='/'||input_string[i]=='('||input_string[i]==')'||input_string[i]=='\0'){
        break;


       }
    }
    l=0;
    int koniecceleho=i;

    char secnumber[1000];
     for(i=multichar+1;i<koniecceleho;i++){
        secnumber[l]=input_string[i];
        l++;
    }
    secnumber[l]='\0';

    float number1 = atof(firstnumber);
    float number2 = atof(secnumber);
    float result = number1 - number2;
    char multi[1000];
    sprintf(multi, "%.2f", result);





    char leftover[1000];
    for(i=0;i<=zaciatokmulti-1;i++){
        leftover[i]=input_string[i];
    }

    leftover[i]='\0';
    l=0;
    for(p=0;p<=strlen(multi);p++){
        leftover[i]=multi[l++];
        i++;
    }

    leftover[i]='\0';
    i--;
    for(p=koniecceleho;p<=strlen(input_string);p++){
        //printf("TUSOM\n");
        leftover[i]=input_string[p];
        i++;
    }

    input_string[0]='\0';
    for(p=0;p<=strlen(leftover);p++){
        input_string[p]=leftover[p];
    }
    for(i=0;i<strlen(input_string);i++){    
        if(input_string[i]=='-'){
            minus(input_string,error);
            break;
        }
    }

}
void root(char input_string[],int *error){
        int j=0;
        int i=0;
        int k=0;
        int l=0;
        int p=0;
    char root_string[1000];
        for(i=0;i<strlen(input_string);i++){
            if(input_string[i]=='r'&&input_string[i+1]=='o'&&input_string[i+2]=='o'&&input_string[i+3]=='t'){
                i=i+4;
                int rootnumber=0;
                for(j=i;j<strlen(input_string)+1;j++){
                    
                    if(input_string[j]=='+'||input_string[j]=='-'||input_string[j]=='*'||input_string[j]=='/'||input_string[j]=='\0'||input_string[i]=='('||input_string[i]==')'){
                      
                        break;
                    }
                    root_string[rootnumber]=input_string[j];
                    rootnumber++;
                    lastcharacterroot=j;
                    
                    
                    
                }
                root_string[rootnumber]='\0';
                // Root to power of N
                if(input_string[i-5]==']'){
                    bool isfullroot=false;
                    char n_array[500];
                    char leftover_input_string[1000];
                    char new_input_string[1000];
                    char root_input_string[1000];
        
                    i=i-5;
                    for(p=0;p<strlen(input_string);p++){
        
                        if(input_string[p]=='['){
           
                            isfullroot=true;
                            break;
                        }
                    
                    }
   
                    if(isfullroot==false){
                       
                        *error=1;
                        break;
                    }
                    // N not initialize
                    if(p+1==i){
                        printf("N not initialize\n");
                        break;
                    }

                    for(k=p+1;k<=i-1;k++){
                        n_array[l]=input_string[k];
                        l++;
                    }
                    n_array[l]='\0';
     
                    k=0;
                    // RIGHT OF ROOT
                    for(j=lastcharacterroot;j<=strlen(input_string);j++){
                        leftover_input_string[k]=input_string[j];
                        k++;
                    }
                    leftover_input_string[k]='\0';
          
                    for(k=0;k<=p-1;k++){
                        new_input_string[k]=input_string[k];

                    }
                    new_input_string[k]='\0';
 
                    float number = atof(root_string);
                    float n = atof(n_array);
     
                    float root = pow(number, 1.0 / n);
                    sprintf(root_input_string, "%.2f", root);
   
                    input_string[0]='\0';
                    for(i=0;i<=strlen(new_input_string);i++){
                        input_string[i]=new_input_string[i];
                    }
         
                    for(k=0;k<strlen(root_input_string);k++){
                        input_string[i-1]=root_input_string[k];
                        i++;
                    }
                    input_string[i-1]='\0';
             
                    for(k=0;k<strlen(leftover_input_string);k++){
                        input_string[i-1]=leftover_input_string[k];
                        i++;
                    }
                    input_string[i-1]='\0';
       
                }else{
                    i=i-4;
                    float number = atof(root_string);
                    float root = pow(number, 1.0 / 2);
                    char root_input_string[1000];
                    char new_input_string[1000];
                    char leftover_input_string[1000];
           
                    sprintf(root_input_string, "%.2f", root);
     
                    for(j=i;j>=0;j--){
                        new_input_string[j]=input_string[j];
                    }
                    new_input_string[i]='\0';
          
                    if(new_input_string[i-1]=='['){
                        *error=1;
                        break;
                    }
                    for(j=0;j<=strlen(root_input_string);j++){
                        new_input_string[i]=root_input_string[j];
                        i++;
                    }
                    new_input_string[i]='\0';

                    for(j=lastcharacterroot;j<=strlen(input_string);j++){
                        leftover_input_string[k]=input_string[j];
                        k++;
                    }

                    i=strlen(new_input_string);
                    for(j=0;j<=k;j++){
                        new_input_string[i]=leftover_input_string[j];
                        i++;
                    }
 
                    for(i=0;i<=strlen(new_input_string);i++){
                        input_string[i]=new_input_string[i];
                    }
                    input_string[i+1]='\0';
 
                }
            }

        }
        
    for(i=0;i<strlen(input_string);i++){
        if(input_string[i]=='r'&&input_string[i+1]=='o'&&input_string[i+2]=='o'&&input_string[i+3]=='t'){
            root(input_string,error);
            break;
        }
    }
        
}
void brackets(char input_string[],int *error){ 
    int fistright=0;
    int fistleft=0;

    bool isfirst=false;
    bool isfirstleft=false;
    int lastleft=0;
    char BracketString[1000];
    char TempString[1000];
    char TempString2[1000];
    for(i=0;i<strlen(input_string);i++){
        if(input_string[i]=='('){ 
            if(isfirstleft==false){
                fistleft=i;
                isfirstleft=true;
            }
            startbracket++;
            lastleft=i;

        }
        if(input_string[i]==')'){
            if(isfirst==false){
                fistright=i;
                isfirst=true;
            }
            endingbracket++;

            
        }
    }
    

    if(lastleft<0){
  
        *error=1;
    }
    if(input_string[lastleft-1]!='+'&&input_string[lastleft-1]!='-'&&input_string[lastleft-1]!='*'&&input_string[lastleft-1]!='/'){

        if(lastleft==0){

        }else{
            *error=1;
        }
        
    }
    p=0;
    if(lastleft>fistright){
        j=0;
        for(j=fistleft+1;j<=fistright-1;j++){
            BracketString[p++]=input_string[j];
        }
        BracketString[p]='\0';
  
        
        for(j=0;j<fistleft;j++){
            TempString[j]=input_string[j];
            
        }
        TempString[j]='\0';
        int counter=0;
        for(j=fistright+1;j<=strlen(input_string);j++){
            TempString2[counter]=input_string[j];
            counter++;
        }
 
    }else{
   
        for(j=lastleft+1;j<=fistright-1;j++){
            BracketString[p++]=input_string[j];
        }
        BracketString[p]='\0';
        for(j=0;j<lastleft;j++){
            TempString[j]=input_string[j];
            
        }
        TempString[j]='\0';
       
        int counter=0;
        for(j=fistright+1;j<=strlen(input_string);j++){
            TempString2[counter]=input_string[j];
            counter++;
        }
     
    }
    
    //IS ROOT ?
    for(i=0;i<strlen(BracketString);i++){
            if(BracketString[i]=='r'&&BracketString[i+1]=='o'&&BracketString[i+2]=='o'&&BracketString[i+3]=='t'){
                root(BracketString,error);
            
                break;
            }
    }
    for(i=0;i<strlen(BracketString);i++){
            if(BracketString[i]=='s'&&BracketString[i+1]=='i'&&BracketString[i+2]=='n'){
                sinus(BracketString,error);
             
                break;
            }
    }
 
    for(i=0;i<strlen(BracketString);i++){
            if(BracketString[i]=='c'&&BracketString[i+1]=='o'&&BracketString[i+2]=='s'){
                cosinus(BracketString,error);
             
                break;
            }
    }

    for(i=0;i<strlen(BracketString);i++){
            if(BracketString[i]=='^'){
                exponentiation(BracketString,error);
            
                break;
            }
    }
    for(i=0;i<strlen(BracketString);i++){
            if(BracketString[i]=='l'&&BracketString[i+1]=='o'&&BracketString[i+2]=='g'){
                logaritm(BracketString,error);
              
                break;
            }
    }

    for(i=0;i<strlen(BracketString);i++){
            if(BracketString[i]=='*'){
                multiplication(BracketString,error);
             
                break;
            }
    }

    for(i=0;i<strlen(BracketString);i++){
            if(BracketString[i]=='/'){
                devide(BracketString,error);
             
                break;
            }
    }

    for(i=0;i<strlen(BracketString);i++){
            if(BracketString[i]=='+'){
                plus(BracketString,error);
             
                break;
            }
    }

    for(i=0;i<strlen(BracketString);i++){
            if(BracketString[i]=='-'){
                minus(BracketString,error);
              
                break;
            }
    }
  
    //counter=0;
    input_string[0]='\0';
    for(i=0;i<=strlen(TempString);i++){
        input_string[i]=TempString[i];
    }
   
    i--;
    for(j=0;j<=strlen(BracketString);j++){
        input_string[i]=BracketString[j];
        i++;
    }
    i--;
    input_string[i]='\0';
    for(j=0;j<=strlen(TempString2);j++){
        input_string[i]=TempString2[j];
        i++;
    }
    input_string[i]='\0';
   
    for(i=0;i<strlen(input_string);i++){
        if(input_string[i]=='('){ 
        brackets(input_string,error);
        break;
        }
    }
}