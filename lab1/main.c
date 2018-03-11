#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  int m;

  scanf("%d", &n);

  int* a = (int*) malloc(sizeof(int) * (n + 1));

  for (int i = 0; i <= n; i++) {
    scanf("%d", &a[i]);
  }

  scanf("%d", &m);

  for (int i = 0; i < m; i++) {
    int x;

    scanf("%d", &x);

    int res = a[n];

    for (int j = n - 1; j >= 0; j--) {
      res = res * x + a[j];
    }

    printf("%d\n", res);
  }

  return 0;
}