// 플로이드 워셜 알고리즘

// BFS의 경우는 가중치가 같을 경우의 최단거리를 구할 수 있었음

// 다익스트라, 벨만포드, 플로이드 워셜은 가중치가 달라도 최단거리를 구할 수 있음.

// 모든 정점에서 모든 정점으로의 최단거리를 구하는 알고리즘.
// 음수 가중치가 있어도 가능하나, 음수 사이클이 존재해선 안된다.

// 핵심 개념: i - j로 가는 길목에 k가 있으면, i - k - j 로의 비용과 비교해 최소값을 선택해 갱신함.
// ----------------------------
// 현재 i → j 최단거리

// vs

// i → k 최단거리
// +
// k → j 최단거리
// ----------------------------

// 외우자 : 삼중 for문 k -> i -> j

// 아래는 예시 코드임.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    int n = 4;

    vector<vector<int>> dist(
        n + 1,
        vector<int>(n + 1, INF)
    );

    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    dist[1][2] = 4;
    dist[1][3] = 10;
    dist[2][3] = 3;

    // 핵심 코드
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
