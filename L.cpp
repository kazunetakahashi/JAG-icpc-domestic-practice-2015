#include <iostream>
#include <string>
using namespace std;

int main() {
  string s1, s2;
  while (cin >> s1 && s1 != "#") {
    cin >> s2;
    cout << ((s1 < s2) ? "Yes" : "No") << endl;
  }
}
