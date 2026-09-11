#include<bits/stdc++.h>
using namespace std;   
string s; 
int main(){
    
    getline(cin, s); // 개선점 1 : 공백 포함 문자열은 getline(cin, s)를 사용할 것.


    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 65 && s[i] < 97){
            if(s[i] + 13 > 90) s[i] = s[i] + 13 - 26;  // 개선점 2 : 공식 개선 필요.
            else s[i] = s[i] + 13;  
        }else if(s[i] >= 97 && s[i] <= 122){
            if(s[i] + 13 > 122)s[i] = s[i] + 13 - 26; 
            else s[i] = s[i] + 13;  
        }
        cout << s[i];  
    } 
    return 0; 
}
