// 교수가 된 현우 - BOJ 3474

// N!의 오른쪽 끝의 0 개수 구하기
// 못풀었음

#include <bits/stdc++.h>
using namespace std;

int T, N, cnt, remain;
int cnt_2, cnt_5;

int main() {
    cin >> T;

    while (T--) {
        cnt_2 = 0; cnt_5 = 0;
        cin >> N;
        for (int i=2; i <= N; i*=2) {
            cnt_2 += N/i;
        }
        for (int i=5; i <= N; i*=5) {
            cnt_5 += N/i;
        }
        cout << min(cnt_2, cnt_5) << "\n";
    }
    
    return 0;
}
