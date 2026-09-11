#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[26];

int main() {

    cin >> s;

    // 개선점 1 : 향상된 for문의 사용. -> 굳이 s.size()할 필요 X
    for (char c : s) {
        cnt[c - 'a']++; // 개선점 2 : c - 97이 아닌, c - 'a'. -> 굳이 a=97 이라고 생각할 필요 X.
    }

    for (int i=0; i<26; i++) {
        cout << cnt[i] << " ";
    }

    return 0;
}