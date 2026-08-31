#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    // dp[w] = 최대 가치로 무게 한도 w일 때의 값
    vector<int> dp(K + 1, 0);

    for (int i = 0; i < N; ++i) {
        int weight, value;
        cin >> weight >> value;
        if (weight > K) continue; // 무게가 K보다 크면 어차피 사용 불가
        // 0/1 배낭: 뒤에서부터 업데이트하여 한 아이템을 여러 번 사용하지 않음
        for (int w = K; w >= weight; --w) {
            dp[w] = max(dp[w], dp[w - weight] + value);
        }
    }

    cout << dp[K] << '\n';
    return 0;
}

// dp 문제 : 점화식을 세워야 함. 
// dp가 무엇을 의미하는지 정의하기.
// 작은예시를 통해 규칙을 찾아 일반화하기. (이전 상태(부분문제)를 통해 현재 상태를 어떻게 구할지.)
// dp 초기값 설정하기.
// dp 배열을 채우는 순서 결정하기. (앞에서부터, 뒤에서부터)
// 0/1 배낭 문제에서는 뒤에서부터 채워야 함.
// 1. dp[w]를 "무게 한도 w일 때의 최대 가치"로 정의.
// 2. 점화식: dp[w] = max(dp[w], dp[w - weight] + value)
//    (현재 무게 한도 w에서 아이템을 넣지 않는 경우와 넣는 경우 중 최대값 선택)