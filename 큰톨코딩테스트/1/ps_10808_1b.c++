// 알파벳 개수 - 브론즈 4
// 알고리즘 분류 : 구현, 문자열

#include <bits/stdc++.h>
using namespace std;

int a[26];

int main() {
    
    string s;
    cin >> s;

    for (int i=0; i<s.size(); i++) {
        a[s[i]-97]++;
    }

    for (int i=0; i<26; i++) {
        cout << a[i] << " ";
    }

    return 0;
}

// counting star 는 맵(Map) 또는 배열(Array)

// Map - string 기반 ex) "큰돌" 이라는 문자열이 몇개인지 찾을때
// Array - int 기반 ex) 100 이라는 숫자가 몇개인지 찾을때 