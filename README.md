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

```
for(int i=0; i<rows; i++)
  {
    memset(arr[i], 0, sizeof(int)* colums);
    }
```

### DAG(Directed Acyclic Graph)

- 순환은 가지지 않는 방향그래프
- 우선순위를 가진 일련의 작업들은 DAG 구조를 가짐

### 문자열

- https://velog.io/@shin421179/%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8%EB%A5%BC-%EC%9C%84%ED%95%9C-C-%EB%AC%B8%EC%9E%90%EC%97%B4-%EC%B2%98%EB%A6%AC
