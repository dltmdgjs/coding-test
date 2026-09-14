#include<bits/stdc++.h> 
using namespace std;  

int n, ret; 
string s; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n; 

    for(int i = 0; i < n; i++){
        cin >> s; 

        stack<char> stk;

        // 개선점 1 : 조건문에서 스택 사이즈를 체크하므로 1개를 먼저 넣을 필요X.
        // 따라서 향상된 for문을 사용해 간편히 표기 가능.
        for(char a : s){
            if(stk.size() && stk.top() == a)stk.pop();
            else stk.push(a); 
        } 

        if(stk.size() == 0)ret++;
    }

    cout << ret << "\n"; 
}
