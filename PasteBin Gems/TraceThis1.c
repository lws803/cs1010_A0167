#include <stdio.h>
#include <math.h>

#define ABS(x) ((x > 0) ? x : -x)

const double EPS = 1e-4;

int main(void) {
    double a, b, c, d;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    if (a > b) {
        double tmp = a;
        a = b;
        b = tmp;
    }
    if (c > d) {
        double tmp = c;
        c = d;
        d = tmp;
    }
    if (a >= c && b >= d) {
        printf("YES");
        return  0;
    }
    if (a * a + b * b < c * c + d * d) {
        printf("NO");
        return 0;
    }

    double r = hypot(c, d) / 2;
    double x[2], y[2];
    x[0] = -b / 2;
    y[1] = a / 2;

    y[0] = sqrt(r * r - x[0] * x[0]);
    x[1] = -sqrt(r * r - y[1] * y[1]);

    double maxc = hypot(x[1] - x[0], y[1] - y[0]);
    printf((ABS(c - maxc) <= EPS) ? "YES" : "NO");
    return 0;
}