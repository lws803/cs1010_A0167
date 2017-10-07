#include <stdio.h>

int main(void) {

	int day , timeIn , timeOut ; 
	int timeInTotalMinutes, timeOutTotalMinutes , totalTimeParkedInMinutes ; 

	int timeInHourValue , timeInMinuteValue;

	int rateMorning = 0 , rateAfternoon = 0 , rateNight = 0 ;

	int feeBaseInCents = 0 , feeTotalInCents = 0 ;
	int feeTotalCents = 0 , feeTotalDollars = 0 ;

	/* User Input */ 

	printf("Enter day: ") ;
	scanf("%d" , &day) ;

	printf("Enter time-in: ") ;
	scanf("%d" , &timeIn) ;

	printf("Enter time-out: ") ;
	scanf("%d" , &timeOut) ;

	/* End of User Input*/

	/* Converting Time into into minutes & timeIn Hour & timeInMinute Value*/

	timeInTotalMinutes = (( timeIn / 100 ) * 60 ) + ( timeIn % 100 ) ; 
	timeOutTotalMinutes = (( timeOut / 100 ) * 60 ) + ( timeOut % 100 ) ; 

	timeInHourValue = timeIn / 100 ;
	timeInMinuteValue = timeIn % 100 ;

	/* Finding Parking Time */ 

	totalTimeParkedInMinutes = timeOutTotalMinutes - timeInTotalMinutes ; 

	/* Calculate number of times each rate is counted */

	if ( totalTimeParkedInMinutes > 10 ) {  /* Grace Period Exceeded */

		if ( timeIn < 700 ) { 
			
			while ( timeInHourValue < 7 && timeIn < timeOut ) { 
				rateMorning ++ ; 
				timeInHourValue ++ ; 
				timeIn += 100 ; 

				if ( timeIn > 700) {
					timeIn = 700 ; 
					timeInMinuteValue = 0 ;
				}
			}
		}
		
		if ( timeIn >= 700 && timeIn < 1800 && timeIn < timeOut ) {

			if ( timeInMinuteValue <= 29 ) {
				rateAfternoon ++ ;
				timeIn = (timeInHourValue * 100 ) + 30 ;
				timeInMinuteValue = 30 ; 
			}

			else if ( timeInMinuteValue >= 30 ) { 
				rateAfternoon ++ ; 
				timeIn = (timeInHourValue * 100 ) ;
				timeInMinuteValue = 0 ;
			}

			while ( timeIn < 1800 && timeIn < timeOut ) {
				rateAfternoon ++ ; 
				timeIn += 30 ; 
				timeInMinuteValue += 30 ;

				if ( timeInMinuteValue == 60 ) {
					timeIn += 40 ; 
					timeInMinuteValue = 0 ;
				}
			}
		}

		if ( timeIn >= 1800 && timeIn < timeOut ) {
			rateNight ++ ;
		}
	}


	/* Calculating Fee */
	
	if ( day <= 5 ) { /* Weekday */		
		feeBaseInCents = ( rateMorning * 200 ) + ( rateAfternoon * 120 ) + ( rateNight * 500 ) ;

		if ( totalTimeParkedInMinutes > 600 ) {
			feeTotalInCents = ( 110 * feeBaseInCents ) / 100 ; 
		}

		else {
			feeTotalInCents = feeBaseInCents ;
		}
	}
	
	if ( day == 6 ) {  /* Saturday */
		feeBaseInCents = ( rateMorning * 250 ) + ( rateAfternoon * 150 ) + ( rateNight * 700 ) ;

		if ( totalTimeParkedInMinutes > 600 ) {
			feeTotalInCents = ( 120 * feeBaseInCents ) / 100 ; 
		}

		else {
			feeTotalInCents = feeBaseInCents ;
		}
	}

	if ( day == 7 ) { /* Sunday */
		feeTotalInCents = 500 ;
	}	

	if ( totalTimeParkedInMinutes > 10 && timeOut > 2200 ) { /* Exiting after 10pm */
		feeTotalInCents += 300 ;
	}

	/* Convert Cents to Dollars */
	feeTotalDollars = feeTotalInCents / 100 ;
	feeTotalCents = feeTotalInCents % 100 ;


	if ( feeTotalCents >= 10 ) {
	
		printf("Parking fee is $%d.%d.\n" , feeTotalDollars , feeTotalCents ) ; 
	}

	else {
		printf("Parking fee is $%d.0%d.\n" , feeTotalDollars , feeTotalCents ) ; 

	}
	
   return 0;
}
