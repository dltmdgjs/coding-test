// 빈도 정렬 - 실버 3
// 알고리즘 분류 : 자료구조, 정렬, 집합과 맵, 해시 집합과 맵

#include <bits/stdc++.h>
using namespace std;

int N, C, ord = 1;
map<int, int> m; // 빈도
map<int, int> o; // 순서

// 비교 함수
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second > b.second) return true;
    else if (a.second == b.second) {
        return o[a.first] < o[b.first];
    } else {
        return false;
    }
}

int main() {
    // 입력
    cin >> N >> C;
    for (int i=0; i<N; i++) {
        int t; cin >> t;
        // 처음 입력 받는 경우
        if (m.find(t) == m.end()) {
            o.insert({t, ord});
            m.insert({t, 1});
            ord++;
        // 이미 입력 받은 경우
        } else {
            m[t]++;
        }
    }

    // val 기준 정렬을 위해 vector로 옮겨 정렬 수행
    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), compare);

    // 출력
    for (auto it = v.begin(); it<v.end(); it++) {
        for (int i=0; i<it->second; i++) {
            cout << it->first << " ";
        }
    }

    return 0;
}