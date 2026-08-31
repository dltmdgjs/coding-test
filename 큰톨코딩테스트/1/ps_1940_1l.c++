// 주몽 - 실버 4
// 알고리즘 분류 : 정렬, 투 포인터

#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
map<int, int> un;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    cin >> m;

    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        un.insert({a, 1});
        // (m-a) != a 
        // [m의 절반인 수는 안되도록 해야함. 고유번호이기 때문에 2개 존재 X]
        if (un.find(m-a)!=un.end() && (m-a) != a) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}

// 조합으로 풀 수도 있음 (nC2) - 이중 중첩문 활용(2개 뽑기 때문에..) 또는 재귀함수 활용(combi())