#include <stdio.h>

int main(void) {
     
   int a , b , sum=0 ;
   int sumOfDigits =0 ;
   int carryNow = 0 , carryNext = 0 , carryValue = 1 , prevCarryValue = 1  ;
   int top , bottom ;
   int check = 0 ;

   scanf("%d %d" , &a , &b ) ;
   
   top = a ; 
   bottom = b ;
   
   if ( a > b ) {
      printf("Write %d above %d.\n" , a , b ) ;
   } 

   else if ( b > a ) {
      printf("Write %d above %d.\n" , b , a ) ;
      top = b ; 
      bottom = a ;
   }

   

   sum = a + b ; 



   while ( top > 0 ) {
      
      sumOfDigits = (top%10) + (bottom%10) ;

      if ( bottom%10 != 0 || (bottom%10 == 0 && bottom >=10) ) {
      printf("Adding %d and %d " , top%10 , bottom%10) ;
      }
      
      else if( bottom%10 == 0 && carryNow == 1) {
      printf("Adding %d " , top%10 ) ;
      } 

      else if ( bottom%10 == 0 ) {
         printf("Bring down %d.\n" , top%10 ) ;
         check = 1 ;
      }

      
      if (check == 0 ) {

      if ( carryNow == 1 ) {
         carryNow = 0 ;
         sumOfDigits += prevCarryValue ;
         
         printf("with carry 1 ") ;
      }

      if ( sumOfDigits >= 10 ) {
         carryNext = 1 ;
         prevCarryValue = carryValue ;
         carryValue = 1 ;
         sumOfDigits = sumOfDigits % 10 ;

      } 


      printf("gives %d" , sumOfDigits ) ;

      if (carryNext == 1 ) { 
         carryNext = 0 ;
         carryNow = 1 ;

         printf(", then carry %d.\n" , carryValue ) ;

      } 

      else {
         printf(".\n") ;
      }
   }
      
      top /= 10 ; 
      bottom /= 10 ;
      check = 0 ;
      }

   if (carryNow == 1 ) {
      printf("Bring down 1.\n") ;
   }

   printf("The answer is %d.\n" , sum ) ;

   return 0;
}
