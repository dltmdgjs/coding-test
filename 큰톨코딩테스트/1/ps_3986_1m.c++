// 좋은 단어 - 실버 4
// 알고리즘 분류 : 자료구조, 스택

#include <bits/stdc++.h>
using namespace std;

int N, cnt;

int main() {

    cin >> N;

    for (int i=0; i<N; i++) {
        stack<char> st;
        string s;
        cin >> s;
        for (int j=0; j<s.size(); j++) {
            // top, pop 쓰기 전, 스택이 비어있는지 먼저 체크해야함 (참조에러방지)
            if (st.empty()) { 
                st.push(s[j]); continue;
            }
            if (st.top() == s[j]) {
                st.pop();
            } else {
                st.push(s[j]);
            }
        }

        if (st.empty()) cnt++;
    }

    cout << cnt;

    return 0;
}


// 문제에서 '짝짓기, 폭발'이라는 단어가 있으면 '스택'을 사용하는 것을 고려해보자!