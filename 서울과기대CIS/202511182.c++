// 여행자 문제 - 25111 - NP완전탐색(근사해)
// 일반 dfs 이용

#include <iostream>
#include <vector>
using namespace std;

int n, k; // 도시 수, 상한값
vector<vector<int>> w; // 도시 간 거리 저장 배열
vector<bool> used; // 도시 방문 여부
int best = 1e9; // 최소 비용

// 현재 도시, 방문한 도시 수, 지금까지의 거리
void dfs(int cur, int depth, int cost) {
    // 모든 도시를 다 방문한 경우 
    if (depth == n - 1) {
        if (w[cur][0] != 0) { // 현재 도시에서 시작 도시로 돌아갈 수 있으면, 
            // [현재까지의 최소비용]과 [지금까지의 거리 + 돌아가는 거리] 중 최소값으로 갱신
            best = min(best, cost + w[cur][0]); 
        }
        return;
    }

    // 다음 방문 도시 선택 - cur에서 가능한 경로 모두 탐색
    for (int next = 1; next < n; next++) {
        if (!used[next] && w[cur][next] != 0) { // 방문하지 않은 도시이면서, 길이 있는 경우 방문함.
            used[next] = true; // 방문 처리
            dfs(next, depth + 1, cost + w[cur][next]); // 재귀 호출(다음 도시에서부터 탐색)
            used[next] = false; // 탐색이 끝나면 방문 해제(다른 경로로 시도하기위함)
        }
    }
}

int main() {
    cin >> n >> k;
    w.assign(n, vector<int>(n)); // n x n 배열 w 생성
    used.assign(n, false); // n 배열 used 생성

    // 입력
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> w[i][j];

    // 시작 도시 = 0
    used[0] = true; // 0번 도시 방문 처리
    dfs(0, 0, 0);
    if (best > k) cout << -1;
    else cout << best;
    return 0;
}



// #include <bits/stdc++.h>
// using namespace std;

// int N;
// long long K;
// long long cost[20][20];
// bool visited[20];
// long long answer = LLONG_MAX;

// void dfs(int curr, int count, long long sum) {
//     // 현재까지 비용이 K를 초과하면 더 갈 필요 없음
//     if (sum > K) return;

//     // 모든 도시를 방문한 경우
//     if (count == N) {
//         // 다시 1번 도시(=0)로 돌아오는 비용이 있는지 확인
//         if (cost[curr][0] != 0) {
//             long long total = sum + cost[curr][0];
//             if (total <= K) {
//                 answer = min(answer, total);
//             }
//         }
//         return;
//     }

//     // 다음 도시 선택
//     for (int nxt = 0; nxt < N; nxt++) {
//         if (!visited[nxt] && cost[curr][nxt] != 0) {
//             visited[nxt] = true;
//             dfs(nxt, count + 1, sum + cost[curr][nxt]);
//             visited[nxt] = false;
//         }
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin >> N >> K;

//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             cin >> cost[i][j];
//         }
//     }

//     // 1번 도시 = index 0
//     visited[0] = true;
//     dfs(0, 1, 0);

//     if (answer == LLONG_MAX) cout << -1;
//     else cout << answer;

//     return 0;
// }
