## 알고리즘 문제풀이 정리 (c++)

### 빠른 입출력
```
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
```

### vector 초기화

##### 2차원 vector 초기화 (fill 이용)

- nxm 크기의 vec이라는 vector를 0으로 초기화하는 경우
```
  vector<vector<int>> vec(n, vector<int>(m));
  fill(vec.begin(), vec.end(), vector<int>(m, 0));
```

### 배열 초기화

##### 2차원 배열 초기화 (fill 이용)

- nxm 크기의 arr vector를 0으로 초기화하는 경우
```
  fill(&arr[0][0],&arr[n-1][m],0);
```
##### 2차원 배열 초기화 (fill 이용)

- nxmxk 크기의 arr vector를 0으로 초기화하는 경우
```
  fill(&arr[0][0][0],&arr[n-1][m-1][k],0);
```