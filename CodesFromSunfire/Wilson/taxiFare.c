#include "stdio.h"

float totalMeteredFare (int distance) {
	float meterdFare = 0;

	if (distance>1000) {
		//1st 1km 
		distance -= 1000;
		meterdFare += 3.40;
	}
	
	int distanceTabulated=0;
	while (distanceTabulated<9200 && distance >0) {
		meterdFare += 0.22;
		distanceTabulated += 400;
		distance -= 400;
	}

	while(distance > 0 && distanceTabulated>=9200) {
		//After 10.2km
		meterdFare += 0.22;
		distance -= 350;
	}
	return meterdFare;
}


float computeFare(int dayType, int boardTime, int distance){
	float fare;
	if (dayType) {
		//Day type = weekdays and non PH
		if (boardTime >0 && boardTime <=359) {
			//midnight charge
			fare = totalMeteredFare(distance)*1.50;
		}
		else if (boardTime>=1080 && boardTime<=1439) {
			//6pm to 11:59pm
			fare = totalMeteredFare(distance)*1.25;
		}else if (boardTime>= 360 && boardTime<= 569) {
			//peak hour 6am to 9:29am
			fare = totalMeteredFare(distance)*1.25;
		}
		else{	
			fare = totalMeteredFare(distance);
		}

	}else{

		if (boardTime >0 && boardTime <=359) {
			//midnight charge
			fare = totalMeteredFare(distance)*1.50;
		}
		else if (boardTime>=1080 && boardTime<=1439) {
			//6pm to 11:59pm
			fare = totalMeteredFare(distance)*1.25;
		}else if (boardTime>= 360 && boardTime<= 569) {
			//peak hour 6am to 9:29am
			fare = totalMeteredFare(distance);
		}
		else{	
			fare = totalMeteredFare(distance);
		}
	}

	printf("%f\n", fare);


	return fare;
}




int main(int argc, char const *argv[])
{
	int dayType, boardHour, boardMin, distance;

	printf("Day type: ");
	scanf("%d", &dayType);

	printf("Boarding hour and minute: ");
	scanf("%d %d", &boardHour, &boardMin);

	printf("Distance: ");
	scanf("%d", &distance);


	int boardTime = boardHour*60 + boardMin;
	printf("Boarding time is %d minutes\n", boardTime);
	printf("Total taxi fare is $%0.2f\n", computeFare(dayType, boardTime, distance));

	return 0;
}




/*
Day type: 0
Boarding hour and minute: 14 27
Distance: 10950
Boarding time is 867 minutes
Total taxi fare is $9.12
*/
