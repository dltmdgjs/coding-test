#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int A[101][101], temp[101][101];
int result = 98765432;

struct Rotate {
    int r, c, s;
};

vector<Rotate> R;
vector<int> p; // 순열을 위한 인덱스 벡터

// 특정 껍질을 시계 방향으로 1칸 회전시키는 함수
void rotate_layer(int r1, int c1, int r2, int c2) {
    int top = temp[r1][c1];
    
    // 왼쪽 변: 아래에서 위로
    for (int i = r1; i < r2; i++) temp[i][c1] = temp[i + 1][c1];
    // 아래 변: 오른쪽에서 왼쪽으로
    for (int i = c1; i < c2; i++) temp[r2][i] = temp[r2][i + 1];
    // 오른쪽 변: 위에서 아래로
    for (int i = r2; i > r1; i--) temp[i][c2] = temp[i - 1][c2];
    // 위 변: 왼쪽에서 오른쪽으로
    for (int i = c2; i > c1 + 1; i--) temp[r1][i] = temp[r1][i - 1];
    
    temp[r1][c1 + 1] = top;
}

// 회전 연산 수행
void apply_rotation(int r, int c, int s) {
    for (int i = 1; i <= s; i++) {
        rotate_layer(r - i, c - i, r + i, c + i);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) cin >> A[i][j];

    for (int i = 0; i < K; i++) {
        int r, c, s;
        cin >> r >> c >> s;
        R.push_back({r, c, s});
        p.push_back(i);
    }

    do {
        memcpy(temp, A, sizeof(A));
        
        // 순열에 따른 순서로 회전 수행
        for (int i : p) {
            apply_rotation(R[i].r, R[i].c, R[i].s);
        }

        // 결과 계산
        for (int i = 1; i <= N; i++) {
            int row_sum = 0;
            for (int j = 1; j <= M; j++) row_sum += temp[i][j];
            result = min(result, row_sum);
        }
    } while (next_permutation(p.begin(), p.end()));

    cout << result << "\n";
    return 0;
}