// 불! - 골드 3
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, BFS, 격자 그래프

#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321; // 불과 지훈 비교시 반례 방지를 위해..
char arr[1001][1001];
int R, C;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int fire_visited[1001][1001];
int person_visited[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    queue<pair<int, int>> q;
    fill(&fire_visited[0][0], &fire_visited[0][0] + 1001 * 1001, INF);
    
    int sy, sx;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'F') {
                fire_visited[i][j] = 1;
                q.push({i, j});
            } else if (arr[i][j] == 'J') {
                sy = i; sx = j;
            }
        }
    }

    // 불의 BFS - 각 좌표에 불이 도달하는 최단 시간을 기록함.
    while (!q.empty()) {
        pair<int, int> u = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = u.first + dy[i];
            int nx = u.second + dx[i];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
            if (fire_visited[ny][nx] != INF || arr[ny][nx] == '#') continue;
            fire_visited[ny][nx] = fire_visited[u.first][u.second] + 1;
            q.push({ny, nx});
        }
    }

    // 지훈의 BFS - 각 좌표에 지훈이가 도달하는 시간과 불이 도달하는 시간을 비교함.
    person_visited[sy][sx] = 1;
    q.push({sy, sx});
    int ret = 0;
    while (!q.empty()) {
        pair<int, int> u = q.front(); q.pop();
        //현재 경계에 있는 경우 중단.
        if (u.first == 0 || u.first == R - 1 || u.second == 0 || u.second == C - 1) {
            ret = person_visited[u.first][u.second];
            break;
        }
        for (int i = 0; i < 4; i++) {
            int ny = u.first + dy[i];
            int nx = u.second + dx[i];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
            if (person_visited[ny][nx] || arr[ny][nx] == '#') continue;
            if (fire_visited[ny][nx] <= person_visited[u.first][u.second] + 1) continue;
            person_visited[ny][nx] = person_visited[u.first][u.second] + 1;
            q.push({ny, nx});
        }
    }

    if (ret != 0) cout << ret << "\n";
    else cout << "IMPOSSIBLE\n";

    return 0;
}