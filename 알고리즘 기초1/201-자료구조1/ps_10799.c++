// 문제 : 쇠막대기
// 알고리즘 분류 : 스택



#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    stack<char> s;
    int result = 0;

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == '(') {
            s.push('(');
        } else {
            s.pop(); // '(' 제거

            if (str[i - 1] == '(') {
                // 레이저일 경우
                result += s.size(); // 현재 남은 쇠막대기 수만큼 조각 생김
            } else {
                // 쇠막대기 끝
                result += 1;
            }
        }
    }

    cout << result << '\n';
    return 0;
}
