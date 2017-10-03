// CS1010 AY2012/3 Semester 1
// PE1 Ex2: ucard.c
// Name:
// Matriculation number:
// plab account-id:
// Discussion group:
// Description:

#include <stdio.h>


int checkNumber (int);
void checkRegion (int);

int main(void) {

	int uCardNo;
	printf("Enter uCard Number: ");
	scanf("%d", &uCardNo);


	printf("The check number is %d\n", 	checkNumber(uCardNo));

	//multiples of 7
	if (checkNumber(uCardNo)%7 == 0) {
		printf("Valid\n");
		checkRegion(uCardNo);
	}else{
		printf("Invalid\n");
	}

	return 0;

}


int checkNumber (int ucardNo) {
	int count = 1, sum = 0, boolean = 0;

	while (ucardNo > 0) {
		if (count % 2 == 0) {

			int number = ucardNo % 10 * 2;

			while (number > 0 ){
				sum += number % 10;
				number /= 10;
			}

		}else {
			sum += ucardNo%10;
		}

		ucardNo /= 10;
		count++;
	}
	return sum;
}

void checkRegion (int ucardNo) {
	int count = 1; 
	int first2 = ucardNo;

	while (first2/count >= 100) {
		count *= 10;
	}

	first2 /= count;

	printf("Issued by ");

	if (first2 >= 31 && first2 <= 35){
		printf("East branch\n");
	}else if (first2 >= 51 && first2 <= 55){
		printf("West branch\n");
	}else {
		printf("Central branch\n");
	}


}




