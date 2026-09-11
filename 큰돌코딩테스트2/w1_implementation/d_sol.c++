// 팰린드롬인지 확인하기 - BOJ 10988

#include<bits/stdc++.h>
using namespace std;   
string s, temp; // 개선점 1 : 변수명 목적에 맞게 작성하기.
int main(){
    cin >> s; 
    temp = s; 
    reverse(temp.begin(), temp.end());  // 개선점 2 : 자주쓰는 라이브러리 함수는 사용법을 암기하자. (파라미터 등)
    if(temp == s) cout << 1 << "\n"; 
    else cout << 0 << "\n"; 
      
    return 0; 
}
