// 치킨배달 - 골드 5
// 알고리즘 분류 : 구현, 브루트포스, 백트래킹

// 시간초과 해결방법 찾기
//  -> 문제점 : combi 함수에서 재귀호출 시 i+1로 전달해야함.

#include <bits/stdc++.h>
using namespace std;

int N, M, a[100][100], K, n, mn=1000000;
vector<pair<int, int>> h; // 집(1)의 위치
vector<pair<int, int>> c; // 치킨집(2)의 위치

int chicken_dist(vector<pair<int, int>>& b) {
    int ret = 0;

    for (auto home : h) {
        int min_val = 1000000;
        for (auto chicken : b) {
            int dist = abs(home.first - chicken.first) + abs(home.second - chicken.second);
            min_val = min(min_val, dist);
        }
        ret += min_val;
        if (ret > mn) break;
    }

    return ret;
}

void combi(int start, vector<pair<int, int>>& b) {
    if (b.size() == K) {
        // 로직 수행
        int t = chicken_dist(b);
        mn = min(mn, t);
        return;
    }
    for (int i=start; i<n; i++) {
        b.push_back({c[i].first, c[i].second});
        combi(i+1, b); // i+1 해줘야함....
        b.pop_back();
    }
}

int main() {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) h.push_back({i, j});
            if (a[i][j] == 2) c.push_back({i, j});
        }
    }

    n = c.size();

    for (int i=1; i<=M; i++) {
        K = i;
        vector<pair <int, int>> b;
        combi(0, b);
    }

    cout << mn;

    return 0;
}