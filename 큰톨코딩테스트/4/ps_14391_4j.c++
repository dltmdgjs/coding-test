// 종이 조각 - 골드 3
// 알고리즘 분류 : 브루트 포스, 비트 마스킹
// 2차원 배열을 비트마스킹으로 푸는 문제..
// one line -> 2 dim matrix


#include <bits/stdc++.h>
using namespace std;


int N, M, a[5][5];
int p[5][5];
bool visited[5][5];
int mx;

string go (int y, int x) {
    string s = "";
    s += a[y][x];
    visited[y][x] = true;
    if (p[y][x] == 1) {
        while (true) {
            y += 1;
            if (y >= N || p[y][x] == 0) break;
            s += a[y][x];
            visited[y][x] = true;
        }
    } else {
        while (true) {
            x += 1;
            if (x >= M || p[y][x] == 1) break;
            s += a[y][x];
            visited[y][x] = true;
        }
    }
    return s;
}


int main() {

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        for (int j=0; j<M; j++) {
            a[i][j] = s[j];
        }
    }

    int S = N*M; // 1차원으로 변환

    // 핵심 로직 (비트마스킹)
    for (int i=0; i<(1<<S); i++) {
        int temp = 0;
        fill(&p[0][0], &p[0][0]+5*5, 0);
        fill(&visited[0][0], &visited[0][0]+5*5, false);
        for (int j=0; j<S; j++) {
            int r = (j)/M; int c = (j)%M; // 2차원으로 복원
            // cout << r << " : " << c << '\n';
            if (i & (1<<j)) {
                p[r][c] = 1;
            } else {
                p[r][c] = 0;
            }
        }
        for (int l=0; l<N; l++) {
            for (int m=0; m<M; m++) {
                if(!visited[l][m]) {
                    string s = go(l,m);
                    temp += stoi(s);
                }
            }
        }
        mx = max(mx, temp);
    }

    cout << mx;
    return 0;
}


// 비트 마스킹 내부 로직 개선
// 1. 비트 마스킹으로 0, 1 선택 (경우의 수)
// 2. N*M 가로줄 순차 탐색 (0) -> 계산
// 3. M*N 세로줄 순차 탐색 (1) -> 계산
// 4. 갱신
// 5. 반복