#include <iostream>
#include <math.h>
#include <vector>

double f(double x) {
  return 4 * exp(-sin(x))- log(x * x - x + 1);
}

double df(double x) {
  return -4 * cos(x) * exp(-sin(x))- (2 * x - 1)/(x * x - x + 1);
}

double ddf(double x) {
  return exp(-sin(x)) * (sin(x) + cos(x)) - (2 * (x * x + 1) - pow(2 * x - 1, 2)) / pow(x * x - x + 1, 2);
}

double max(double a, double b) {
  return a > b ? a : b;
}

int main() {
  int a = -10, b = 10, n = 20;
  int h = (b - a)/n;

  double inaccuracy_df = 0;
  double inaccuracy_ddf = 0;

  std::vector<double> df_calculated;
  std::vector<double> ddf_calculated;

  for (int x = a - h; x <= b + h; x += h) {
    df_calculated.push_back((f(x + h) - f(x - h))/ 2 * h);
  }

  for (int i = 1; i < df_calculated.size() - 1; i++) {
    ddf_calculated.push_back((df_calculated[i + 1] - df_calculated[i - 1])/ 2 * h);
  }

  int i = 0;

  for (int x = a; x <= b; x += h) {
    inaccuracy_df = max(inaccuracy_df, fabs(df(x) - df_calculated[i + 1]));
    inaccuracy_ddf = max(inaccuracy_ddf, fabs(ddf(x) - ddf_calculated[i + 1]));

    std::cout << x
              << " "
              << df(x)
              << " "
              << df_calculated[i + 1]
              << " "
              << ddf(x)
              << " "
              << ddf_calculated[i]
              << std::endl;
    i++;
  }

  std::cout << inaccuracy_df << " " << inaccuracy_ddf << std::endl;

  return 0;
}