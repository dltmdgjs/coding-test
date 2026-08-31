// 영역 구하기 - 실버 1
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, BFS, DFS, 플러드 필

#include <bits/stdc++.h>
using namespace std;


int M, N, K, a[101][101], cnt, area[101];
bool visited[101][101];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};


void dfs(int y, int x, int cnt) {
    visited[y][x] = true;
    area[cnt]++;
    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if (!visited[ny][nx] && a[ny][nx] == 0) {
            // cout << ny << ", " << nx << '\n';
            dfs(ny, nx, cnt);
        }
    }
    return;
}

int main() {

    cin >> M >> N >> K;

    for (int i=0; i<K; i++) {
        int x_1, y_1, x_2, y_2;
        cin >> x_1 >> y_1 >> x_2 >> y_2;

        // 색칠하기
        for (int l=x_1; l<x_2; l++) {
            for (int m=y_1; m<y_2; m++) {
                // cout << l << ", " << m << '\n';
                a[l][m] = 1;
            }
        }
    }

    // Connected Component 찾기 - BFS or DFS
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (!visited[i][j] && a[i][j] == 0) {
                // cout << i << ", " << j << '\n';
                dfs(i, j, cnt);
                cnt++;
            }
        }
    }

    cout << cnt << '\n';

    sort(area, area+cnt);

    for (int i=0; i<cnt; i++) {
        cout << area[i] << " ";
    }

    return 0;
}


// int 형 dfs로 풀 수도 있음
        // int dfs(int y, int x) {
        //     visited[y][x] = true;
        //     int res = 1;
        //     for (int i=0; i<4; i++) {
        //         int ny = y + dy[i];
        //         int nx = x + dx[i];
        //         if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        //         if (!visited[ny][nx] && a[ny][nx] == 0) {
        //             res += dfs(ny, nx, cnt);
        //         }
        //     }
        //     return res
        // }