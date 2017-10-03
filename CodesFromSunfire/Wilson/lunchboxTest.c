#include "stdio.h"

int main() {
  int n, c, d, t, arraySchools[1000], totalLunchboxes, schoolsDistributed;


  printf("enter number of elements \n");
  scanf("%d", &n);

  printf("enter integers %d\n", n);
  for (c = 0; c < n; c++) {
    scanf("%d", &arraySchools[c]);
  }

  printf("key in total lunchboxes \n");
  scanf("%d", &totalLunchboxes);


  // Sorting algorithm
  for (c = 0; c < n; c++) {
    /* code */
    d = c;
    while (d > 0 && arraySchools[d] < arraySchools[d-1]) {
      /* code */
      t = arraySchools[d];
      arraySchools[d] = arraySchools[d-1];
      arraySchools[d-1] = t;

      d--;
      }
    }

    printf("sorted schools \n");

    for (c = 0; c < n; c++) {
      printf("%d \n", arraySchools[c]);

      if (totalLunchboxes>=arraySchools[c]) {
        totalLunchboxes = totalLunchboxes-arraySchools[c];
        schoolsDistributed = c+1;
      }
  }
  printf("school(s) distributed: %d \n", schoolsDistributed);
  printf("leftOvers: %d \n", totalLunchboxes);

  return 0;
}
