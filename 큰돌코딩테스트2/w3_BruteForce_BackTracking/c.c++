// 인구 이동 - BOJ 16234

#include <bits/stdc++.h>
using namespace std;
#define MAX 104

// 1. 인구 차이를 계산해 국가 그룹을 생성해야함. -> 국가 그룹 벡터가 필요함.
// 2. 2차원

int N, L, R, days = 0;
int A[MAX][MAX], visited[MAX][MAX], temp[MAX][MAX];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<pair<int, int> > v;
bool isModified = false;

void bfs(int ys, int xs) {
    queue<pair<int, int> > q;
    v.push_back({ys, xs});
    q.push({ys, xs});
    visited[ys][xs] = 1;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue; // 범위 체크
            if (visited[ny][nx] == 1) continue; // 방문 여부 체크
            int diff = abs(temp[y][x] - temp[ny][nx]);
            if (diff >= L && diff <= R) {
                v.push_back({ny, nx});
                q.push({ny, nx});
                visited[ny][nx] = 1;
            } // 차이 체크 -> 그룹 포함 결정
        }
    }
}

void move_human() {
    int sum = 0;
    int numNation = v.size();

    for (pair<int, int> p : v) {
        int y = p.first; int x = p.second;
        sum += temp[y][x];
    }

    int value = sum / numNation;

    for (pair<int, int> p : v) {
        int y = p.first; int x = p.second;
        temp[y][x] = value;
    }
}

int main() {

    cin >> N >> L >> R;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> A[i][j];
        }
    }

    while (true) {
        isModified = false;
        fill(&visited[0][0], &visited[0][0] + MAX*MAX, 0);

        memcpy(temp, A, sizeof(A));

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (!visited[i][j]) {
                    v.clear();
                    bfs(i, j); // 그룹에 포함 시키기.
                    if (v.size()>1) {
                        isModified = true;
                        move_human();
                    }
                }
            }
        }

        if (!isModified) {
            break;
        }

        memcpy(A, temp, sizeof(A));

        days++;
    }

    cout << days;

    return 0;
}