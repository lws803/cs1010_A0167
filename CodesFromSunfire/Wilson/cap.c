#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char module[8];
	float grade;
	int mcs;
}result_t;

typedef struct {
	char name[31];
	result_t results[50];
} student_t;


float convert_grade (char[]);
int read (student_t *);
float calc (student_t *, int );

int main(void) {
	student_t student;
	int size;

	size = read(&student);

	printf ("CAP = %0.2f\n", calc (&student, size));

	return 0;
}

int read (student_t *student) {
	int size;
	printf("Enter student's name: ");
	fgets (student->name, 30, stdin);

	printf("Enter number of modules taken: ");
	scanf ("%d", &size);
	printf("Enter results of 5 modules: \n");
	for (int i = 0; i < size; i++) {
		char grade [3];
		scanf ("%s %s %d", student->results[i].module, grade, &student->results[i].mcs);
		student->results[i].grade = convert_grade(grade);
		//printf("%s %f %d\n", student.results[i].module, student.results[i].grade, student.results[i].mcs);
	}

	return size;
}


float calc (student_t *student, int size) {
	float sum = 0, sum_mcs = 0;
	for (int i = 0; i < size; i++) {
		sum += student->results[i].mcs * student->results[i].grade; 
		sum_mcs += student->results[i].mcs;
	}

	return sum/sum_mcs;
}

float convert_grade (char str[]) {
	char arr[][3] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "D+", "D", "F"};

	for (int i = 0; i < 11; i++) {
		if (strcmp(str, arr[i]) == 0) {
			switch (i) {
				case 0: case 1:
				return 5.0;
				default: 
				return 5.0 - (i-1) * 0.5;
			}
		}
	}
	return -1;
}