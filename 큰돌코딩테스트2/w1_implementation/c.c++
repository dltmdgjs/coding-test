// 트럭 주차 - BOJ 2979

#include <bits/stdc++.h>
using namespace std;


int A, B, C;

int cnt[101];

int total;

void solve(int at, int lt) {
    for (int i=at+1; i<=lt; i++) {
        cnt[i]++;
    }
}

int main() {
    cin >> A >> B >> C;

    for (int i=0; i<3; i++) {
        int at, lt;
        cin >> at  >> lt;
        solve(at, lt);
    }

    for (int i=1; i<=100; i++) {
        if (cnt[i] == 1) {
            total += A;
        } else if (cnt[i] == 2) {
            total += B * 2;
        } else if (cnt[i] == 3) {
            total += C * 3;
        }
    }

    cout << total;
    return 0;
}