// 보물섬 BOJ 2589

#include <bits/stdc++.h>
using namespace std;
#define MAX 54

// 1. 2차원 배열이 필요하다. (상태, 방문)
// 2. 육지 그룹 저장 공간이 필요하다.
// 2. 하나씩 탐색한다. 새로 육지를 만나게 되면, 육지 그룹을 생성한다.
// 4. 거기서 DFS든 BFS든 상하좌우 탐색하며 같은 그룹의 육지 위치를 저장한다.
// 5. 그룹이 다 형성 되었으면 그 그룹내에서 2개를 선택하는 조합을 생성하여, 하나는 시작점, 하나는 종료점으로 설정하고,
// BFS로 탐색(최소거리 보장)하여 거리를 계산한다. 그렇게 계산된 거리중 가장 긴 거리를 선택한다.
// 6. 한 그룹이 끝나면 그 그룹은 모두 방문처리를 한다. 그리고 다시 하나씩 탐색하며 새로운 그룹을 찾고 이와 같은 과정을 반복한다.

// 개선점 : sol에 정리함.

int N, M, a[MAX][MAX], visited[MAX][MAX], dist = -1234567;
vector<pair<int, int> > v; // 육지 그룹 저장 공간.
vector<pair<int, int> > couple; // 두 육지 쌍 저장 공간.
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int sy,sx,ey,ex; // 시작점, 끝점

// 두 쌍 사이의 거리 계산 & 갱신
void calculate_distance() {
    // 시작점, 끝점.
    tie(sy, sx) = couple[0]; tie(ey, ex) = couple[1];

    int count = 0;
    int check[MAX][MAX]; // 방문 체크 + 거리 저장용.
    fill(&check[0][0], &check[0][0] + MAX*MAX, 0);

    queue<pair<int, int> > q;
    q.push({sy, sx});
    check[sy][sx] = 1;
    while (!q.empty()) {
        int y = q.front().first; int x = q.front().second; q.pop();

        // 끝점 도달 시, 거리 반환
        if (y == ey && x == ex) {
            dist = max(dist, check[ey][ex]);
            break;
        }

        for (int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (a[ny][nx] == 0 || check[ny][nx] > 0) continue;
            q.push({ny, nx}); 
            check[ny][nx] = check[y][x] + 1; // 방문처리 + 거리저장
        }
    }
    
}

// 두 개의 육지 조합 생성
void combi(int start) {
    if (couple.size() == 2) {
        calculate_distance();
        return;
    }

    for (int i=start; i<v.size(); i++) {
        couple.push_back(v[i]);
        combi(i+1);
        couple.pop_back();
    }

    return;
}

// 육지 그룹 생성
void search_group(int y, int x) {
    visited[y][x] = 1;

    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if (a[ny][nx] == 0 || visited[ny][nx] == 1) continue; // 탐색시 방문체크는 해주셔야 무한굴레(seg fault)에 빠지지 않습니다.
        v.push_back({ny, nx});
        search_group(ny, nx);
    }

    return;
}

int main() {

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        string s; cin >> s;
        for (int j=0; j<M; j++) {
            if (s[j] == 'L') a[i][j] = 1; // 땅은 1로 표시.
        }
    }

    // 하나씩 탐색
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (!(a[i][j] == 0) && !(visited[i][j] == 1)) {
                v.clear();
                v.push_back({i, j});
                search_group(i, j);
                
                couple.clear();
                combi(0);
            }
        }
    }

    cout << dist - 1; // 거리 계산 시, 1부터 시작했으니 1을 빼줌.

    return 0;
}