// 연구소 - BOJ 14502

// 벽은 반드시 3개를 세워야 함. 
// 0 : 빈칸, 1 : 벽, 2 : 바이러스(4방향으로 퍼짐.)
// 브루트 포스로 전수 검사?

#include <bits/stdc++.h>
using namespace std;


int N, M, a[10][10], temp[10][10];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int ret = -98765432;
vector<pair<int, int> > virus;

// 바이러스 퍼짐.
void spread() {
    copy(&a[0][0], &a[0][0] + 10*10, &temp[0][0]);
    for (pair<int, int> p : virus) {
        queue<pair<int, int> > q;
        q.push({p.first, p.second});
        while (q.size()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for (int i=0; i<4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if (temp[ny][nx] == 1 || temp[ny][nx] == 2) continue;
                q.push({ny, nx});
                temp[ny][nx] = 2;
            }
        }
    }
}

// 안전영역 구하기
int safe_area() {
    int cnt = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (temp[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

// 벽 3개 세우기 
// 개선점 1 : 2차원 배열에서 조합을 만들 때는 1차원 인덱스로 펴면 편하다.
// 개선점 2 : 조합에서는 현재 선택한 위치 i의 다음 위치인 i+1부터 탐색해야 중복을 피할 수 있다. (i++ 금지)
void go(int start, int cnt) {
    if (cnt == 3) {
        spread();
        ret = max(ret, safe_area());
        return;
    }

    for (int i=start; i<N*M; i++) {
        int y = i/M;
        int x = i%M;
        if (a[y][x] == 0) {
            a[y][x] = 1;
            go(i+1, cnt+1);
            a[y][x] = 0;
        }
    }
}

int main() {

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) {
                virus.push_back({i, j});
            }
        }
    }

    go(0, 0);

    cout << ret;
    
    return 0;
}