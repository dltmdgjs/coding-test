#include <iostream>
#include <vector>

using namespace std;
#define ull unsigned long long int

int getPisano(ull m) {
    int previous = 0;
    int current = 1;
    int pisano_length = 0;

    for (ull i = 0; i < m * m; i++) {
        int temp = current;
        current = (previous + current) % m;
        previous = temp;

        pisano_length++;

        // 피사노 주기의 시작 부분(다시 되돌아오는 부분)을 찾음.(0, 1)
        if (previous == 0 && current == 1) {
            return pisano_length;
        }
    }

    return pisano_length;
}

int main() {
    ull n;
    cin >> n;
    ull a=0, b=1, c=0;

    const int mod = 1000000;

    // 연산량이 많으므로 피사노 주기를 이용함.
    // 피사노 주기란? 어떤 수 m에 대해 피보나치 수를 m으로 나눈 나머지의 주기
    int pisano = getPisano(mod);
    n = n % pisano; // 피사노 주기를 이용해 n을 줄임. 최대 피사노 주기 만큼만 계산하면됨.

    for (ull i=2; i<=n; i++) {
        c = (a + b) % mod;
        a = b;
        b = c;
    }

    if (n == 0) c = 0;
    else if (n == 1) c = 1;
    int result = c % 1000000;
    cout << result;

    return 0;
}