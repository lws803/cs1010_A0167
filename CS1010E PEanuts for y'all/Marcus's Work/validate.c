#include <stdio.h>

int main(void) {
  
  int age , count ; 

  printf("Enter age: ") ; 
  scanf("%d" , &age ) ; 

  for ( count = 1 ; age > 100 || age < 1 ; count++ ) { 
     printf("Enter age: ") ; 
     scanf("%d" , &age ) ; 
  } 

  printf("Your age is %d.\n" , age) ;
  printf("Number of attempts = %d\n" , count) ;

   return 0;
}
