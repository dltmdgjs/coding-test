// 수학 숙제 - 실버 4
// 알고리즘 분류 : 문자열, 정렬, 파싱

// 내 풀이
// #include <bits/stdc++.h>
// using namespace std;

// int N;
// vector<string> v; // 찾은 숫자를 집어넣을 공간 (매우 클 수 있으므로 string으로 저장)

// bool comp(string a, string b) {
//     if (a.size() == b.size()) {
//         return a < b;
//     } else {
//         return a.size() < b.size();
//     }
// }

// int main() {

//     cin >> N;
//     for (int i=0; i<N; i++) {

//         int flag = 0; // 알파벳/숫자 플래그 (0=알파벳, -1=숫자)

//         string s; cin >> s;
//         string s1 = ""; // 숫자를 저장할 문자열

//         // 문자 하나씩 검사
//         for (int l=0; l<s.size(); l++) {
//             // 알파벳인 경우
//             if (s[l] >= 97 && s[l] <= 122) {
//                 // '이전 문자가 숫자라면'
//                 if (flag < 0) { 
//                     // 숫자의 앞의 0이 있으면 제거후 삽입
//                     while (s1[0] == '0' && s1.size() > 1) {
//                         s1 = s1.substr(1, s1.size()-1);
//                     }
//                     v.push_back(s1);
//                     s1.clear();
//                 }
//                 // 현재 == 알파벳임
//                 flag = 0;
//             }
//             // 숫자인 경우
//             else {
//                 s1 += s[l];
//                 flag = -1;
//             }
//         }

//         // 마지막 숫자가 남은 경우, 남은 수 삽입
//         if (flag == -1) {
//             while (s1[0] == '0' && s1.size() > 1) {
//                 s1 = s1.substr(1, s1.size()-1);
//             }
//             v.push_back(s1);
//         }
//     }

//     sort(v.begin(), v.end(), comp); // 오름차순 정렬

//     for (auto it=v.begin(); it<v.end(); it++) {
//         cout << *it << '\n';
//     }

//     return 0;
// }

// 100글자 라는 것을 보고 숫자로 변환할 수 없음을 알아야 함.
// int - 10자, long long - 19자


// 다른 풀이
#include <bits/stdc++.h>
using namespace std;   

int n; 
vector<string> v; 
string s, ret;

// 숫자열을 v에 집어넣는 함수
void go(){   
    // 앞의 0 제거
	while(ret.size() > 1 && ret.front() == '0'){
        ret.erase(ret.begin());
	}
    // 삽입
	v.push_back(ret);
    // ret 초기화 (재사용을 위해)
	ret = "";
}

bool cmp(string a, string b){
	if(a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main () {
	cin >> n; 
	for(int i = 0; i < n; i++){
		cin >> s; 
	 	ret = "";

        // 하나씩 검사
		for(int j = 0; j < s.size(); j++){
			if(s[j] < 65)ret += s[j]; // 숫자면 저장
			else if(ret.size()) go(); // 알파벳이고 저장된 숫자열이 있다면 go해서 저장
		}
        // 남은 숫자열이 있으면 go해서 저장
		if(ret.size()) go(); 
	}

    // 정렬 후 출력
	sort(v.begin(), v.end(), cmp);
	for(string i : v)cout << i << "\n"; 
    
	return 0;
}