// 쿼드트리 - BOJ 1992



#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int N;
int a[MAX][MAX];

// 해당 범위가 모두 같은 수인지 체크
bool check(int y_1, int x_1, int y_2, int x_2) {
    int first = a[y_1][x_1];

    for (int i=y_1; i<y_2; i++) {
        for (int j=x_1; j<x_2; j++) {
            if (a[i][j] != first) {
                return false;
            }
        }
    }
    return true;
}

string recursive(int y_1, int x_1, int y_2, int x_2) {
    string s = "";
    // 조건 검사
    if (check(y_1, x_1, y_2, x_2)) {
        // 로직 : 문자열 구성
        return to_string(a[y_1][x_1]);
    }

    // 재귀 탐색 
    // 범위 설정 잘하자: [중간점 = 양 끝점 합 / 2]
    s += "(";
    s += recursive(y_1, x_1, (y_1+y_2)/2, (x_1+x_2)/2); // 좌상
    s += recursive(y_1, (x_1+x_2)/2, (y_1+y_2)/2, x_2); // 우상
    s += recursive((y_1+y_2)/2, x_1, y_2, (x_1+x_2)/2); // 좌하
    s += recursive((y_1+y_2)/2, (x_1+x_2)/2, y_2, x_2); // 우하
    s += ")";

    return s;
}

int main() {

    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%1d", &a[i][j]);
        }
    }

    string s = recursive(0, 0, N, N);

    cout << s;

    return 0;
}