// 연구소 - 골드 4
// 알고리즘 분류 : 구현, 그래프 이론, 그래프 탐색, 브루트포스, bfs, 격자 그래프

#include <bits/stdc++.h>
using namespace std;

int N, M, a[10][10], t[10][10]; // (t = 임시 저장)
vector<pair<int, int>> v; // 0의 위치 저장;
int mx, n, k=3; // 최대 안전영역 수 mx, 0의 개수 n, 조합 시 뽑을 갯수 k
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x) {
    
    for (int i=0; i<4; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M || t[ny][nx] == 1) continue;
        if (t[ny][nx] == 0) {
            t[ny][nx] = 2;
            dfs(ny, nx);
        }
    }

}

// 조합으로 벽의 위치 결정
void combi(int start, vector<pair<int, int>>& b) {
    if (b.size() == k) {
        // 벽 세우기
        for (auto i : b) {
            t[i.first][i.second] = 1;
        }

        // 전파 진행 (t에서 진행)
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (t[i][j] == 2) {
                    dfs(i, j);
                }
            }
        }
        
        // 안전영역 크기 구하기 
        int tmp = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (t[i][j] == 0) {
                    tmp++;
                }
            }
        }
        // 전파 전으로 복구 (t = a로 복구)
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                t[i][j] = a[i][j];
            }
        }
        // 최댓값 갱신
        mx = (mx < tmp) ? tmp : mx;

        return;
    }

    for (int i=start; i<n; i++) {
        b.push_back(v[i]);
        combi(i+1, b);
        b.pop_back();
    }
    return;
}

int main() {

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> a[i][j];
            t[i][j] = a[i][j];
            if (a[i][j] == 0) {
                v.push_back({i, j});
            }
        }
    }

    n = v.size();

    vector<pair<int, int>> b;
    combi(0, b);

    cout << mx;

    return 0;
}


// 조합 공식 - n개중 k개 뽑을 때
            // void combi(int start, vector<int>& b) {
            //     if (b.size() == k) {
            //         // 로직..(출력 등 선택된 조합을 이용)
            //         for (auto i : b) {
            //             cout << i << '\n';
            //         }
            //         return;
            //     }
            //     for (int i=start; i<n; i++) {
            //         b.push_back(i);
            //         combi(i+1, b);
            //         b.pop_back();
            //     }
            //     return;
            // }

// 조합 공식 - 3개 이하를 뽑는 경우에는 위와 같이 함수 대신 삼(이)중 for문으로 해결가능