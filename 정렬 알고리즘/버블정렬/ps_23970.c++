// 버블 정렬3
#include <iostream>
#define MAX 10001
using namespace std;

int N, c=0; // N: 원소 개수, c: 출력할 값
int arr[MAX],targetArr[MAX]; // 원소 배열
int sameIdx = 0;

// 문제점 : 전체 검사를 수행하니 시간 복잡도가 증가하여 시간초과가 발생한다.
// 뒤로 가는 수는 다시 앞으로 가는 경우가 없고, 앞으로 가는 수는 다시 뒤로 가는 경우가 없다는 것을 이용하여
// 두 배열의 앞부분부터 검사해 최대한 같은 상태의 인덱스를 저장하여, 이후 버블 정렬 후
// 검사 수행 시 이전에 같았던 인덱스까지는 검사하지 않도록 하여 시간 복잡도를 줄임.

bool isSame() {
    for (int i=sameIdx; i<N; i++) {
        if (arr[i] != targetArr[i]) {
            return false;
        } else {
            sameIdx++; // 같은 상태인 인덱스 증가
        }
    }
    c = 1; // 완전 같아지는 순간 1로 설정
    return true;
}

// 버블 정렬 함수
void bubbleSort() {
    bool same = isSame(); // 처음부터 같은 상태인지 검사
    for (int i=1; i<=N-1 && !same; i++) { // 완전 같아지기 전까지 수행
        for (int j=1; j<=N-i && !same; j++) {
            // 인접한 두 원소 비교 후 교환
            if (arr[j-1] > arr[j]) {
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
                same = isSame();
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // 입력
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }
    for (int i=0; i<N; i++) {
        cin >> targetArr[i];
    }

    bubbleSort();
    cout << c; // 비교 결과 출력
    return 0;
}