#include<stdio.h> 

int main(void) { 
   double massInKg , heightInM, bmi, heightInMSquared ; 

   scanf("%lf" , &massInKg ) ;

   scanf("%lf" , &heightInM ) ; 

   heightInMSquared = ( heightInM * heightInM ) ;
   bmi = (massInKg / heightInMSquared) ;  

   printf("%f\n" , bmi ) ; 


   return 0 ; 
} 
