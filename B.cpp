#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

char dx[5] = {'a', 'i', 'u', 'e', 'o'};

int main() {
  int n;
  while(cin >> n && n) {
    string str[100];
    for (auto i=0; i<n; i++) {
      cin >> str[i];
    }
    string red[100];
    for (auto i=0; i<n; i++) {
      red[i] = "";
      red[i] += str[i][0];
      for (unsigned j=0; j<str[i].size()-1; j++) {
        for (auto k=0; k<5; k++) {
          if (str[i][j] == dx[k]) {
            red[i] += str[i][j+1];
            break;
          }          
        }
      }
    }
    int ans = -1;
    for (int k=1; k<51; k++) {
      string hikaku[100];
      for (auto i=0; i<n; i++) {
        hikaku[i] = red[i].substr(0, k);
      }
      sort(hikaku, hikaku+n);
      bool ok = true;
      for (auto i=0; i<n-1; i++) {
        if (hikaku[i] == hikaku[i+1]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        ans = k;
        break;
      }
    }
    cout << ans << endl;
  }
}
