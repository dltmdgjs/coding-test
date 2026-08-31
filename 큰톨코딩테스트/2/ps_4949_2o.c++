// 균형잡힌 세상 - 실버 4
// 알고리즘 분류 : 자료구조, 문자열, 스택

#include <bits/stdc++.h>
using namespace std;


int main() {

    while (true) {
        string t;
        getline(cin, t);
        if (t == ".") break;
        
        stack<char> s;
        for (int i=0; i<t.size()-1; i++) {
            if (t[i] == '(' || t[i] == '[') {
                s.push(t[i]);
            } else if (t[i] == ')') {
                if (s.size() > 0 && s.top() == '(') s.pop();
                else {s.push(t[i]); break;}
            } else if (t[i] == ']') {
                if (s.size() > 0 && s.top() == '[') s.pop();
                else {s.push(t[i]); break;}
            }
        }
        if (s.size()) {
            cout << "no" << '\n';
        } else {
            cout << "yes" << '\n';
        }
    }

    return 0;
}

// 스택 top, pop 하기 전, 비어 있는지 체크 잘 해주기