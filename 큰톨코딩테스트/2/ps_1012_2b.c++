// 유기농 배추 - 실버 2
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, BFS, DFS, 격자 그래프, 플러드 필



// BFS 풀이
// #include <bits/stdc++.h>
// using namespace std;

// int T;
// int dy[4] = {-1, 0, 1, 0};
// int dx[4] = {0, 1, 0, -1};

// int main() {
//     cin >> T;

//     for (int i=0; i<T; i++) {
//         int N, M, K;
//         int a[100][100] = {0};
//         bool visited[100][100] = {false};
//         queue<pair<int, int>> q;
//         int count = 0;
//         cin >> M >> N >> K;
//         for (int j=0; j<K; j++) {
//             int x, y;
//             cin >> x >> y;
//             a[y][x] = 1;
//         }
//         for (int l=0; l<N; l++) {
//             for (int m=0; m<M; m++) {
//                 if (!visited[l][m] && a[l][m] == 1) {
//                     // bfs(l, m); 수행 로직 작성(로컬로)
//                     visited[l][m] = true;
//                     q.push({l, m});

//                     while (q.size()) {
//                         pair<int, int> u = q.front();
//                         q.pop();
//                         for (int n=0; n<4; n++) {
//                             int ny = u.first + dy[n];
//                             int nx = u.second + dx[n];
//                             if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
//                             if (!visited[ny][nx] && a[ny][nx] == 1) {
//                                 visited[ny][nx] = true;
//                                 q.push({ny, nx});
//                             }
//                         }
//                     }
//                     count++;
//                 }
//             }
//         }
//         cout << count << '\n';
//     }

//     return 0;
// }



// DFS 풀이
#include <bits/stdc++.h>
using namespace std;


int T, N, M, K, a[101][101], cnt;
bool visited[101][101];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};


void dfs(int y, int x) {
    visited[y][x] = true;
    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if (!visited[ny][nx] && a[ny][nx] == 1) {
            dfs(ny, nx);
        }
    }
}

int main() {
    cin >> T;
    for (int i=0; i<T; i++) {
        // 각 케이스 입력
        cin >> M >> N >> K;
        fill(&a[0][0], &a[0][0]+100*100, 0);
        fill(&visited[0][0], &visited[0][0]+100*100, false);
        cnt = 0;
        for (int i=0; i<K; i++) {
            int x, y;
            cin >> x >> y;
            a[y][x] = 1;
        }

        // dfs실행
        for (int l=0; l<N; l++) {
            for (int m=0; m<M; m++) {
                if (!visited[l][m] && a[l][m] == 1) {
                    dfs(l, m);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}