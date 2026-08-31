// 안전 영역 - 실버 1
// 그래프 이론, 그래프 탐색, 브루트포스, BFS, DFS, 격자 그래프


// bfs 풀이 방법
// #include <bits/stdc++.h>
// using namespace std;

// int N, maxh, result, a[104][104];
// int dy[4] = {-1, 0, 1, 0};
// int dx[4] = {0, 1, 0, -1};

// int main() {

//     cin >> N;
//     for (int i=0; i<N; i++) {
//         for (int j=0; j<N; j++) {
//             cin >> a[i][j];
//             maxh = max(maxh, a[i][j]);
//         }
//     }

//     for (int i=0; i<maxh; i++) {
//         bool visited[104][104] = {false};
//         queue<pair<int, int>> q;
//         int count = 0;
//         for (int l=0; l<N; l++) {
//             for (int m=0; m<N; m++) {
//                 if (!visited[l][m] && a[l][m]>i) {
//                     visited[l][m] = true;
//                     q.push({l, m});
//                     while (q.size()) {
//                         pair<int, int> u = q.front();
//                         q.pop();
//                         for (int n=0; n<4; n++) {
//                             int ny = u.first + dy[n];
//                             int nx = u.second + dx[n];
//                             if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
//                             if (!visited[ny][nx] && a[ny][nx]>i) {
//                                 visited[ny][nx] = true;
//                                 q.push({ny, nx});
//                             }
//                         }
//                     }
//                     count++;
//                 }
//             }
//         }
//         result = max(result, count);
//     }

//     cout << result;

//     return 0;
// }


// dfs 풀이 방법
#include <bits/stdc++.h>
using namespace std;

int N, maxh, result, a[101][101];
bool visited[101][101];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int h) {
    visited[y][x] = true;
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        if (!visited[ny][nx] && a[ny][nx]>h) {
            dfs(ny, nx, h);
        }
    }
}

int main() {

    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> a[i][j];
            maxh = max(maxh, a[i][j]);
        }
    }

    for (int i=0; i<maxh; i++) {
        fill(&visited[0][0], &visited[0][0]+101*101, false);
        int count = 0;
        for (int l=0; l<N; l++) {
            for (int m=0; m<N; m++) {
                if (!visited[l][m] && a[l][m] > i) {
                    dfs(l, m, i);
                    count++;
                }
            }
        }
        result = max(result, count);
    }

    cout << result;


    return 0;
}


