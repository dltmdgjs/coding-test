// 한국이 그리울 땐 서버에 접속하지 - 실버 3
// 알고리즘 분류 : 문자열, 정규 표현식

#include <bits/stdc++.h>
using namespace std;

int N;
string p, s[100];
string first, last;


// 앞, 뒤를 뽑아서 패턴과 비교
bool comparePattern(string t) {
    string first_t = t.substr(0, first.size());
    string last_t = t.substr(t.size()-last.size() , t.size());

    if (first != first_t || last != last_t) {
        return false;
    }
    
    return true;
}

int main() {

    cin >> N;
    cin >> p;
    for (int i=0; i<N; i++) {
        cin >> s[i];
    }

    // 패턴을 * 기준으로 나눔
    int idx = p.find('*');
    first = p.substr(0, idx);
    last = p.substr(idx+1, p.size());

    // 검사할 문자열 하나씩 검사
    for (int i=0; i<N; i++) {
        string t = s[i];

        // 사이즈 자체가 안되면 NE
        if (t.size()<p.size()-1) {
            cout << "NE" << '\n';
            continue;
        }
        
        // 앞, 뒤 검사
        bool da = comparePattern(t);

        // 검사 결과에 따라 출력 DA,NE
        if (da) {
            cout << "DA" << '\n';
        } else {
            cout << "NE" << '\n';
        }
    }

    return 0;
}

// 반례 체크 중요. (여기서는 사이즈에 대한 반례가 존재했음)
// -> ja*ja이 패턴이고, ja가 검사대상일 때, 사이즈 비교를 먼저 해주지 않으면
//    DA로 잘못 출력됨.