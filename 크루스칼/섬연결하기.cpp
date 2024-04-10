#include <bits/stdc++.h>
using namespace std;

// 정점 사이의 거리를 짧은 순으로 정렬한다.
// 사이클이 생성되지 않는다면 업데이트한다
queue<int> q;
int parent[101];
bool cmp(vector<int> a, vector<int> b) { return a[2] < b[2]; }

int getParent(int *parent, int x) {
  if (parent[x] == x)
    return x;
  return parent[x] = getParent(
             parent, parent[x]); // 나의 부모(parent[x])의 부모를 찾는다
}

void unionParent(int *parent, int a, int b) {
  a = getParent(parent, a);
  b = getParent(parent, b);
  if (a < b) {
    parent[b] = a; // 작은 노드쪽으로 부모 병합
  } else {
    parent[a] = b;
  }
}

bool find(int *parent, int a, int b) {
  a = getParent(parent, a);
  b = getParent(parent, b);
  return a == b;
}

int solution(int n, vector<vector<int>> costs) {
  int result = 0;
  memset(parent, 0, sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }
  sort(costs.begin(), costs.end(), cmp);
  for (int i = 0; i < costs.size(); i++) {
    int from = costs[i][0];
    int to = costs[i][1];
    int co = costs[i][2];
    if (!find(parent, from, to)) {
      result += co;
      unionParent(parent, from, to);
    }
  }

  return result;
}