#include <stdio.h>

int main(void) {

   int income , credit , debt , risk ;
   
   scanf("%d %d %d" , &income , &credit , &debt ) ; 
   
   if ( income < 15000 ) { 
      risk = 1 ; } 

      else if ( income > 35000 ) { 
         if ( credit == 0 ) { 
            risk = 1 ; } 
       else if ( credit == 1 ) { 
            risk = 3 ; } 
         else {
            risk = 2 ; } } 
   
 else if ( income >= 15000 && income <= 35000 )  {
      if ( credit == 0 ) { 
         risk = 2 ; } 
     else if ( credit == 1 ) { 
         risk = 4 ; } 

      else if ( debt == 0 ) { 
         risk = 5 ; }   
         
         else { risk = 3 ; }  } 

   printf("%d\n" , risk ) ;
   

   return 0;
}
