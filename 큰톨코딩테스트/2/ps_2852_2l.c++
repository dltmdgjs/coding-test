// NBA 농구 - 실버 3
// 알고리즘 분류 : 구현, 문자열

// 내 풀이
#include <bits/stdc++.h>
using namespace std;

int N;
int p1, p2;
vector<pair<int, pair<int, int>>> v; // {팀 번호, 득점 시간}
int MM1, SS1, MM2, SS2; // 각 팀의 이기고 있던 시간 합


void printResult(int MM, int SS) {
    string r = "";
    if (MM < 10) {
        r+="0";
    }
    r+=to_string(MM);
    r+=":";
    if (SS < 10) {
        r+="0";
    }
    r+=to_string(SS);
    cout << r << '\n';
}

int main() {

    cin >> N;

    for (int i=0; i<N; i++) {
        int a; string b;
        cin >> a >> b;

        int mm = stoi(b.substr(0,2));
        int ss = stoi(b.substr(3,2));

        v.push_back({a, {mm, ss}});
    }
    v.push_back({0, {48, 0}});

    if (v[0].first == 1) {
        p1++;
    } else {
        p2++;
    }

    for (int i=1; i<=N; i++) {
        int m1 = v[i].second.first - v[i-1].second.first;
        int s1 = v[i].second.second - v[i-1].second.second;
        if (s1 < 0) {
            m1--;
            s1 = 60 + s1;
        }

        if (p1 > p2) {
            MM1 += m1;
            SS1 += s1;
        } else if (p1 < p2) {
            MM2 += m1;
            SS2 += s1;
        }

        if (v[i].first == 1) {
            p1++;
        } else if (v[i].first == 2){
            p2++;
        }
    }

    if (SS1 > 60) {
        MM1 += SS1 / 60;
        SS1 = SS1 % 60;
    }
    if (SS2 > 60) {
        MM2 += SS2 / 60;
        SS2 = SS2 % 60;
    }

    printResult(MM1, SS1);
    printResult(MM2, SS2);

    return 0;
}

// ---------------------------------------------------------------------------

// 하나의 단위로 통일할 것 -> 초로 통일
// prev 변수를 사용해 입력과 동시에 로직 처리 가능 (prev는 define 해줘야 함.)

// 다른 풀이
#include<bits/stdc++.h>
using namespace std;
#define prev kundol

int n, o, A, B, asum, bsum;
string s, prev; 

string print(int a){ 
    string d = "00" + to_string(a / 60); 
    string e = "00" + to_string(a % 60); 
    return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2); 
}

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
        if(A > B) go(asum, s);
        else if(B > A) go(bsum, s);
		o == 1 ? A++ : B++;
        prev = s; 
    } 

    if(A > B) go(asum, "48:00");
    else if(B > A) go(bsum, "48:00"); 

    cout << print(asum) << "\n"; 
    cout << print(bsum) << "\n";
}