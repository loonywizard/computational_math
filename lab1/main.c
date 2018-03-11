#include <stdio.h>
#include <stdlib.h>

/**
 * Structure for complex numbers
 *
 * re - real part
 * im - imaginary part
 */
struct ComplexNumber {
  double re;
  double im;
};

/**
 * Function, that returns the result of the multiplication of two complex numbers
 *
 * (a + ib)(c + id) = ac + ibc + iad - bd = (ac - bd) + i(bc + ad)
 *
 * @param a first complex number
 * @param b second complex number
 * @return multiplication of a and b
 */
struct ComplexNumber multiply(struct ComplexNumber a, struct ComplexNumber b) {
  struct ComplexNumber res;

  res.re = a.re * b.re - a.im * b.im;
  res.im = a.im * b.re + a.re * b.im;

  return res;
}

/**
 * Function, that returns the result of the addition of two complex numbers
 *
 * (a + ib) + (c + id) = (a + c) + i(b + d)
 *
 * @param a first complex number
 * @param b second complex number
 * @return sum of a and b
 */
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

  /*
   * array for storing polynomial coefficients
   *
   * P(x) = a0 + a1*x + a2*x^2 + ... + an*x^n
   *
   * a[0] = a0
   * a[1] = a1
   * ...
   * a[n] = an
   */
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

    /*
     * P(x) = a0 + a1*x + a2*x^2 + ... + an*x^n = a0 + x(a1 + x(a2 + ... + x(an-1 + an*x)))
     */
    struct ComplexNumber res = a[n];

    for (int j = n - 1; j >= 0; j--) {
      res = add(multiply(res, x), a[j]);
    }

    printf("%lf %lf\n", res.re, res.im);
  }

  return 0;
}