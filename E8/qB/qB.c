#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ARRAY_MAX 200010

double array_mean(const int a[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) sum += (double)a[i];
    return sum / n;
}
double array_variance(const int a[], int n, double mean) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double diff = (double)a[i] - mean;
        sum += diff * diff;
    }
    return sum / n;
}

int print_fixed(double x, int digits) {
    if (digits < 0 || digits > 15) return 0;
    int n = snprintf(NULL, 0, "%.*f", digits, x);
    if (n < 0) return 0;
    char *text = malloc((size_t)n + 1);
    if (!text) return 0;
    if (snprintf(text, (size_t)n + 1, "%.*f", digits, x) != n) {
        free(text);
        return 0;
    }
    int skip = text[0] == '-' && strtod(text, NULL) == 0.0;
    int ok = fputs(text + skip, stdout) != EOF;
    free(text);
    return ok;
}


int main(void) {
    static int a[ARRAY_MAX];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    double mean = array_mean(a, n);
    double std_variance = sqrt(array_variance(a, n, mean));
    print_fixed(mean, 4);
    printf("\n");
    for (int i = 0; i < n; i++){
        print_fixed((a[i]-mean)/std_variance, 4);
        printf("\n");
    }
    return 0;
}
