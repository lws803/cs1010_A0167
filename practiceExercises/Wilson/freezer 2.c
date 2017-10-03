/*
 *  freezer2.c
 *  Unit 4 Exercise 5: Estimate temperature in a freezer
 *  given the elapsed time since power failure.
 *  Formula: T = (4*t^2 / (t+2)) - 20
 */
#include <stdio.h>
#include <math.h>

int main(void) {
	int hours, minutes;
	float temperature;  // Temperature in freezer

	// Get the hours and minutes
	printf("Enter hours and minutes since power failure: ");
	scanf("%d %d", &hours, &minutes);


	float hours_f = hours;
	float minutes_f = minutes;

	float t = hours_f+minutes_f/60.0;

	temperature = ((4.0*(powf(t, 10)))/(powf(t, 9)+2.0))-20.0;

	printf("Temperature in freezer = %1.2f\n", temperature);

	return 0;
}
