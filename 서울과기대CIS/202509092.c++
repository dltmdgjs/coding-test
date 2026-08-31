#include <iostream>

using namespace std;

int main() {
    int N, f;
    int countA=0, countB=0, countC=0;
    cin >> N >> f;
    // 전략 A
    for (int i=0; i<N; i++) {
        if (i==f) {
            countA = i+1;
            break;
        }
    }
    // 전략 B
    for (int i=0; i<N; ) {
        if (f==i or f==i+1) {
            countB = (i/2)+1;
            break;
        } else {
            i += 2;
        }
    }
    // 전략 C, 동전을 절반으로 나누어 비교한다. 이후 더 가벼운 절반에 대해 이 과정을 반복한다.
    int left = 0, right = N-1;
    int mid = (left + right) / 2;
    int i=1;
    while (left <= right) {
        if(f==mid or f==mid+1) {
            countC = i;
            break;
        } else {
            if(f<mid) {
                right = mid - 1;
                mid = (left + right) / 2;
            } else {
                left = mid + 1;
                mid = (left + right) / 2;
            }
        }
        i++;
    }
    if (countC >1) countC = i+1;

    // 결과 출력
    cout << countA << "\n";
    cout << countB << "\n";
    cout << countC << "\n";
    return 0;
}