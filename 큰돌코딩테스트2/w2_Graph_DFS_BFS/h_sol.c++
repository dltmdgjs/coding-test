#include <bits/stdc++.h>
using namespace std;  

string s; 
int lcnt, vcnt; 

bool isVowel(int idx){
    return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

int main () { 

    while(true){
        // 개선점 1 : 몇회 입력인지 주어지지 않은 경우의 입력을 받는 방법
        cin >> s; 
        if(s == "end")break; // 이렇게 end인지 검사해야함.

        lcnt = vcnt = 0;
        bool flag = 0;
        bool is_include_v = 0;
        int prev = -1;

        for(int i = 0; i < s.size(); i++){
            int idx = s[i]; 
            if(isVowel(idx)) {
                lcnt++, vcnt = 0, is_include_v = 1;
            } else {
                vcnt++, lcnt = 0;
            }
            if(vcnt == 3 || lcnt == 3) flag = 1; 
            if(i >= 1 && (prev == idx) && (idx != 'e' && idx != 'o')){
                flag  = 1;
            } 
            prev = idx;
        }  

        if(is_include_v == 0) flag = 1;

        if(flag) cout << "<" << s << ">" << " is not acceptable.\n";
        else cout << "<" << s << ">" << " is acceptable.\n";
    } 
    return 0;
}
