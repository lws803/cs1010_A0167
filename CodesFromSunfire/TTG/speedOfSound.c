#include <stdio.h>
#include <math.h>

int main(void){
	double speed,temp;
	printf("Temperature in degree Fahrenheit: ");
	scanf("%lf",&temp);
	
	speed = 1086 * sqrt((5*temp + 297)/247);
	printf("Speed of sound in the air of %0.2lf degree: %0.2lf ft/sec\n",temp,speed);
}