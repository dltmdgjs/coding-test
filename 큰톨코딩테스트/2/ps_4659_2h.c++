// 비밀번호 발음하기 - 실버 5
// 알고리즘 분류 : 구현, 문자열


// 내 풀이
// #include <bits/stdc++.h>
// using namespace std;

// vector<char> m = {'a', 'e', 'i', 'o' ,'u'};
// vector<char> j = {'b', 'c' ,'d', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};

// bool check1(string s) {
//     // 모음이 반드시 1개 이상
//     for (int i=0; i<s.size(); i++) {
//         if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
//             return true;
//         }
//     }
//     return false;
// }

// bool check2(string s) {
//     if (s.size() < 3) {
//         return true;
//     }
//     // 모음 또는 자음 3연속 이상 X
//     for (int i=0; i<=s.size()-3; i++) {
//         if (
//             (find(m.begin(), m.end(), s[i]) != m.end()) &&
//             (find(m.begin(), m.end(), s[i+1]) != m.end()) &&
//             (find(m.begin(), m.end(), s[i+2]) != m.end())
//         ) return false;
//         else if (
//             find(j.begin(), j.end(), s[i]) != j.end() &&
//             find(j.begin(), j.end(), s[i+1]) != j.end() &&
//             find(j.begin(), j.end(), s[i+2]) != j.end()
//         ) return false;
//     }
//     return true;
// }

// bool check3(string s) {
//     if (s.size() < 2) return true;
//     // ee, oo 제외 동일 문자 연속 X
//     for (int i=0; i<=s.size()-2; i++) {
//         if (s[i] == s[i+1]) {
//             if (s[i] == 'e' || s[i] == 'o') return true;
//             return false;
//         }
//     }
//     return true;
// }

// int main() {
//     string end = "end";
//     string s;

//     while(true) {
//         cin >> s;
//         if (s == end) break;
//         if (check1(s) && check2(s) && check3(s)) {
//             cout << "<" << s << "> " << "is acceptable." << "\n";
//         } else {
//             cout << "<" << s << "> " << "is not acceptable." << "\n";
//         }
//     }

//     return 0;
// }

// --------------------------------------------------------------------------------

// 다른 풀이 방법
#include <bits/stdc++.h>
using namespace std;  

string s; 
int lcnt, vcnt; // 연속된 자음, 모음 카운트

// 모음인지 체크하는 함수
bool isVowel(int idx){
	return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

int main () { 
	while(true){
		cin >> s; 
		if(s == "end")break; 

		lcnt = vcnt = 0; // 연속된 자모음 카운트 초기화
		bool flag = 0; // 결과 플래그 (1 -> not, 0 -> acc)
		bool is_include_v = 0; // 모음이 있는지 체크하는 불리언값
		int prev = -1; // 이전 문자의 아스키 값

        // 문자 하나씩 순회
		for(int i = 0; i < s.size(); i++){
			int idx = s[i]; // 현재 문자의 아스키 값.
            // 모음인 경우 
			if(isVowel(idx))vcnt++, lcnt = 0, is_include_v = 1;
            // 자음인 경우
			else lcnt++, vcnt = 0;
            // 모음 또는 자음 3연속인 경우
			if(vcnt == 3 || lcnt == 3) flag = 1; 
            // ee oo 제외, 같은 문자 연속인 경우
			if(i >= 1 && (prev == idx) && (idx != 'e' && idx != 'o')){
				flag  = 1;
			} 
			prev = idx; // 이전 갱신.
		}

        // 모음이 없으면 
		if(is_include_v == 0) flag = 1;
		if(flag) cout << "<" << s << ">" << " is not acceptable.\n";
		else cout << "<" << s << ">" << " is acceptable.\n";
	} 
	return 0;
}