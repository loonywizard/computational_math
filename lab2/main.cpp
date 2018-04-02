#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

double f(double x) {
  return 1.8 * pow(x, 3) - 2.47 * pow(x, 2) - 5.53 * x + 1.539;
}

double df(double x) {
  return 5.4 * pow(x, 2) - 4.94 * x - 5.53;
}

int main() {
  vector<double> roots;

  double a = -100;
  double b = 100;
  double h = 1;
  double e = pow(10, -8);

  // cin >> a >> b >> h >> e;

  if (f(a) == 0) {
    roots.push_back(a);
  }

  if (f(b) == 0) {
    roots.push_back(b);
  }

  for (double i = a + h; i <= b; i += h) {
    double t1 = f(i - h);
    double t2 = f(i);

    if (t2 == 0 && i != b) {
      roots.push_back(t2);

      continue;
    }

    if (t1 == 0) {
      continue; // was already added
    }

    if (t1 > 0 && t2 < 0 || t1 < 0 && t2 > 0) {
      double ak = i - h;
      double bk = i;
      double xk;

      bool passStep2 = false;

      while (true) {
        if (!passStep2) {
          xk = (ak + bk) / 2;
        }

        passStep2 = false;

        if (f(xk) == 0) {
          roots.push_back(xk);

          break;
        }

        if (f(xk) * f(ak) > 0) {
          ak = xk;
        } else {
          bk = xk;
        }

        if (df(xk) == 0) {
          continue;
        }

        double xkd = xk - f(xk) / df(xk);

        if (xkd > bk || xkd < ak) {
          continue;
        }

        xk = xkd;

        if (fabs(f(xk) / df(xk)) <= e) {
          roots.push_back(xk);

          break;
        }

        passStep2 = true;
      }
    }
  }

  for (int i = 0; i < roots.size(); i++) {
    cout << roots[i] << endl;
  }

  return 0;
}