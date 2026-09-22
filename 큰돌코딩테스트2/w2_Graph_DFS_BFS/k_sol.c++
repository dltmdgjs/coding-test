#include <bits/stdc++.h>
using namespace std;     
int n, a;


int main () {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> n; 
    
    
    for(int i = 0; i < n; i++){
        cin >> a; 
        int ret5 = 0; 
        for(int j = 5; j <= a; j *= 5){
            ret5 += a / j; // 난 왜 이해가 안되냐... 왜 원래수를 제곱수로 나누는 거지?
            // 몫의 의미를 다시 생각해봐야 함 (몫 = n이하 k의 배수의 개수)
        }
        cout << ret5 << "\n";
    } 
    return 0;
}
