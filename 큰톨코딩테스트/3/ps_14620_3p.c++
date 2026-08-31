// 꽃길 - 실버 2
// 알고리즘 분류 : 브루트포스, 백트래킹

#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int tmp;
int N, res = 987654321;
int a[10][10];
bool visited[10][10];

bool check(vector<int> b) {
    fill(&visited[0][0], &visited[0][0]+10*10, false);
    tmp = 0;
    for (auto v : b) {
        int y = v/N;
        int x = v%N;
        if (visited[y][x]) return false;
        visited[y][x] = true;
        tmp += a[y][x];
        for (int i=0; i<4; i++) {
            int ny = y+dy[i];
            int nx = x+dx[i];
            if (ny < 0 || ny >=N || nx < 0 || nx >= N || visited[ny][nx]) return false;
            visited[ny][nx] = true;
            tmp += a[ny][nx];
        }
    }
    return true;
}

void combi(int start, vector<int> b) {
    if (b.size() == 3) {
        // 로직 수행
        if (check(b)) {
            res = min(tmp, res);
        }
        return;
    }
    for (int i=start; i<N*N; i++) {
        b.push_back(i);
        combi(i+1, b);
        b.pop_back();
    }
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> b;
    combi(0, b);

    cout << res;
    return 0;
}


    // 조합 - N*N 노드 중에서 3개의 노드 선택 
    // -> 각자 4방향 탐색 
    //    (범위를 벗어나거나 서로 겹치는 경우(visited활용), 탐색 종료 후 다른 조합 고르기
    // 최솟값 갱신.