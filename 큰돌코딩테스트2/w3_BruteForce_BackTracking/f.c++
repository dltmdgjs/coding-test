// 괄호 추가하기 - BOJ 16637 (해결못함)

// 현재의 식을 계산하거나 안하거나.

// 괄호 추가하기 - BOJ 16637

#include <bits/stdc++.h>
using namespace std;

int N;
string s;
int ret = INT_MIN;

// 연산 처리
int calc(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    return a * b;
}

/*
    idx : 현재 연산자의 위치
    sum : 현재까지 계산한 값

    문자열 구조
    숫자 연산자 숫자 연산자 숫자 ...

    ex)
    3+8*7-9

    0 1 2 3 4 5 6
    3 + 8 * 7 - 9
*/
void go(int idx, int sum) {

    // 더 이상 계산할 연산자가 없음
    if (idx >= N) {
        ret = max(ret, sum);
        return;
    }

    /*
        1. 괄호를 사용하지 않는 경우

        현재 sum과 바로 다음 숫자를 계산한다.

        ex)
        sum = 3
        idx = 1 ('+')

        3 + 8
    */
    int next = calc(sum, s[idx + 1] - '0', s[idx]);

    go(idx + 2, next);


    /*
        2. 오른쪽 연산에 괄호를 사용하는 경우

        현재 구조가

        sum + 8 * 7

        이라면

        sum + (8 * 7)

        을 계산한다.

        따라서 idx + 2 이후에
        연산자가 하나 더 존재해야 함.
    */
    if (idx + 2 < N) {

        int bracket = calc(
            s[idx + 1] - '0',
            s[idx + 3] - '0',
            s[idx + 2]
        );

        int nextWithBracket = calc(
            sum,
            bracket,
            s[idx]
        );

        // 괄호에 사용한 연산까지 건너뜀
        go(idx + 4, nextWithBracket);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin >> s;

    // 첫 번째 숫자를 현재 값으로 두고
    // 첫 번째 연산자(index 1)부터 시작
    go(1, s[0] - '0');

    cout << ret;

    return 0;
}