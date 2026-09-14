// 1 - BOJ 4375

// 풀지 못함... 다시 풀어봐야 함.

#include <bits/stdc++.h>
using namespace std;

int n;

int main() {

    // 문제 이해조차 어려웠음..
    // N의 배수 중에서 각 자리가 모두 1인 것. 그중 최솟값의 자리수 출력
    // ex) N = 3이면, 3의 배수 중 각 자리가 모두 1인 것은, 111, 3자리임.

    while (scanf("%d", &n) != EOF) {

        int cnt = 1, ret = 1;

        while (true) {
            if (cnt % n == 0) {
                printf("%d\n", ret);
                break;
            } else {
                cnt = (cnt * 10) + 1;
                cnt %= n; // 모듈러 연산 적용 : 나머지 활용.
                ret++;
            }
        }

    }

    return 0;
}