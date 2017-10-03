// CS1010 AY2014/5 Semester 1
// PE1 Ex1: parking.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 


#include <stdio.h>

int processTime (int);
double computeFee(int, int, int);
double computeWeekdays (int, int);
double computeSat (int, int);
double computeSun (int, int);

int main(void){
	int day, timeIn, timeOut;
	double fee;

	printf("Enter day: ");
	scanf("%d", &day);

	printf("Enter time-in: ");
	scanf("%d", &timeIn);
	printf("Enter time-out: ");
	scanf("%d", &timeOut);


	fee = computeFee(day, timeIn, timeOut);

	printf("Parking fee is $%.2f.\n", fee);

	return 0;
}

//pre cond, time out is no earlier than time in
int processTime (int time) {
	int timeMins = 0;
	timeMins += time%100;
	timeMins += (time/100) * 60;

	return timeMins;
}


double computeFee(int day, int timeIn, int timeOut) {
	double fees = 0.0;


	if (processTime(timeOut) - processTime(timeIn) <= 10) {
		return fees;
	}


	switch (day) {
		case 1: case 2: case 3: case 4: case 5:
		fees = computeWeekdays(timeIn, timeOut);
		break;
		case 6: 
		fees = computeSat(timeIn, timeOut);
		break;
		case 7: 
		fees = computeSun(timeIn, timeOut);
		break;
	}

	return fees;
}


double computeWeekdays (int timeIn, int timeOut) {
	double fees;

	int converted_timeIn = processTime(timeIn);
	int converted_timeOut = processTime(timeOut) + 60 - processTime(timeOut)%60;

	while (converted_timeIn < converted_timeOut) {
		//4am to 7pm 
		if (converted_timeIn >= 240 && converted_timeIn < 420) {
			fees += 2.00;
			converted_timeIn += 60;
		}
		//7am to 6pm 
		else if (converted_timeIn >= 420 && converted_timeIn < 1080) {
			fees += 1.20;
			converted_timeIn += 30;
		}
		//6pm to midnight
		else if (converted_timeIn >= 1080) {
			fees += 5.00;
			break;
		}
	}
	
	//surcharge
	if ((processTime(timeOut) - processTime(timeIn))/60 >= 10) {
		fees *= 1.1;
	}

	if (processTime(timeOut) > 1320) {
		fees += 3.00;
	}

	return fees;
}

double computeSat (int timeIn, int timeOut) {
	double fees;

	int converted_timeIn = processTime(timeIn);
	int converted_timeOut = processTime(timeOut) + 60 - processTime(timeOut)%60;

	while (converted_timeIn < converted_timeOut) {
		//4am to 7pm 
		if (converted_timeIn >= 240 && converted_timeIn < 420) {
			fees += 2.50;
			converted_timeIn += 60;
		}
		//7am to 6pm 
		else if (converted_timeIn >= 420 && converted_timeIn < 1080) {
			fees += 1.50;
			converted_timeIn += 30;
		}
		//6pm to midnight
		else if (converted_timeIn >= 1080) {
			fees += 7.00;
			break;
		}
	}


	//surcharge
	if ((processTime(timeOut) - processTime(timeIn))/60 >= 10) {
		fees *= 1.20;
	}

	if (processTime(timeOut) > 1320) {
		fees += 3.00;
	}
	

	return fees;
}

double computeSun (int timeIn, int timeOut) {
	double fees;

	int converted_timeIn = processTime(timeIn);
	int converted_timeOut = processTime(timeOut) + 60 - processTime(timeOut)%60;

	fees += 5.00;

	if (processTime(timeOut) > 1320) {
		fees += 3.00;
	}
	

	return fees;
}

