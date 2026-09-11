// ROT13 - BOJ 11655

#include <bits/stdc++.h>
using namespace std;

string s, r;

int main() {

    // 대/소문자, 숫자 구분해야함. 판정 방법 : 아스키 코드 (대문자 : 65 ~ 90, 소문자 97 ~ 122)
    // 범위 초과 시 공식 : a + ((x+13) - z) || A + ((X+13) - Z)
    // 개선 : x + 13 - 26

    getline(cin, s);
    
    for (char a : s) {
        if (a >= 'a' && a <= 'z') {
            if (a + 13 > 'z') cout << (char) ('a' + ((a+13) - 'z') - 1);
            else {
                cout << (char) (a+13);
            }
        } else if (a >= 'A' && a <= 'Z') {
            if (a + 13 > 'Z') cout << (char) ('A' + ((a+13) - 'Z') - 1);
            else {
                cout << (char) (a+13);
            }
        } else {
            cout << a;
        }
    }


    return 0;
}