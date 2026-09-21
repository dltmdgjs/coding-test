// 빈도 정렬 - BOJ 2910

// 숫자를 빈도 순으로 정렬 (내림차순)


#include <bits/stdc++.h>
using namespace std;

int N, C, num, order = 1;
map<int, int> mp; // 숫자, 빈도
map<int, int> mp2; // 숫자, 순서
vector<pair<int, int> > v; // 숫자 빈도 정렬

bool compare(pair<int, int> &a, pair<int, int> &b) {
    if (a.first == b.first) {
        return mp2[a.second] < mp2[b.second];
    }
    return a.first > b.first;
}

int main() {

    cin >> N >> C;

    for (int i=0; i<N; i++) {
        cin >> num;
        if (mp.find(num) == mp.end()) {
            mp2[num] = order;
            order++;
        }
        mp[num]++;
    }

    for (pair<int, int> p : mp) {
        v.push_back({p.second, p.first});
    }

    sort(v.begin(), v.end(), compare);

    for (pair<int, int> p : v) {
        for (int i=0; i<p.first; i++) {
            cout << p.second << " ";
        }
    }

    return 0;
}