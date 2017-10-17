#include <stdio.h>
#include <math.h>

int main(void){
	double hour,min,temp;
	printf("Enter hours and minutes since power failure: ");
	scanf("%lf %lf",&hour,&min);
	time = hour + min/60;
	
	temp = ((4*pow(time,10)/(pow(time,9)+2))-20;
	printf("Temperature in freezer: %lf",temp);
}