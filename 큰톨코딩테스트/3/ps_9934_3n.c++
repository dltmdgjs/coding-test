// 완전 이진 트리 - 실버 1
// 알고리즘 분류 : 트리, 재귀

#include <bits/stdc++.h>
using namespace std;

int k, n, a[2000];
vector<int> v[11];

void go (int idx, int level, int dist) {
    if (level > k) return;
    v[level].push_back(a[idx]);
    go(idx-dist, level+1, dist/2);
    go(idx+dist, level+1, dist/2);
}

int main() {
    cin >> k;
    n = pow(2, k);

    for (int i=1; i<n; i++) {
        cin >> a[i];
    }

    // level 1부터 탐색.
    go(n/2, 1, pow(2, k-2));

    for (int i=1; i<=k; i++) {
        for (auto j : v[i]) {
            cout << j << " ";
        }
        cout << '\n';
    }
    return 0;
}

// 완전이진트리
// - [depth = k] -> [노드 개수 n = 2^k - 1]

// 중위 순회한 완전이진트리를 1차원 배열로 줌
// ex)
//   1 2 3 4 5 6 7     idx
//   ---------------------------
//   1 6 4 3 5 2 7     array

//         3           level - 1, dist = 2
//     6       2       level - 2, dist = 1
//   1   4   5   7     level - 3

//   현재 위치에서 양 옆을 재귀적으로 탐색함. (dist : 다음 레벨로 탐색할 offset)



// 다른 풀이 방법
// - 오프셋 설정 대신 구간을 나누어서 풀이할 수 있음 (이진 탐색의 느낌)
        // void go(int start, int end, int level) {
        //     if (start > end) return;
        //     if (start == end) {
        //         v[level].push_back(a[start]);
        //         return;
        //     }
        //     int mid = (start + end) / 2;
        //     v[level].push_back(a[mid]);
        //     go(start, mid-1, level+1);
        //     go(mid+1, end, level);
        // }