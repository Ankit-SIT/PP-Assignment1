/*
Ankit Das
19070122023
5th August 2020
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

char *tostr(int n){
    char *result = malloc(32*sizeof(char));
    sprintf(result,"%d",n);
    return result;
}

char *strrev(char *string)
{
    if (!string || ! *string)
        return string;

    int i = strlen(string) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = string[i];
        string[i] = string[j];
        string[j] = ch;
        i--;
        j++;
    }
    return string;
}

char* fromDecimal(int decimal,int base)
{
 const char *hex[] = {"A","B","C","D","E","F"};
 unsigned int current = 0;
 char* result = malloc(32*sizeof(char));

 while(decimal){   
  switch(base)
  {
      case 16:
           current = decimal % base;
           decimal /= base;
           if(current > 9){
             strncat(result,hex[current-10],1); 
           }

           else{
               strcat(result,tostr(current));
           }
           break;

      case 2:
      case 8:
           current = decimal % base;
           decimal /= base;
           strcat(result,tostr(current));
           break;

      case 10:
           strcat(result,tostr(decimal));
           return result;
           break;
      
      default:
           printf("\n\nBaseError: Unsupported base!");
           return 0;
           break;       
  }
 }  
  return strrev(result);
}

long int toDecimal(char* str, int base){
unsigned int i = 0;
long int result = 0;

switch (base)
{
case 2:
    result =  strtol(str,NULL,2);   
    break;

case 8:
    result = strtol(str,NULL,8);
    break;

case 16:
    result = strtol(str,NULL,16);
    break;

case 10:
    result = strtol(str,NULL,10);
    break;

default:
    break;
}

return result;
}


int main()
{
   char number[10];
   unsigned int base = 0 , decimal = 0;
   printf("<positive number> <base>\n");
   scanf("%s %d",&number,&base); 

   decimal = toDecimal(number,base);
   printf("\nDecimal - %ld",decimal);
   printf("\nBinary - %s",fromDecimal(decimal,2));
   printf("\nOctal - %s",fromDecimal(decimal,8));
   printf("\nHexadecimal - %s\n",fromDecimal(decimal,16));

   return 0; 
}
