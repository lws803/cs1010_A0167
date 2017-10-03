// CS1010 AY2011/2 Semester 1 
// PE1 Ex2: winners.c
// Name: 
// Matriculation number: 
// plab account-id: 
// Discussion group: 
// Description: 

#include <stdio.h> 

int winners (int, int, int); 
int containsNumber (int, int);

int main(void)
{
	int factor, mustHave, n;       

	printf ("Enter factor-digit: ");
	scanf("%d", &factor);
	printf("Enter must-have-digit: ");
	scanf("%d", &mustHave);
	printf("Enter number of participants: ");
	scanf("%d", &n);

	printf("Number of winners: %d\n", winners(factor, mustHave, n));

	return 0;
}



int winners (int factor, int mustHave, int n) {
	int i, count = 0;

	for (i = 1; i <= n; i++) {
		if (i % factor == 0 && containsNumber(mustHave, i)) {
			count++;
		}
	}

	return count;
} 


int containsNumber (int mustHave, int i) {
	int boolean = 0;
	while (i > 0) {
		if (i%10 == mustHave){
			boolean = 1;
		}
		i /= 10;
	}

	return boolean;
}