#include <stdio.h>
#include <math.h>


double cartesian_distance (double [], double []);
int main () {
	int num_features = 2, d;
	double features[2][3] = {{3, 3, 3}, {5, 10, 6}};
	double target[3];

	printf ("Enter target (x, y, z): ");
	for (d = 0; d < 3; d++) {
		scanf("%lf", &target[d]);	
	}

	double distance = cartesian_distance (features[0], target);
	int i, first = 0, index = 0;
	for (i = 0; i < num_features; i++) {
		double internal_distance = cartesian_distance (features[i], target);
		if (distance > internal_distance) {
			index = i;
			distance = internal_distance;
		}
	}

	printf ("Nearest feature: (%0.2lf, %0.2lf, %0.2lf)\n", features[index][0], 
		features[index][1], features[index][2]);
	
	printf ("distance: %0.2lf\n", distance);

}

double cartesian_distance (double feature[], double target[]) {
	double x = target[0] - feature[0];
	double y = target[1] - feature[1];
	double z = target[2] - feature[2];
	return sqrt (x*x + y*y + z*z);
}

