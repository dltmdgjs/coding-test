#include <bits/stdc++.h>
using namespace std;

int R, C;
char a[20][20];
bool alpha[26]; // 방문했는지..
int mx;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int cnt) {
    mx = max(mx, cnt);
    for (int i=0; i<4; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        if (!alpha[a[ny][nx]-'A']) {
            alpha[a[ny][nx]-'A'] = true;
            dfs(ny, nx, cnt+1);
            alpha[a[ny][nx]-'A'] = false;
        }
    }
    return;
}

int main() {
    cin >> R >> C;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> a[i][j];
        }
    }
    alpha[a[0][0]-'A'] = true;
    dfs(0, 0, 1);

    cout << mx;
    return 0;
}