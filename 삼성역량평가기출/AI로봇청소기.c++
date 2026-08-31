#include <bits/stdc++.h>
using namespace std;
#define MAX 35

int N, K, L;
// 우선순위 방향: 우(0), 하(1), 좌(2), 상(3) -> 청소 방향 선택 시 중요
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int a[MAX][MAX]; // 먼지 양 및 물건(-1)
vector<pair<int, int>> cleaner;
int has_cleaner[MAX][MAX]; // 청소기 위치 체크용

void move_cleaner() {
    for (int i = 0; i < cleaner.size(); i++) {
        int y = cleaner[i].first;
        int x = cleaner[i].second;
        
        // 현재 청소기 위치 잠시 비움 (이동 후 갱신)
        has_cleaner[y][x] = 0;

        int dist[MAX][MAX];
        memset(dist, -1, sizeof(dist));
        queue<pair<int, int>> q;
        
        dist[y][x] = 0;
        q.push({y, x});

        int min_d = 987654321;
        pair<int, int> target = {987654321, 987654321};

        while (!q.empty()) {
            pair<int, int> u = q.front(); q.pop();

            if (dist[u.first][u.second] > min_d) break;

            // 먼지가 있는 칸이면 타겟 후보
            if (a[u.first][u.second] > 0) {
                if (dist[u.first][u.second] < min_d) {
                    min_d = dist[u.first][u.second];
                    target = u;
                } 
                else if (dist[u.first][u.second] == min_d) {
                    // 행 작고, 열 작은 우선순위
                    if (u.first < target.first || (u.first == target.first && u.second < target.second)) {
                        target = u;
                    }
                }
            }

            for (int d = 0; d < 4; d++) {
                int ny = u.first + dy[d];
                int nx = u.second + dx[d];
                if (ny < 1 || ny > N || nx < 1 || nx > N) continue;
                // 물건(-1)이 아니어야 하고, 다른 청소기가 없어야 함
                if (dist[ny][nx] == -1 && a[ny][nx] != -1 && has_cleaner[ny][nx] == 0) {
                    dist[ny][nx] = dist[u.first][u.second] + 1;
                    q.push({ny, nx});
                }
            }
        }

        if (target.first != 987654321) {
            cleaner[i] = target;
        }
        // 이동 완료 후 위치 확정
        has_cleaner[cleaner[i].first][cleaner[i].second] = 1;
    }
}

void clean() {
    for (auto k : cleaner) {
        int y = k.first;
        int x = k.second;

        int max_dust = -1;
        int best_dir = -1;

        // 4방향(우, 하, 좌, 상 순서) 중 최적 방향 찾기
        for (int d = 0; d < 4; d++) {
            int current_sum = 0;
            // 청소할 4개 격자: 제자리(0), 왼쪽(1), 앞쪽(2), 오른쪽(3)
            int targets[4] = {-1, (d + 3) % 4, d, (d + 1) % 4};

            for (int i = 0; i < 4; i++) {
                int ny, nx;
                if (i == 0) { ny = y; nx = x; }
                else { ny = y + dy[targets[i]]; nx = x + dx[targets[i]]; }

                if (ny >= 1 && ny <= N && nx >= 1 && nx <= N && a[ny][nx] > 0) {
                    current_sum += min(a[ny][nx], 20); // 최대 20까지만 청소 가능
                }
            }

            if (current_sum > max_dust) {
                max_dust = current_sum;
                best_dir = d;
            }
        }

        // 선택된 방향으로 실제 청소 진행
        int final_targets[4] = {-1, (best_dir + 3) % 4, best_dir, (best_dir + 1) % 4};
        for (int i = 0; i < 4; i++) {
            int ny, nx;
            if (i == 0) { ny = y; nx = x; }
            else { ny = y + dy[final_targets[i]]; nx = x + dx[final_targets[i]]; }

            if (ny >= 1 && ny <= N && nx >= 1 && nx <= N && a[ny][nx] > 0) {
                a[ny][nx] -= min(a[ny][nx], 20);
                if (a[ny][nx] < 0) a[ny][nx] = 0;
            }
        }
    }
}

void accumulate_dust() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (a[i][j] > 0) a[i][j] += 5;
        }
    }
}

void spread_dust() {
    int temp[MAX][MAX];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) temp[i][j] = a[i][j];
    }

    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            // 깨끗한 격자이면서 물건이나 로봇이 없는 곳에 확산
            if (a[y][x] == 0 && a[y][x] != -1) {
                int r = 0;
                for (int i = 0; i < 4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (ny < 1 || ny > N || nx < 1 || nx > N) continue;
                    if (a[ny][nx] > 0) r += a[ny][nx];
                }
                temp[y][x] = r / 10;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) a[i][j] = temp[i][j];
    }
}

void print_result() {
    long long total = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (a[i][j] > 0) total += a[i][j];
        }
    }
    cout << total << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); // 성능 최적화
    if (!(cin >> N >> K >> L)) return 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) cin >> a[i][j];
    }
    for (int i = 0; i < K; i++) {
        int y, x;
        cin >> y >> x;
        cleaner.push_back({y, x});
        has_cleaner[y][x] = 1;
    }

    for (int i = 0; i < L; i++) {
        move_cleaner();
        clean();
        accumulate_dust();
        spread_dust();
        print_result();
    }
    return 0;
}