// 시험 감독 - 브론즈 2

// 전체 시험장의 최소 감독관 수를 구하시오
// 조건 1. 총감독관은 반드시 각 시험장 당 1명
// 조건 2. 부감독관은 여러명 가능


#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000

int N; // 시험장 개수
int A[MAX]; // 시험장 인원 수 배열
int B, C; // 총,부 감독관이 감독 가능한 인원 수


int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    cin >> B >> C;

    // int로 설정할 경우 정수 오버플로우 문제 발생. -> long long으로 설정
    long long count = 0;

    for (int i=0; i<N; i++) {
        A[i] -= B;
        count++;

        if (A[i] > 0) {
            count += A[i]/C;
            if (A[i]%C>0) {
                count++;
            }
        }
        
    }

    cout << count;

    return 0;
}