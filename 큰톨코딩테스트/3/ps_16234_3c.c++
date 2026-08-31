// 인구이동 - 골드 4
// 알고리즘 분류 : 구현, 그래프이론, 그래프탐색, 시뮬레이션, bfs

#include <bits/stdc++.h>
using namespace std;

int N, L, R, arr[51][51], cnt, sum, k;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
bool visited[51][51];
bool be; // 인구이동이 일어났는지 확인하는 플래그


void go(int y, int x, vector<pair<int, int>>& v) {
    // 해당 칸의 상하좌우 탐색
    for (int i=0; i<4; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
            continue;
        }
        // 두 칸의 인구 수 차이
        int d = abs(arr[ny][nx] - arr[y][x]);
        // 조건에 맞으면 방문처리(연합) 후 재귀호출
        if (!visited[ny][nx] && R >= d && L <= d) {
            be = true;
            visited[ny][nx] = true;
            sum += arr[ny][nx]; k++;
            v.push_back({ny, nx});
            go(ny, nx, v);
        }
    }
    return;
}

int main() {

    cin >> N >> L >> R;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }

    // 각 날짜에 대해 검사
    while (true) {
        // 초기값 설정
        be = false;
        fill(&visited[0][0], &visited[0][0] + 50*50, false);

        // 각 칸에 대해 검사
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (!visited[i][j]) {
                    // 초기값 설정
                    visited[i][j] = true;
                    sum = arr[i][j]; k = 1; // 합과 개수
                    vector<pair <int, int>> v; // 연합된 칸을 저장할 공간
                    v.push_back({i, j});
                    // 탐색시작
                    go(i, j, v);
                    // 칸의 값 갱신 (1개(연합X)인 경우 갱신 X)
                    if (k!=1) {
                        for (auto ii : v) {
                            arr[ii.first][ii.second] = sum/k;
                        }
                        // cout << sum << ":" << k << '\n';
                    }
                }
            }
        }

        // 연합되지 못한 날인 경우 종료.
        if (!be) break;

        // 날짜 증가
        cnt++;

        // 디버깅
        // cout << cnt << "일차 결과" << '\n';
        // for (int i=0; i<N; i++) {
        //     for (int j=0; j<N; j++) {
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
    }

    cout << cnt;
    return 0;
}