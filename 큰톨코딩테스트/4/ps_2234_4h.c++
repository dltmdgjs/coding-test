// 성곽 - 골드 3
// 알고리즘 분류 : 


#include <bits/stdc++.h>
using namespace std;

int N, M, a[50][50], visited[50][50];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
int Q1, Q2, Q3;


void go(int y, int x) {

    int cnt = 1;
    queue<pair <int, int>> q;
    visited[y][x] = 1;
    q.push({y,x});
    while (q.size()) {
        pair<int, int> u = q.front(); q.pop();

        // 좌상우하
        for (int i=0; i<4; i++) {
            int ny=u.first+dy[i];
            int nx=u.second+dx[i];
            if (ny<0 || ny>=N || nx< 0 || nx>=M || visited[ny][nx]) continue;
            // 벽인지 체크 -> 개선 필요
            // if ((abs(a[ny][nx]-a[u.first][u.second])) == (1<<i)) {
            //     continue;
            // }
            visited[ny][nx] = 1; cnt++;
            q.push({ny, nx});
        }
    }


    Q2 = max(Q2, cnt);
}

int main() {
    cin >> M >> N;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> a[i][j];
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (!visited[i][j]) {
                go(i, j); Q1++;
            }
        }
    }

    cout << Q1 << '\n' << Q2 << '\n' << Q3;

    return 0;
}