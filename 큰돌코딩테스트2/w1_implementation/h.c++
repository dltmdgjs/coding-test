// 수열 - BOJ 2559

// 핵심 : 구간의 합의 최댓값을 구하는 문제임.
// 연속 일수(구간의 길이)가 주어짐.

#include <bits/stdc++.h>
using namespace std;

int N, K, max_val = -(1e9); // 수열 길이, 구간 길이.
int a[100001];

int main() {
    cin >> N >> K;
    int sum=0;
    for (int i=1; i<=N; i++) {
        cin >> a[i];
        sum += a[i];
        if (i>K) {
            sum -= a[i-K];
        }
        if (i>=K && max_val < sum) {
            max_val = sum;
        }
    }

    cout << max_val;

    return 0;
}