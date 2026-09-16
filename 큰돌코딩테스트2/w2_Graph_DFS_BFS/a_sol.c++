#include<bits/stdc++.h>
using namespace std; 



const int max_n = 104; 
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1}; 
int n, m, a[max_n][max_n], visited[max_n][max_n], y, x; 



int main(){ 
    scanf("%d %d", &n, &m); 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &a[i][j]); // 개선점 1 : c스타일 코드로 간편히 한글자씩 입력받음.
        }
    } 


    queue<pair<int, int>> q;  
    visited[0][0] = 1;  // 차이점 1 : 원본 배열 보존을 위해 '방문배열'을 따로 둠.
    q.push({0, 0});  

    while(q.size()){
        tie(y, x) = q.front(); // 개선점 2 : pair저장을 위해 tie() 사용.
        q.pop();  
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i]; 
            int nx = x + dx[i]; 
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0) continue; 
            if(visited[ny][nx]) continue; 
            visited[ny][nx] = visited[y][x] + 1; // '방문여부 + 거리' 메커니즘은 같음, 단지 원본 보존을 위해 사용.
            q.push({ny, nx}); 
        } 
    }

    printf("%d", visited[n - 1][m - 1]); 
    return 0;
}  
