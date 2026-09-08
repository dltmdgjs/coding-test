// 다익스트라 알고리즘

// BFS의 경우는 가중치가 같을 경우의 최단거리를 구할 수 있었음

// 다익스트라, 벨만포드, 플로이드 워셜은 가중치가 달라도 최단거리를 구할 수 있음.

// 다익스트라 알고리즘은 한 정점에서 다른 모든 정점까지의 최단 거리를 구하는 알고리즘임.
// 다익스트라 알고리즘은 간선의 가중치가 반드시 양수여야 함.

// 동작 방식
// 1. 현 위치(A)에서 갈 수 있는 모든 곳(B)을 살펴본다.
// 2. 시작 위치에서 A까지의 거리(계산된 값) + A에서 B까지의 가중치를 계산해,
// 3. 그 값이 원래 시작위치에서 B까지의 거리보다 작다면 그 값으로 갱신함. (완화, relaxation)
// 4. 모든 곳을 다 조사했으면 다음 노드로 방문하지 않은 곳 중 거리가 가장 짧은 노드를 선택. 반복

// 공식 코드 - 기존에 알던 거리보다 cur를 거쳐 가는 거리가 더 짧으면 갱신함.
// if (dist[next] > dist[cur] + cost) {
//     dist[next] = dist[cur] + cost;
// }

// 실전에선 우선순위 큐를 사용함. - 다음 노드 방문 선택 시, 가장 짧은 노드를 빠르게 찾아야 하기 떄문.
// (V+E)logV

// 이중 for문을 사용하여도 구현 가능함 
// V^2

// 공식 코드
// priority_queue<
//     pair<int, int>,           // 큐에 저장할 자료형: {거리, 정점 번호}
//     vector<pair<int, int>>,   // 내부에서 데이터를 저장할 컨테이너
//     greater<pair<int, int>>   // 작은 값이 먼저 나오게 됨(최소 힙)
// > pq;

// 아래는 예시 코드임.

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int n = 4;

    vector<vector<pair<int, int>>> graph(n + 1);
    // graph[a] = {b, cost}
    // graph[a]에 {b, cost} 저장
    // → a번 정점에서 b번 정점으로 가는 간선의 비용이 cost
    // → n + 1인 이유는 정점 번호를 1번부터 n번까지 사용하기 위해서
    graph[1].push_back({2, 2});
    graph[1].push_back({3, 5});
    graph[2].push_back({3, 1});
    graph[2].push_back({4, 4});
    graph[3].push_back({4, 1});

    vector<int> dist(n + 1, INT_MAX);

    priority_queue<
        pair<int, int>, // {거리, 정점 번호}
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    // 중간에 거리 갱신되어도, 
    // → pq 안의 기존 값 수정 X
    // → 새로운 {더 짧은 거리, 정점} 추가
    // → 나중에 오래된 값은 continue로 무시

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int curDist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (curDist > dist[cur]) {
            continue;
        }

        for (auto [next, cost] : graph[cur]) {
            int newDist = curDist + cost;

            if (newDist < dist[next]) {
                dist[next] = newDist;
                pq.push({newDist, next});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << '\n';
    }
}