// 미로 탐색 - 실버 1
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색, 격자 그래프


#include <bits/stdc++.h>
using namespace std;

int N,M;
int a[104][104];
int visited[104][104];
queue<pair<int, int>> q;
int dy[]={-1, 0, 1, 0};
int dx[]={0, 1, 0, -1};


int main() {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        for (int j=0; j<M; j++) {
            a[i][j] = s[j] - '0';
        }
    }

    visited[0][0] = 1;
    q.push({0, 0});

    while(q.size()) {
        pair<int, int> u = q.front();
        q.pop();
        for (int i=0; i<4; i++) {
            int ny = u.first + dy[i];
            int nx = u.second + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (!visited[ny][nx] && a[ny][nx] == 1) {
                visited[ny][nx] = visited[u.first][u.second] + 1;
                q.push({ny, nx});
            }
        }
    }

    cout << visited[N-1][M-1];

    return 0;
}

// 하나씩 입력 받는 다른 방법
//      scanf(%1d, &a[i][j]);