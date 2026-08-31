// 컴백홈 - 실버 1
// 알고리즘 분류 : 그래프, 브루트포스, DFS, 백트래킹, 격자 그래프

#include <bits/stdc++.h>
using namespace std;

int R, C, K, res;
char a[10][10];
bool visited[10][10];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int cnt) {
    if (cnt == K && y == 0 && x == C-1) {
        res++;
        return;
    }
    for (int i=0; i<4; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if (ny < 0 || ny >=R || nx < 0 || nx >= C) continue;
        if (!visited[ny][nx] && a[ny][nx] == '.') {
            visited[ny][nx] = true;
            dfs(ny, nx, cnt+1);
            visited[ny][nx] = false;
        }
    }
    return;
}


int main() {

    cin >> R >> C >> K;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> a[i][j];
        }
    }

    visited[R-1][0] = true; // 첫 방문 노드 체크해줘야함.
    dfs(R-1, 0, 1);

    cout << res;

    return 0;
}