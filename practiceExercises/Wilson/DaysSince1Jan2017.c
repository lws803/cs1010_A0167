#include <stdio.h>


int computeDays(int, int);


int main() {
	int day, month;
	printf("Enter day and month: ");
	scanf("%d %d", &day, &month);
	printf("Day %d of month %d is the %dth day of 2017\n", day, month, computeDays(day, month));
}


int computeDays(int day, int month) {
	int i, sumOfDays = 0;
	for (i= 0; i<month-1; i++){
		switch (i) {
			case 0: case 2: case 4: case 6: case 7: case 9: case 11:
			sumOfDays+= 31;
			break;
			case 1: 
			sumOfDays += 28;
			break;
			default: 
			sumOfDays += 30;
		}
	}
	sumOfDays += day;

	return sumOfDays;
}
