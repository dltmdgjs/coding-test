// 주유소
// 알고리즘 분류 : 그리디

// 1. 처음 도시에선 무조건 다음 도시 거리만큼 기름 구매한다. 이때 기름 최솟값을 갱신한다.
// 2. 다음 도시에선 이 도시의 기름값과 이전 도시들의 기름 최솟값을 비교해 최솟값을 갱신하거나 유지하고 다음 도시 거리만큼 구매한다.
// 3. 마지막 도시 기름값은 사실상 의미가 없음.

#include <iostream>
using namespace std;

int N;
long long length[100001];
long long price[100001];
long long totalPrice = 0;
long long minPrice = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 입력
    cin >> N;
    for (int i=0; i<N-1; i++){
        cin >> length[i];
    }
    for (int i=0; i<N; i++) {
        cin >> price[i];
    }

    // 최솟값 구하기
    totalPrice += length[0] * price[0];
    minPrice = price[0];
    for (int i=1; i<N-1; i++) {
        // 최소비용 갱신.
        if (price[i] < minPrice) {
            minPrice = price[i];
        }
        totalPrice += minPrice * length[i];
    }

    // 출력
    cout << totalPrice << "\n";
    return 0;
}