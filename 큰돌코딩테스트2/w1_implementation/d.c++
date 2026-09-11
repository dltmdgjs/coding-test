// 팰린드롬인지 확인하기 - BOJ 10988

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, r;

    cin >> s;

    r = s;

    reverse(s.begin(), s.end());

    if (s == r) {cout << 1;} 
    else {cout << 0;}

    return 0;
}