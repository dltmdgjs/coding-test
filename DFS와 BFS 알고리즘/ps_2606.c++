// 문제 : 바이러스
// 알고리즘 분류 : DFS, BFS

// 이 문제는 BFS또는 DFS로 노드를 하나씩 탐색해 나가면 된다.
// 아래는 재귀함수로 DFS를 구현한 코드이다.

#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<set<int> > E;
bool visited[101] = {false};
int count = 0;

// 오름차순으로 방문
void dfs(int R, int& count) {
    visited[R] = true;
    count++;
    for (int x : E[R]) {
        if (!visited[x]) {
            dfs(x, count);
        }
    }
}

int main() {
    // 입력
    int N, M;
    cin >> N >> M;
    E.resize(N+1);
    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        E[a].insert(b);
        E[b].insert(a);
    }
    
    int count = 0;
    dfs(1, count);

    cout << count-1 << "\n";
    return 0;
}