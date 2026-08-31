// 분할 정복 : 행렬 곱셈

// 행렬 A(N x M)과 행렬 B(M x K)의 곱을 출력(N x K)

#include <iostream>
using namespace std;

int N, M, K;
int A[101][101], B[101][101];


// 결과의 i,j 위치의 원소를 계산함.
int mul(int i, int j) {
    int result = 0;
    for (int a=1; a<=M; a++) {
        result += A[i][a] * B[a][j];
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin >> A[i][j];
        }
    }
    cin >> M >> K;
    for (int i=1; i<=M; i++) {
        for (int j=1; j<=K; j++) {
            cin >> B[i][j];
        }
    }
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=K; j++) {
            cout << mul(i,j) << " ";
        }
        cout << "\n";
    }

    return 0;
}