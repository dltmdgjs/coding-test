// 문제 : 알고리즘 수업 - 너비 우선 탐색 2
// 알고리즘 분류 : BFS

// 큐를 이용해서 bfs를 구현한다. 
// 1. 첫 방문한 노드를 큐에 저장하고, 
// 2. 순차적으로 빼내서 그 노드의 인접노드를 하나씩 탐방한다(내림차순)
// 3. 첫 방문이면 큐에 저장한다.
// 4. 큐가 빌 때까지 반복한다.


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> E[200001];
bool visited[100001] = {false};
int order[100001] = {0};
queue<int> q;

void bfs(int R) {
    int count = 0;
    visited[R] = true;
    count++;
    order[R] = count;
    q.push(R);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : E[u]) {
            if (!visited[v]) {
                visited[v] = true;
                count++;
                order[v] = count;
                q.push(v);
            }
        }
    }
}

bool compare(int a, int b) {
    if (a > b) {
        return true;
    } 
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 입력
    int N, M, R;
    cin >> N >> M >> R;
    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    // 오름차순 정렬
    for (int i=1; i<=N; i++) {
        sort(E[i].begin(), E[i].end(), compare);
    } 

    // BFS 
    bfs(R);

    for (int i=1; i<=N; i++) {
        cout << order[i] << "\n";
    }
    return 0;
}