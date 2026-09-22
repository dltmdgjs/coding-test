#include <bits/stdc++.h>
using namespace std;   

int n; 
vector<string> v; 
string s, ret;

void go(){   
    while(true){  
        // 개선점 1s.erase(iter)로 iter에 위치한 문자를 지울 수 있음.
        if(ret.size() && ret.front() == '0')ret.erase(ret.begin()); 
        else break;
    }
    if(ret.size() == 0) ret = "0"; 
    v.push_back(ret);
    ret = "";  
}

// 개선점 2 : 문자열로 되어진 숫자 정렬시 다음과 같이 비교함수 정의 필요함.
// 왜냐하면 문자열을 그냥 그대로 비교하게 되면 앞에서부터 1자씩 비교하기 때문임.
// 즉 12 가 115보다 크다고 판단되어버림 (쉽게 말해 사전순으로 정렬된다는 것임.)
// 그래서 문자열의 길이를 기준으로 비교하되, 같은 경우는 사전순 비교하면 되는 것임.
bool cmp(string a, string b){
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main () {
    cin >> n; 
    for(int i = 0; i < n; i++){
        cin >> s; 
        ret = "";
        for(int j = 0; j < s.size(); j++){
            if(s[j] < 65)ret += s[j];
            else if(ret.size()) go(); 
        }
        if(ret.size()) go(); // 개선점 3 : 문자열이 비어 있는지에 대한 판단은 s.size()로 확인하면됨.
    }
    sort(v.begin(), v.end(), cmp);
    for(string i : v)cout << i << "\n"; 
    return 0;
}
