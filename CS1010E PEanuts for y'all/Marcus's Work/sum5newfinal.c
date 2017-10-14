#include <stdio.h>

int main(void) {

   int value = 1 ; 
   int sumPartial = 0 ;
   int sumMax = 0 ;
   int checkZero = 0 ;
   int i , start, end ;
   int overZero  = 0 ;
   int sumMaxPrev = 0 ;
   int checkMax = 0 ;
   int startPossible = 0 ;
   int compareMax = 0 ;

   start = 1 ;

   for ( i = 1 ; value != 0 ; i++ ) {

      scanf(" %d" , &value ) ;

      if (value != 0 ) {
      sumPartial += value ;
      
         if ( sumPartial > sumMax ) { 
            sumMax = sumPartial ;
            end = i ;
            overZero = 1 ;
               
         } 
         
         if ( overZero == 1 && sumPartial <= 0) {
            sumMaxPrev = sumMax ;
            checkMax = 1 ;
         } 

         if ( checkMax == 1 && sumPartial > 0 ) { 

               startPossible = i ;
               checkMax = 0 ;
               compareMax = 1 ;
            }

         if (compareMax == 1 && sumMax > sumMaxPrev ) { 
            start = startPossible ;
         }

        

         if ( checkZero == 0 ) {
            
            if ( sumPartial == 0 && sumMax == 0 ) { 
               checkZero = 1 ; 
            }
           
            if ( sumPartial < 0 && sumMax == 0 ) {
           
           sumMax = sumPartial ;
               end = i ; 
            } 
         }

      printf("%d,%d\n" , value, sumPartial ) ; 
      
}
     
     if ( sumPartial < 0 && overZero == 0 ) { 
         start = i + 1 ; 
     }
    
     
     if ( sumPartial < 0 ) { 
         sumPartial = 0 ;
          
      } 
}    

if (start > end ) { 
   start = end ; 
} 

 printf("%d[%d,%d]\n" , sumMax, start , end) ; 

   return 0;
}
