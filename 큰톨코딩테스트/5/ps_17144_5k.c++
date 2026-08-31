#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int R, C, T, res;
int a[100][100], temp[100][100]; // temp : 업데이트할 변량을 저장(확산량 or 감소량)
int air_y, air_x = 0;


// 공기청정기 찾기
int find_airpuri() {
    for (int i=0; i<R; i++) {
        if (a[i][0] == -1) {
            return i;
        }
    }
}

// 확산
void spread(int y, int x) {
    int cnt = 0;
    for (int i=0; i<4; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        if (a[ny][nx] == -1) continue;
        temp[ny][nx] += a[y][x]/5;
        cnt++;
    }

    // 주의 : 누적해서 -를 해줘야함. 그냥 -를 저장하는 것이 아님(왜냐하면 이 값이 이전에 업데이트 됬었을 수 있기 때문)
    temp[y][x] -= (a[y][x]/5) * cnt; // 사실 확산 근원지는 temp 쓰지 않고, a로 바로 업데이트 해도 됨. 

}

// 회전(순환) : 일단 외곽 부분만 순환한다고 치자.
void circulate() {
    // 주의 : 경계값
    // 반시계방향
    // 상 - 하
    for (int i=air_y-1; i>0; i--) {
        a[i][0] = a[i-1][0];
    }
    // 우 - 좌
    for (int i=0; i<C-1; i++) {
        a[0][i] = a[0][i+1];
    }
    // 하 - 상
    for (int i=0; i<air_y; i++) {
        a[i][C-1] = a[i+1][C-1];
    }
    // 좌 - 우
    for (int i=C-1; i>1; i--) {
        a[air_y][i] = a[air_y][i-1];
    }
    a[air_y][1] = 0;


    // 시계방향
    // 하 - 상
    for (int i=air_y+2; i<R-1; i++) {
        a[i][0] = a[i+1][0];
    }
    // 우 - 좌
    for (int i=0; i<C-1; i++) {
        a[R-1][i] = a[R-1][i+1];
    }
    // 상 - 하
    for (int i=R-1; i>air_y+1; i--) {
        a[i][C-1] = a[i-1][C-1];
    }
    // 좌 - 우
    for (int i=C-1; i>1; i--) {
        a[air_y+1][i] = a[air_y+1][i-1];
    }
    a[air_y+1][1] = 0;
}

int main() {

    cin >> R >> C >> T;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> a[i][j];
        }
    }

    air_y = find_airpuri();

    while (T--) {
        fill(&temp[0][0], &temp[0][0]+100*100, 0);
        // memcpy(&temp, &a, sizeof(a));
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {

                if (a[i][j] <= 0) {continue;}
                else {
                    spread(i, j);
                }

            }
        }
        // memcpy(&a, &temp, sizeof(temp));
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                a[i][j] += temp[i][j];
            }
        }
        
        circulate();
    }

    // 결과 출력
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            res += a[i][j];
        }
    }
    cout << res+2; // 공기청정기로 감소된 량 2를 더해줌

    return 0;
}