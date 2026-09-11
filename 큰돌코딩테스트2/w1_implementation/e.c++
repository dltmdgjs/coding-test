// 농구 경기 - BOJ 1159

#include <bits/stdc++.h>
using namespace std;

int cnt;
map<char, int> mp;
bool isPredaja = true;

int main() {
    cin >> cnt;

    for (int i=0; i<cnt; i++) {
        string s;
        cin >> s;
        if (mp.find(s[0]) != mp.end()) {
            mp[s[0]]++;
        } else {
            mp.insert({s[0], 1});
        }
    }

    for (pair<char, int> p : mp) {
        if (p.second >= 5) {
            isPredaja = false;
            cout << p.first;
        }
    }

    if (isPredaja) {
        cout << "PREDAJA";
    }

    return 0;
}