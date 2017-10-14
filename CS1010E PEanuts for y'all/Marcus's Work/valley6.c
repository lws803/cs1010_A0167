#include <stdio.h>

int main(void) {

   int height , prevHeight ; 
   int valleyCheck = 0 , valleyHeight = 0 , valleyMaxHeight = 0 ;
   int up = 0 , down = 0 ;

   scanf("%d" , &prevHeight) ;
   scanf("%d" , &height) ;

   while ( prevHeight != -1 && height != -1 ) { 
  

         if ( height > prevHeight ) {
            up = 1 ;

            if (down == 1 && up == 1) {

               down = 0 ;
               up = 0 ;

               if (valleyHeight >= valleyMaxHeight) {
                  valleyMaxHeight = valleyHeight ;
                  valleyCheck = 1 ;
               }

            } 
         }

         else if ( height < prevHeight ) {
            valleyHeight = height ;
            down = 1 ;
         } 

         prevHeight = height ;

         scanf("%d" , &height) ;

      } 
 
   if ( valleyCheck == 0 ) {
      printf("NONE\n") ;
   } 

   if ( valleyCheck == 1 ) {
      printf("%d\n" , valleyMaxHeight) ;
   }
   

   return 0;
}
