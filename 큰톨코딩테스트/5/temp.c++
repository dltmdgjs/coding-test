#include <bits/stdc++.h>
using namespace std;

// 1번 인덱스부터 사용하므로 최대 100 조건에 맞춰 105로 설정
#define MAX 105 

int N, M, K;
int A[MAX][MAX];     // 원본 배열
int temp[MAX][MAX];  // 회전 연산을 수행할 임시 배열
int result = 98765432;

struct Rotate {
    int r, c, s;

    // 순열(next_permutation) 처리를 위한 정렬 기준
    bool operator<(const Rotate& other) const {
        if (r != other.r) return r < other.r;
        if (c != other.c) return c < other.c;
        return s < other.s;
    }
};

vector<Rotate> R; // 회전 명령 리스트

// 행의 합 중 최솟값 계산 및 결과 갱신
void calculate_array_refresh() {
    for (int i = 1; i <= N; i++) {
        int r_sum = 0;
        for (int j = 1; j <= M; j++) {
            r_sum += temp[i][j];
        }
        if (result > r_sum) {
            result = r_sum;
        }
    }
}

// 껍질 크기 s에 대해 테두리를 시계 방향으로 딱 1칸 이동시키는 직관적인 함수
void rotate_layer(int r, int c, int s) {
    int top = r - s;
    int bottom = r + s;
    int left = c - s;
    int right = c + s;

    // 왼쪽 위 모서리 값을 임시 보관
    int start_val = temp[top][left];

    // 1. 왼쪽 변: 아래에서 위로 당기기
    for (int i = top; i < bottom; i++) {
        temp[i][left] = temp[i + 1][left];
    }
    // 2. 아랫 변: 오른쪽에서 왼쪽으로 당기기
    for (int j = left; j < right; j++) {
        temp[bottom][j] = temp[bottom][j + 1];
    }
    // 3. 오른쪽 변: 위에서 아래로 내리기
    for (int i = bottom; i > top; i--) {
        temp[i][right] = temp[i - 1][right];
    }
    // 4. 윗 변: 왼쪽에서 오른쪽으로 밀기
    for (int j = right; j > left + 1; j--) {
        temp[top][j] = temp[top][j - 1];
    }

    // 보관해 둔 값을 올바른 다음 위치(윗변 왼쪽에서 두 번째)에 삽입
    temp[top][left + 1] = start_val;
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력 받기
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 1; i <= K; i++) {
        int r, c, s;
        cin >> r >> c >> s;
        R.push_back({r, c, s});
    }

    // next_permutation 사용 전 필수 정렬
    sort(R.begin(), R.end());

    // 연산 순서 순열 탐색 시작
    do {
        // 매 순열 연산마다 원본 배열 A를 temp에 새롭게 복사
        memcpy(temp, A, sizeof(A));

        // 배치된 회전 연산들 순서대로 적용
        for (Rotate _R : R) {
            // 가장 바깥 테두리(s)부터 안쪽 테두리(1)까지 중심을 향해 순차적으로 회전
            for (int curr_s = _R.s; curr_s > 0; curr_s--) {
                rotate_layer(_R.r, _R.c, curr_s);
            }
        }

        // 결과값 갱신
        calculate_array_refresh();

    } while (next_permutation(R.begin(), R.end()));

    // 최종 최솟값 출력
    cout << result << "\n";

    return 0;
}
