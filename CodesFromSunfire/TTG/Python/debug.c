#include <stdio.h>
#include <math.h> // for sin()

#define MAX 50
#define PI 3.14159265358979323846

int main(){
    int i;
    double array[MAX];

    for (i=0;i<MAX;i++){
        array[i] = sin(((2*PI)/49)*i);
    }

    for (i=0;i<MAX;i+=2){
        printf("a[\"%d\"] = %lf\n",i,array[i]);
    }
}
