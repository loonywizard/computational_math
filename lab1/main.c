#include <stdio.h>
#include <stdlib.h>

struct ComplexNumber {
  double re;
  double im;
};

struct ComplexNumber multiply(struct ComplexNumber a, struct ComplexNumber b) {
  struct ComplexNumber res;

  res.re = a.re * b.re - a.im * b.im;
  res.im = a.im * b.re + a.re * b.im;

  return res;
}

struct ComplexNumber add(struct ComplexNumber a, struct ComplexNumber b) {
  struct ComplexNumber res;

  res.re = a.re + b.re;
  res.im = a.im + b.im;

  return res;
}

int main() {
  int n;
  int m;

  scanf("%d", &n);

  struct ComplexNumber* a = (struct ComplexNumber*) malloc(sizeof(struct ComplexNumber) * (n + 1));

  for (int i = 0; i <= n; i++) {
    scanf("%lf", &a[i].re);
    scanf("%lf", &a[i].im);
  }

  scanf("%d", &m);

  for (int i = 0; i < m; i++) {
    struct ComplexNumber x;

    scanf("%lf", &x.re);
    scanf("%lf", &x.im);

    struct ComplexNumber res = a[n];

    for (int j = n - 1; j >= 0; j--) {
      res = add(multiply(res, x), a[j]);
    }

    printf("%lf %lf\n", res.re, res.im);
  }

  return 0;
}