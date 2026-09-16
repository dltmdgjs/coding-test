// 미로 탐색 - BOJ 2178

// 최소 칸의 수 -> BFS 너비 우선 탐색으로 N, M에 도달 시 바로 최솟값 구할 수 있음.
// 그래프 탐색 -> 4방향 이동 배열 정의 필요.


#include <bits/stdc++.h>
using namespace std;
#define MAX 101

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;
int a[MAX][MAX];
string s;


int main(){
    cin >> N >> M;

    for (int i=1; i<=N; i++) {
        cin >> s;
        for (int j=1; j<=M; j++) {
            a[i][j] = s[j-1] - '0'; // 입력 오류 주의 : 인덱스 및 자료형 ('1' == 48)
        }
    }

    // BFS : 최소거리 보장 (가중치가 양수이고 동일한 경우)
    queue<pair<int, int> > q;
    q.push({1, 1});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || ny < 1 || nx > N || ny > M || a[nx][ny] != 1) continue;
            q.push({nx, ny});
            a[nx][ny] = a[x][y] + 1; // 방문여부 + 거리 용도로 사용
        }
    }

    cout << a[N][M];

    return 0;
}