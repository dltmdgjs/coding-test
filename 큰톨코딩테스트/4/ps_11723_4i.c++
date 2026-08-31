// 집합 - 실버 5
// 알고리즘 분류 : 구현, 집합과 맵, 비트 마스킹

// 일반적인 set 연산으로 풀이할 경우 시간초과
// -> 비트마스킹을 통해 시간을 단축함. (n=20이므로 2^20 -> 비트 마스킹에 충분함)

#include <bits/stdc++.h>
using namespace std;

int x, M;
int S;
// set<int> s;

void add() {
    // s.insert(x);
    if (!(S & (1<<x))) {
        S |= (1<<x);
    }
}

void remove() {
    // if (s.find(x) != s.end()) {
    //     s.erase(x);
    // }
    if ((S & (1<<x))) {
        S &= ~(1<<x);
    }
}

void check() {
    // if (s.find(x) != s.end()) {
    //     cout << 1 << '\n';
    // } else {
    //     cout << 0 << '\n';
    // }
    if (S & (1<<x)) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
}

void toggle() {
    // if (s.find(x) != s.end()) {
    //     s.erase(x);
    // } else {
    //     s.insert(x);
    // }
    // if (!(S & (1<<x))) {
    //     S |= (1<<x);
    // } else {
    //     S &= ~(1<<x);
    // }
    S ^= (1<<x); // XOR 으로 가능.
}

void all() {
    S = (1<<21) - 1; // 주의 : 1<<N은 N번쨰 비트만 켜짐. 이하 다 켜기 위해선 -1 해줘야 함.
}

void empty() {
    S = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M;
    for (int i=0; i<M; i++) {
        string s;
        cin >> s;
        if (s == "all") {
            all();
        } else if (s == "empty") {
            empty();
        } else {
            cin >> x;
            if (s == "add") {add();}
            else if (s == "remove") {remove();}
            else if (s == "check") {check();}
            else if (s == "toggle") {toggle();}
        }
    }

    return 0;
}



// 선생님 풀이
#include <bits/stdc++.h>
using namespace std;
int n, m, x;
char s[11];
int main() {
    scanf(" %d", &m);
    for (int i = 0; i < m; i++) {
        scanf(" %s %d", &s, &x); 
        if (s[0]=='a' && s[1]=='d') n |= (1 << x);
        else if (s[0] == 'r') n &= ~(1 << x);
        else if (s[0] == 'c') printf("%d\n", (n&(1 << x)) ==0? 0: 1);
        else if (s[0] == 't') n ^=(1<<x);
        else if (s[0] == 'a' && s[1] == 'l') n = (1 << 21) - 1;
        else n = 0;
    }
}