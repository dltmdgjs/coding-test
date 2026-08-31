// 게리맨더링 - 골드 3
// 알고리즘 분류 : 수학, 그래프, 브루트포스, 조합, bfs, 비트마스킹, dfs

#include <bits/stdc++.h>
using namespace std;

int N, p[10];
vector<int> v[10];
int mn = 987654321;
bool flag; // 선거구를 나눌 수 있는지 확인


bool check(vector<int> t) {
    // 선거수 비어있으면 false
    if (t.empty()) return false;

    // bfs로 탐색 - connected component
    bool visited[10] = {false};
    queue<int> q;
    visited[t[0]] = true;
    q.push(t[0]);
    while(q.size()) {
        int u = q.front(); q.pop();
        for (int i : v[u]) {
            // 같은 선거구인지 체크
            bool isSameTeam = false;
            for (int m : t){
                if(m == i) {
                    isSameTeam = true; 
                    break;
                }
            }
            if (isSameTeam && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    // 탐색 결과, 선거구 내 모든 지역 방문했으면 true 반환
    for (int i : t) {
        if (!visited[i]) return false;
    }
    return true;
}

int main() {

    // 입력
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> p[i];
    }
    for (int i=0; i<N; i++) {
        int k; cin >> k;
        for (int j=0; j<k; j++) {
            int t; cin >> t;
            v[i].push_back(t-1);
        }
    }

    // 로직 시작 - 비트마스킹 - 경우의 수를 빠르게 탐색
    for (int i=1; i<(1<<N); i++) {

        // 선거구를 나누고, 각 선거구의 인구수 계산
        vector<int> a, b; int ra = 0, rb = 0;
        for (int j=0; j<N; j++) {
            if (i & (1<<j)) {
                a.push_back(j);
                ra += p[j];
            } else {
                b.push_back(j);
                rb += p[j];
            }
        }

        // 각 선거구의 연결성 체크
        if (check(a) && check(b)) {
            flag = true;
            mn = min(mn, abs(ra - rb));
        }
    }

    if (flag) {
        cout << mn;
    } else {
        cout << -1;
    }
    return 0;
}




// 다른 풀이
#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;  
int n, a[11], m, temp, ret = INF, comp[11], visited[11];
vector<int> adj[11]; 

pair<int, int> dfs(int here, int value){
    visited[here] = 1; 
    pair<int, int> ret = {1, a[here]}; 
    for(int there : adj[here]){
        if(comp[there] != value) continue; 
        if(visited[there]) continue; 
        pair<int, int> _temp = dfs(there, value); 
        ret.first += _temp.first; 
        ret.second += _temp.second;  
    }
    return ret; 
}  

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n; 
    for(int i = 1; i <= n; i++){
        cin >> a[i];  
    }
    for(int i = 1; i <= n; i++){
        cin >> m; 
        for(int j = 0; j < m; j++){
            cin >> temp; 
            adj[i].push_back(temp); 
            adj[temp].push_back(i); 
        } 
    }

    for(int i = 1; i < (1 << n) - 1; i++){
        fill(comp, comp + 11, 0);
        fill(visited, visited + 11, 0);
        int idx1 = -1, idx2 = -1; 
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){comp[j + 1] = 1; idx1 = j + 1;}
            else idx2 = j + 1; 
        }
        pair<int, int> comp1 = dfs(idx1, 1);
        pair<int, int> comp2 = dfs(idx2, 0);   
        if(comp1.first + comp2.first == n) ret = min(ret, abs(comp1.second - comp2.second)); 
    } 
    cout << (ret == INF ? -1 : ret)<< "\n";
}