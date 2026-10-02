#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

// 최단 시간 = BFS (최단 시간 보장)

int n, k;
int dist[MAX + 1], cnt[MAX + 1]; // 해당위치까지의 시간, 해당위치까지오는 경로 수.

int main() {
    cin >> n >> k;
    fill(&dist[0], &dist[0] + MAX + 1, -1);
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    cnt[n] = 1;
    while(!q.empty()) {
        int x = q.front(); q.pop();

        int next[3] = {x - 1, x + 1, x * 2}; // 이동 정의

        for (int i=0; i<3; i++) {
            int nx = next[i];
            if (nx < 0 || nx > MAX) continue; // 엣지체크
            // 처음 방문인 경우 -> 시간/경로 수 갱신, 다음 방문을 위해 큐 삽입.
            if (dist[nx] == -1) {dist[nx] = dist[x] + 1; cnt[nx] = cnt[x]; q.push(nx);}
            // 이미 방문한 경우 -> 경로수만 증가
            else if (dist[nx] == dist[x] + 1) {cnt[nx] += cnt[x];} 
        }
    }

    cout << dist[k] << "\n" << cnt[k];


    return 0;
}