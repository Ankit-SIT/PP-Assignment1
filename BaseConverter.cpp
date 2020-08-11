/*
Ankit Das
19070122023
7th August 2020

*/

#include<iostream>
#include<string>

std::string strrev(std::string str)
{
    if (str.empty())
        return str;

    int i = str.length() - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}

std::string fromDecimal(long int decimal,int base)
{
 std::string hex[] = {"A","B","C","D","E","F"};
 std::string result;
 unsigned int current = 0;
 
 while(decimal){   
  switch(base)
  {
      case 16:
           current = decimal % base;
           decimal /= base;
           if(current > 9){
             result += hex[current-10]; 
           }

           else{
               result += std::to_string(current);
           }
           break;

      case 2:
      case 8:
           current = decimal % base;
           decimal /= base;
           result += std::to_string(current);
           break;

      case 10:
           result += std::to_string(decimal);
           return result;
           break;
      
      default:
           std::cout<<"\n\nBaseError: Unsupported base!";
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
   std::cout<<"<positive number> <base>     [upto 11 digits long]\n";
   std::cin>>number>>base; 

   decimal = toDecimal(number,base);
   std::cout<<"\nDecimal - "<< decimal;
   std::cout<<"\nBinary - "<<fromDecimal(decimal,2);
   std::cout<<"\nOctal - "<<fromDecimal(decimal,8);
   std::cout<<"\nHexadecimal - "<<fromDecimal(decimal,16)<<std::endl;

   return 0; 
}