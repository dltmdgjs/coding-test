// 벨만포드 알고리즘

// BFS의 경우는 가중치가 같을 경우의 최단거리를 구할 수 있었음
// 다익스트라, 벨만포드, 플로이드 워셜은 가중치가 달라도 최단거리를 구할 수 있음.


// 한 정점에서 모든 정점까지의 최단 경로를 구하는 알고리즘임.
// 음수 가중치, 음수 사이클이 존재하여도 가능함.


// 핵심 개념 : 모든 간선을 여러 번 반복해서 확인하면서 거리를 계속 갱신한다.
// 다익스트라는 현재 가장 가까운 정점을 골랐지만, 벨만 포드는 그냥 모든 간선을 본다.

// 핵심 코드
// if (dist[from] != INF && dist[to] > dist[from] + cost) {
//     dist[to] = dist[from] + cost;
// }
// from을 거쳐서 to로 가는 게 더 짧으면 갱신한다. 다익스트라와 거의 똑같음

// 모든 간선을 V-1번 반복하므로 느림.


// 동작 방식
// 1. 모든 간선에 대해 V-1 번 반복한다.
// 2. 음수 사이클을 확인한다. (갱신되지 않으면 없음, 갱신되면 있음.)


// 아래는 예시 코드임.
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

struct Edge {
    int from;   // 출발 정점
    int to;     // 도착 정점
    int cost;   // 간선 비용
};

int main() {
    int V = 3;  // 정점 개수
    int E = 3;  // 간선 개수
    int start = 1;

    vector<Edge> edges;

    // 간선 정보
    edges.push_back({1, 2, 4});
    edges.push_back({1, 3, 5});
    edges.push_back({2, 3, -10});

    const long long INF = numeric_limits<long long>::max();

    // dist[i] = 시작점에서 i번 정점까지의 최단거리
    vector<long long> dist(V + 1, INF);

    dist[start] = 0;

    // 정점 개수 - 1번 반복
    for (int i = 1; i <= V - 1; i++) {

        // 모든 간선을 확인
        for (const auto& edge : edges) {

            int from = edge.from;
            int to = edge.to;
            int cost = edge.cost;

            // 시작점에서 from까지 갈 수 없는 경우
            if (dist[from] == INF) {
                continue;
            }

            // from을 거쳐 to로 가는 것이 더 짧으면 갱신
            if (dist[to] > dist[from] + cost) {
                dist[to] = dist[from] + cost;
            }
        }
    }

    // 음수 사이클 확인
    bool negativeCycle = false;

    for (const auto& edge : edges) {

        int from = edge.from;
        int to = edge.to;
        int cost = edge.cost;

        if (dist[from] == INF) {
            continue;
        }

        // V-1번 돌았는데도 또 갱신된다면 음수 사이클 존재
        if (dist[to] > dist[from] + cost) {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle) {
        cout << "음수 사이클이 존재합니다.\n";
    } else {
        for (int i = 1; i <= V; i++) {

            if (dist[i] == INF) {
                cout << i << "번 정점: 도달 불가\n";
            } else {
                cout << i << "번 정점까지 최단거리: "
                     << dist[i] << '\n';
            }
        }
    }

    return 0;
}