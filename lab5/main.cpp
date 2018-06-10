#include <iostream>
#include <math.h>
#include <vector>

double f(double x) {
  return 4 * exp(-sin(x))- log(x * x - x + 1);
}

double df(double x) {
  return -4 * cos(x) * exp(-sin(x))- (2 * x - 1)/(x * x - x + 1);
}

double max(double a, double b) {
  return a > b ? a : b;
}

int main() {
  int a = -10, b = 10, n = 20;
  int h = (b - a)/n;

  double inaccuracy_df = 0;

  std::vector<double> df_calculated;
  std::vector<double> ddf_calculated;

  for (int x = a - h; x <= b + h; x += h) {
    df_calculated.push_back((f(x + h) - f(x - h))/ 2 * h);
  }

  int i = 0;

  for (int x = a; x <= b; x += h) {
    inaccuracy_df = max(inaccuracy_df, fabs(df(x) - df_calculated[i + 1]));
    std::cout << x << " " << df_calculated[i + 1] << " " << df(x) << std::endl;
    i++;
  }

  std::cout << inaccuracy_df << std::endl;

  return 0;
}