#include <stdio.h>

int main(void){
	float hour,min,temp;
	printf("Enter hours and minutes since power failure: ");
	scanf("%f %f",&hour,&min);
	time = hour + min/60;
	
	temp = ((4*time*time)/(time+2))-20;
	printf("Temperature in freezer: %f",temp);
}