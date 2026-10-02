// 숨바꼭질 2 - BOJ 12851 (해결 못함)
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

// <이 문제에서 개선할 점>
//
// 1. 최단 시간을 구하는 문제이므로 DFS보다 BFS를 사용하는 것이 적절함.
//    BFS는 같은 시간에 도달 가능한 위치를 레벨 단위로 탐색함.
//
// 2. 현재 DFS에서는 같은 위치를 계속 다시 방문할 수 있으므로
//    중복 탐색이 매우 많이 발생함.
//    ex) 5 -> 6 -> 5 -> 6 ...
//
// 3. 단순 visited만 사용하면 안 됨.
//    같은 위치에 "같은 최단 시간"으로 다시 도착한 경우도
//    최단 경로의 개수에 포함해야 하기 때문.
//
// 4. 따라서 dist[x]에 해당 위치의 최소 도착 시간을 저장하고,
//    다음 위치를 처음 방문하거나 같은 최단 시간으로 도착한 경우를 처리해야 함.
//
// 5. DFS에서 time > k-n 으로 가지치기하는 것도 안전하지 않음.
//    순간이동(*2)을 이용하면 k-n보다 훨씬 빠르게 도착할 수 있고,
//    n > k인 경우에는 k-n 자체가 음수가 됨.

int n, k;
int dist[MAX + 1];   // 해당 위치까지의 최소 시간
int cnt[MAX + 1];    // 해당 위치까지 최소시간으로 가는 방법의 수

int main() {
    cin >> n >> k;
    fill(dist, dist + MAX + 1, -1);

    queue<int> q;
    q.push(n);
    dist[n] = 0;
    cnt[n] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int next[3] = {cur - 1, cur + 1, cur * 2};

        for (int i = 0; i < 3; i++) {
            int nx = next[i];

            if (nx < 0 || nx > MAX) continue;
            // 처음 방문한 위치인 경우
            if (dist[nx] == -1) {
                dist[nx] = dist[cur] + 1;
                // cur까지 오는 모든 최단경로가 nx까지의 최단경로가 됨.
                cnt[nx] = cnt[cur];
                q.push(nx);
            }
            // 이미 방문했지만 같은 최단시간으로 다시 도착한 경우
            else if (dist[nx] == dist[cur] + 1) {
                cnt[nx] += cnt[cur];
            }
        }
    }

    cout << dist[k] << '\n';
    cout << cnt[k];

    return 0;
}