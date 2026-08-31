// 문제 : DFS와 BFS
// 알고리즘 분류 : DFS, BFS

#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

vector<set<int> > E;
bool visitedDFS[1001] = {false};
bool visitedBFS[1001] = {false};
queue<int> q;


void dfs(int V) {
    visitedDFS[V] = true;
    cout << V << " ";
    for (int i : E[V]) {
        if(!visitedDFS[i]) {
            dfs(i);
        }
    }
}

void bfs(int V) {
    visitedBFS[V] = true;
    q.push(V);
    cout << V << " ";
    while(!q.empty()) {
        int n = q.front();
        q.pop();
        for (int i : E[n]) {
            if (!visitedBFS[i]) {
                q.push(i);
                cout << i << " ";
                visitedBFS[i] = true;
            }
        }
    }
}


int main() {
    // 입력
    int N, M, V;
    cin >> N >> M >> V;
    E.resize(N+1);
    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        E[a].insert(b);
        E[b].insert(a);
    }
    // dfs
    dfs(V);

    cout << "\n";
    
    // bfs
    bfs(V);

    return 0;
}