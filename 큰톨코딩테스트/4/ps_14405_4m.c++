// 피카츄 - 실버 5
// 알고리즘 분류 : 문자열

#include <bits/stdc++.h>
using namespace std;

// 한 문자씩 읽어들인다. 
// 문자열 s에 저장한다(초기상태 "")
// 3가지 단어와 일치하는지 비교한다.
// 일치하지 않으면 계속 읽어들이며 비교
// 일치하면 s를 빈 문자열로 만듦
// s의 크기가 4를 넘어서면 즉시 중단
// 다 읽어들인 후 크기가 0이면 yes, 아니면 no 출력

string s;
string t;
string pi = "pi", ka = "ka", chu = "chu";

int main() {
    cin >> s;
    for (int i=0; i<s.size(); i++) {
        t += s[i];
        if (t.size() >= 4) break;
        if (t == pi || t == ka || t == chu) {
            t = "";
        }
    }
    if (t.size() == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}

// 선생님 풀이 -> substr 이용