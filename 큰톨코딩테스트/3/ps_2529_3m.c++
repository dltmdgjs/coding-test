// 부등호 - 실버 1
// 알고리즘 분류 : 브루트포스, 백트래킹

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int k;
char a[10];
ll mx = 0, mn = 9999999999;

bool comp(char sign, int a, int b) {
    if (sign == '>') {
        return a > b;
    } else if (sign == '<') {
        return a < b;
    }
}

bool check(vector<int> b) {
    for (int i=0; i<k; i++) {
        if (!comp(a[i], b[i], b[i+1])) {
            return false;
        }
    }
    return true;
}

void combi(int start, vector<int> b) {
    if (b.size() == k+1) {
        // logic - 순열 생성해 부등호 검사
        do {
            if (check(b)) {
                string cur_s = "";
                for (int i=0; i<k+1; i++) {
                    cur_s += to_string(b[i]);
                }
                ll cur_i = stoll(cur_s);
                // max, min 갱신
                mn = min(mn, cur_i);
                mx = max(mx, cur_i);

            }
        } while (next_permutation(b.begin(), b.end()));
        return;
    }
    for (int i=start; i<10; i++) {
        b.push_back(i);
        combi(i+1, b);
        b.pop_back();
    }
}

int main() {

    cin >> k;
    for (int i=0; i<k; i++) {
        cin >> a[i];
    }

    vector<int> v;
    combi(0, v);

    string r_max = to_string(mx);
    string r_min = to_string(mn);
    if (r_max.size() < k+1) {
        string temp = "0";
        temp += r_max;
        r_max = temp;
    }
    if (r_min.size() < k+1) {
        string temp = "0";
        temp += r_min;
        r_min = temp;
    }

    cout << r_max << '\n';
    cout << r_min << '\n';

    return 0;
}

// 10! == 362만...

// 다른 풀이 - dfs(완전탐색, 재귀(dfs) + 원복)
        // #include <iostream>
        // #include <vector>
        // using namespace std;

        // int k;
        // pair<string, string> ans = {"", ""};

        // vector<char> a;
        // vector<int> n;
        // vector<bool> visited(10, false);

        // void dfs() {
        //   // n의 size가 필요한 숫자 개수(k+1)이면
        //   // -> min, max 갱신
        //   if (n.size() == k + 1) {
        //     string s = "";
        //     for (int v : n) {
        //       s += v + '0';
        //     }
        //     // 순서대로 방문을 하므로 처음의 것이 min, 맨 나중의 것이 max임
        //     if (ans.second == "") {
        //       ans.second = s;
        //     }
        //     ans.first = s;
        //   }
        //   // 아직 아닌 경우 -> 방문하지 않은 숫자를 방문(재귀호출)
        //   else {
        //     for (int i = 0; i < 10; i++) {
        //       if (!visited[i]) {
        //         if ((a[n.size() - 1] == '<' && n.back() < i) 
        //             || (a[n.size() - 1] == '>' && n.back() > i)) {
        //           visited[i] = true;
        //           n.push_back(i);
        //           dfs();
        //           n.pop_back();
        //           visited[i] = false;
        //         }
        //       }
        //     }
        //   }
        // }

        // int main() {
        //   // 입력
        //   cin >> k;
        //   a.resize(k);
        //   for (int i = 0; i < k; i++) {
        //     cin >> a[i];
        //   }

        //   // 방문 시작
        //   for (int i = 0; i < 10; i++) {
        //     visited[i] = true;
        //     n.push_back(i);
        //     dfs();
        //     n.pop_back();
        //     visited[i] = false;
        //   }

        //   cout << ans.first << endl;
        //   cout << ans.second << endl;

        //   return 0;
        // }