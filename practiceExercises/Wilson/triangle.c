#include <stdio.h>
#include <math.h>

double distance(int x1, int x2, int y1, int y2){
	float x1_f = x1;
	float x2_f = x2;
	float y1_f = y1;
	float y2_f = y2;


	double distance = sqrt(pow(x1_f-x2_f, 2)+pow(y1_f-y2_f, 2));

	return distance;
}



int main(int argc, char const *argv[])
{
	int x_1, y_1, x_2, y_2, x_3, y_3;

	printf("Enter 1st point: ");
	scanf("%d %d", &x_1, &y_1);
	printf("Enter 2nd point: ");
	scanf("%d %d", &x_2, &y_2);
	printf("Enter 3rd point: ");
	scanf("%d %d", &x_3, &y_3);

	double perimeter = distance(x_1, x_2, y_1, y_2) + distance(x_2, x_3, y_2, y_3) + distance(x_1, x_3, y_1, y_3);
	printf("Perimter of triangle = %.2lf\n", perimeter);

	return 0;
}