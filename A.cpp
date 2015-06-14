#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
  int D;
  double E;
  while(cin >> D >> E && D) {
    double ans = 10000000;
    for (int x=0; x<=D; x++) {
      int y = D-x;
      ans = min(ans, abs(sqrt(x*x + y*y) - E));
    }
    cout << fixed << setprecision(9) << ans << endl;
  }
}
