// 숨바꼭질 4 - 골드 4
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, BFS, 역추적

#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int n, k, visited[MAX];
int pre[MAX];  // 현재 노드의 바로 이전 노드의 값을 저장함. -> 역추적

int main() {
    cin >> n >> k;

    queue<int> q;
    q.push(n);
    visited[n] = 1;
    while (q.size()) {
        int cur = q.front();
        q.pop();
        int x[3] = {cur+1, cur-1, cur*2};
        for (int i=0; i<3; i++) {
            int nx = x[i];
            if (nx < 0 || nx >= MAX) continue;
            if (visited[nx] == 0) {
                q.push(nx);
                visited[nx] = visited[cur] + 1;
                // 이전 노드의 값 저장 - 일종의 링크드 리스트
                pre[nx] = cur;
            }
        }
    }

    cout << visited[k]-1 << '\n';
    int i = k; stack<int> s;
    s.push(k);
    while (i != n) {
        s.push(pre[i]);
        i = pre[i];
    }
    
    while (s.size()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}

// reverse(v.begin(), v.end()) 를 이용해서 거꾸로 위치시킬 수 있음