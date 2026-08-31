#include <bits/stdc++.h>
using namespace std;

string s;

int main() {

    getline(cin, s);

    for (int i=0; i<s.size(); i++) {
        // 대소문자 구분
        if (s[i] >= 65 && s[i] <= 90) {
            // 13자 밀기
            if (s[i]+13 > 90) {
                s[i] = s[i]+13-26; // 넘어선 지점에서 알파벳 갯수(26)만큼 빼주면 cyclic이 됨.
            } else {
                s[i] = s[i]+13;
            }
        } else if (s[i] >= 97 && s[i] <= 122){
            // 13자 밀기
            if (s[i]+13 > 122) {
                s[i] = s[i]+13-26; // 넘어선 지점에서 알파벳 갯수(26)만큼 빼주면 cyclic이 됨.
            } else {
                s[i] = s[i]+13;
            }
        }
        cout << s[i];
    }

    return 0;
}

// getline(cin, s) : 띄어쓰기 포함 통쨰로 한줄을 입력받음