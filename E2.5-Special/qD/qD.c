#include <stdio.h>
#include <math.h>

int main(void){
    int n, b ,e;
    double f[1000000];
    long double sum=0.0L;
    scanf("%d%d%d", &n, &b, &e);
    for (int i = 0; i<n; i++) {
        scanf("%lf", &f[i]);
        sum+= f[i];
    }

    double ua, square=0.0, f_ = sum/n;
    for (int i = 0; i<n; i++) {
        square += pow(f[i]-f_, 2);
    }
    ua = sqrt(square/((double)n*(n-1)));

    double ub, u;
    ub = b*pow(10, -e)/sqrt(3.0);
    u = sqrt(pow(ua, 2)+pow(ub, 2));

    printf("%.*lf %.*lf", e, f_, e, u);
    return 0;
}
