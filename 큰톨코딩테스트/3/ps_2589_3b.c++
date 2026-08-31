// 시간초과 해결방법 찾기
//  -> 해결법 : 굳이 쌍을 고르지 않고, 모든 곳에 bfs를 돌리면 됨. 
//             (L(1)인 부분만 bfs 실행하면 됨. max 값만 찾으면..)

#include <bits/stdc++.h>
using namespace std;

int N, M, arr[51][51], mx;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int visited[51][51];


void bfs(int y, int x) {
    // 큐를 이용.
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;

    while(q.size()) {
        pair<int, int> u = q.front();
        q.pop();

        for (int i=0; i<4; i++) {
            int ny = u.first + dy[i];
            int nx = u.second + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M || arr[ny][nx] == 0) continue;

            if (!visited[ny][nx] && arr[ny][nx] == 1) {
                visited[ny][nx] = visited[u.first][u.second] + 1;
                q.push({ny, nx});
                mx = max(mx, visited[ny][nx]);
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        for (int j=0; j<M; j++) {
            if (s[j] == 'W') {
                arr[i][j] = 0;
            }
            else {
                arr[i][j] = 1;
            }
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (arr[i][j] == 1) {
                fill(&visited[0][0], &visited[0][0]+51*51, 0);
                bfs(i, j);
            }
        }
    }

    cout << mx - 1;
    return 0;
}