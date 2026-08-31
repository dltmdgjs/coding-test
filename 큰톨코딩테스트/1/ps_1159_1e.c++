// 농구 경기 - 브론즈 2
// 알고리즘 분류 : 구현, 문자열

#include <bits/stdc++.h>
using namespace std;


int cnt[26];
int N;

int main() {

    cin >> N;

    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        cnt[s[0]-97]++;
    }

    bool over5 = false;
    for (int i=0; i<26; i++) {
        if (cnt[i] >= 5) {
            over5 = true;
            cout << (char)(i+97);
        }
    }
    if (!over5) {
        cout << "PREDAJA";
    }

    return 0;
}


// 위 풀이 수정 - 숫자를 문자로 변환(자동)
            // string ret;

            // for (int i=0; i<26; i++) {
            //     if (cnt[i] >= 5) {
            //         ret += (i+'a');
            //     }
            // }

            // if (ret.size()) cout << ret;
            // else cout << "PREDAJA";