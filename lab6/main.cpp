#include <iostream>
#include <math.h>

double f(double x) {
  return (-2 * x * x + 25 * x - 53) / ((x * x - 3 * x - 4) * (x - 7));
}

int main() {
  double a = 10, b = 20, n = 100;
  double h = (b - a) / n;

  double I = -0.8077;
  double J1 = 0, J2 = 0, J3 = 0;

  for (double x = a + h; x <= b; x += h) {
    J1 += f(x - h/2);
  }

  J1 = J1 * h;

  for (double x = a + h; x <= b - h; x += h) {
    J2 += f(x);
  }

  J2 = h * ((f(a) + f(b))/2 + J2);

  J3 = (b - a)/6 * (f(a) + 4 * f((a + b)/2) + f(b));g

  double inaccuracy_J1 = fabs(I - J1);
  double inaccuracy_J2 = fabs(I - J2);
  double inaccuracy_J3 = fabs(I - J3);

  std::cout << I << std::endl;
  std::cout << J1 << " " << inaccuracy_J1 << std::endl;
  std::cout << J2 << " " << inaccuracy_J2 << std::endl;
  std::cout << J3 << " " << inaccuracy_J3 << std::endl;

  return 0;
}