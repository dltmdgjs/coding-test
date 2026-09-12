#include<bits/stdc++.h> 
using namespace std;  
typedef long long ll;  

int n, k, temp, psum[100001], ret = -10000000; 


// 개선점 1 : 누적합을 이용해서 구간합을 구할 수 있음. 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> n >> k; 

    for(int i = 1; i <= n; i++){
        cin >> temp; 
        // 누적합 계산
        psum[i] = psum[i - 1] + temp; 
    } 

    for(int i = k; i <= n; i++){
        // 누적합 - 누적합 = 구간합...
        ret = max(ret, psum[i] - psum[i - k]); 
    }

    cout << ret << "\n";
    return 0;
}
