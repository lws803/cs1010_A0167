#include <stdio.h>
#include <string.h>
#define MAX_CUSTOMER 20
#define MAX_RECORD 100
#define MAX_LENGTH 50

typedef struct {
	int id;
	char name[MAX_LENGTH+1];
} customer_t;

typedef struct {
	int cusID;
	char category[MAX_LENGTH+1];
	int spending;
} record_t;

void printRecords(record_t [], int, int);
void readRecords (customer_t [], record_t [], int *, int *); 
int insert_at (record_t[], record_t, int, int); 
void search (customer_t [], record_t [], int, int); 


int main(void) {
	customer_t customers[MAX_CUSTOMER];
	record_t records[MAX_RECORD];
	int customer_size, records_size;
	readRecords(customers, records, &customer_size, &records_size);
	search (customers, records, customer_size, records_size);
	return 0;
}


void printRecords(record_t records[], int size, int cusID){
	int i;
	
	for (i = 0; i < size; i++)
		if (records[i].cusID == cusID)
			printf("%s %d\n", records[i].category, records[i].spending);

}

void readRecords (customer_t customers[], record_t records[], int *customer_size, int *records_size) {
	int numCustomers, numRecords, i ,d;
	printf("Enter number of customers: ");
	scanf ("%d", &numCustomers);
	printf("Enter customers: \n");
	for (i = 0; i < numCustomers; i++) {
		scanf("%d %s", &customers[i].id, customers[i].name);
	}

	printf("Enter number of records: ");
	scanf("%d", &numRecords);
	printf("Enter records: \n");
	// Sort on insert 

	int index = 0;
	for (i = 0; i < numRecords; i++) {
		record_t thisRecord;
		scanf ("%d %s %d", &thisRecord.cusID, thisRecord.category, &thisRecord.spending);
		for (d = index-1; d >= 0; d--) {
			if (records[d].spending > thisRecord.spending) {
				index =  insert_at (records, thisRecord, d+1, index);
				break;
			}
		}
		// If smallest or if index is 0
		if (d < 0) {
			index =  insert_at (records, thisRecord, 0, index);
		}
	}

	*customer_size = numCustomers;
	*records_size = numRecords;
}


void search (customer_t customers[], record_t records[], int customer_size, int records_size) {
	int i, key = -1, count = 0;
	char name[MAX_LENGTH+1];
	printf("Enter name: ");
	scanf ("%s", name);
	// Linear search
	for (i = 0; i < customer_size; i++) {
		if (strcmp(name, customers[i].name) == 0) {
			key = customers[i].id;
			break;
		}
	}
	// To check if there are any records for that person. 
	if (key != -1) {
		for (i = 0; i < records_size; i++) {
			if (records[i].cusID == key)
				count++;
		}
	}
	if (key != -1 && count > 0) {
		printf("The records for are as follows: \n");
		printRecords (records, records_size, key);
		return;
	}
	printf("No record can be found for %s\n", name); // Incomplete
}

int insert_at (record_t arr[], record_t element, int atIndex, int size) {
    int i;
    for (i = size-1; i >= atIndex; i--) {
        arr[i+1] = arr[i];
    }
    arr[atIndex] = element;
    size++;
    return size;
}