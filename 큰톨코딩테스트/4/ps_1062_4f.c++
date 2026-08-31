// 가르침 - 골드 4
// 알고리즘 분류 : 브루트 포스, 비트마스킹, 백트래킹


#include <bits/stdc++.h>
using namespace std;

int N, K, mx = -1;
vector<string> v;
bool visited[26];

void check() {
    int cnt = 0; 
    for (string s : v) {
        bool flag = true;
        for (int i=0; i<s.size(); i++) {
            if (!visited[(s[i]-'a')]) {flag = false; break;}
        }
        if (flag) cnt++; 
    }
    mx = max(mx, cnt);
}

void combi(int start, int cnt) {
    if (cnt == K) {
        // 체크
        check();
        return;
    }
    for (int i=start; i<26; i++) {
        if (i==0 || i==2 || i==8 || i==13 || i==19) continue;
        visited[i] = true;
        combi(i+1, cnt+1);
        visited[i] = false;
    }
}

int main() {
    cin >> N >> K;
    for (int i=0; i<N; i++) {
        string s; cin >> s;
        v.push_back(s);
    }

    if (K < 5) {cout << 0; return 0;}

    visited[0] = true;visited[2] = true;visited[8] = true;visited[13] = true;visited[19] = true;

    vector<int> b;
    combi(0, 5);

    cout << mx;
    return 0;
}



// 다른 풀이 - 비트마스킹 이용
#include <bits/stdc++.h>
using namespace std;
int n, m, words[51];
string s; 
int count(int mask) {
    int cnt = 0;
    for (int word : words) { 
        if(word && (word & mask) == word)cnt++; 
    }
    return cnt;
}
int go(int index, int k, int mask) {
    if (k < 0) return 0;
    if (index == 26) return count(mask); 
    int ret = go(index+1, k-1, mask | (1 << index)); 
    if (index != 'a'-'a' && index != 'n'-'a' && index != 't'-'a' && index != 'i'-'a' && index != 'c'-'a') {
        ret = max(ret, go(index+1, k, mask)); 
    }
    return ret;
}
int main() { 
    cin >> n >> m; 
    for (int i=0; i<n; i++) { 
        cin >> s;
        for (char str : s) {
            words[i] |= (1 << (str - 'a'));
        }
    }
    cout << go(0, m, 0) << '\n';
    return 0;
}