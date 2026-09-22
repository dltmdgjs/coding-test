// 수학숙제 - BOJ 2870

// 숫자 찾아서 오름차순 정렬하는 거임. atoi, stoi를 활용
// 소문자 a의 아스키 코드 = 90, 
// 그러므로 1자씩 저장하다가 90 이상이 되면 거기까지 저장된 문자열을 숫자로 변환해 배열에 저장하면됨.

#include <bits/stdc++.h>
using namespace std;

int N;
string s;
string number_str = "";
vector<string> v;

bool check_all_zero(string str) {
    for (char c : str) {
        if (c != '0') return false;
    }
    return true;
}

string detach_zero(string str) {
    if (check_all_zero(str)) return "0";
    else {
        for (int i=0; i<str.size(); i++) {
            if (str[i] == '0') {
                continue;
            }
            else {
                return str.substr(i, s.size()-i);
            }
        }
    }
}

void solve() {
    for (char c : s) {
        if (c >= 90) {
            if (number_str != "") {
                v.push_back(detach_zero(number_str));
                number_str = "";
            }
        } else {
            number_str += c;
        }
    }

    if (number_str != "") {
        v.push_back(detach_zero(number_str));
        number_str = "";
    }
}

bool compare(string a, string b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main() {

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> s;
        solve();
    }

    sort(v.begin(), v.end(), compare);

    for (string k : v) {
        cout << k << "\n";
    }

    return 0;
}