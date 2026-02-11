/**
 *    author:  tourist
 *    created: 29.01.2026 06:38:27
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int x, y;
    cin >> x >> y;
    if ((x & y) == 0) {
      cout << x << " " << y << '\n';
      continue;
    }
    int p = -1, q = -1;
    for (int b = 29; b >= 0; b--) {
      if ((x >> b) & 1) {
        if ((y >> b) & 1) {
          p = x;
          q = y;
          p &= ~((1 << b) - 1);
          q &= ~((1 << b) - 1);
          q -= 1;
          {
            int cx = x & ~((1 << b) - 1);
            cx |= ((1 << b) - 1);
            cx += 1;
            if ((cx & y) == 0) {
              if (abs(cx - x) < abs(p - x) + abs(q - y)) {
                p = cx;
                q = y;
              }
            }
          }
          {
            int cy = y & ~((1 << b) - 1);
            cy |= ((1 << b) - 1);
            cy += 1;
            if ((x & cy) == 0) {
              if (abs(cy - y) < abs(p - x) + abs(q - y)) {
                p = x;
                q = cy;
              }
            }
          }
          break;
        }
      }
    }
    cout << p << " " << q << '\n';
  }
  return 0;
}
