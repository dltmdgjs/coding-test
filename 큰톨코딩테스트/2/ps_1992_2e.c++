// 쿼드트리 - 실버 1
// 알고리즘 분류 : 분할 정복, 재귀

#include <bits/stdc++.h>
using namespace std;

int N, a[100][100];

bool isSame(int y_1, int x_1, int y_2, int x_2) {
    int firstVal = a[y_1][x_1];
    for (int i=y_1; i<y_2; i++) {
        for (int j=x_1; j<x_2; j++) {
            if (a[i][j] != firstVal) {
                return false;
            }
        }
    }
    return true;
}

void go(int y_1, int x_1, int y_2, int x_2) {
    // 영역 내 같은지 검사
    if (!isSame(y_1, x_1, y_2, x_2)) {
        cout << "(";
        // 안같으면 4분할 -> 재귀 호출 (왼위, 오위, 왼아래, 오아래 순서로..)
        go(y_1, x_1, (y_1+y_2)/2, (x_1+x_2)/2);
        go(y_1, (x_1+x_2)/2, (y_1+y_2)/2, x_2);
        go((y_1+y_2)/2, x_1, y_2, (x_1+x_2)/2);
        go((y_1+y_2)/2, (x_1+x_2)/2, y_2, x_2);
        cout << ")";
    } else {
        // 같으면 그 수 출력 후 리턴
        cout << a[y_1][x_1];
        return;
    }
    
}

int main() {

    cin >> N;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%1d", &a[i][j]);
        }
    }

    go(0, 0, N, N);

    return 0;
}