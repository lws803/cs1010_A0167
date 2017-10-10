#include <stdio.h>

int body_type(int,int,int);

int main(void) {
	int gender,status;
	double weight, height;
	
	printf("Enter your gender (0 for female, 1 for male): ");
	scanf("%d",&gender);
	
	printf("Enter your weight (kg) and height (m): ");
	scanf("%lf %lf",&weight,&height);
	
	status = body_type(gender,weight,height);
	
	if (status == 0) {
		printf("Great! Maintain it!);
	}
	else if (status > 1) {
		printf("Time to join the gym!");
	}
	else if (status < 1) {
		printf("Stuff yourself with more food!");
	}	
	return 0;
}

// This function accepts weight and height of the person to compute the BMI.
// Then determines if the person is overweight, underweight or acceptable and returns the respective values.
int body_type(int gender,int weight, int height) {
	int bmi;
	
	bmi = weight/(height*height);
	
	if (gender == 0) { // If the person is a female.
		if (bmi <= 19) {
			return -1; 
		}
		else if (bmi >= 19 && bmi < 24) {
			return 0; 
		}
		else if (bmi >= 24) {
			return 1; 
		}
	}
	else { 	// If the person is a male.
		if (bmi <= 20) {
			return -1; 
		}
		else if (bmi >= 20 && bmi < 25) {
			return 0;
		}
		else if (bmi >= 25) {
			return 1; 
		}
	}	
}