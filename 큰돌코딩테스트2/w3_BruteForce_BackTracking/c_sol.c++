#include <bits/stdc++.h>
using namespace std;
int visited[54][54], a[54][54], n, l, r, sum, cnt; 
const int dy[]={-1,0,1,0};
const int dx[] ={0,1,0,-1}; 
vector<pair<int,int>>v;

// <내 코드와의 차이점>
//
// 1. 나는 BFS로 하나의 연합을 탐색하고,
//    해설은 DFS로 하나의 연합을 탐색함.
//    탐색 방식만 다를 뿐 연결된 국가를 찾는 원리는 동일함.
//
// 2. 나는 BFS에서는 연합에 속한 국가의 좌표만 v에 저장하고,
//    탐색이 끝난 뒤 move_human()에서 v를 다시 순회하여
//    전체 인구수의 합을 계산함.
//
//    해설은 DFS로 새로운 국가를 발견하는 순간
//    v에 좌표를 저장하는 동시에 sum에 인구수를 더함.
//    따라서 탐색과 인구수 합 계산을 동시에 수행함.
//
// 3. 나는 하루가 시작될 때 A를 temp로 복사한 뒤
//    인구 이동 결과를 temp에 반영하고,
//    하루의 모든 연합 처리가 끝난 뒤 다시 A로 복사함.
//
//    해설은 별도의 temp 배열 없이 연합을 찾은 직후
//    원본 배열 a의 값을 바로 수정함.
//    이미 처리한 국가는 visited로 다시 탐색하지 않으므로
//    이 문제에서는 바로 수정해도 문제가 없음.
//
// 4. 나는 bfs() 내부에서 시작 국가를
//    v와 queue에 추가하고 visited 처리함.
//
//    해설은 main에서 시작 국가의 visited, v, sum을 먼저 초기화하고
//    dfs()는 주변 국가를 탐색하는 역할만 수행함.
//
// 5. 두 코드 모두 연합의 크기가 2 이상이면
//    인구 이동이 발생했다고 판단함.
//    하루 동안 연합이 하나도 만들어지지 않으면 반복을 종료함.

void dfs(int y,int x){ 
    for(int i=0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(nx<0 || nx>=n || ny<0 || ny>=n || visited[ny][nx])continue;
        if(abs(a[ny][nx]- a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r){
            visited[ny][nx] =1;
            v.push_back({ny,nx});
            sum += a[ny][nx];
            dfs(ny,nx);
        }
    }
}


int main(){ 
    cin>>n>>l>>r;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }



    while(true){
        bool flag =0;
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]){
                    v.clear();
                    visited[i][j] = 1;
                    v.push_back({i,j});
                    sum = a[i][j];
                    dfs(i,j);
                    if(v.size() == 1) continue;  
                    for(pair<int,int> b : v){ 
                        a[b.first][b.second] = sum / v.size();
                        flag = 1;
                    }
                } 
            }
        }
        if(!flag) break;  
        cnt++;
    } 


    cout<< cnt << "\n";
    return 0;
}
