// 사과 담기 게임 - BOJ 2828

#include <bits/stdc++.h>
using namespace std;

int N, M, J;
int l, r;
int loc;
int result = 0;


int solve() {
    int ret = 0;
    if (loc >= l && loc <= r) {
        return 0;
    } else if (loc < l) {
        ret = l - loc;
        l = loc; r = l+M-1;
    } else if (loc > r) {
        ret = loc - r;
        r = loc; l = r-M+1;
    }
    return ret;
}

int main() {

    cin >> N >> M;
    cin >> J;
    l = 1; r = M;
    for (int i=0; i<J; i++) {
        cin >> loc;
        result += solve();
    }

    cout << result;

    return 0;
}