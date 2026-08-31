#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxBeauty(vector<int>& flowers) {
    int n = flowers.size();
    vector<int> dp(n, 0);

    int max_beauty = 0;

    for (int i = 0; i < n; i++) {
        dp[i] = 0; // 꽃을 뽑지 않는 경우도 포함해야 함
        for (int j = 0; j < i; j++) {
            dp[i] = max(dp[i], dp[j] + (flowers[j] - flowers[i]) * (flowers[j] - flowers[i]));
        }
        max_beauty = max(max_beauty, dp[i]);
    }

    return max_beauty;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> flowers(N);
    for (int i = 0; i < N; i++) {
        cin >> flowers[i];
    }

    cout << maxBeauty(flowers) << endl;

    return 0;
}

