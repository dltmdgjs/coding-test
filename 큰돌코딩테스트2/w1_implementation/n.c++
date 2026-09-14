// 곱셈 - BOJ 1629

// A를 B번 곱한 수를 C로 나눈 나머지를 구하자.
// 나머지를 곱하면서 나누는 수를 넘기면 다시 % 연산해주면 되는구나.
// -> 그냥 선형으로 하니 시간초과 (N) 
// -> 분할 정복 이용, 2씩 나누며 범위를 좁힘. (log N)

// 테스트 케이스 1번 [10 11 12]에 대해서만 자꾸 시간초과.. 답은 맞음.
// -> 채점 사이트 오류 같음. 정답 코드 제출해도 같음. 걱정안해도 될듯.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll A, B, C, R;
stack<ll> st;

int main() {

    cin >> A >> B >> C;

    while (B != 1) {
        A %= C;

        if (B % 2 == 1) {
            st.push(A);
        }

        A = (A * A) % C;

        B = B / 2;
    }

    A %= C;

    while (!st.empty()) {
        ll i = st.top(); st.pop();
        A = (A*i) % C;
    }

    cout << A;

    return 0;
}