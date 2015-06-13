#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
  int m;
  cin >> m;
  for (auto t=0; t<m; t++) {
    int S;
    cin >> S;
    cout << fixed << setprecision(9) << sqrt(S) * sqrt(2)/2 << endl;
  }
}
