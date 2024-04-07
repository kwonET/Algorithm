#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define all(v) v.begin(), v.end()

// -99 -2 -1 4 98
int n, a;
vector<int> arr;
pair<int, int> result;

void search() {
  int lo = 0;
  int hi = n - 1;
  int mid;
  int tot = 2000000000;

  while (lo < hi) { // lo와 hi 사이에 다른 칸이 존재한다면 탐색
    if (abs(tot) > abs(arr[lo] + arr[hi])) {
      tot = arr[lo] + arr[hi];
      result = {lo, hi};
      if (tot == 0) {
        break;
      }
    }
    if ((arr[lo] + arr[hi]) < 0)
      lo++;
    else if ((arr[lo] + arr[hi]) > 0)
      hi--;
  }
}
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    arr.push_back(a);
  }
  sort(arr.begin(), arr.end());
  search();
  cout << arr[result.first] << " " << arr[result.second];
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1; // cin>>T;
  while (T--)
    solve();
  return 0;
}