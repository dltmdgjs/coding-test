#include <bits/stdc++.h>
using namespace std;

int n;

int main() {

    while (scanf("%d", &n) != EOF) {

        int cnt = 1, ret = 1;

        while (true) {
            if (cnt % n == 0) {
                printf("%d\n", ret);
                break;
            } else {
                cnt = (cnt * 10) + 1;
                cnt %= n; // 개선점 1 : 모듈러 연산이 무엇인지 공부 필요.
                          // x mod N = (x mod N) mod N -> 숫자 커짐을 방지...
                ret++;
            }
        }

    }

    return 0;
}