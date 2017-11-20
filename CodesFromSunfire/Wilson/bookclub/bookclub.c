#include <stdio.h>
#include <string.h>
#define MAX_MEMBER 20
#define MAX_RECORD 100
#define MAX_RESULT 1000
#define MAX_LENGTH 50

typedef struct {
	char name[MAX_LENGTH+1];
	char title[MAX_LENGTH+1];
} result_t;

typedef struct {
	int id;
	char name[MAX_LENGTH+1];
} member_t;

typedef struct {
	int memID;
	char title[MAX_LENGTH+1];
} record_t;

void sortResults(result_t results[], int);
void printResults(result_t results[], int);
int readInputs (record_t [], member_t [], int *, int *);
int leftJoin (record_t [], member_t [], result_t [], int, int );  
int innerJoin (record_t [], member_t [], result_t[], int , int ); 


int main(void) {
	int numRes;
	result_t results[MAX_RESULT];
	record_t records[MAX_RECORD];
	member_t members[MAX_MEMBER];
	int numMembers, numRecords;

	if (readInputs (records, members, &numMembers, &numRecords) == 1) {
		numRes = innerJoin(records, members, results, numRecords, numMembers);

	}else {
		numRes = leftJoin(records, members, results, numRecords, numMembers);
	}

	sortResults(results, numRes);
		
	printf("The results of the join are as follows: \n");
	printResults(results, numRes);
	
	return 0;
}



// Sort the results first by name and then by book title
// in alphabetical order
void sortResults(result_t results[], int size){
	int i, start, index;
	result_t temp;
  
	for (start = 0; start < size-1; start++) {
		index = start;
		for (i = start+1; i < size; i++)
			if (strcmp(results[i].name, results[index].name) < 0 || 
				(strcmp(results[i].name, results[index].name) == 0 
					&& strcmp(results[i].title, results[index].title) < 0))
				index = i;

		temp = results[start];
		results[start] = results[index];
		results[index] = temp;
	}
}

void printResults(result_t results[], int size){
	int i;
	
	for (i = 0; i < size; i++){
		printf("%s %s\n", results[i].name, results[i].title);
	}
}

int readInputs (record_t records[], member_t members[], int *numMembers, int *numRecords) {
	int size_members, size_records, i;
	scanf("%d", &size_members);
	for (i = 0; i < size_members; i++) {
		scanf ("%d %s", &members[i].id, members[i].name);
	}
	scanf ("%d", &size_records);
	for (i = 0; i < size_records; i++) {
		scanf ("%d %s", &records[i].memID, records[i].title);
	}

	*numMembers = size_members;
	*numRecords = size_records;

	int option;
	scanf("%d", &option);

	return option;
}

int innerJoin (record_t records[], member_t members[], result_t results[], int numRecords, int numMembers) {
	int i, d, index = 0;
	for (i = 0; i < numMembers; i++) {
		for (d = 0; d < numRecords; d++) {
			if (records[d].memID == members[i].id) {
				strcpy(results[index].name, members[i].name);
				strcpy(results[index].title, records[d].title);
				index++; 
			}
		}
	}
	return index;
}

int leftJoin (record_t records[], member_t members[], result_t results[], int numRecords, int numMembers) {
	int i, d, index = 0;
	for (i = 0; i < numMembers; i++) {
		int count = 0;
		for (d = 0; d < numRecords; d++) {
			if (members[i].id == records[d].memID) {
				strcpy(results[index].name, members[i].name);
				strcpy(results[index].title, records[d].title);
				index++;
				count++;
			}
		}
		if (count == 0) {
			strcpy(results[index].name, members[i].name);
			strcpy(results[index].title, "***");
			index++;
		}
	}
	return index;
}