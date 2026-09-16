// 안전영역 - BOJ 2468

// 개선점 1 : 경계조건 잘 확인하기 (엣지)

#include <bits/stdc++.h>
using namespace std;
#define MAX 101

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N, w, res=0, cnt=0;
int a[MAX][MAX], visited[MAX][MAX];

void dfs(int x, int y) {
    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if (visited[nx][ny] || a[nx][ny] <= w) continue;
        visited[nx][ny] = 1;
        dfs(nx, ny);
    }
}

int main() {

    cin >> N;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> a[i][j];
            w = max(w, a[i][j]);
        }
    }
    
    while(w--) {
        fill(&visited[0][0], &visited[0][0] + MAX * MAX, 0);
        cnt = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (!visited[i][j] && a[i][j] > w) {
                    visited[i][j] = 1;
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        res = max(res, cnt);
    }
    
    cout << res;

    return 0;
}