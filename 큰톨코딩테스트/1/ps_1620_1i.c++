// 나는야 포켓몬 마스터 이다솜 - 실버 4
// 알고리즘 분류 : 자료구조, 집합과 맵, 해시를 사용한 집합과 맵

#include <bits/stdc++.h>
using namespace std;

int N, M;
map<string, int> m1; // 포켓몬명, 도감번호
map<int, string> m2; // 도감번호, 포켓몬명
vector<string> q; // 문제

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    // 도감 입력
    for (int i=1; i<=N; i++) {
        string s;
        cin >> s;
        m1.insert({s, i}); // insert로 맵에 요소를 삽입함.
        m2.insert({i, s});
    }
    
    // 문제 입력
    for (int i=0; i<M; i++) {
        string s;
        cin >> s;
        q.push_back(s);
    }

    // 답 출력
    for (int i=0; i<M; i++) {
        // string이면 m1을 출력하고, 아니면 m2를 출력함.
        if (m1.find(q[i]) != m1.end()) {
            cout << m1[q[i]] << '\n';
        } else {
            cout << m2[stoi(q[i])] << '\n'; // stoi()로 string을 int로 변환가능.
        }
    }

    return 0;
}

// 숫자인지 문자열인지 판별하는 법 : atoi(s.c_str()) -> 반환값이 1이상이면 숫자, 0이면 문자열임.
// 만약에 위 로직에서 문자열인지 숫자인지 판별하는 것이 찾기 전에 선행되게 하려면 atoi를 쓰는게 좋음.
// stoi는 '문자열로된 숫자'를 '숫자'로 변환해주지만, stoi("abx")같은 경우 숫자로 변환하지 못하므로 에러 발생함.

// 즉, 아래와 같이 수정 가능함.
            // if (atoi(q[i].c_str()) == 0) {
            //     cout << m1[q[i]] << '\n';
            // } else {
            //     cout << m1[atoi(q[i].c_str())] << '\n';
            // }

// ps. 도감 문제는 0을 도감 범위로 포함하지 않으므로 위 로직이 문제 되지 않으나
//     도감이 0을 포함하면 이를 고려해야함.