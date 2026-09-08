// 최대 증가 부분 수열 (LIS)
// 방법 1) DP - N^2
//// 방법 2) 이분 탐색 - NlogN, 실제 수열 추적 불가

#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> v = {10, 20, 10, 30, 20, 50};
    int n = v.size();

    vector<int> dp(n, 1); // i번째 원소(v[i])를 마지막 원소로 가지는 LIS의 길이.

    for (int i=0; i<n; i++) {
        // 현재 원소의 앞의 원소들을 하나씩 검사.
        for (int j=0; j<i; j++) {
            // 현재 원소가 앞의 원소보다 크면,
            if (v[j] < v[i]) {
                // 현재 LIS와 앞의 LIS + 1를 비교해서 큰 값을 현재의 LIS로 함.
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}