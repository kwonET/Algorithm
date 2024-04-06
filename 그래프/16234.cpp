// 45분 , 초심 되찾자 !!
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

// 인구 이동은 하루 동안 다음과 같이 진행되고,
//     더 이상 아래 방법에 의해 인구 이동이 없을 때까지 지속된다.

//     국경선을 공유하는 두 나라의 인구 차이가 L명 이상,
//     R명 이하라면,
//     두 나라가 공유하는 국경선을 오늘 하루 동안 연다.위의
//         조건에 의해 열어야하는 국경선이 모두 열렸다면,
//     인구 이동을 시작한다.국경선이
//         열려있어 인접한 칸만을 이용해 이동할 수 있으면,
//     그 나라를 오늘 하루 동안은 연합이라고 한다.연합을 이루고 있는 각 칸의
//         인구수는(연합의 인구수) /
//         (연합을 이루고 있는 칸의 개수)
//             가 된다.편의상 소수점은 버린다.연합을 해체하고,
//     모든 국경선을 닫는다.

// 1) 모든 칸을 방문을 체크한다.
// 2) dfs를 진행한다 (L과 R 사이) 만약 그 크기가 2이상이면, 연합에 추가한다.
// 모든 칸에 대해 1) 2)를 진행한 뒤에 인구수를 조정한다.

// 위 과정을 방문 자료구조가 변경되지 않을 때까지 반복한다.
int n, l, r, a;
int result = 0;
int arr[51][51];
int visited[51][51];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector<pair<int, int>> oneteam;
void move() {
  int people = oneteam.size();
  int sump = 0;
  for (int v = 0; v < oneteam.size(); v++) {
    int y = oneteam[v].first;
    int x = oneteam[v].second;
    sump += arr[y][x];
  }
  int tot = sump / people;
  for (int v = 0; v < oneteam.size(); v++) {
    int y = oneteam[v].first;
    int x = oneteam[v].second;
    arr[y][x] = tot;
  }
}
void dfs(int y, int x) {
  visited[y][x] = 1;
  oneteam.push_back({y, x});
  for (int d = 0; d < 4; d++) {
    int ny = y + dy[d];
    int nx = x + dx[d];
    if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
      continue;
    }
    if (visited[ny][nx] == 1) {
      continue;
    }
    if (abs(arr[ny][nx] - arr[y][x]) < l || abs(arr[ny][nx] - arr[y][x]) > r) {
      continue;
    }
    dfs(ny, nx);
  }
}
void solve() {
  cin >> n >> l >> r;
  for (int i = 0; i < n; i++) {
    memset(arr[i], 0, sizeof(int) * n);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a;
      arr[i][j] = a;
    }
  }
  while (true) {
    for (int i = 0; i < n; i++) {
      memset(visited[i], 0, sizeof(int) * n);
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (visited[i][j] == 0) {
          dfs(i, j);
          if (oneteam.size() > 1) {
            move();
            flag = 1;
          }
          oneteam.clear();
        }
      }
    }
    if (flag) {
      result++;
    } else {
      break;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1; // cin>>T;
  while (T--)
    solve();
  cout << result;
  return 0;
}