// 수열 - 실버 3
// 알고리즘 분류 : 누적합, 투 포인터, 슬라이딩 윈도우

#include <bits/stdc++.h>
using namespace std;
#define MAX 200000
#define MIN -10000000

int N, K;
int temp[MAX]; 
int acc[MAX]; // 0~i까지의 temp합.
int result = MIN; // 최댓값 (MIN값으로 설정 중요)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    cin >> N >> K;
    for (int i=1; i<=N; i++) {
        cin >> temp[i];
    }

    // 누적합 구하기
    for (int i=1; i<=N; i++) {
        acc[i] = acc[i-1] + temp[i];
        // cout << "누적합" << acc[i] << '\n';
    }

    // 구간합 구하기 K이용
    for (int i=0; i<=N-K; i++) {
        int sec_sum = acc[K+i]-acc[i];
        // cout << "구간합 (" << K+i << "~" << i+1 << ")" << sec_sum << '\n';
        if (result < sec_sum) {
            result = sec_sum;
        }
    }

    cout << result;

    return 0;
}


// 위 코드 수정 - 구간합 반복문 조건 수정
            // for (int i=K; i<+N; i++) {
            //     result = max(result, acc[i]-acc[i-K]);
            // }