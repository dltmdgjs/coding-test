// 문제 : 알고리즘 수업 - 깊이 우선 탐색 2
// 알고리즘 분류 : DFS

// 24479번 문제와 달리 내림차순으로 방문함.


#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[100001];
int N, M, R;
bool visited[100001] = {false};
int order[100001] = {0};


void dfs(int R, int& count) { // 참조형으로 count를 받아서 순서를 저장한다. (값의 변경이 일어나기 때문.)
    order[R] = count;
    count++;
    visited[R] = true;
    for (int x : v[R]) {
        if (!visited[x]) {
            dfs(x, count);
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
    cin >> N >> M >> R;
    for (int i=0; i<M; i++) {
        int node, linkedNode;
        cin >> node >> linkedNode;
        v[node].push_back(linkedNode);
        v[linkedNode].push_back(node); // 양방향 그래프(무방향 그래프)
    }

    // 내림차순 정렬
    for (int i=1; i<=N; i++) {
        sort(v[i].begin(), v[i].end(), compare);
    }

    int count = 1;
    // DFS
    dfs(R, count);

    // 출력
    for (int i=1; i<=N; i++) {
        cout << order[i] << "\n";
    }

    return 0;
}