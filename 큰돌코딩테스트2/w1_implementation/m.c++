// 좋은 단어 - BOJ 3986

// 좋은 단어가 될 혹은 되지 못할 조건/상황을 생각해보자.
// 1. 단어 길이가 홀수이거나 2이면 무조건 좋은 단어가 아님.
// 2. 같은 단어 사이에 다른 단어가 홀수개 존재하면 무조건 좋은 단어가 아님.

// 이렇게 생각해보자. 같은 단어끼리 만나면 폭탄처럼 터져 없어지는 거라고.
// -> 스택 구조를 활용? 
// 스택이 비면 -> 좋은 단어.
// 스택이 차있으면 -> 좋은 단어 X.

#include <bits/stdc++.h>
using namespace std;

int N;
string s;
int result;

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> s;

        stack<char> st;
        st.push(s[0]); // 첫번째 문자만 먼저 삽입 (로직 상 불가피)

        for (int j=1; j<s.size(); j++) {
            if (st.size() && st.top() == s[j]) {
                st.pop();
            } else{
                st.push(s[j]);
            }
        }

        // 스택이 비면 -> 좋은단어.
        if (st.size() == 0) {
            result++;
        }
    }

    cout << result;

    return 0;
}