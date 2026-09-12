// 나는야 포켓몬 마스터 이다솜 - BOJ 1620

#include <bits/stdc++.h>
using namespace std;

map<string, int> mp1; // 이름 : 번호
map<int, string> mp2; // 번호 : 이름
int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 번호를 말하면 이름을 말하거나
    // 이름을 말하면 번호를 말하도록 구성.

    cin >> N >> M;

    for (int i=1; i<=N; i++) {
        string name;
        cin >> name;
        mp1.insert({name, i});
        mp2.insert({i, name});
    }

    for (int i=0; i<M; i++) {
        // 숫자인지, 문자열인지 판별 필요.
        char s[20]; // atoi에 넣으려면 char[] 타입이어야 함 (string은 stoi)
        cin >> s;   // 만약 첨부터 string 입력받으면, s.c_str()함수로 변환해야함.
        if (std::atoi(s) == 0) { // atoi는 잘못된 값이 들어오면 0반환 (stoi는 예외 발생)
            cout << mp1[s] << "\n";
        } else {
            cout << mp2[atoi(s)] << "\n";
        }
    }

    return 0;
}