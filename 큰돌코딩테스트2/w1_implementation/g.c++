// 한국이 그리울 땐 서버에  - BOJ 9996

#include <bits/stdc++.h>
using namespace std;

vector<string> v;
string p;
int N, p_len;

bool solve(string s) {
    int s_len = s.size();

    int ss=0, se=s_len-1;
    int ps=0, pe=p_len-1;

    // 바깥 껍질부터 검사
    while (true) {
        if (s[ss] == p[ps]) {
            ss++; ps++;
        } else if (p[ps] == '*') {
            ss++;
        } else {
            return false;
        }
        if (s[se] == p[pe]) {
            se--; pe--;
        } else if (p[pe] == '*') {
            se--;
        } else {
            return false;
        }

        if (ss >= se) {
            return true;
        }
    }
}

int main() {
    cin >> N;
    cin >> p; p_len = p.size();
    for (int i=0; i<N; i++) {
        string s; cin >> s;
        if (solve(s)) {
            cout << "DA" << "\n";
        } else {
            cout << "NE" << "\n";
        }
    }

    return 0;
}