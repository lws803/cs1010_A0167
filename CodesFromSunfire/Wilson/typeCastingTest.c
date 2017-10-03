#include <stdio.h>

int main ( void )
{
    double w = 216/22;
    double x = (216/22);
    double y = ((double)216/22);
    double z = (216/(double)22);
    double q = (216.0/22);

    printf("w %lf\n",w);
    printf("x %lf\n",x);
    printf("y %lf\n",y);
    printf("z %lf\n",z);
    printf("q %lf\n",q);
    return(0);
}
