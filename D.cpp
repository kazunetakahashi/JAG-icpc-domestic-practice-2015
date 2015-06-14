#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <stack>
#include <cassert>
using namespace std;

typedef tuple<int, int, bool> pass;
typedef tuple<int, int> point;

const int dx[8] = {0, -1, 0, 1, 1, -1, 0, 0};
const int dy[8] = {-1, 0, 1, 0, 0, 0, 1, -1};

// H == 1, W == 1は別扱いで。

int main() {
  int H, W, R, C;
  while(cin >> H >> W >> R >> C && H) {
    bool F[510][510];
    fill(&F[0][0], &F[0][0]+510*510, false);
    for (auto i=0; i<=H+1; i++) {
      F[i][0] = true;
      F[i][W+1] = true;
    }
    for (auto i=0; i<=W+1; i++) {
      F[0][i] = true;
      F[H+1][i] = true;
    }
    vector<pass> P[510][510];
    for (int i=1; i<=H+1; i++) {
      for (int j=1; j<=W; j++) {
        int t;
        cin >> t;
        bool c = (t == 0);
        P[i-1][j].push_back(make_tuple(i, j, c));
        P[i][j].push_back(make_tuple(i-1, j, c));
      }
      if (i == H+1) break;
      for (int j=1; j<=W+1; j++) {
        int t;
        cin >> t;
        bool c = (t == 0);
        P[i][j-1].push_back(make_tuple(i, j, c));
        P[i][j].push_back(make_tuple(i, j-1, c));
      }
    }
    stack<point> S;
    for (auto i=1; i<=H; i++) {
      for (auto j=1; j<=W; j++) {
        S.push(make_tuple(i, j));
      }
    }
    while (!(S.empty())) {
      int x = get<0>(S.top());
      int y = get<1>(S.top());
      S.pop();
      if (!F[x][y]) {
        for (auto i=0; i<6; i++) {
          int nx1, nx2, ny1, ny2;
          if (i < 4) {
            nx1 = x + dx[i];
            ny1 = y + dy[i];
            nx2 = x + dx[(i+1)%4];
            ny2 = y + dy[(i+1)%4];
          } else if (i == 4) {
            nx1 = x + dx[i];
            ny1 = y + dy[i];
            nx2 = x + dx[i+1];
            ny2 = y + dy[i+1];
          } else if (i == 5) {
            nx1 = x + dx[i+2];
            ny1 = y + dy[i+2];
            nx2 = x + dx[i+1];
            ny2 = y + dy[i+1];
          }
          if (F[nx1][ny1] && F[nx2][ny2]) {
            bool bl1, bl2;
            bool find1=false, find2=false;
            for (unsigned j=0; j<P[x][y].size(); j++) {
              int ikx = get<0>(P[x][y][j]);
              int iky = get<1>(P[x][y][j]);
              bool ikb = get<2>(P[x][y][j]);
              if (nx1 == ikx && ny1 == iky) {
                bl1 = ikb;
                find1 = true;
              } else if (nx2 == ikx && ny2 == iky) {
                bl2 = ikb;
                find2 = true;
              }
            }
            assert(find1 && find2);
            if ((bl1 && !(bl2)) || (bl2 && !(bl1))) {
              F[x][y] = true;
              for (auto j=0; j<4; j++) {
                int dsx = x + dx[j];
                int dsy = y + dy[j];
                if (!F[dsx][dsy]) {
                  S.push(make_tuple(dsx, dsy));
                }
              }
            }
          }
        }
      }
    }
    /*
    cerr << "Field" << endl;
    for (auto i=1; i<=H; i++) {
      for (auto j=1; j<=W; j++) {
        cerr << (F[i][j] ? "W" : "L");
      }
      cerr << endl;
    }
    */
    vector<point> I;
    I.push_back(make_tuple(R, C));
    for (unsigned i=0; i<P[R][C].size(); i++) {
      if (get<2>(P[R][C][i])) {
        I.push_back(make_tuple(get<0>(P[R][C][i]), get<1>(P[R][C][i])));
      }
    }
    bool ok = false;
    for (unsigned i=0; i<I.size(); i++) {
      if (F[get<0>(I[i])][get<1>(I[i])]) {
        ok = true;
        break;
      }
    }
    cout << (ok ? "Yes" : "No") << endl;
  }
}
