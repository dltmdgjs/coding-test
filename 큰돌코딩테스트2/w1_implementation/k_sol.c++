#include<bits/stdc++.h> 
using namespace std; 

// 개선점 1 : 펠린드롬이 되기 위한, 될 수 없는 조건/상황을 잘 생각해야함.

// 쓰인 기술 : 아스키코드-인덱스 활용, 비트마스킹, 문자열에 문자 삽입

string s, ret; 
int cnt[200], flag; // 문자의 아스키 코드를 인덱스로 활용.
char mid;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;

    for(char a : s) cnt[a]++; // 각 문자의 갯수를 저장함.

    for(int i = 'Z'; i >= 'A'; i--){ // Z부터 A까지 (오름차순 우선순위 출력을 위해)
        if(cnt[i]) { //값이 있으면

            if(cnt[i] & 1){ // 비트 마스킹 (홀수인지 검사)
                mid = char(i); // 홀수면 가운데 문자로 설정함.
                flag++; // 홀수 문자 개수.
                cnt[i]--; 
            }

            if(flag == 2) break; // 홀수인 문자가 2개이상이면 펠린드롬이 되지 못하므로 중단.

            // 해당 문자를 앞 뒤에 붙이기.
            for(int j = 0; j < cnt[i]; j += 2){
                ret = char(i) + ret; 
                ret += char(i);
            }
        }
    }

    // 가운데 값이 있는 경우 -> 가운데에 가운데 문자를 삽입.
    if(mid) {
        ret.insert(ret.begin() + ret.size() / 2, mid);
    }

    // 홀수인 문자가 2개 이상인 경우 - 펠린드롬 X
    if(flag == 2) {
        cout << "I'm Sorry Hansoo\n";
    } 
    // 가운데 값이 없는 경우
    else {
        cout << ret << "\n"; 
    }
}
