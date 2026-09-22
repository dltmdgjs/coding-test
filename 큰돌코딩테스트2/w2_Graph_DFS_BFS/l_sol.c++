#include<bits/stdc++.h>
using namespace std;
#define prev kundol

int n, o, A, B, asum, bsum;
string s, prev; 

string print(int a){ 
    string d = "00" + to_string(a / 60); // 분은 몫
    string e = "00" + to_string(a % 60); // 초는 나머지
    return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2); 
}

// 개선점 1 : 나는 분과 초를 따로 관리했지만, 해설은 분을 전부 초로 변경하여 한번에 쉽게 계산 후, 다시 분으로 변환함.
// 즉 시간과 같이 단위가 있는 것은 작은 단위로 변환 후 계산하는 것이 편리함.

// 이 방식은 시간뿐 아니라 꽤 자주 써.
// - 시간 → 초
// - 길이 → mm 또는 cm
// - 무게 → g
// - 화폐 → 원 또는 센트
// - 각도 → 필요하면 도 단위 하나로 통일
// - 날짜/시간 → 특정 기준 시점부터의 초나 일수
// 그리고 계산이 끝난 뒤 출력할 때 다시 원하는 단위로 변환하면 돼.

// 핵심 : 입력은 여러 단위여도 계산은 하나의 단위로 통일하고, 출력할 때 다시 나눈다.
int changeToInt(string a){
    return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
}

void go(int &sum, string s){ 
    sum += (changeToInt(s) - changeToInt(prev)); 
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL); 
    cin >> n; 
    for(int i = 0; i < n; i++){
        cin >> o >> s; 
        if(A > B)go(asum, s);
        else if(B > A)go(bsum, s);
        o == 1 ? A++ : B++;
        prev = s; 
    } 
    if(A > B)go(asum, "48:00");
    else if(B > A)go(bsum, "48:00"); 
    cout << print(asum) << "\n"; 
    cout << print(bsum) << "\n";
}
