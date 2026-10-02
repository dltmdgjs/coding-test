// <이 문제에서 개선할 점>
//
// 1. 괄호의 모든 배치를 직접 만들려고 하지 말고,
//    현재 연산에서
//    - 그냥 계산하는 경우
//    - 오른쪽 연산을 먼저 계산해 괄호를 친 경우
//    두 가지로 DFS 분기하는 방식으로 생각할 것.
//
// 2. 문자열 구조가
//    숫자 - 연산자 - 숫자 - 연산자 ...
//    로 고정되어 있으므로,
//    인덱스를 기준으로 숫자와 연산자를 바로 접근할 수 있음.
//
// 3. 괄호를 사용한 경우에는 다음 연산까지 이미 처리한 것이므로
//    DFS 인덱스를 더 많이 건너뛰어야 함.
//
// 4. 이 문제는 계산식 문제처럼 보이지만,
//    실제로는 "괄호를 칠지 말지 선택하는 완전탐색 문제"로 보는 것이 핵심.
//
// 5. N이 작기 때문에 모든 가능한 경우를 DFS로 탐색해도 충분함.

#include <bits/stdc++.h>
using namespace std;  

vector<int> num; // 숫자 벡터
vector<char> oper_str; // 연산자 벡터
int n, ret = -987654321; 
string s; // 식

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);   
} 

// 계산함수
int oper(char a, int b, int c){
    if(a == '+') return b + c; 
    if(a == '-') return b - c; 
    if(a == '*') return b * c;  
} 

void go(int here, int _num){
    // 숫자의 끝에 도달하면 최댓값 갱신.
    if(here == num.size() - 1){ 
        ret = max(ret, _num); 
        return;
    }  

    // 계산하기(괄호가 있다고 생각)
    go(here + 1, oper(oper_str[here], _num, num[here + 1])); // 현재와 다음을 계산하고 다음으로 넘어감

    // 계산안하기(괄호가 없다고 생각)
    if(here + 2 <= num.size() - 1){
        int temp = oper(oper_str[here + 1], num[here + 1], num[here + 2]); // 현재 다음 값을 계산 (바로 다음에 괄호가 있다고 생각)
        go(here + 2, oper(oper_str[here], _num, temp));  // 현재와 그 다음 괄호를 계산하고 다음다음으로 넘어감.
    } 

    return;
} 

int main(){
    fastIO();
    cin >> n;  
    cin >> s; 

    // 숫자, 연산자 구분해서 벡터에 각각 저장함.
    for (int i = 0; i < n; i++){
        if(i % 2 == 0) num.push_back(s[i] - '0');
        else oper_str.push_back(s[i]);
    } 

    go(0, num[0]);

    cout << ret << "\n";

    return 0;
} 
