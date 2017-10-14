#include <stdio.h>

int main(void) {
   
   int no1 , no2 , no3 , mid ;

   printf("Enter three values: ") ; 
   scanf("%d %d %d" , &no1 , &no2 , &no3)  ; 

   if ( ( ( no1 <= no2 ) && (no1 >= no3) ) || ( ( no1 >= no2 ) && (no1 <= no3) ) ) { 
      mid = no1 ;
   } 

    else if ( ( ( no2 <= no1 ) && (no2 >= no3) ) || ( ( no2 >= no1 ) && (no2 <= no3) ) ) {
    mid = no2 ;
 }
   
   else {
      mid = no3 ; 
   }

   printf("The middle value is %d\n" , mid) ;

return 0;
}
