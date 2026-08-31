// 펠린드롬 수 확인하기 - 브론즈 3
// 알고리즘 분류 : 구현, 문자열

#include <bits/stdc++.h>
using namespace std;

string s;
string s1;

int main() {

    cin >> s;

    s1 = s;

    reverse(s.begin(), s.end());

    if (s.compare(s1) == 0) {
        cout << 1;
    } else {
        cout << 0;
    }

    return 0;
}