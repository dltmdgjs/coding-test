// 치즈 - BOJ 2636

#include <bits/stdc++.h>
using namespace std;

#define MAX 104

int N, M;
int cnt, area;

int a[MAX][MAX];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool check_empty() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == 1)
                return false;
        }
    }

    return true;
}


// 여기서 중요한 흐름만 기억하면 돼.
// 매 시간마다
// (0,0) 외부 공기 → BFS → 외부 공기와 맞닿은 치즈 발견 → 전부 동시에 제거 → 반복
// 그리고 네 기존 코드에서 temp를 사용해서 동시에 녹이는 방식 자체는 맞았어. 
// 문제는 check_4way()가 0의 종류를 구분할 수 없다는 것이 핵심이야.
int melt() {

    bool visited[MAX][MAX] = {};
    vector<pair<int, int>> cheese;
    queue<pair<int, int>> q;

    // (0, 0)은 항상 외부 공기
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {

        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {

            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                continue;

            if (visited[ny][nx])
                continue;

            visited[ny][nx] = true;

            // 외부 공기에서 치즈를 만남
            // -> 이번 시간에 녹는 치즈
            if (a[ny][nx] == 1) {
                cheese.push_back({ny, nx});
            }

            // 공기라면 계속 BFS
            else {
                q.push({ny, nx});
            }
        }
    }

    // 탐색이 끝난 뒤 동시에 녹임
    for (auto p : cheese) {
        a[p.first][p.second] = 0;
    }

    return cheese.size();
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    while (true) {

        if (check_empty())
            break;

        area = melt();
        cnt++;
    }

    cout << cnt << "\n";
    cout << area;

    return 0;
}