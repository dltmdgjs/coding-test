// 문제 : 알고리즘 수업 - 깊이 우선 탐색 1
// 알고리즘 분류 : DFS

// 1. N(정점 수), M(간선 수), I(시작 정점)를 입력 받는다. 이때 정점 수 만큼 방문확인용 boolean 배열을 만든다.
// 2. M만큼 반복해서 간선 정보를 입력받는다.(첫 숫자는 인덱스로 활용, 두번째 숫자는 그 인덱스에 저장)
// 3. 시작 정점 부터 DFS를 실행한다. (방문하는 경우 방문 처리(true)를 한다.)
// 4. 첫째 줄부터 N개의 줄에 정수를 한 개씩 출력한다. i번째 줄에는 정점 i의 방문 순서를 출력한다. 시작 정점의 방문 순서는 1이다. 시작 정점에서 방문할 수 없는 경우 0을 출력한다.
// N (5 ≤ N ≤ 100,000), 간선의 수 M (1 ≤ M ≤ 200,000), 시작 정점 R (1 ≤ R ≤ N)

#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<set<int> > v;
int N, M, R;
bool visited[100001] = {false};
int order[100001] = {0};


void dfs(int R, int& count) {
    order[R] = count;
    count++;
    visited[R] = true;
    for (int x : v[R]) {
        if (!visited[x]) {
            dfs(x, count);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 입력
    cin >> N >> M >> R;
    v.resize(N + 1); // 정점 수만큼 벡터 크기 설정
    for (int i=0; i<M; i++) {
        int node, linkedNode;
        cin >> node >> linkedNode;
        v[node].insert(linkedNode);
        v[linkedNode].insert(node);
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