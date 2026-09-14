// 주몽 - BOJ 1940

// 핵심 : 2개의 합이 특정 숫자를 넘기느냐..
// 조합을 사용.

#include <bits/stdc++.h>
using namespace std;


int N, M; // 재료의 개수, 갑옷을 만드는데 필요한 수
vector<int> v; // 갑옷
int result;

void combi(vector<int> &a, int start) {
    if (a.size() == 2) {
        int sum = a[0] + a[1];
        if (sum == M) result++;
        return;
    }

    for (int i=start+1; i<v.size(); i++) {
        a.push_back(v[i]);
        combi(a, i);
        a.pop_back();
    }
}

int main() {
    cin >> N >> M; 

    int k;
    for (int i=0; i<N; i++) {
        cin >> k;
        v.push_back(k);
    }

    vector<int> a;
    combi(a, -1);

    cout << result;
    return 0;
}