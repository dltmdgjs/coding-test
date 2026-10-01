// 미로 탈출 - BOJ 4179 (해결못함)

#include <bits/stdc++.h>
using namespace std;

#define MAX 1004

int R, C;

// 개선점 1 : 하나의 배열에는 하나의 역할만 부여하자.

// 실제 미로 정보
// # : 벽, . : 빈 공간, J : 지훈, F : 불
char a[MAX][MAX];

// 각 위치에 불이 도착하는 시간
// 0이면 불이 도달하지 못하는 곳
int fire[MAX][MAX];

// 각 위치에 지훈이가 도착하는 시간
// 0이면 아직 방문하지 않은 곳
int jihun[MAX][MAX];

int sy, sx;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

queue<pair<int, int>> fq;


/*
    <기존 코드에서 개선한 점>

    1. 기존에는 fire_wall 배열 하나에
       - 0      : 빈 공간
       - 1 이상 : 불의 도착 시간
       - 20000  : 벽
       처럼 여러 의미를 동시에 저장했음.

       현재는
       -> a[][]      : 실제 맵
          fire[][]   : 불의 도착 시간
          jihun[][]  : 지훈의 도착 시간

       으로 역할을 분리함.
       따라서 20000 같은 임의의 숫자로 벽을 표현할 필요가 없어짐.


    2. 벽 여부는 fire 배열의 값으로 판단하지 않고

       if (a[ny][nx] == '#')

       처럼 실제 맵을 보고 바로 판단함.

       -> 코드만 봐도 조건의 의미를 바로 알 수 있음.


    3. 먼저 불을 BFS하여 모든 위치의 '불 도착 시간'을 계산함.

       이후 지훈 BFS에서는

       지훈 도착 시간 < 불 도착 시간

       인 경우에만 이동함.


    4. fire[y][x] == 0의 의미를
       '불이 도달하지 못하는 위치'로 명확하게 정의함.

       따라서 불이 도달하지 않는 곳은
       지훈이가 자유롭게 이동할 수 있음.


    5. 기존 코드의 전체적인 BFS 아이디어는 맞았음.
       문제는 하나의 배열에 벽과 불 정보를 같이 저장하면서
       조건문이 복잡해졌다는 점임.
*/


// -------------------------------------------------
// 1. 불 BFS
// 모든 칸에 불이 몇 초 만에 도착하는지 계산
// -------------------------------------------------

void fire_go() {

    while (!fq.empty()) {

        int y = fq.front().first;
        int x = fq.front().second;
        fq.pop();

        for (int i = 0; i < 4; i++) {

            int ny = y + dy[i];
            int nx = x + dx[i];

            // 맵 바깥
            if (ny < 0 || nx < 0 || ny >= R || nx >= C)
                continue;

            // 벽은 불도 이동할 수 없음
            if (a[ny][nx] == '#')
                continue;

            // 이미 불이 방문한 곳
            if (fire[ny][nx] > 0)
                continue;

            fire[ny][nx] = fire[y][x] + 1;

            fq.push({ny, nx});
        }
    }
}


// -------------------------------------------------
// 2. 지훈 BFS
// 불보다 먼저 도착할 수 있는 위치로만 이동
// -------------------------------------------------

int jihun_go() {

    queue<pair<int, int>> q;

    q.push({sy, sx});
    jihun[sy][sx] = 1;

    while (!q.empty()) {

        int y = q.front().first;
        int x = q.front().second;
        q.pop();


        // 현재 위치가 가장자리라면
        // 다음 이동에서 미로 밖으로 탈출할 수 있음.
        //
        // 시작 위치를 1로 설정했기 때문에
        // jihun[y][x] 자체가 탈출에 걸린 시간이 됨.
        if (y == 0 || x == 0 || y == R - 1 || x == C - 1) {
            return jihun[y][x];
        }


        for (int i = 0; i < 4; i++) {

            int ny = y + dy[i];
            int nx = x + dx[i];

            // 맵 바깥
            if (ny < 0 || nx < 0 || ny >= R || nx >= C)
                continue;

            // 벽
            if (a[ny][nx] == '#')
                continue;

            // 이미 지훈이가 방문한 곳
            if (jihun[ny][nx] > 0)
                continue;


            // 지훈이가 다음 위치에 도착할 시간
            int nextTime = jihun[y][x] + 1;


            /*
                fire[ny][nx] == 0
                -> 불이 이곳에 도달하지 않음
                -> 지훈 이동 가능

                fire[ny][nx] > 0
                -> 불이 도달하는 곳

                이 경우 반드시

                지훈 도착 시간 < 불 도착 시간

                이어야 함.


                예)

                지훈 : 3초
                불   : 4초
                -> 이동 가능


                지훈 : 3초
                불   : 3초
                -> 동시에 도착하므로 이동 불가능


                지훈 : 3초
                불   : 2초
                -> 불이 먼저 도착하므로 이동 불가능
            */

            if (fire[ny][nx] > 0 &&
                fire[ny][nx] <= nextTime)
                continue;


            jihun[ny][nx] = nextTime;
            q.push({ny, nx});
        }
    }


    // BFS가 끝날 때까지 가장자리에 도착하지 못함.
    return 0;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;


    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {

            cin >> a[i][j];


            // 불은 여러 개 존재할 수 있으므로
            // 처음부터 모든 불의 위치를 queue에 넣음.
            //
            // -> Multi Source BFS
            if (a[i][j] == 'F') {

                fq.push({i, j});

                // 불이 존재하는 위치는 1부터 시작
                fire[i][j] = 1;
            }


            // 지훈의 시작 위치
            else if (a[i][j] == 'J') {

                sy = i;
                sx = j;
            }
        }
    }


    // 먼저 불의 도착 시간을 모두 계산
    fire_go();


    // 그 다음 지훈이 이동
    int ret = jihun_go();


    if (ret == 0)
        cout << "IMPOSSIBLE";
    else
        cout << ret;


    return 0;
}