#include <bits/stdc++.h>
using namespace std;

const int n = 6;
vector<int> adj[6];
int visited[6];

void dfs(int u) {
    visited[u] = 1;
    cout << u << '\n';
    for(int each : adj[u]) {
        if (visited[each] == 0) {
            dfs(each);
        }
    }
    cout << "노드" << u << "로부터의 호출이 종료됨" << '\n';
    return;
}

int main() {
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[2].push_back(5);
    adj[1].push_back(3);
    dfs(1);

    return 0;
}