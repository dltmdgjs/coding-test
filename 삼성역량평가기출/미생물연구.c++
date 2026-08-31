#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define MAX 16

int N, Q;
set<int> mi_id;
int a[MAX][MAX], temp[MAX][MAX];
int mi[MAX][MAX];
bool visited[MAX][MAX];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};


// 탐색
void bfs(int y, int x, int k) {
    queue<pair<int, int> > q;
    q.push({y, x});
    visited[y][x] = true;
    while (q.size()) {
        pair<int, int> u = q.front(); q.pop();
        for (int i=0; i<4; i++) {
            int ny = u.first + dy[i];
            int nx = u.second + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx]) continue;
            if (a[ny][nx] == k) {
                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }
    }
}

// 연결성 검사
void check_connectivity(int k) {
    int count = 0;
    fill(&visited[0][0], &visited[0][0]+MAX*MAX, false);
    for (int r=0; r<N; r++) {
        for (int c=0; c<N; c++) {
            if (a[r][c] == k && !visited[r][c]) {
                bfs(r, c, k);
                count++;
            }
            if (count > 1) {
                mi_id.erase(k);
                for (int i=0; i<N; i++) {
                    for (int j=0; j<N; j++) {
                        if (a[i][j] == k) {a[i][j] = 0;}
                    }
                }
                return;
            }
        }
    }
}

// 미생물 크기 얻기
int get_size(int k) {
    int count = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (a[i][j] == k) {count++;}
        }
    }
    return count;
}

// 미생물 정렬
bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) {return true;}
    if (a.first == b.first) {return a.second < b.second;}
    return false;
}


// 현 위치에 이동가능한지 체크
bool check_settable(int y, int x) {
    // temp와 mi비교
    for (int i1 = 0; i1 < N; i1++) {
        for (int j1 = 0; j1 < N; j1++) {
            if (mi[i1][j1]) { // 미생물이 있는 칸인데
                int i = y + i1;
                int j = x + j1;
                // 새 용기를 벗어나거나 다른 미생물이 있다면 실패
                if (i >= N || j >= N || temp[i][j]) return false;
            }
        }
    }
    return true;
}

// 미생물 다른 접시에 이동
void set_mi(int y, int x) {
    for (int i1=0; i1<N; i1++) {
        for (int j1=0; j1<N; j1++) {
            if (mi[i1][j1] != 0) {
                temp[y+i1][x+j1] = mi[i1][j1];
            }
        }
    }
}


// 미생물 이동
void go(int k) {
    fill(&mi[0][0], &mi[0][0]+MAX*MAX, 0);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (a[i][j] == k) {
                mi[i][j] = k;
            }
        }
    }
    // 좌 하단으로 옮기기
    bool flag = false;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (mi[i][j] == k) {flag = true; break;}
        }
        if (flag && i>0) {
            for (int r=i; r<N; r++) {
                for (int c=0; c<N; c++) {
                    mi[r-i][c] = mi[r][c];
                    mi[r][c] = 0;
                }
            }
            break;
        } else if (flag) {
            break;
        }
    }
    bool flag2 = false;
    for (int j=0; j<N; j++) {
        for (int i=0; i<N; i++) {
            if (mi[i][j] == k) {flag2 = true; break;}
        }
        if (flag2 && j>0) {
            for (int c=j; c<N; c++) {
                for (int r=0; r<N; r++) {
                    mi[r][c-j] = mi[r][c];
                    mi[r][c] = 0;
                }
            }
            break;
        } else if (flag2) {
            break;
        }
    }

    // 좌 하단부터 검사
    bool flag3 = false;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            // 이동할 수 있으면 이동.
            if (check_settable(i, j)) {
                set_mi(i, j); flag3 = true; break;
            }
        }
        if (flag3) {break;}
    }
    if (!flag3) {
        mi_id.erase(k); // 어디에도 이동할 수 없으면 미생물 삭제
    }
}

int main() {
    cin >> N >> Q;
    for (int i=1; i<=Q; i++) {
        // 1. 미생물 배치
        // 1-1. 영역 색칠
        mi_id.insert(i);
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        for (int r=r1; r<r2; r++) {
            for (int c=c1; c<c2; c++) {
                a[r][c] = i;
            }
        }
        // 1-2. 연결되지 못한 요소 검사 (제거)
        vector<int> copy_id(mi_id.begin(), mi_id.end());
        for (int k : copy_id) {
            check_connectivity(k);
        }

        // 2. 배양 용기 이동
        fill(&temp[0][0], &temp[0][0]+MAX*MAX, 0); // 임시 저장소
        // 2-1. 크기 순 정렬
        vector<pair<int, int> > v;
        for (int k : mi_id) {
             v.push_back({get_size(k), k});
        }
        sort(v.begin(), v.end(), compare);
        // 2-2. 이동
        for (auto c : v) {
            int k = c.second;
            go(k);
        }
        // 2-3. 임시값 확정
        for (int r=0; r<N; r++) {
            for (int c=0; c<N; c++) {
                a[r][c] = temp[r][c];
            }
        }
        
        // 3. 결과 출력
        // 3-1. 인접 쌍들 검사 및 저장 (A, B)
        set<pair <int, int> > pairs;
        for (int r=0; r<N; r++) {
            for (int c=0; c<N; c++) {
                int prev = a[r][c];
                if (prev == 0) continue;
                for (int l=0; l<4; l++) {
                    int ny = r+dy[l];
                    int nx = c+dx[l];
                    if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                    int now = a[ny][nx];
                    if (prev == now) {continue;}
                    else if (now != 0) {
                        pairs.insert({prev, now});
                    }
                }
            }
        }
        // 3-2. 결과 계산 및 출력 (res += sizeOfA*sizeOfB)
        int result = 0;
        for (auto p : pairs) {
            result += get_size(p.first) * get_size(p.second);
        }
        result /= 2;
        cout << result << '\n';
    }

    
    return 0;
}