#include <stdio.h>

int main(void) {
   
   int taxi , distance , day , hour , minute ; 
   int flagDown , rate ;
   int meteredFare ;
   int tabulatedDistance ;
   int timeInMinutes ;
   int totalFare ; 
   int dollars , cents , centsTen , centsOne ; 

  /*Input*/
   scanf("%d %d %d %d %d" , &taxi , &distance , &day , &hour , &minute) ; 
   
   /*Start of Flag Down and Rates Defining*/
   /*Normal Taxi*/
   if ( taxi == 1 ) { 
      flagDown = 340 ; 
      rate = 22 ; 
   } 

   /*Limousine*/
   else if ( taxi == 2 ) { 
      flagDown = 390 ; 
      rate = 22 ; 
   } 
   
   /*Chrysler */
   else { 
      flagDown = 500 ; 
      rate = 33 ; 
   } 
   
   /*End of Flag Down and Rates Defining*/

   /*Start of Metered Fare Calculation*/
   
   meteredFare = flagDown ; 
   tabulatedDistance = 0 ;

   /*1st km*/
   if ( distance >= 1000 ) { 
      distance -= 1000 ;
      tabulatedDistance += 1000 ;
   }
   
   /*Less than 10km of tabulated distance*/ 
  while ( distance > 0 && tabulatedDistance < 9800 ) { 
      meteredFare += rate ; 
      distance -= 400 ;
      tabulatedDistance += 400 ;
      }

  while ( distance > 0 && tabulatedDistance == 9800 ) { 
     meteredFare += rate ; 
     distance -= 200 ; 
     tabulatedDistance += 200 ;
  }


   /*More than 10km of tabulated distance*/
   while ( distance > 0 && tabulatedDistance >= 10000 ) {
       meteredFare += rate ; 
       distance -= 350 ; 
    } 
 
   /*End of Metered Fare Calculation*/

   /*Start of Surcharges*/
   timeInMinutes = ( hour * 60 ) + minute ;
   totalFare = meteredFare ; 

   if (timeInMinutes >= 0 && timeInMinutes < 360 ) {
      totalFare += (meteredFare /2) ;
   } 

   if ( day >= 1 && day <= 5 && timeInMinutes >= 360 && timeInMinutes <= 570 ) { 
      totalFare += ( meteredFare / 4 ) ; 
   } 

   if (timeInMinutes >= 1080 && timeInMinutes < 1440 ) { 
      totalFare += ( meteredFare / 4 ) ; 
   } 
   
   dollars = totalFare/100 ; 
   cents = totalFare%100 ; 

   centsOne = cents%10 ; 
   centsTen = cents/10 ; 
   
   if (centsOne > 0 ) {
      centsOne = 0 ; 
   } 

   printf("$%d.%d%d\n" , dollars , centsTen , centsOne ) ;

  
  
      
  return 0;
}
