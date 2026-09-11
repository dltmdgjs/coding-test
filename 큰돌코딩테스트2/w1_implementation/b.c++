// 알파벳 개수 - BOJ 10808

// 핵심 : 각 알파벳이 단어에 몇 개 포함되는지 구하기.

// a = 97, z = 122

#include <bits/stdc++.h>
using namespace std;

int cnt[26];

int main() {

    string s;

    cin >> s;

    for (int i=0; i<s.size(); i++) {
        cnt[s[i] - 97]++;
    }

    for (int i=0; i<26; i++) {
        cout << cnt[i] << " ";
    }

    return 0;
}