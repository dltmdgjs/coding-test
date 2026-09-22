// 비밀번호 발음하기 - BOJ 4659

#include <bits/stdc++.h>
using namespace std;

string s;

// aeiou 유무 체크
bool aeiou() {
    for (char c : s) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
    }
    return false;
}

// 모음 3개 연속 혹은 자음 3개 연속 체크
bool threeFunc() {
    int count1=0, count2=0; // 모음 자음 연속 횟수 카운트
    for (char c : s) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count1++;
            count2 = 0;
        } else {
            count1 = 0;
            count2++;
        }
        if (count1 == 3 || count2 == 3) return false;
    }
    return true;
}   

// 같은 글자 2연속 체크 (ee oo 허용)
bool twoFunc() {
    char before = s[0];
    for (int i=1; i<s.size(); i++) {
        if (before == s[i] && !(s[i] == 'e' || s[i] == 'o')) return false;
        before = s[i];
    }
    return true;
}

// 전체 함수 - 모두 참이면 acceptable
bool solve() {
    return aeiou() && threeFunc() && twoFunc();
}

int main() {

    while (true) {
        cin >> s;
        if (s == "end") break;
        if (solve()) {
            cout << "<" << s << ">" << " is acceptable." << "\n";
        } else {
            cout << "<" << s << ">" << " is not acceptable." << "\n";
        }
    }

    return 0;
}