#include <stdio.h>

int main(void) {
  int a, max = 0, min = 10, sum = 0;
  for (int i = 0; i < 8; i++) {
    scanf("%d", &a);
    sum += a;
    if (a > max) {
      max = a;
    }
    if (a < min) {
      min = a;
    }
  }
  printf("%.2lf", ((double)(sum - max - min)) / 6);
  return 0;
}
