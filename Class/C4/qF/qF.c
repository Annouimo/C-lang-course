#include <stdio.h>

int main(void){
    unsigned int T, data[10010], n, m;
    double ava;
    double max = 0.0, min = 100000.0;
    scanf("%u", &T);
    for (int i = 0; i<T; i++) {
        scanf("%u %u", &n, &m);
        for (int j = 0; j<m; j++) {
            data[j] = 0;
        }
        for (int j = 0; j<n; j++) {
            scanf("%u", &data[j%m]);
            ava += (double)data[j%m]/m;
            ava -= (double)data[(j+1)%m]/m;
            if (ava > max) {
                max = ava;
            }
            if (ava < min) {
                min = ava;
            }
        }
        printf("%.1lf %.1lf\n", max+0.05, min+0.05);
    }
}
