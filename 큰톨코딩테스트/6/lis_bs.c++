// 최대 증가 부분 수열 (LIS)
//// 방법 1) DP - N^2
// 방법 2) 이분 탐색 - NlogN, 실제 수열 추적 불가

#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {10, 20, 10, 30, 20, 50};

    vector<int> lis;

    for (int x : arr) {
        // x값 이상이 처음 나오는 위치 (주의) lis에서 탐색.)
        auto it = lower_bound(lis.begin(), lis.end(), x);

        // x값 이상이 없는 경우
        if (it == lis.end()) {
            lis.push_back(x); // x값을 마지막에 집어 넣음.
        // x값 이상이 있는 경우
        } else {
            *it = x; // 그 위치의 값을 x로 대체
        }
    }

    cout << lis.size(); // LIS 크기만 출력 (실제 LIS는 추적 불가.)

    return 0;
}