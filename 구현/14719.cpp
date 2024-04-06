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

// 구간 중에 가장 높은, 같은 높이의 블록 2개 사이의 블록들의 높이 차이
// 구간 중에 가장 높다는 걸 어떻게 관리할까?

// 처음 블록보다 높이가 높거나 같은 블록이 나타나면 무조건 물이 찬다
// -> 없다면 그 중 가장 높은 애들만큼 찬다

int h, w, a;
int arr[501];
// 쌓이는 물의 양은
// 1 ~ w-2 각각 열을 기준으로
// 해당 열의 왼쪽과, 오른쪽의 최대 블록 높이 중 (작은 값 - 내 블록 높이)로
// 정해진다.
int result = 0;
void search() {
  for (int i = 1; i < w - 1; i++) {
    int left = 0;
    int right = 0;
    int block = 0;
    for (int j = 0; j < i; j++) {
      left = max(left, arr[j]);
    }
    for (int j = i + 1; j < w; j++) {
      right = max(right, arr[j]);
    }
    block = min(left, right);
    if (block > arr[i]) {
      result += (block - arr[i]);
    }
  }
}
void solve() {
  cin >> h >> w;
  memset(arr, 0, sizeof(int) * w);
  for (int i = 0; i < w; i++) {
    cin >> a;
    arr[i] = a;
  }
  search();
  cout << result;
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