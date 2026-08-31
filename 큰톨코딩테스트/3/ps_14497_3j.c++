// 주난의 난 - 골드 4
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, BFS, 최단경로, 다익스트라, 0-1 BFS

#include <bits/stdc++.h>
using namespace std;


int dy[4] = {-1, 0 ,1, 0};
int dx[4] = {0, 1, 0, -1};

int N, M, x_1, y_1, x_2, y_2;
char a[300][300];
int visited[300][300];

int main() {

    cin >> N >> M;
    cin >> y_1 >> x_1 >> y_2 >> x_2;
    y_1--, x_1--, y_2--, x_2--;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> a[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push({y_1, x_1});
    visited[y_1][x_1] = 1;
    int cnt = 0;
    while(a[y_2][x_2] != '0') {
        cnt++;
        queue<pair<int, int>> t;
        while(q.size()) {
            pair<int, int> u = q.front();
            q.pop();
            for (int i=0; i<4; i++) {
                int ny = u.first + dy[i];
                int nx = u.second + dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) continue;
                if (a[ny][nx] != '0') {
                    a[ny][nx] = '0';
                    t.push({ny, nx});
                } else if (a[ny][nx] == '0') {
                    q.push({ny, nx});
                }
                visited[ny][nx] = 1;
            }
        }
        q = t;
    }

    cout << cnt;

    return 0;
}

// 상하좌우 -> dy, dx 배열 정의
// 파동이 퍼져나감 (종료조건 - 1 or #을 만날때 종료)
// BFS로 layer 별로 풀이를 이어나가야함. 그러나 일반적인 BFS와 다르게
// 위 조건으로 인해 layer가 한칸씩 지정 되는게 아닌 임의의 모양으로 지정됨.

// 풀이 포인트 -> 0을 만나면 계속해서 탐색하기 위해 q.push
//          -> 1 or #을 만나면 탐색을 종료해야함. (0으로 변경도 해야함)
//             하지만 다음 탐색 지점으로 설정하기 위해 임시 공간에 저장 t.push
// 즉 2개의 큐를 이용한 BFS 알고리즘임.

