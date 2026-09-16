// 영역구하기 - BOJ 2583
// 분리된 영역을 구하기.
// 그림 상, 상하가 반전되어 있어 헷갈림 주의.
// N, M 의 정의 주의. (M =행, N=열)

// a에서 1=빈 부분, 0=색칠된 부분으로 정의하였다.
// 문제에서의 (x, y)를 (열, 행)으로 사용했지만,
// 나는 (x, y)를 (행, 열)로 정의했다.

#include <bits/stdc++.h>
using namespace std;
#define MAX 101

int M, N, K, x_1, y_1, x_2, y_2, cnt = 0, depth;
int a[MAX][MAX], visited[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> v; // 넓이

void dfs(int x, int y) {
    visited[x][y] = 1;

    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
        if (visited[nx][ny] || a[nx][ny] == 0) continue;
        depth++;
        dfs(nx, ny);
    }
}

int main() {

    cin >> M >> N >> K;

    fill(&a[0][0], &a[0][0] + MAX*MAX, 1);
    fill(&visited[0][0], &visited[0][0] + MAX*MAX, 0);

    while(K--) {
        cin >> y_1 >> x_1 >> y_2 >> x_2; // 입력 주의
        for (int i=x_1; i<x_2; i++) {
            for (int j=y_1; j<y_2; j++) {
                a[i][j] = 0;
            }
        }
    }

    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            if (a[i][j] == 1 && !visited[i][j]) {
                cnt++;
                depth = 1;
                dfs(i, j);
                v.push_back(depth);
            }
        }
    }

    sort(v.begin(), v.end());

    cout << cnt << "\n";
    for (int i : v) {
        cout << i << " ";
    }
    return 0;
}