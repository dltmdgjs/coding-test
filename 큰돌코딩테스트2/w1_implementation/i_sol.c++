#include<bits/stdc++.h>
using namespace std;
int n, m;
string s; 
map<string, int> mp;
map<int, string> mp2;
string a[100004];
int main(){  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m; 

    for(int i = 0; i < n; i++){
        cin >> s; 
        mp[s] = i + 1;  
        mp2[i + 1] = s; 
        a[i + 1] = s;
    }

    // 개선점 1 : atoi(), stoi() 사용방법 익히기
    // 둘다 문자열 -> 숫자 변환 이지만 차이가 있음.
    // atoi(char [] s) -> 잘못된 값 입력 시, 0반환. -> 이 문제에선 이 특성을 이용해 문자열인지 숫자인지 검사하는 기능으로 활용
    // stoi(string s) -> 잘못된 값 입력 시, 예외 발생


    for(int i = 0; i < m; i++){
        cin >> s; 
        if(atoi(s.c_str()) == 0){ // 검사
            cout << mp[s] << "\n";
        }else{
            cout << a[atoi(s.c_str())] << "\n"; // string은 c_str() 함수로 char[]로 변환 가능함.
            //cout << mp2[atoi(s.c_str())] << "\n"; 
        }
    } 
}
