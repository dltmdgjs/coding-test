// 소가 길을 건너간 이유 3 - 실버 4
// 알고리즘 분류 : 그리디, 정렬

// 라인스위핑 - 구간 관련 문제는 정렬을 하라.
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
int N, time_now;

int main() {
    cin >> N;
    
    for (int i=0; i<N; i++) {
        int t1, t2; cin >> t1 >> t2;
        v.push_back({t1, t2});
    }

    sort(v.begin(), v.end());

    for (auto c : v) {
        int arrival_t = c.first, test_t = c.second;
        if (arrival_t < time_now) {
            time_now += test_t;
        } else {
            time_now = arrival_t + test_t;
        }
    }

    cout << time_now;
    
    return 0;
}