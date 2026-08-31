// # 여행자 문제 25111 - NP완전탐색(근사해)

// 비트 마스킹 이용, dp로 중복계산 방지

#include <iostream>
#include <cstring>
using namespace std;

#define INF 987654321;

int n,k,map[16][16];
int dp[16][1<<16]; // 각 도시에서 방문한 도시 상태를 저장(비트 이용)

int dfs(int cur, int visit){ // 현재도시와 지금까지 방문한 도시
    
    // 모든 도시를 방문했는지 확인함.
    if (visit == (1<<n)-1){ // 모든 도시를 방문했으면,
        if(map[cur][0] == 0) return INF; // 현재도시에서 출발점으로 돌아갈 길이 없는 경우 INF를 반환함.
        return map[cur][0]; // 현재 도시에서 출발점으로 가는 비용을 반환함.
    }
    
    // 이미 계산된 DP값이면,
    if (dp[cur][visit] != -1)
        return dp[cur][visit]; // 중복 계산할 필요 없으므로 바로 반환함.
    
    // 다음 방문할 도시를 탐색함.
    dp[cur][visit] = INF; // dp 초기화
    for (int i=0; i<n; i++){
        if (map[cur][i]==0) continue; // 길이 이어져 있지 않은 경우 이 도시를 선택 X
        if ((visit & (1<<i)) == (1<<i)) continue; // 이미 방문한 경우 이 도시를 선택 X
        // i도시를 방문하고, dfs재귀호출로 i도시부터 이후도시들로의 경로 비용을 DFS로 계산함.
        dp[cur][visit] = min(dp[cur][visit], map[cur][i] + dfs(i, visit | 1<<i));
        // dfs시 visit갱신(i도시를 방문했다고 표시함.)
    }
    
    // 최종 최소 비용 반환함.
    return dp[cur][visit];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    // 입력
    cin >> n >> k;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>map[i][j];
        }
    }
    
    memset(dp, -1, sizeof(dp)); // dp배열 -1로 초기화

    // 출력
    int result = dfs(0,1); // 0번 도시에서 시작, visit = 1 (000...1)
    if (result<=k) {
        cout << result;
    } else {
        cout << -1;
    }

    return 0;
}

// 비트 마스킹이란?
// 정수의 비트 하나하나를 상태 저장에 활용하는 기법임.
// 이 코드에서는 어떤 도시를 방문했는지 정수 하나로 저장함 (방문 = 1, 미방문 = 0)
// 비트가 1101(=13)이라면 3,2,0번 도시를 방문한 것임. 즉 visit = 13이라는 한 숫자만으로 방문 상태 전체를 저장할 수 있음.
// 자주쓰는 연산 - visit & (1<<i) [i번 도시를 방문했는지 체크함]
//            - (1<<n)-1 [모든 도시 방문 여부 확인시 사용, visit과 같은지 확인]

// dp 배열의 의미
// dp[cur][visit]
// - cur : 현재 도시, visit : 지금까지 방문한 도시들(비트마스크)
// - 이 상태에서 남은 도시를 모두 방문하고 다시 0으로 가는 최소 비용
// -> 같은 상태를 한 번 계산하면 다시 계산할 필요 없음.(중복계산 제거)

