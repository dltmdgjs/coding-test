#include<bits/stdc++.h>
using namespace std; 

int n, cnt[26]; 
string s, ret; 

int main(){
    cin >> n; 

    for(int i = 0; i < n; i++){
        cin >> s; 
        cnt[s[0] - 'a']++; // 개선점 1 : 문자를 숫자화 하면 맵을 쓰지 않고 간편히 배열에 저장가능. 특히 알파벳 문제에서 유용.
    } 

    for(int i = 0; i < 26; i++) {
        if(cnt[i] >= 5) {
            ret+=  i + 'a'; // 원상 복구시엔 다시 더해주면 됨.
        }
    }
    
    if(ret.size()) cout << ret << "\n"; 
    else cout << "PREDAJA" << "\n";
}
