#include <stdio.h>

int main(void) {
  int hoursStart , minutesStart , secondsStart ;
  int hoursEnd , minutesEnd , secondsEnd ; 
  int hoursDiff , minutesDiff , secondsDiff ; 

  int hoursInSec , minutesInSec ; 

  int secondsDiffTotal ; 

  scanf("%d %d %d" , &hoursStart , &minutesStart , &secondsStart) ; 

  scanf("%d %d %d" , &hoursEnd , &minutesEnd , &secondsEnd) ; 

  hoursDiff = hoursEnd - hoursStart ; 
  minutesDiff = minutesEnd - minutesStart ; 
  secondsDiff = secondsEnd - secondsStart ; 

  hoursInSec = hoursDiff * 60 * 60 ;
  minutesInSec = minutesDiff * 60 ;

  secondsDiffTotal = secondsDiff + hoursInSec + minutesInSec ;


  printf("%d\n" , secondsDiffTotal) ;

   return 0;
}
