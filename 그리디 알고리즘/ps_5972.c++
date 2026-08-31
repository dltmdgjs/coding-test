// 다익스트라 알고리즘.
#include <iostream>
#include <vector>
#include <queue>
#include <climits> // INT_MAX 사용을 위해 필요
using namespace std;

const int MAX = 50001; // 최대 노드 수

// 그래프는 인접 리스트 형태로 저장 (노드, 거리)
vector<pair<int, int>> graph[MAX];

// 거리 배열: dist[i] = 1번에서 i번까지의 최소 거리
int dist[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; // N: 노드 개수, M: 간선 개수
    cin >> N >> M;

    // M개의 간선 입력 받기
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // 양방향 그래프라면 두 방향 모두 저장
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    // 다익스트라 알고리즘.
    // 거리 배열 초기화 (처음엔 무한대)
    for (int i = 1; i <= N; i++) {
        dist[i] = INT_MAX;
    }

    // (거리, 노드)를 저장하는 우선순위 큐 (최소 힙)
    // greater<pair<int,int>> 사용 → 가장 짧은 거리부터 꺼냄 (정렬 과정이 없어도..)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 시작 노드: 1번
    dist[1] = 0;
    pq.push({0, 1}); // (거리 0, 노드 1)

    // 다익스트라 알고리즘 시작
    while (!pq.empty()) {
        int currentDist = pq.top().first;  // 현재 노드까지의 거리
        int currentNode = pq.top().second; // 현재 노드 번호
        pq.pop();

        // 이미 더 짧은 경로로 방문한 적이 있으면 스킵
        if (currentDist > dist[currentNode])
            continue;

        // 현재 노드와 연결된 모든 인접 노드 탐색
        for (auto &edge : graph[currentNode]) {
            int nextNode = edge.first;      // 인접 노드
            int weight = edge.second;       // 간선 가중치
            int nextDist = currentDist + weight; // 새로운 거리 후보

            // 더 짧은 경로이면 갱신, 다음으로 방문할 노드 후보로 추가
            if (nextDist < dist[nextNode]) {
                dist[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        }
    }

    // 결과 출력
    if (dist[N] == INT_MAX)
        cout << "-1\n"; // 1번에서 N번까지 갈 수 없는 경우
    else
        cout << dist[N] << '\n'; // 최소 비용 출력

    return 0;
}
