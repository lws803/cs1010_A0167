#include <stdio.h>
#define MAX 20
#define MAX_TIME 1000

typedef struct {
	int start;
	int finish;
}interval_t;

int readLessons (interval_t[]); 
int longest_lesson (interval_t[], int); 
int num_free_period (int [], int, int); 
void timeline_store (int [], int , interval_t [], int *, int *) ; 
int max_concurrent (int [], int, int); 


int main () {
	interval_t intervals[MAX];
	int size = readLessons (intervals);
	int time_line [MAX_TIME] = {0};
	int start, finish;

	

	timeline_store (time_line, size,  intervals, &finish, &start);

	printf("Longest lesson: %d\n", longest_lesson(intervals, size));
	printf("Num of free periods: %d\n", num_free_period(time_line, start, finish));
	printf("Max no of concurrent lessons: %d\n", max_concurrent(time_line, start, finish));
}


int readLessons (interval_t intervals[]) {
	int size, i;
	scanf ("%d", &size);
	for (i = 0; i < size; i++) {
		scanf ("%d %d", &intervals[i].start, &intervals[i].finish);
	}

	return size;
}

int longest_lesson (interval_t intervals[], int size) {
	int i, longest = intervals[0].finish - intervals[0].start;
	for (i = 0; i < size; i++) {
		if (longest < intervals[i].finish - intervals[i].start) {
			longest = intervals[i].finish - intervals[i].start;
		}
	}

	return longest;
}

int num_free_period (int time_line[], int start, int finish) {
	int i, count = 0, turn = 0;

	for (i = start; i < finish; i++) {
		if (time_line[i] == 0 && !turn) {
			count++;
			turn = 1;
		}else if (time_line[i] > 0){
			turn = 0;
		}
	}
	
	return count;
}

int max_concurrent (int time_line[], int start, int finish) {
	int max = 0, i;
	for (i = start; i < finish; i++) {
		if (time_line[i] > max){
			max = time_line[i];
		}
	}
	return max;
}


void timeline_store (int time_line[], int size, interval_t intervals[], int *last, int *first) {
	// Look for finish time of last lesson
	int i, d, last_time = intervals[0].finish, first_time = intervals[0].start;
	for (i = 0; i < size; i++) {
		if (last_time < intervals[i].finish) {
			last_time = intervals[i].finish;
		}
		if (first_time > intervals[i].start) {
			first_time = intervals[i].start;
		}
	}

	for (i = 0; i < size; i++) {
		for (d = 0; d < last_time; d++) {
			if (d >= intervals[i].start && d <= intervals[i].finish) {
				time_line[d] += 1;
			}
		}
	}
	*last = last_time;
	*first = first_time;
}
