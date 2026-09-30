// 효율적인 해킹 - BOJ 1325

// 신뢰 관계 A - B (A가 B를 신뢰함 : B해킹시 A같이 해킹됨)

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v[10001];
int cnt[10001];
int visited[10001];
int mx;


// 개선점 : dfs 연습 더해야할거 같음. (아이디어는 떠오르나 막상 구현하려니 어렵다.)
// 2차원 그래프 탐색은 템플릿을 외워서 쉬운데, 이런 방식은 처음임..

// 근데 이 방식도 사실 보면 그냥 연결된 것을 하나씩 탐색하는 것임.
// 2차원 그래프는 상하좌우를 탐색했다면, 여기에선 한 정점에 연결된 다른 정점들을 꺼내서 하나씩 탐색하는 구조.
// 어려울 것 없음.
int dfs(int x) {
    visited[x] = 1;
    int res = 0;
    for (int c : v[x]) {
        if (visited[c]) continue;
        res += dfs(c);
    }
    return res + 1;
}

int main() {
    cin >> N >> M;

    int a, b;
    for (int i=0; i<M; i++) {
        cin >> a >> b;
        v[b].push_back(a);
    }

    for (int i=1; i<=N; i++) {
        fill(&visited[0], &visited[0] + 10001, 0);
        cnt[i] = dfs(i);
        mx = max(cnt[i], mx);
    }
    for (int i=1; i<=N; i++) {
        if (mx == cnt[i]) cout << i << " ";
    }

    return 0;
}