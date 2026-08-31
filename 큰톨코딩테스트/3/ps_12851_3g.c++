// 숨바꼭질 2 - 골드 4
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비우선탐색(BFS)

#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int n, k, visited[MAX], cnt[MAX];

int main() {
    cin >> n >> k;

    queue<int> q;
    q.push(n);
    visited[n] = 1;
    cnt[n] = 1;
    while (q.size()) {
        int cur = q.front();
        q.pop();
        int x[3] = {cur+1, cur-1, cur*2};
        for (int i=0; i<3; i++) {
            int nx = x[i];
            if (nx < 0 || nx >= MAX) continue;

            // 한번도 방문한 적이 없는 경우 -> 계속 탐색 및 방문 갱신
            if (visited[nx] == 0) {
                q.push(nx);
                visited[nx] = visited[cur] + 1;
                cnt[nx] = cnt[cur];
            // 방문한 적이 있고 이전 지점의 방문값+1과 동일하다면(즉, 이 지점으로 오는 또다른 경로라는 의미)
            // -> 찾는 방법 수 갱신(더해주면 됨)
            } else if (visited[nx] == visited[cur] + 1) {
                cnt[nx] += cnt[cur];
            }
        }
    }

    cout << visited[k]-1 << '\n';
    cout << cnt[k];

    return 0;
}

// 1초라는 동일한 가중치로 최단 시간을 구하기 -> BFS(너비우선탐색)
// BFS는 첫 방문이 최단 경로임을 보장함 (단 가중치가 1로 동일할 경우에 한정됨)