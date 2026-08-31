// 문제 : 오큰수
// 알고리즘 분류 : 스택

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> answer(N, -1); // 결과를 -1로 초기화
    stack<int> s; // 인덱스를 저장

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        // 현재 숫자가 스택의 top 인덱스 값보다 크다면 오큰수
        while (!s.empty() && A[s.top()] < A[i]) {
            answer[s.top()] = A[i];
            s.pop();
        }
        s.push(i);
    }

    for (int i = 0; i < N; i++) {
        cout << answer[i] << " ";
    }

    return 0;
}
