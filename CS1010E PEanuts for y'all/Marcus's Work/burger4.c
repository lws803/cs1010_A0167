#include <stdio.h>

int main(void) {
   int burgers , sides, drinks ;
   int costB , costS , costD ;
   int total ; 
   int totalDollars ; 
   int totalCents ;

   scanf("%d %d %d" , &burgers , &sides , &drinks) ; 
   
   costB = 985 ;
   costS = 280 ; 
   costD = 195 ;
   

   total = ( burgers * costB ) + ( sides * costS ) + ( drinks * costD ) ; 
   total = total * 1.07 ;  
 
   totalDollars = total / 100 ;
   totalCents = total % 100 ; 

   if ( totalCents >= 10)   { 

   printf("$%d.%d\n" , totalDollars , totalCents ) ; 
   } 

   else {
      printf("$%d.0%d\n" , totalDollars, totalCents ) ; 
 }     
   return 0;
}
