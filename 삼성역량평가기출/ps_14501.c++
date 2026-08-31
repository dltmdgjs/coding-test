// 퇴사 - 실버 3

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> t(N), p(N);
    for (int i = 0; i < N; ++i) {
        cin >> t[i] >> p[i];
    }

    // dp[i] = i일부터 끝까지 얻을 수 있는 최대 수익
    vector<int> dp(N+1, 0);
    // 뒤에서부터 계산
    for (int i = N-1; i >= 0; --i) {
        // i일부터 i+t[i]일까지 일할 수 있다면, p[i] + dp[i+t[i]]와 dp[i+1] 중 큰 값을 선택
        if (i + t[i] <= N) {
            dp[i] = max(p[i] + dp[i + t[i]], dp[i+1]);
        }
        // 일할 수 없다면, dp[i+1]과 같다
        else {
            dp[i] = dp[i+1];
        }
    }

    // 첫날부터 끝까지 얻을 수 있는 최대 수익
    cout << dp[0] << '\n';
    return 0;
}

// 뒤에서부터 계산하는 이유는, dp[i]를 계산할 때 dp[i+t[i]]와 dp[i+1]이 필요하기 때문입니다.
// 만약 앞에서부터 계산한다면, dp[i+t[i]]와 dp[i+1]이 아직 계산되지 않았을 수 있습니다.