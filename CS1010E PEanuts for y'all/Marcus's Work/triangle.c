#include <stdio.h>

int main(void) {
   int side1 , side2 , side3 ; 

   printf("Enter three sides of the triangle: ") ;
   scanf("%d %d %d" , &side1 , &side2 , &side3) ; 

   if (( side1 == side2 ) && ( side1 == side3) && ( side2 == side3)) { 
      printf("Triangle with sides %d %d %d is equilateral\n" , side1 , side2 , side3) ;
      } 
  
  else if (  (( side1 == side2 ) || ( side1 == side3) || ( side2 == side3))) { 
     printf("Triangle with sides %d %d %d is isosceles\n" , side1 , side2 , side3) ;
     } 

     else {
        printf("Triangle with sides %d %d %d is scalene\n" , side1 , side2 , side3) ;
        }  

   return 0;
}
