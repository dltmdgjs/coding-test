// 유기농 배추 - BOJ 1012
// 인접한 배추의 그룹 수를 찾는 것과 같음


#include <bits/stdc++.h>
using namespace std;
#define MAX 51

int T, N, M, K, a[MAX][MAX], cnt, tx, ty;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y) {
    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx > N || ny > M || a[nx][ny] == 0) continue;
        a[nx][ny] = 0;
        dfs(nx, ny);
    }
} 

int main() {
    cin >> T;
    while (T--) {
        // 케이스 여러개 주어지면 로직 시작 전 값 초기화 중요!
        fill(&a[0][0], &a[0][0] + MAX*MAX, 0); // 초기화 방식도 잘 숙지하자, fill(first, last, value)
        cnt = 0;
        cin >> N >> M >> K;

        while (K--) {
            cin >> tx >> ty;
            a[tx][ty] = 1;
        }

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (a[i][j] == 0) continue;
                else {
                    a[i][j] = 0;
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";

    }

    return 0;
}