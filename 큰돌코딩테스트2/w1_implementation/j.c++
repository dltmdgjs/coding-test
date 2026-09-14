// 패션왕 신해빈 - BOJ 9375

// 아래와 같이 복잡하게 분기해 풀 필요X. 경우의 수 공식만 알면 됨.
// sol 참조.

#include <bits/stdc++.h>
using namespace std;

// 종류별 분류 필요.
map<string, int> mp; // 종류이름과 각 종류의 의상 수.
vector<int> v; // 각 종류의 의상 수.
int n; // 케이스 수
int k; // 각 케이스의 의상 수.
int result;


void combi(vector<int> &a, int start, int t) {
    if (a.size() == t) {
        int mul = 1;
        for (int i : a) {
            mul *= i;
        }
        result += mul;
    }
    for (int i=start; i<v.size(); i++) {
        a.push_back(v[i]);
        combi(a, ++start, t);
        a.pop_back();
    }
}

void solve(int t) {
    // 입력
    for (int i=0; i<t; i++) {
        string name, type;
        cin >> name >> type;
        if (mp.find(type) != mp.end()) {
            mp[type]++;
        } else {
            mp[type] = 1;
        }
    }

    // 각각 하나씩 입는 경우의 수
    for (pair<string, int> p : mp) {
        result += p.second;
        // 각 종류의 의상 수만 벡터에 담음
        v.push_back(p.second);
    }

    // 2개 이상 씩 조합해서 입는 경우의 수.
    int numOfTypes = v.size(); // 종류의 수.
    // 계산 시작
    for (int i=2; i<=numOfTypes; i++) {
        vector<int> a;
        combi(a, 0, i);
    }

    cout << result << "\n";
}



int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        mp.clear();
        v.clear();
        result = 0;
        cin >> k;
        solve(k);
    }


    return 0;
}