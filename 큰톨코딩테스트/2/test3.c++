#include <bits/stdc++.h>
using namespace std;

int N, M, arr[104][104], visited[104][104];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
queue<pair<int,int>> q;

int ys,xs,ye,xe;

// 큐를 이용한 bfs
int bfs(int y, int x) {
    visited[y][x] = 1;
    q.push({y, x});
    while(q.size()) {
        pair<int, int> u = q.front();
        q.pop();
        for (int i=0; i<4; i++) {
            int ny = u.first+dy[i];
            int nx = u.second+dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (!visited[ny][nx] && arr[ny][nx] == 1) {
                visited[ny][nx] = visited[u.first][u.second] + 1;
                if (ny == ye && nx == xe) return visited[ny][nx];
                q.push({ny, nx});
            }
        }
    }
}

int main() {

    cin >> N >> M;
    cin >> ys >> xs;
    cin >> ye >> xe;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> arr[i][j];
        }
    }

    // 최단거리(가중치 동일) -> bfs
    int result = bfs(ys,xs);
    cout << result;
    return 0;
}