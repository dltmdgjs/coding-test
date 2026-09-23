#include <bits/stdc++.h>
using namespace std; 


int a[104][104], visited[104][104];
int dy[] = {-1,0,1,0}, dx[] = {0,1,0,-1};   
int n, m, cnt, cnt2;
vector<pair<int,int> > v; // 외부 공기와 맞닿은 치즈를 임시 저장함.

// dfs
void go(int y,int x){
    // 빙믄 처리
    visited[y][x] = 1;

    // 외부와 닿은 치즈는 임시 저장.
    if(a[y][x] == 1){
        v.push_back({y,x});
        return; // 리턴 해야함. (더 탐색하면 치즈 내부까지 가기 때문에 안됨.)
    }

    // 4방 탐색. (dfs)
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue; 
        go(ny,nx);
    }

    return; // 리턴 해야함. (더 탐색하면 치즈 내부까지 가기 때문에 안됨.)
}


int main(){ 

    cin >> n >> m; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    while(true){ 
        // 초기화
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        v.clear(); 

        // 0,0 공기부터 탐색
        go(0,0); 
        cnt2 = v.size(); // 마지막에 녹일 치즈 수를 구하기 위해 필요

        // 외부와 닿은 치즈 녹이기
        for(pair<int, int> b : v){ 
            a[b.first][b.second] = 0;
        }

        // 치즈가 다 녹았는지 확인
        bool flag = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] != 0) flag = 1;
            }
        }

        cnt++;
        if(!flag) break;
    }

    cout << cnt << '\n' << cnt2 << '\n'; 
}
