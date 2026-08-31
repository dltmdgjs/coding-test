// 치즈 - 골드 4
// 알고리즘 분류 : 구현, 그래프이론, 그래프 탐색, 시뮬레이션, BFS, 격자 그래프

#include <bits/stdc++.h>
using namespace std;

int N, M, a[101][101], visited[101][101];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main() {

    cin >> N >> M;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> a[i][j];
        }
    }

    queue<pair<int, int>> q;
    queue<pair<int, int>> last;
    q.push({0, 0}); // 판의 가장자리는 무조건 치즈가 아니므로 따로 치즈인지 공기인지 찾을 필요X
    visited[0][0] = 1;
    int cnt = 0;
    while(true) {

        cnt++;
        queue<pair<int, int>> temp;
        last = q;
        while (q.size()) {
            pair<int, int> u = q.front(); q.pop();
            for (int i=0; i<4; i++) {
                int ny = u.first + dy[i];
                int nx = u.second + dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) continue;
                visited[ny][nx] = visited[u.first][u.second] + 1;
                if (a[ny][nx] == 0) {
                    q.push({ny, nx});
                } else {
                    temp.push({ny, nx});
                    a[ny][nx] = 0;
                }
            }
        }
        q = temp;
        if (q.size() == 0) break;
    }

    cout << cnt - 1 << '\n';
    cout << last.size();
    
    return 0;
}

// 2개의 큐를 이용 -> q = 현재 layer에서 탐색할 것, temp = 다음 layer에서 탐색을 시작할 것
