#include<bits/stdc++.h> 
using namespace std;   

int n; 
string s, ori_s, pre, suf; 


int main(){
    cin >> n;
    cin >> ori_s;  

    // 개선점 1 : 하나씩 문자 검사가 아닌, 문자열 자르기 이용 s.substr(start, end);
    int pos = ori_s.find('*');  // '*' 의 위치
    pre = ori_s.substr(0, pos); // '*' 앞의 문자열
    suf = ori_s.substr(pos + 1); // '*' 뒤의 문자열

    for(int i = 0; i < n; i++){
        cin >> s; 
        // 애초에 크면 안되므로 NE 출력
        if(pre.size() + suf.size() > s.size()){
            cout << "NE\n";
        }else{
            // 앞쪽 뒷쪽이 같은지 비교.
            if(pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size())){
                cout << "DA\n";
            } 
            else {
                cout <<"NE\n";  
            }
        } 
    } 
    return 0;
} 
