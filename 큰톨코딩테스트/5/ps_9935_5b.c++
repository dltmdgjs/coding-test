// 문자열 폭발 - 골드 4
// 알고리즘 분류 : 자료구조, 문자열, 스택

#include <bits/stdc++.h>
using namespace std;

string s, b;
vector<char> st1;

int main () {
    
    cin >> s;
    cin >> b;

    for (int i=0; i<s.size(); i++) {
        // 스택에 삽입
        st1.push_back(s[i]);

        // 스택 크기가 폭탄문자열 크기보다 크거나 같고, top의 문자가 폭탄의 마지막과 같다면, 
        if (st1.size() >= b.size() && st1[st1.size()-1] == b[b.size()-1]) {
            // 스택의 끝 지점부터 폭탄 문자열 크기만큼 검사 후에,
            bool flag = true;
            for (int it=0;it<b.size(); it++) {
                if (st1[st1.size()-it-1] !=  b[b.size()-it-1]) {flag = false; break;}
            }
            // 완전 같으면 제거.
            if (flag) {
                for (int i=0; i<b.size(); i++) {
                    st1.pop_back();
                }
            }
        }
    }

    if (st1.size()) {
        for (auto c : st1) {cout << c;}
    } else {
        cout << "FRULA";
    }

    return 0;
}

// "폭발, 짝짓기" - 스택으로 풀릴 가능성 큼

// 스택 구조를 활용(실시간 입력으로 한번에 처리)해야 함. - 실제 스택 자료 구조를 사용하기 보단 그 원리를 사용하기.
// 일반적인 탐색방식(슬라이딩 윈도우 식으로 하나씩 계속 검사 & 삭제)으로는 시간초과


// erase를 쓰는 방법도 있음 ret.erase(start, end)