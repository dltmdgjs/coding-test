# C++ Coding Test Handbook

> C++17 · 한국어 학습/복습 노트 · 모든 구간과 인덱스의 의미를 먼저 확인하세요.

이 문서는 개념 학습 → 템플릿 적용 → 실수 점검 → 시험 직전 복습 순으로 사용할 수 있도록 구성했습니다. 모든 알고리즘 장은 같은 여덟 항목으로 구성합니다. 코드는 문제의 입력·출력 부분을 제외한 재사용 함수이며, 아래 공통 헤더와 함께 사용합니다. 정점과 배열은 기본적으로 **0부터 시작**, 구간은 **[l, r)** 입니다. Fenwick Tree의 내부 인덱스만 1부터 시작합니다.

## 목차

- [PART 0. 코딩테스트 기본 세팅](#part-0-코딩테스트-기본-세팅)
- [PART 1. C++ 자주 쓰는 문법 / STL](#part-1-c-자주-쓰는-문법--stl)
- [PART 2. 기본 문제 해결 기법](#part-2-기본-문제-해결-기법): 누적합, 구현, 그리디
- [PART 3. 탐색](#part-3-탐색): 그래프 탐색, BFS, DFS, 완전탐색, 백트래킹
- [PART 4. 탐색 공간 최적화](#part-4-탐색-공간-최적화): 비트연산/비트마스킹, 이분탐색
- [PART 5. 정렬된 데이터 / 구간 처리](#part-5-정렬된-데이터--구간-처리): 라인스위핑, 투포인터, LIS
- [PART 6. 동적 계획법](#part-6-동적-계획법): DP
- [PART 7. 그래프 최단거리](#part-7-그래프-최단거리): Dijkstra, Floyd-Warshall, Bellman-Ford
- [PART 8. 고급 자료구조](#part-8-고급-자료구조): Fenwick Tree
- [PART 9. 시험 직전 Cheat Sheet](#part-9-시험-직전-cheat-sheet): 선택표, 복잡도 표, 점검표

### 학습 순서와 사용 방법

1. 처음에는 PART 0~3을 읽고 작은 예제를 직접 추적합니다.
2. 정렬·단조성·상태 정의를 익히며 PART 4~6으로 넘어갑니다.
3. 가중치 조건에 따른 최단거리 선택과 구간 자료구조를 공부합니다.
4. 복습할 때는 각 장의 ‘문제에서 보이는 신호’와 ‘30초 복습’을 먼저 읽습니다.
5. 템플릿을 복사한 뒤 인덱스, 구간, 수치 범위, 반환값 의미를 해당 문제에 맞게 확인합니다.

---

## PART 0. 코딩테스트 기본 세팅

### 0.1 공통 헤더와 실행 뼈대

아래 헤더는 표준 C++17 헤더입니다. `bits/stdc++.h`는 GCC 계열의 편의 헤더이며 표준이 아니므로 이 문서에서는 사용하지 않습니다. 각 알고리즘 코드는 이 헤더·별칭이 선언되어 있다고 가정합니다.

```cpp
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

// 최단거리의 모든 유한한 값은 이 값보다 작아야 합니다.
constexpr ll INF = numeric_limits<ll>::max() / 4;
constexpr int dr[4] = {-1, 1, 0, 0};
constexpr int dc[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // 입력 → 계산 → 출력
    return 0;
}
```

함수 템플릿은 `main` 앞에 둡니다. 검증용 첨부 파일은 모든 함수를 한곳에 모아 실행 가능한 예제와 함께 제공합니다.

### 0.2 수치 범위와 초기화

| 항목 | 기억할 점 | 예시 |
|---|---|---|
| `int` | 일반적인 채점 환경에서 약 ±21억. 정확한 한계는 `numeric_limits<int>` | 인덱스, 작은 개수 |
| `long long` | 최소 64비트. 일반적인 환경에서 약 ±9.22×10¹⁸ | 누적합, 거리, 큰 곱 |
| 곱셈 | 대입 전 연산부터 큰 자료형이어야 함 | `1LL * a * b` |
| 무한대 | 실제 답보다 커야 하며 연산 여유가 필요 | 위의 `INF` |
| 부동소수점 | 정수의 큰 값과 소수는 정확히 표현되지 않을 수 있음 | 정수 비교는 정수로 |
| 배열 초기화 | 의미 있는 값으로 `fill` 또는 생성자 사용 | `vector<ll> d(n, INF)` |

`INF`라고 해서 무조건 안전한 것은 아닙니다. 이 문서의 산술 코드는 입력의 합·곱·거리 계산이 자료형 범위 안에 있다는 전제가 있습니다. 최단거리 템플릿은 모든 중간 유한 거리의 절댓값이 `INF`보다 작다고 가정합니다. 음수 사이클을 검사하는 Bellman-Ford에서는 **반복 중 만들어지는 값**도 확인해야 합니다.

### 0.3 입출력과 공통 실수

- 빠른 입출력 설정 후 C의 `scanf/printf`와 C++ 스트림을 혼용하지 않습니다.
- 단순 줄바꿈에는 `endl` 대신 `'\n'`을 사용합니다. `endl`은 버퍼도 비웁니다.
- `cin >> n` 직후 한 줄을 읽으려면 `cin.ignore(numeric_limits<streamsize>::max(), '\n');` 후 `getline(cin, s)`를 사용합니다. `getline(cin >> ws, s)`는 앞의 공백과 빈 줄을 건너뜁니다.
- 여러 테스트케이스에서는 전역 컨테이너, 방문 배열, 정답 변수를 다시 초기화합니다.
- `vector::size()`는 부호 없는 형식입니다. 역순 반복은 빈 배열을 고려해 정수 인덱스를 씁니다.
- 재귀 깊이가 큰 그래프는 반복형 DFS/BFS를 사용합니다. 허용 깊이는 환경에 따라 다릅니다.

---

## PART 1. C++ 자주 쓰는 문법 / STL

아래 예시는 API 사용법을 보여주는 조각입니다. 변수는 해당 문제에서 선언하고, 빈 컨테이너 접근을 피하세요.

### 1.1 컨테이너 선택표

| 필요 | 컨테이너 | 핵심 함수 | 주요 비용 |
|---|---|---|---|
| 가변 배열 | `vector<T>` | `push_back`, `pop_back`, `size`, `empty`, `back` | 인덱스 O(1), 뒤 추가 분할상환 O(1) |
| 고정 크기 배열 | `array<T,N>` | `fill`, `size` | 인덱스 O(1) |
| FIFO | `queue<T>` | `push`, `front`, `pop` | O(1) |
| LIFO | `stack<T>` | `push`, `top`, `pop` | O(1) |
| 양쪽 끝 삽입/삭제 | `deque<T>` | `push_front`, `push_back`, `pop_front`, `pop_back` | O(1) |
| 최댓값/최솟값 반복 추출 | `priority_queue<T>` | `push`, `top`, `pop` | 삽입/삭제 O(log N), top O(1) |
| 정렬된 유일 원소 | `set<T>` | `insert`, `erase`, `find`, `lower_bound` | O(log N) |
| 정렬된 키-값 | `map<K,V>` | `find`, `count`, `operator[]` | O(log N) |
| 해시 조회 | `unordered_map`, `unordered_set` | `find`, `insert`, `erase`, `reserve` | 평균 O(1), 최악 O(N) |
| 정렬된 중복 원소 | `multiset<T>` | `insert`, `find`, `erase` | 조회 O(log N), 삭제 비용은 개수에 영향 |

`pop()`은 값을 반환하지 않습니다. `front/back/top`은 비어 있으면 사용할 수 없습니다. `map[key]`는 키가 없을 때 기본값을 삽입하므로 조회만 할 때는 `find`를 씁니다. `multiset.erase(value)`는 일치하는 원소를 모두 지우며, 하나만 지우려면 `find` 결과 반복자를 `erase`에 넘깁니다.

### 1.2 배열, pair, tuple, 순회

```cpp
vector<int> v(5, 0);
vector<vector<int>> board(3, vector<int>(4, -1));
pair<int, int> p = {2, 7};
auto [x, y] = p; // 값 복사, C++17 구조적 바인딩
for (auto& row : board) { // 참조로 접근해야 원본 변경
    fill(row.begin(), row.end(), 0);
}
tuple<int, int, int> state = {1, 2, 3};
auto [a, b, c] = state;
```

`vector` 재할당으로 원소를 가리키던 반복자·참조가 무효화될 수 있습니다. `reserve(n)`은 용량만 확보하고 크기를 늘리지 않습니다. 원소에 접근하려면 `resize(n)` 또는 생성자로 크기를 지정하세요.

### 1.3 정렬과 탐색

```cpp
sort(v.begin(), v.end());
sort(v.begin(), v.end(), greater<int>()); // 내림차순
vector<pair<int,int>> jobs = {{1,3}, {2,3}, {0,2}};
sort(jobs.begin(), jobs.end(), [](const auto& a, const auto& b) {
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first; // 동률 기준 명시, <= 금지
});
// pair 기본 정렬은 first, 그다음 second 오름차순
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end()); // 정렬 후 중복 제거
int lo = int(lower_bound(v.begin(), v.end(), 3) - v.begin()); // 첫 >= 3
int hi = int(upper_bound(v.begin(), v.end(), 3) - v.begin()); // 첫 > 3
bool exists = binary_search(v.begin(), v.end(), 3);
```

이분 탐색 계열은 탐색 기준에 맞게 정렬되어 있어야 합니다. 찾는 값이 없으면 `end()`가 나올 수 있습니다. `set/map`에서는 일반 `lower_bound` 대신 멤버 `.lower_bound()`를 써야 O(log N) 탐색을 얻습니다. `unique`는 인접 중복만 모아 제거할 끝 위치를 반환하므로 `erase`가 필요합니다.

### 1.4 힙, 문자열, 수치 함수

```cpp
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
using State = pair<ll,int>; // {거리, 정점}
priority_queue<State, vector<State>, greater<State>> pq;
string s = "abcd";
string middle = s.substr(1, 2); // "bc": 시작 위치, 길이
size_t pos = s.find("bc");
if (pos != string::npos) { /* 찾음 */ }
int number = stoi("123");
string text = to_string(123);
ll total = accumulate(v.begin(), v.end(), 0LL); // 초기값의 형식이 중요
int g = gcd(12, 18); // <numeric>, C++17
int l = lcm(12, 18); // 결과가 형식 범위 내에 있어야 함
reverse(s.begin(), s.end());
iota(v.begin(), v.end(), 0); // 0, 1, 2, ...
```

| 함수 | 용도 / 주의 | 시간복잡도 |
|---|---|---|
| `sort` | 비교 함수는 엄격한 순서를 정의 | O(N log N) 비교 |
| `stable_sort` | 동등 원소의 원래 순서 보존 | 메모리 확보 시 O(N log N), 부족 시 O(N log²N) 비교 |
| `min/max`, `swap` | 두 값 비교·교환, 원소 형식 비용 고려 | 기본 수치형 O(1) |
| `min_element/max_element` | 반복자를 반환, 빈 범위는 end | O(N) |
| `find/count` | 선형 탐색/개수 세기 | O(N) |
| `fill/reverse/accumulate` | 채우기/뒤집기/누적 | O(N) |
| `lower_bound/upper_bound` | vector 기준 첫 ≥ x / 첫 > x | O(log N) |
| `next_permutation` | 다음 사전순 순열, 마지막이면 처음으로 돌아가 false | 한 번 O(N) |
| `string::substr` | 문자열 복사 | 복사 길이에 비례 |

`pow`는 정수 거듭제곱을 정확히 계산하는 용도로 쓰지 않습니다. `abs`도 최솟값의 절댓값을 같은 정수형으로 표현하지 못하는 경우가 있습니다. 정수 나눗셈은 0 방향으로 버립니다. 양의 정수의 올림 나눗셈은 `a / b + (a % b != 0)`처럼 덧셈 오버플로를 피할 수 있습니다.

### 1.5 좌표 압축

값의 대소관계만 필요하고 값 범위가 클 때 정렬·중복 제거한 배열의 위치로 바꿉니다. 실제 거리나 길이는 보존하지 않으므로 스위핑에서 길이를 계산할 때는 원래 좌표를 사용합니다.

```cpp
vector<ll> values = {100, -5, 100, 900};
vector<ll> xs = values;
sort(xs.begin(), xs.end());
xs.erase(unique(xs.begin(), xs.end()), xs.end());
for (ll x : values) {
    int rank = int(lower_bound(xs.begin(), xs.end(), x) - xs.begin());
    // rank: 0부터 시작하는 압축 좌표, Fenwick 내부 처리는 별도
}
```

---

## PART 2. 기본 문제 해결 기법

### 2.1 누적합

#### 언제 사용하는가

배열이 변하지 않고 구간 합을 여러 번 묻는 문제. 직사각형 합은 2차원 누적합으로 확장합니다.

#### 핵심 아이디어

`p[i]`에 앞의 i개 합을 저장합니다. [l,r)의 합은 `p[r]-p[l]`입니다. 2차원에서는 겹친 영역을 한 번 되돌리는 포함·배제를 사용합니다.

#### 템플릿 코드

```cpp
vector<ll> prefix1D(const vector<int>& a) {
    vector<ll> p(a.size() + 1, 0);
    for (int i = 0; i < int(a.size()); ++i)
        p[i + 1] = p[i] + a[i]; // p[0]은 빈 구간의 합
    return p;
}
ll rangeSum(const vector<ll>& p, int l, int r) {
    return p[r] - p[l]; // 0 <= l <= r <= 원본 크기
}
vector<vector<ll>> prefix2D(const vector<vector<int>>& a) {
    int n = int(a.size()), m = n ? int(a[0].size()) : 0;
    vector<vector<ll>> p(n + 1, vector<ll>(m + 1));
    for (int r = 0; r < n; ++r)
        for (int c = 0; c < m; ++c)
            p[r+1][c+1] = a[r][c] + p[r][c+1]
                         + p[r+1][c] - p[r][c];
    return p;
}
ll rectSum(const vector<vector<ll>>& p, int r1, int c1, int r2, int c2) {
    // 행 [r1,r2), 열 [c1,c2)
    return p[r2][c2] - p[r1][c2] - p[r2][c1] + p[r1][c1];
}
```

#### 코드 설명

`[2,3,5]`의 누적합은 `[0,2,5,10]`. [1,3)의 합은 10−2=8입니다. 2차원 입력은 모든 행의 길이가 같은 직사각형이어야 합니다.

#### 시간복잡도

1차원 전처리 O(N), 질의 O(1), 추가 공간 O(N). 2차원 전처리·공간 O(RC), 질의 O(1).

#### 자주 하는 실수

- 양끝 포함 구간을 그대로 대입: [l,r]은 [l,r+1)로 바꿉니다.
- 원소 변경 후 누적합을 그대로 재사용.
- 합을 int로 저장하여 오버플로.

#### 문제에서 보이는 신호

“구간 합 Q번”, “직사각형 영역의 합”, “배열은 고정”.

#### 30초 복습

앞에서부터 누적 → 끝 누적합 − 시작 누적합. 변경이 있으면 Fenwick Tree를 고려합니다.

---

### 2.2 구현 / 시뮬레이션

#### 언제 사용하는가

규칙에 따라 상태를 갱신하는 격자 이동, 게임, 로봇, 회전 문제.

#### 핵심 아이디어

상태·명령·경계·갱신 순서를 분리합니다. 아래 예시는 0=위, 1=아래, 2=왼쪽, 3=오른쪽으로 이동하며 벽과 경계 밖 이동은 무시합니다.

#### 템플릿 코드

```cpp
pair<int,int> simulate(const vector<string>& board, int r, int c,
                       const vector<int>& commands) {
    // 전제: 비어 있지 않은 직사각형 격자, 시작점은 이동 가능한 칸
    int n = int(board.size()), m = int(board[0].size());
    for (int dir : commands) {
        if (dir < 0 || dir >= 4) continue; // 유효하지 않은 명령 무시
        int nr = r + dr[dir], nc = c + dc[dir];
        // 배열 접근보다 경계 검사가 먼저입니다.
        if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        if (board[nr][nc] == '#') continue;
        r = nr; c = nc; // 검사를 모두 통과한 뒤 상태 반영
    }
    return {r, c};
}
```

#### 코드 설명

현재 위치를 즉시 바꾸지 않고 후보 위치를 검사합니다. 여러 개체가 “동시에” 움직이면 현재 보드와 다음 보드를 분리해야 합니다. 이 코드는 한 개체의 순차 이동용입니다.

#### 시간복잡도

명령 수 K에 대해 O(K), 추가 공간 O(1).

#### 자주 하는 실수

- 행/열과 x/y 축을 혼동.
- 검증 전에 위치 변경.
- 동시 갱신을 순차 갱신으로 처리.
- 문제의 방향 번호와 코드의 방향 배열 불일치.

#### 문제에서 보이는 신호

“주어진 규칙대로”, “T초 후”, “회전한다”, “벽이면 무시”.

#### 30초 복습

상태 정의 → 한 명령 처리 → 경계 확인 → 갱신. 작은 예제를 손으로 추적합니다.

---

### 2.3 그리디

#### 언제 사용하는가

현재 최선의 선택이 전체 최적해로 이어짐을 증명할 수 있을 때. 예시는 겹치지 않는 구간의 최대 개수입니다.

#### 핵심 아이디어

끝나는 시간이 빠른 구간부터 선택하면 이후 구간을 위한 공간이 최대한 남습니다. 최적해의 첫 구간을 가장 빨리 끝나는 구간으로 교체해도 나머지 선택을 유지할 수 있다는 교환 논증을 사용합니다.

#### 템플릿 코드

```cpp
int maxNonOverlapping(vector<pair<ll,ll>> intervals) {
    // 각 구간 [시작,끝), 시작 < 끝. 가중치 없이 개수를 최대화합니다.
    sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });
    ll lastEnd = numeric_limits<ll>::lowest();
    int answer = 0;
    for (auto [start, finish] : intervals) {
        if (start >= lastEnd) { // 끝과 다음 시작이 같아도 선택 가능
            ++answer;
            lastEnd = finish;
        }
    }
    return answer;
}
```

#### 코드 설명

선택한 마지막 끝 시각만 기억합니다. `[0,3), [1,2), [2,4)`에서는 `[1,2), [2,4)`를 선택합니다. 구간마다 보상이 다르면 이 규칙은 최적이 아닐 수 있으므로 가중 구간 DP 등을 검토합니다.

#### 시간복잡도

O(N log N), 정렬 후 순회 O(N). 인자로 복사한 배열까지 포함해 추가 공간 O(N).

#### 자주 하는 실수

- “좋아 보이는 선택”을 증명 없이 사용.
- 임의의 동전 체계에 큰 동전부터 고르기 적용: {1,3,4}, 금액 6의 반례.
- 시작 시각이나 짧은 길이로 정렬하면 항상 맞는다고 가정.

#### 문제에서 보이는 신호

“최대 개수”, “최소 비용”은 후보 신호일 뿐입니다. 교환 논증이나 선택의 안전성을 증명할 수 있는지 확인합니다.

#### 30초 복습

선택 기준을 정하고 반례 탐색 → 교환/불변식 증명 → 정렬과 한 번의 순회.

---

## PART 3. 탐색

### 3.1 그래프 탐색: 표현과 연결 요소

#### 언제 사용하는가

정점 사이 관계, 연결 여부, 연결된 그룹 수, 격자를 그래프로 표현할 때.

#### 핵심 아이디어

인접 리스트에 이웃을 저장하고, 아직 방문하지 않은 정점마다 탐색을 새로 시작합니다. 아래 코드는 무방향 그래프의 연결 요소 번호를 구합니다.

#### 템플릿 코드

```cpp
vector<vector<int>> makeGraph(int n, const vector<pair<int,int>>& edges,
                              bool directed = false) {
    vector<vector<int>> g(n);
    for (auto [u, v] : edges) { // 정점 번호는 [0,n)
        g[u].push_back(v);
        if (!directed) g[v].push_back(u);
    }
    return g;
}
vector<int> componentIds(const vector<vector<int>>& g) {
    // 무방향 그래프 전용 연결 요소 분류
    int n = int(g.size()), id = 0;
    vector<int> comp(n, -1);
    for (int s = 0; s < n; ++s) {
        if (comp[s] != -1) continue;
        stack<int> st;
        st.push(s); comp[s] = id;
        while (!st.empty()) {
            int u = st.top(); st.pop();
            for (int v : g[u]) {
                if (comp[v] != -1) continue;
                comp[v] = id; // 넣을 때 방문 표시하여 중복 삽입 방지
                st.push(v);
            }
        }
        ++id;
    }
    return comp;
}
```

#### 코드 설명

같은 번호를 받은 정점끼리 연결되어 있습니다. 고립된 정점도 하나의 연결 요소입니다. 방향 그래프의 강한 연결 요소(SCC)는 별도 알고리즘이 필요합니다.

#### 시간복잡도

인접 리스트 구축 O(V+E), 탐색 O(V+E), 공간 O(V+E). 무방향 간선은 두 번 저장하지만 같은 차수입니다.

#### 자주 하는 실수

- 무방향 간선을 한쪽만 추가.
- 1부터 주어진 번호를 변환하지 않음.
- 한 시작점만 탐색하고 비연결 부분을 놓침.
- 인접 행렬 순회를 O(V+E)라고 계산: 보통 O(V²).

#### 문제에서 보이는 신호

“연결된 묶음”, “도달 가능한가”, “섬의 개수”, “관계”.

#### 30초 복습

정점·간선·방향 정의 → 인접 리스트 → 미방문 정점마다 탐색.

---

### 3.2 BFS

#### 언제 사용하는가

모든 간선 비용이 같을 때 최단 이동 횟수, 가까운 순서의 탐색.

#### 핵심 아이디어

FIFO 큐로 거리 0, 1, 2, … 순서로 확장합니다. 처음 발견한 거리가 최단거리입니다.

#### 템플릿 코드

```cpp
vector<int> bfs(const vector<vector<int>>& g, int start) {
    vector<int> dist(g.size(), -1); // -1: 도달하지 못함
    queue<int> q;
    dist[start] = 0; q.push(start);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + 1; // 큐에 넣는 시점에 방문 확정
            q.push(v);
        }
    }
    return dist;
}
```

#### 코드 설명

유효한 시작 정점이 필요합니다. 경로가 필요하면 발견 시 `parent[v]=u`를 저장한 뒤 도착점부터 역추적합니다. 다중 시작점은 모든 시작점의 거리를 0으로 설정하고 중복 없이 큐에 넣습니다. 벽 파괴 횟수 등 미래 행동에 영향을 주는 값은 방문 상태의 차원에 포함합니다.

#### 시간복잡도

O(V+E), 거리 배열과 큐의 추가 공간 O(V). 격자 R×C의 상하좌우 탐색은 O(RC).

#### 자주 하는 실수

- 꺼낼 때 방문 처리하여 중복 삽입.
- 가중치가 다른데 일반 BFS 사용.
- 위치만 방문 처리하고 열쇠·벽 파괴 횟수 같은 상태를 생략.

#### 문제에서 보이는 신호

“최소 몇 번 이동”, “가중치 없는 최단거리”, “동시에 퍼진다”.

#### 30초 복습

큐 + 넣을 때 방문 + 이전 거리 + 1. 비용이 다르면 최단거리 알고리즘을 다시 고릅니다.

---

### 3.3 DFS

#### 언제 사용하는가

깊게 내려가며 도달성, 트리 순회, 진입·종료 시점 처리 등을 수행할 때.

#### 핵심 아이디어

스택에 현재 정점과 다음에 확인할 이웃 위치를 저장하면 재귀의 실행 순서를 반복문으로 재현할 수 있습니다.

#### 템플릿 코드

```cpp
pair<vector<int>, vector<int>> dfsOrders(const vector<vector<int>>& g, int start) {
    vector<char> seen(g.size(), false);
    vector<int> enter, leave;
    vector<pair<int,int>> st; // {정점, 다음에 확인할 인접 리스트 인덱스}
    seen[start] = true; enter.push_back(start);
    st.push_back({start, 0});
    while (!st.empty()) {
        int u = st.back().first;
        int next = st.back().second;
        if (next == int(g[u].size())) {
            leave.push_back(u); // 재귀 함수가 반환하는 시점
            st.pop_back();
            continue;
        }
        ++st.back().second;
        int v = g[u][next];
        if (seen[v]) continue;
        seen[v] = true; enter.push_back(v);
        st.push_back({v, 0});
    }
    return {enter, leave};
}
```

#### 코드 설명

`enter`는 진입 순서, `leave`는 종료 순서입니다. 시작점에서 도달 가능한 부분만 처리합니다. 트리 DP에서는 자식이 부모보다 먼저 나오는 종료 순서를 활용할 수 있습니다. 방향 그래프 사이클 검사는 단순 방문 여부 외에 현재 탐색 중인지 나타내는 색 상태가 필요합니다.

#### 시간복잡도

도달 부분 기준 O(V+E), 추가 공간 O(V).

#### 자주 하는 실수

- 깊은 재귀로 스택 초과.
- DFS가 일반 그래프의 최단거리를 보장한다고 생각.
- 무방향 그래프 사이클 검사에서 부모 간선을 사이클로 오인.

#### 문제에서 보이는 신호

“끝까지 따라간다”, “하위 트리”, “모든 연결 정점”, “진입/종료 순서”.

#### 30초 복습

깊게 방문 → 자식 처리 → 종료. 순서가 필요하면 스택에 다음 이웃 위치도 저장합니다.

---

### 3.4 완전탐색

#### 언제 사용하는가

후보 수가 충분히 작아 모든 경우를 검사할 수 있을 때. 복잡한 최적화 전에 작은 입력용 정답 검증기를 만들 때도 유용합니다.

#### 핵심 아이디어

후보 생성과 조건 판정을 분리합니다. 아래는 도시 0을 시작·끝으로 고정한 모든 순서를 비교합니다.

#### 템플릿 코드

```cpp
ll tspBrute(const vector<vector<ll>>& cost) {
    // 완전 유향 그래프의 비용 행렬. 모든 비용·합이 표현 가능해야 함
    int n = int(cost.size());
    if (n <= 1) return 0;
    vector<int> order(n - 1);
    iota(order.begin(), order.end(), 1); // 정렬된 초기 순열
    ll answer = INF;
    do {
        ll sum = 0;
        int prev = 0;
        for (int v : order) {
            sum += cost[prev][v];
            prev = v;
        }
        sum += cost[prev][0]; // 시작점으로 복귀
        answer = min(answer, sum);
    } while (next_permutation(order.begin(), order.end()));
    return answer;
}
```

#### 코드 설명

정점 0을 고정해 회전 중복을 줄이고 (N−1)!개 순서를 검사합니다. 간선이 없는 그래프라면 해당 경로를 건너뛰는 처리가 필요합니다. 이 템플릿은 모든 간선이 존재한다고 가정합니다.

#### 시간복잡도

O(N·(N−1)!), 추가 공간 O(N).

#### 자주 하는 실수

- factorial 증가를 과소평가.
- 초기 순열을 정렬하지 않아 일부 경우 누락.
- 마지막 복귀 간선 누락.
- `while`만 사용해 첫 순열을 검사하지 않음.

#### 문제에서 보이는 신호

“N이 매우 작다”, “모든 배치”, “가능한 순서”, “조건을 만족하는 경우”.

#### 30초 복습

경우 수부터 계산 → 빠짐없이 생성 → 조건 검사. 시간 안에 되면 가장 직접적인 풀이입니다.

---

### 3.5 백트래킹

#### 언제 사용하는가

부분 선택 단계에서 더 진행할 필요가 없는 분기를 알아낼 수 있을 때. 조합, 순열, 배치 제약 문제.

#### 핵심 아이디어

선택 → 재귀 → 선택 취소를 반복합니다. 아래는 1~N에서 K개를 중복 없이 고르는 조합이며 남은 수가 부족하면 중단합니다.

#### 템플릿 코드

```cpp
vector<vector<int>> combinations(int n, int k) {
    vector<vector<int>> result;
    if (k < 0 || k > n) return result;
    vector<int> path;
    function<void(int)> dfs = [&](int start) {
        if (int(path.size()) == k) {
            result.push_back(path); // 현재 조합 복사
            return;
        }
        int need = k - int(path.size());
        // x를 선택한 뒤 필요한 숫자들을 남겨둘 수 있는 범위까지만
        for (int x = start; x <= n - need + 1; ++x) {
            path.push_back(x);
            dfs(x + 1); // 증가 순서로만 선택하여 순서 중복 제거
            path.pop_back(); // 다음 분기를 위해 상태 복구
        }
    };
    dfs(1);
    return result;
}
```

#### 코드 설명

N=4, K=2이면 {1,2}, {1,3}, {1,4}, {2,3}, {2,4}, {3,4}입니다. 순열은 순서가 중요하므로 `used` 배열로 선택 여부를 추적하는 방식으로 바꿉니다. 많은 결과는 저장하지 말고 발견 시 처리하세요.

#### 시간복잡도

유효한 1≤K≤N에서 출력 복사까지 O(K·C(N,K)), 재귀 작업 공간 O(K), 결과 공간 O(K·C(N,K)). K=0은 빈 조합 하나.

#### 자주 하는 실수

- 선택 취소 누락.
- 조합과 순열을 혼동.
- 음수가 가능한 합 문제에서 “현재 합이 목표 초과”로 잘못 가지치기.
- 가지치기가 최악의 지수 복잡도를 항상 없앤다고 생각.

#### 문제에서 보이는 신호

“중복 없이 K개 선택”, “가능한 배치”, “선택 도중 제약 확인 가능”.

#### 30초 복습

종료 조건 → 안전한 가지치기 → 선택 → 재귀 → 복구.

---

## PART 4. 탐색 공간 최적화

### 4.1 비트연산 / 비트마스킹

#### 언제 사용하는가

원소 수가 작은 집합의 상태 저장, 부분집합 열거, 부분집합 DP.

#### 핵심 아이디어

i번째 비트가 1이면 원소 i가 집합에 포함됩니다. 비트 OR/AND/XOR로 추가·검사·토글하고, unsigned 형식으로 시프트합니다.

#### 템플릿 코드

```cpp
uint64_t addBit(uint64_t mask, int i) { return mask | (1ULL << i); }
uint64_t removeBit(uint64_t mask, int i) { return mask & ~(1ULL << i); }
bool hasBit(uint64_t mask, int i) { return (mask & (1ULL << i)) != 0; }
uint64_t toggleBit(uint64_t mask, int i) { return mask ^ (1ULL << i); }
int bitCount(uint64_t mask) { // 표준 C++17만 사용하는 구현
    int count = 0;
    while (mask) {
        mask &= mask - 1; // 가장 낮은 1비트 제거
        ++count;
    }
    return count;
}
vector<ll> subsetSums(const vector<int>& a) {
    // 모든 부분집합 결과를 저장하므로 작은 N 전용
    int n = int(a.size());
    assert(n <= 20); // 이 예제의 실용적 메모리 제한
    vector<ll> sums(1ULL << n, 0);
    for (uint64_t mask = 0; mask < (1ULL << n); ++mask)
        for (int i = 0; i < n; ++i)
            if (hasBit(mask, i)) sums[mask] += a[i];
    return sums;
}
vector<uint64_t> submasks(uint64_t mask) {
    vector<uint64_t> result;
    uint64_t sub = mask;
    while (true) {
        result.push_back(sub); // 공집합 0도 포함
        if (sub == 0) break;
        sub = (sub - 1) & mask;
    }
    return result;
}
```

#### 코드 설명

비트 함수의 i는 0~63이어야 합니다. `mask=5`(101₂)의 부분마스크는 5,4,1,0입니다. C++20의 `std::popcount`는 C++17 표준 함수가 아닙니다. 고정 길이 비트열은 `bitset<N>`의 `set/reset/test/count`도 활용할 수 있습니다.

#### 시간복잡도

단일 비트 조작 O(1), bitCount O(1비트 수). 부분집합 합 O(N·2^N), 공간 O(2^N). K개 비트가 켜진 마스크의 부분마스크 열거 O(2^K), 반환 공간 O(2^K). 모든 마스크의 부분마스크를 함께 열거하면 O(3^N).

#### 자주 하는 실수

- `1 << i`를 큰 시프트에 사용.
- 형식의 비트 폭 이상 시프트.
- `mask & (1ULL << i) == 0`의 우선순위 착각: AND 결과를 괄호로 감쌉니다.
- 0 부분마스크에서 탈출하지 않아 반복.

#### 문제에서 보이는 신호

“N≈20”, “선택한 원소의 집합이 상태”, “부분집합”, “방문한 도시 집합”.

#### 30초 복습

추가 OR, 삭제 AND NOT, 토글 XOR, 검사 AND. 2^N이 실제로 가능한지 계산합니다.

---

### 4.2 이분탐색 / 매개변수 탐색

#### 언제 사용하는가

정렬된 배열 검색 또는 답 후보에 대한 판정이 한 방향으로만 바뀔 때.

#### 핵심 아이디어

거짓→참으로 바뀌는 첫 지점을 찾습니다. 아래 함수는 [lo,hi) 안의 첫 참을 반환하며 없으면 원래 hi를 반환합니다.

#### 템플릿 코드

```cpp
template<class Predicate>
ll firstTrue(ll lo, ll hi, Predicate ok) {
    // 전제: lo <= hi, hi-lo가 ll 범위 이내, 판정은 false ... true
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (ok(mid)) hi = mid; // mid도 정답 후보
        else lo = mid + 1;     // mid까지는 정답 아님
    }
    return lo;
}
ll minimumCapacity(const vector<int>& weights, int days) {
    // 순서를 유지하며 days일 이내에 운반. 무게는 양수, days >= 1
    if (weights.empty()) return 0;
    ll lo = *max_element(weights.begin(), weights.end());
    ll total = accumulate(weights.begin(), weights.end(), 0LL);
    auto feasible = [&](ll cap) {
        int used = 1;
        ll load = 0;
        for (int w : weights) {
            if (load + w > cap) { ++used; load = 0; }
            load += w;
        }
        return used <= days;
    };
    // total은 항상 가능. total+1은 배타적 상한이며 오버플로 없어야 함
    return firstTrue(lo, total + 1, feasible);
}
```

#### 코드 설명

용량이 커지면 필요한 일수는 늘어나지 않으므로 판정은 단조적입니다. `[1,2,3,4,5]`, 2일이면 최소 용량 9입니다. 최댓값을 구하는 문제도 판정 방향을 먼저 정한 뒤 경계를 설계합니다.

#### 시간복잡도

탐색 폭 W에 대해 O(log(W+1))회 판정. 운반 예제는 O(N log(W+1)), 추가 공간 O(1).

#### 자주 하는 실수

- 단조성을 확인하지 않음.
- 양끝 포함과 반열린 구간을 혼용.
- `lo=mid`로 갱신해 무한 반복.
- hi를 정답에 포함하면서 배타적 상한 코드 사용.

#### 문제에서 보이는 신호

“최소 용량”, “최대 가능한 거리”, “조건을 만족하는 최소 정수”.

#### 30초 복습

정답을 고정하면 판정 가능한가? 판정이 단조적인가? 첫 참의 경계를 유지합니다.

---

## PART 5. 정렬된 데이터 / 구간 처리

### 5.1 라인스위핑

#### 언제 사용하는가

좌표·시간 순서로 구간의 합집합 길이, 동시 활성 구간 수, 겹침을 처리할 때.

#### 핵심 아이디어

시작은 +1, 끝은 −1 이벤트로 만들고 좌표 순으로 처리합니다. 같은 좌표의 변화량을 묶기 전에 이전 좌표부터 현재까지의 상태를 계산합니다.

#### 템플릿 코드

```cpp
pair<ll,int> sweepIntervals(const vector<pair<ll,ll>>& intervals) {
    // [l,r), l <= r. 빈 구간은 제외. 길이의 합은 ll 범위 이내
    vector<pair<ll,int>> events;
    for (auto [l, r] : intervals) {
        if (l == r) continue;
        events.push_back({l, +1});
        events.push_back({r, -1});
    }
    if (events.empty()) return {0, 0};
    sort(events.begin(), events.end());
    ll length = 0, prev = events[0].first;
    int active = 0, peak = 0;
    size_t i = 0;
    while (i < events.size()) {
        ll x = events[i].first;
        if (active > 0) length += x - prev; // [prev,x)는 이전 상태
        int delta = 0;
        while (i < events.size() && events[i].first == x)
            delta += events[i++].second;
        active += delta; // x 이후의 활성 구간 수
        peak = max(peak, active);
        prev = x;
    }
    return {length, peak};
}
```

#### 코드 설명

`[1,3), [3,5)`는 길이 4, 최대 겹침 1입니다. 반열린 구간이므로 끝과 시작이 같은 시각은 겹치지 않습니다. 닫힌 구간의 한 점 중첩을 세는 문제는 이벤트 처리 규칙을 바꿔야 합니다.

#### 시간복잡도

O(N log N), 이벤트 공간 O(N).

#### 자주 하는 실수

- 같은 좌표의 시작/끝 순서에 따라 잘못된 최대 겹침 계산.
- 현재 이벤트 반영 후 이전 구간의 길이를 계산.
- 압축 좌표의 차이를 실제 길이로 사용.
- 닫힌 구간과 반열린 구간 의미를 혼동.

#### 문제에서 보이는 신호

“동시 접속 수”, “겹치는 최대 개수”, “선분들의 총 길이”, “시간순 이벤트”.

#### 30초 복습

좌표 정렬 → 이전 구간 정산 → 같은 좌표 이벤트 묶기 → 상태 갱신.

---

### 5.2 투포인터 / 슬라이딩 윈도우

#### 언제 사용하는가

양 끝 인덱스를 한 방향으로만 이동해 연속 구간을 처리할 수 있을 때. 예제는 양수 배열에서 합이 S 이상인 최소 길이입니다.

#### 핵심 아이디어

오른쪽을 늘려 합을 키우고, 조건을 만족하는 동안 왼쪽을 줄여 최소 길이를 갱신합니다. 양수라는 조건이 이 이동의 안전성을 보장합니다.

#### 템플릿 코드

```cpp
int minLengthAtLeast(const vector<int>& a, ll target) {
    // 전제: 모든 a[i] > 0, target > 0
    int n = int(a.size()), left = 0, answer = n + 1;
    ll sum = 0;
    for (int right = 0; right < n; ++right) {
        sum += a[right]; // 오른쪽 끝 포함
        while (sum >= target) {
            answer = min(answer, right - left + 1);
            sum -= a[left++]; // 조건을 만족하는 동안 왼쪽 축소
        }
    }
    return answer == n + 1 ? 0 : answer; // 불가능하면 0
}
bool hasPairSum(vector<int> a, ll target) {
    sort(a.begin(), a.end());
    int l = 0, r = int(a.size()) - 1;
    while (l < r) {
        ll sum = ll(a[l]) + a[r];
        if (sum == target) return true;
        if (sum < target) ++l; // 더 큰 합이 필요
        else --r;
    }
    return false;
}
```

#### 코드 설명

`[2,3,1,2,4,3]`, S=7의 최소 길이는 2입니다. 중첩 while이어도 각 포인터는 최대 N번 이동합니다. 두 수의 합 템플릿은 정렬 후 사용하는 별도 패턴이며 음수도 허용됩니다. 원래 인덱스가 필요하면 값과 인덱스를 함께 정렬합니다.

#### 시간복잡도

연속 구간 템플릿 O(N), 추가 공간 O(1). 두 수의 합은 정렬 포함 O(N log N), 배열 복사 공간 O(N).

#### 자주 하는 실수

- 음수가 있는 배열에 양수용 윈도우 적용.
- 연속 구간 문제에서 배열을 정렬해 원래 순서를 파괴.
- 두 수 합에서 같은 원소를 두 번 사용.
- 불가능 반환값을 답 길이로 오인.

#### 문제에서 보이는 신호

“연속 부분 배열”, “양수”, “구간을 확장/축소”, “정렬된 배열의 두 수”.

#### 30초 복습

포인터 이동이 조건을 어느 방향으로 바꾸는지 증명합니다. 두 포인터가 각각 N번만 움직이면 O(N).

---

### 5.3 LIS: 최장 증가 부분 수열

#### 언제 사용하는가

원래 순서를 유지하면서 엄격히 증가하는 부분 수열의 최대 길이를 구할 때.

#### 핵심 아이디어

`tails[k]`는 길이 k+1인 증가 부분 수열의 가능한 최소 마지막 값입니다. 각 값을 넣을 첫 ≥ 위치를 이분 탐색합니다.

#### 템플릿 코드

```cpp
int lisLength(const vector<int>& a) {
    vector<int> tails;
    for (int x : a) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x; // 길이는 유지하면서 끝 값을 작게 만듦
    }
    return int(tails.size());
}
vector<int> lisSequence(const vector<int>& a) {
    int n = int(a.size());
    vector<int> tails, tailIndex, parent(n, -1);
    for (int i = 0; i < n; ++i) {
        int p = int(lower_bound(tails.begin(), tails.end(), a[i]) - tails.begin());
        if (p > 0) parent[i] = tailIndex[p - 1]; // 이전 길이의 마지막 위치
        if (p == int(tails.size())) {
            tails.push_back(a[i]); tailIndex.push_back(i);
        } else {
            tails[p] = a[i]; tailIndex[p] = i;
        }
    }
    vector<int> result;
    if (tails.empty()) return result;
    for (int i = tailIndex.back(); i != -1; i = parent[i])
        result.push_back(a[i]);
    reverse(result.begin(), result.end());
    return result;
}
```

#### 코드 설명

`[10,20,10,30,20,50]`의 길이는 4입니다. tails 자체는 원래 인덱스 순서를 보장하지 않으므로 정답 수열로 출력할 수 없습니다. 실제 수열은 부모 인덱스로 복원합니다. 같은 값을 허용하는 비감소 수열은 두 함수 모두 `upper_bound`로 바꿉니다.

#### 시간복잡도

O(N log N), 공간 O(N). 학습용 O(N²) DP는 `dp[i]=1+max(dp[j])` (j<i, a[j]<a[i])로 정의할 수 있습니다.

#### 자주 하는 실수

- 부분 수열과 연속 부분 배열을 혼동.
- 원본 배열을 정렬.
- 중복값 허용 여부에 맞지 않는 bound 사용.
- tails를 실제 LIS라고 출력.

#### 문제에서 보이는 신호

“순서를 유지하며 일부 삭제”, “가장 긴 증가 수열”, “비감소”.

#### 30초 복습

길이별 최소 끝값 유지. 엄격 증가 lower_bound, 비감소 upper_bound. 수열은 parent로 복원.

---

## PART 6. 동적 계획법

### 6.1 DP: 상태·전이·초기화·순서

#### 언제 사용하는가

작은 문제의 답을 재사용하고, 현재 상태가 이후 결정에 필요한 정보를 충분히 담을 때.

#### 핵심 아이디어

① 상태의 의미 ② 점화식 ③ 시작 상태 ④ 계산 순서 ⑤ 최종 답을 먼저 씁니다. 아래 0/1 배낭은 “처리한 물건으로 용량 c 이하에서 가능한 최대 가치”를 상태로 사용합니다.

#### 템플릿 코드

```cpp
ll knapsack01(const vector<int>& weight, const vector<ll>& value, int capacity) {
    // 각 물건은 최대 한 번. 양의 무게, capacity >= 0, 같은 배열 길이
    vector<ll> dp(capacity + 1, 0); // 아무것도 고르지 않는 선택 허용
    for (int i = 0; i < int(weight.size()); ++i) {
        // 역순: dp[c-weight[i]]가 이번 물건을 아직 사용하지 않은 상태
        for (int c = capacity; c >= weight[i]; --c)
            dp[c] = max(dp[c], dp[c - weight[i]] + value[i]);
    }
    return dp[capacity];
}
int minCoins(const vector<int>& coins, int target) {
    // 양의 동전, 각 동전 무한 사용. target은 메모리에 들어오는 작은 값
    const int BAD = target + 1;
    vector<int> dp(target + 1, BAD);
    dp[0] = 0; // 합 0을 만드는 데 필요한 동전은 0개
    for (int sum = 1; sum <= target; ++sum)
        for (int coin : coins)
            if (coin <= sum && dp[sum - coin] != BAD)
                dp[sum] = min(dp[sum], dp[sum - coin] + 1);
    return dp[target] == BAD ? -1 : dp[target];
}
```

#### 코드 설명

0/1 배낭에서 순방향으로 갱신하면 현재 물건을 여러 번 쓰게 됩니다. “정확히 용량 c”를 채우는 문제는 dp[0]=0, 나머지 불가능 상태를 −INF로 두고 이전 상태의 가능 여부도 검사해야 합니다. 동전 최소 개수는 불가능 상태를 큰 값으로 초기화합니다. 경우의 수 DP에서는 순서를 구분하는지에 따라 반복 순서가 바뀝니다.

#### 시간복잡도

물건 N개·용량 C: O(NC), 공간 O(C). 동전 K종·목표 S: O(KS), 공간 O(S). 수치 C/S에 비례하므로 입력 비트 길이 기준으로는 의사다항 시간입니다.

#### 자주 하는 실수

- dp 배열을 만든 뒤 의미를 나중에 정함.
- 불가능 상태를 0으로 초기화.
- 압축 후 갱신 방향 오류.
- 경우의 수에서 중복 계산과 모듈러 연산 누락.
- 재귀 메모이제이션에서 “미계산”과 실제 0을 혼동.

#### 문제에서 보이는 신호

“최대/최소/경우의 수”와 함께 부분 문제가 반복됨. “앞 i개”, “현재 위치와 남은 자원” 등으로 상태를 정의할 수 있음.

#### 30초 복습

상태를 한 문장으로 → 전이 → 초기값 → 순서 → 답. 시간은 대체로 상태 수 × 상태당 전이 수.

---

## PART 7. 그래프 최단거리

### 7.1 Dijkstra

#### 언제 사용하는가

모든 간선 가중치가 0 이상인 그래프에서 한 시작점의 최단거리.

#### 핵심 아이디어

현재 가장 짧은 거리 후보를 최소 힙에서 꺼내 간선을 완화합니다. 더 나중에 개선되어 낡은 후보는 무시합니다.

#### 템플릿 코드

```cpp
using WeightedGraph = vector<vector<pair<int,ll>>>; // {다음 정점, 가중치}
vector<ll> dijkstra(const WeightedGraph& g, int start) {
    vector<ll> dist(g.size(), INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist[start] = 0; pq.push({0, start});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue; // 이미 개선된 과거 후보 건너뛰기
        for (auto [v, w] : g[u]) {
            // 전제: w >= 0, d+w가 범위 내이며 유한 거리는 INF 미만
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist; // INF는 도달 불가능
}
```

#### 코드 설명

힙은 `{거리,정점}` 순서여야 합니다. 삽입 시점에는 최단거리 확정이 아닙니다. 목표 정점만 필요하면 낡은 후보 검사를 통과한 뒤 해당 정점을 꺼냈을 때 종료할 수 있습니다. 경로는 완화 시 parent를 기록합니다.

#### 시간복잡도

중복 후보를 넣는 이 구현은 O(V+E log(E+2)), 추가 공간 O(V+E). 단순 그래프에서는 흔히 O((V+E) log V)로 표기합니다. 입력 그래프 공간은 O(V+E).

#### 자주 하는 실수

- 음수 간선에 적용.
- 기본 최대 힙을 그대로 사용.
- 삽입할 때 방문 확정.
- 거리와 가중치를 int로 저장.
- 낡은 후보 건너뛰기 누락으로 불필요한 연산 증가.

#### 문제에서 보이는 신호

“출발점 하나”, “가중치가 음수가 아님”, “최소 비용 경로”.

#### 30초 복습

최소 힙 → 과거 후보 무시 → 완화. 음수가 있으면 적용 조건이 깨집니다.

---

### 7.2 Floyd-Warshall

#### 언제 사용하는가

모든 정점 쌍의 최단거리가 필요하고 O(V³)이 가능한 작은 그래프. 음수 간선은 허용하되 음수 사이클의 영향을 따로 해석합니다.

#### 핵심 아이디어

k를 중간에 허용하는 정점으로 늘리며 `dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])`를 계산합니다.

#### 템플릿 코드

```cpp
vector<vector<ll>> floydWarshall(int n, const vector<tuple<int,int,ll>>& edges) {
    vector<vector<ll>> d(n, vector<ll>(n, INF));
    for (int i = 0; i < n; ++i) d[i][i] = 0;
    for (auto [u, v, w] : edges)
        d[u][v] = min(d[u][v], w); // 방향 간선, 중복이면 최소 비용
    for (int k = 0; k < n; ++k) // 중간 정점 루프가 반드시 가장 바깥
        for (int i = 0; i < n; ++i) {
            if (d[i][k] == INF) continue;
            for (int j = 0; j < n; ++j) {
                if (d[k][j] == INF) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    return d;
}
vector<vector<char>> negativeCyclePairs(const vector<vector<ll>>& d) {
    int n = int(d.size());
    vector<vector<char>> bad(n, vector<char>(n, false));
    for (int k = 0; k < n; ++k) if (d[k][k] < 0)
        for (int i = 0; i < n; ++i) if (d[i][k] != INF)
            for (int j = 0; j < n; ++j) if (d[k][j] != INF)
                bad[i][j] = true; // 음수 사이클을 거쳐 갈 수 있는 쌍
    return bad;
}
```

#### 코드 설명

무방향 그래프는 역방향 간선도 입력합니다. `d[k][k]<0`이면 음수 사이클이 있습니다. `bad[i][j]`인 쌍은 비용을 끝없이 줄일 수 있어 유한한 최단거리가 없습니다. 그 외 쌍에서 INF는 도달 불가능입니다. 음수 사이클로 중간 수치가 커질 수 있으므로 위 수치 범위 전제를 특히 확인하세요.

#### 시간복잡도

O(V³), 거리 및 영향 행렬 공간 O(V²).

#### 자주 하는 실수

- k를 안쪽 루프에 둠.
- 자기 자신 거리를 0으로 초기화하지 않음.
- 다중 간선 최소값 처리 누락.
- INF에 음수 값을 더해 가짜 경로 생성.
- 음수 사이클 영향을 받은 값을 최단거리로 사용.

#### 문제에서 보이는 신호

“모든 도시 쌍”, “각 지점에서 각 지점까지”, “정점 수가 작음”.

#### 30초 복습

대각 0, 간선 최소값, k-i-j, INF 확인. 음수 대각이면 영향받는 쌍을 구분합니다.

---

### 7.3 Bellman-Ford

#### 언제 사용하는가

음수 간선이 있는 그래프의 단일 시작점 최단거리, 시작점에서 도달 가능한 음수 사이클 검출.

#### 핵심 아이디어

모든 간선을 V−1회 완화합니다. 음수 사이클이 없으면 최단 단순 경로는 최대 V−1개 간선입니다. 이후에도 개선될 정점에서 전파하면 음수 사이클의 영향을 받는 모든 정점을 알 수 있습니다.

#### 템플릿 코드

```cpp
struct Edge { int u, v; ll w; };
struct BellmanResult {
    vector<ll> dist;
    vector<char> negative; // true이면 최단거리가 음의 무한대
};
BellmanResult bellmanFord(int n, const vector<Edge>& edges, int start) {
    vector<ll> d(n, INF);
    d[start] = 0;
    for (int round = 0; round < n - 1; ++round) {
        bool changed = false;
        for (auto [u, v, w] : edges) {
            if (d[u] == INF) continue; // 시작점에서 도달한 간선만 완화
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                changed = true;
            }
        }
        if (!changed) break;
    }
    vector<vector<int>> g(n);
    vector<char> negative(n, false);
    queue<int> q;
    for (auto [u, v, w] : edges) {
        g[u].push_back(v);
        // 여기서는 d를 변경하지 않고 개선 가능한 정점만 표시
        if (d[u] != INF && d[u] + w < d[v] && !negative[v]) {
            negative[v] = true; q.push(v);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) if (!negative[v]) {
            negative[v] = true; q.push(v);
        }
    }
    return {d, negative};
}
```

#### 코드 설명

`negative[v]`가 true면 d[v]를 답으로 쓰지 않습니다. false이면서 INF이면 도달 불가능, 나머지는 유한 최단거리입니다. 그래프 어디에든 있는 음수 사이클을 검출하려면 모든 정점으로 비용 0 간선을 갖는 가상 시작점을 추가하거나 모든 초기 거리를 0으로 둡니다. 후자는 원래 시작점의 최단거리를 구하는 초기화가 아닙니다.

#### 시간복잡도

O(VE+V+E), 추가 공간 O(V+E). 보통 최단거리 완화 비용을 O(VE)로 표기합니다.

#### 자주 하는 실수

- 도달 불가능한 정점의 INF에 가중치를 더함.
- V−1회 완화만 하고 음수 사이클을 놓침.
- 시작점과 무관한 음수 사이클까지 찾는다고 가정.
- 중간 거리 오버플로. 단순 경로 범위만 보고 판단하면 부족할 수 있음.

#### 문제에서 보이는 신호

“음수 비용”, “시간이 되돌아감”, “음수 사이클”, “가중치 음수 허용”.

#### 30초 복습

V−1회 전체 간선 완화 → 한 번 더 개선 가능 여부 → 영향 정점 전파. 출발점 도달성 조건을 기억합니다.

---

## PART 8. 고급 자료구조

### 8.1 Fenwick Tree / Binary Indexed Tree

#### 언제 사용하는가

배열 값이 바뀌면서 구간 합을 여러 번 묻는 문제. 좌표 압축과 함께 누적 빈도·역전쌍 계산에도 사용합니다.

#### 핵심 아이디어

내부 인덱스 i는 `i & -i` 길이의 누적 구간을 관리합니다. 갱신은 상위 구간으로 올라가고, 누적합은 구간을 떼어내며 내려갑니다.

#### 템플릿 코드

```cpp
struct Fenwick {
    int n;
    vector<ll> tree;
    explicit Fenwick(int n) : n(n), tree(n + 1, 0) {}
    void add(int index, ll delta) {
        // 외부는 0-based, 내부는 1-based. 0 <= index < n
        assert(0 <= index && index < n);
        for (int i = index + 1; i <= n; i += i & -i)
            tree[i] += delta;
    }
    ll prefix(int r) const {
        // 원본 배열 [0,r)의 합. 0 <= r <= n
        assert(0 <= r && r <= n);
        ll sum = 0;
        for (int i = r; i > 0; i -= i & -i)
            sum += tree[i];
        return sum;
    }
    ll query(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        return prefix(r) - prefix(l); // [l,r)
    }
};
```

#### 코드 설명

초기 배열 a는 각 i에서 `add(i,a[i])`를 호출해 구축합니다. a[i]를 x로 교체하려면 `add(i,x-a[i])` 후 원본 a[i]도 x로 바꿉니다. [2,3,5]에서 query(1,3)=8, add(1,4) 후 12입니다. 일반적인 임의 구간 최소값 문제는 이 합 템플릿으로 해결되지 않습니다.

#### 시간복잡도

갱신·누적합·구간합 O(log N), 공간 O(N). add 반복 초기화 O(N log N).

#### 자주 하는 실수

- 내부 인덱스를 0에서 시작해 무한 루프.
- add에 새 값 자체를 전달.
- prefix(r)를 r번째 원소까지 포함한다고 오해.
- long long 합 누락.
- 범위를 벗어난 인덱스 사용.

#### 문제에서 보이는 신호

“값 갱신과 구간 합 반복”, “앞에서 작은 값 개수”, “동적 누적 빈도”.

#### 30초 복습

외부 0-based, 내부 +1. add는 차이만, prefix(r)는 [0,r). 구간 합은 두 누적합의 차이.

---

## PART 9. 시험 직전 Cheat Sheet

### 9.1 알고리즘 선택표

| 문제 조건 / 목표 | 먼저 검토할 알고리즘 | 반드시 확인할 조건 |
|---|---|---|
| 고정 배열의 반복 구간 합 | 누적합 | 변경 없음, 구간 인덱스 |
| 직사각형 합 | 2차원 누적합 | 포함·배제, 행/열 범위 |
| 규칙에 따른 시간 진행 | 구현 / 시뮬레이션 | 동시 갱신 여부 |
| 무방향 연결 그룹 | DFS/BFS | 비연결 정점 전체 순회 |
| 같은 비용의 최소 이동 횟수 | BFS | 상태에 필요한 차원 포함 |
| 깊이 우선 방문·종료 순서 | DFS | 깊이, 방문 표시 |
| 후보 수가 작음 | 완전탐색 | 실제 후보 수 × 검사 비용 |
| 부분 선택에서 불가능 판정 | 백트래킹 | 가지치기가 항상 안전한가 |
| 작은 집합의 상태 | 비트마스킹 | 2^N 시간·메모리 |
| 현재 선택의 안전성 증명 가능 | 그리디 | 반례와 교환 논증 |
| 시간/좌표 순 이벤트 | 라인스위핑 | 같은 좌표, 끝점 포함 여부 |
| 양수 연속 구간 합 | 투포인터 | 이동 방향의 단조성 |
| 정렬된 두 수 합 | 양끝 투포인터 | 서로 다른 원소, 원래 인덱스 |
| 단조적인 가능/불가능 판정 | 이분탐색 | 탐색 경계와 판정 방향 |
| 순서 유지 최장 증가 부분 수열 | LIS | 엄격 증가 / 비감소 |
| 겹치는 부분 문제 | DP | 상태·전이·초기화·순서 |
| 점 갱신 + 구간 합 | Fenwick Tree | add는 변화량 |
| 단일 출발, 비음수 가중치 | Dijkstra | 음수 간선 없음 |
| 모든 쌍, 작은 정점 수 | Floyd-Warshall | O(V³) 가능, 음수 사이클 |
| 단일 출발, 음수 간선 | Bellman-Ford | O(VE) 가능, 음수 사이클 영향 |

가중치가 0과 1뿐이면 deque를 사용하는 **0-1 BFS**, DAG라면 위상순서 DP도 후보입니다. 이 두 알고리즘은 선택표의 확장 안내이며 본문 템플릿 범위 밖입니다. 음수 간선이 있다는 이유만으로 Bellman-Ford를 선택한 뒤 시간 제한을 무시하지 마세요.

### 9.2 시간복잡도 표

V=정점 수, E=간선 수, N=원소 수, Q=질의 수, C=용량, W=이분탐색 후보 폭, K=선택 개수입니다. 공간은 입력 외 추가 공간이며 반환 결과와 코드의 인자 복사도 포함합니다.

| 알고리즘 | 시간 | 추가 공간 | 주의 |
|---|---|---|---|
| 누적합 | O(N+Q) | O(N) | 질의당 O(1) |
| 2차원 누적합 | O(RC+Q) | O(RC) | 큰 격자 메모리 |
| 구현 예제 | O(명령 수) | O(1) | 실제 규칙에 따라 달라짐 |
| 그리디 구간 선택 | O(N log N) | O(N) | 배열 복사 포함 |
| 그래프 연결 요소 | O(V+E) | O(V), 그래프 구축 O(V+E) | 인접 리스트 |
| BFS / DFS | O(V+E) | O(V) | 도달 부분 탐색 |
| 순열 완전탐색 예제 | O(N·(N−1)!) | O(N) | 시작 정점 고정 |
| 조합 백트래킹 | O(K·C(N,K)) | O(K·C(N,K)) | 결과 저장, 1≤K≤N |
| 부분집합 합 예제 | O(N·2^N) | O(2^N) | 비트마스크 전수 검사 |
| 그 마스크의 부분마스크 | O(2^K) | O(2^K) | K는 켜진 비트 수 |
| 라인스위핑 | O(N log N) | O(N) | 이벤트 정렬 |
| 투포인터 구간 | O(N) | O(1) | 각 포인터 이동 합 |
| 이분탐색 | O(log(W+1) × 판정 비용) | 판정에 따름 | 예제 판정 O(N) |
| LIS | O(N log N) | O(N) | 복원 포함 |
| 0/1 배낭 | O(NC) | O(C) | 압축 배열 역순 |
| Fenwick Tree | 구축 O(N log N), 연산 O(log N) | O(N) | 본문 구축 방식 |
| Dijkstra | O(V+E log(E+2)) | O(V+E) | 중복 후보 힙 |
| Floyd-Warshall | O(V³) | O(V²) | 행렬 |
| Bellman-Ford | O(VE+V+E) | O(V+E) | 음수 영향 전파 포함 |

### 9.3 제한에서 연산 규모 가늠하기

다음은 실행 시간을 보장하는 기준이 아니라 후보 복잡도를 거르기 위한 연산량 예시입니다. 채점 시간, 상수 비용, 언어 환경, 메모리 접근 패턴에 따라 결과가 달라집니다.

| 규모 예시 | 연산 규모 | 판단 포인트 |
|---|---|---|
| N=10의 순열 | 10! ≈ 363만 | 후보당 O(N) 검사 비용도 곱함 |
| N=20의 부분집합 | 2²⁰ ≈ 105만 | N배하면 약 2,100만 |
| N=40의 부분집합 | 2⁴⁰ ≈ 1.1조 | 단순 전수 검사는 매우 큼 |
| N=5,000의 이중 루프 | 2,500만 | 내부 처리 비용을 확인 |
| V=500의 Floyd | 1억 2,500만 | 시간 제한에 따라 부담 |
| N=200,000의 정렬 | N log₂N ≈ 350만 규모 | 비교 비용과 입출력도 포함 |
| 5,000²개의 8바이트 값 | 약 200MB | 컨테이너 추가 비용 별도 |

### 9.4 한 줄 암기 카드

| 항목 | 핵심 |
|---|---|
| 구간 합 | `[l,r)` = `p[r]-p[l]` |
| 직사각형 합 | 전체 − 위 − 왼쪽 + 겹침 |
| BFS | 큐, 발견 시 방문, 거리 +1 |
| DFS | 스택, 진입과 종료 구분 |
| 백트래킹 | 선택 → 재귀 → 취소 |
| 비트 | OR 추가 / AND NOT 삭제 / XOR 토글 |
| 그리디 | 선택 전에 증명 |
| 스위핑 | 이전 구간 정산 후 같은 좌표 일괄 갱신 |
| 투포인터 | 각 포인터의 총 이동 횟수 |
| 이분탐색 | 첫 참: 참이면 hi=mid, 거짓이면 lo=mid+1 |
| LIS | 엄격 증가 lower_bound / 비감소 upper_bound |
| DP | 상태 → 전이 → 초기값 → 순서 → 답 |
| 0/1 배낭 | 용량 역순 |
| Fenwick | 외부 0-based, 내부 +1, 차이 갱신 |
| Dijkstra | 비음수 + 최소 힙 + 낡은 후보 무시 |
| Floyd | k가 가장 바깥 |
| Bellman | V−1회 완화 + 추가 개선 검사 |

### 9.5 제출 전 점검표

- [ ] 입력 크기로 시간복잡도와 메모리 사용량을 계산했다.
- [ ] 배열/정점 번호, 구간 포함 여부, 방향 번호를 확인했다.
- [ ] 합·곱·거리의 중간 연산까지 범위를 확인했다.
- [ ] 방문 표시 시점과 테스트케이스별 초기화를 확인했다.
- [ ] 빈 입력(허용 시), 원소 하나, 중복값, 불가능한 경우를 확인했다.
- [ ] 그래프의 비연결, 자기 간선, 중복 간선, 가중치 조건을 확인했다.
- [ ] 정렬 비교 함수에서 `<=`를 사용하지 않았다.
- [ ] 재귀 깊이와 결과 저장량이 과도하지 않다.
- [ ] 출력 형식, 개행, 정밀도, 문제의 불가능 표기를 맞췄다.
- [ ] 템플릿의 전제가 실제 입력 조건과 일치한다.

### 9.6 직접 풀어보는 작은 복습 문제

1. `[3,-2,5,1]`의 [1,4) 합은? **4**. 음수도 누적합에는 문제없습니다.
2. 간선 0–1, 1–2, 정점 3이 고립되어 있다면 연결 요소는? **2개**.
3. `[2,2,2]`의 엄격 증가 LIS 길이와 비감소 길이는? **1, 3**.
4. 0/1 배낭에서 무게 2, 가치 3인 물건 하나, 용량 4일 때 정답은? **3**. 순방향 갱신으로 6이 나오면 중복 사용 오류입니다.
5. `[0,2), [2,4)`의 합집합 길이와 최대 겹침은? **4, 1**.
6. 0에서 도달할 수 없는 음수 사이클을 기본 Bellman-Ford가 표시하는가? **아니요**.
7. a=[2,3,5]에서 두 번째 값을 7로 변경하려면 Fenwick에 무엇을 더하는가? **add(1,4)**.
8. 합 조건의 슬라이딩 윈도우에 음수가 있으면 왜 위험한가? **왼쪽을 제거해도 합이 커질 수 있어 포인터 이동의 근거가 깨집니다.**

### 첨부 코드 사용

`cpp17_templates.cpp`에는 본문 알고리즘 함수와 대표·경계 사례를 확인하는 assertion이 들어 있습니다. 표준 C++17 컴파일러에서 실행할 수 있습니다.

```sh
c++ -std=c++17 -O2 -Wall -Wextra -pedantic cpp17_templates.cpp -o templates
./templates
```

정상 실행 시 `All template checks passed.`를 출력합니다. assertion을 끄는 `-DNDEBUG`는 검증 시 사용하지 마세요. 이 검증은 대표 사례를 확인하며, 모든 입력에 대한 정확성을 보장하는 전수 검증은 아닙니다.

