#include<bits/stdc++.h>
using namespace std;


int n, r, temp, root;
vector<int> adj[54];


// 탐색
int dfs(int here){
    int ret = 0; // 리프 노드 수
    int child = 0; // 자식 노드 수

    for(int there : adj[here]){
        if(there == r) continue; // r노드 이면 더 이상 탐색 X (자르기)
        ret += dfs(there); // 탐색해, 리프노드 수를 더함
        child++;
    }

    if(child == 0) return 1; // 자식이 없으므로 리프노드임. 1반환.
    return ret;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(temp == -1)root = i; // 부모 노드가 -1이면 i노드를 루트로 함.
        else adj[temp].push_back(i); // temp라는 부모 노드에 i라는 자식을 달아줌.
    }
    
    cin >> r;
    if(r == root){ // 조기 종료
        cout << 0 << "\n";
        return 0;
    }
    
    cout << dfs(root) << "\n";
    return 0;
}
