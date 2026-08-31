// 문제 : 잃어버린 괄호
// 알고리즘 분류 : 그리디

// '-'가 나오면 그 뒤의 모든 수를 빼면 된다.
// '-'가 나오기 전까지는 모두 더해주면 된다.

// 문자열 처리 및 구현에 있어서 어려웠음.
// + 또는 - 인 경우와, 숫자인 경우를 분리해서 처리.
// + 또는 - 인 경우 -> 부호에 상관 없이, 이전에 -가 나온 경우라면 결과에서 무조건 빼고, 그게 아니면 더한다.
//                  또한 - 이면 -가 나왔다고 bool 변수에 저장한다.
// 숫자인 경우 -> int 변수에 저장해서 다음 연산에 쓰도록 한다.

#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cin >> input;

    bool isMinus = false;
    int result = 0;
    string number = "";

    for (int i = 0; i <= input.size(); i++) {
        // 연산자인 경우, 혹은 마지막인 경우
        if (input[i] == '+' || input[i] == '-' || i == input.size()) {
            // 직전에 저장한 number를 연산
            if (isMinus) {
                result -= stoi(number);  // string to int
            } else {
                result += stoi(number);  // string to int
            }

            number = ""; // number 초기화

            // '-'인 경우 -> isMinus = true
            if (input[i] == '-') {
                isMinus = true;
            }
        }
        // 숫자인 경우 -> number에 저장
        else {
            number += input[i];
        }
    }

    cout << result << "\n";
    return 0;
}