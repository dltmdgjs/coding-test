// 버블 정렬2 - 2529-2 - 정렬 알고리즘
#include <iostream>
#define MAX 1000
using namespace std;

int N, cnt=0; // N: 원소 개수, cnt: 교환 횟수
int arr[MAX]; // 원소 배열


// 배열 상태 출력 함수
void showArr() {
    for (int i=0; i<N; i++) {
        if (i == N-1) {
            cout << arr[i];
        } else {
            cout << arr[i] << "_";
        }
    }
    cout << "\n";
}

// 버블 정렬 함수
void bubbleSort() {
    for (int i=1; i<=N-1; i++) {
        for (int j=1; j<=N-i; j++) {
            // 인접한 두 원소 비교 후 교환
            if (arr[j-1] > arr[j]) {
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
                cnt++; // 교환 횟수 증가
                showArr(); // 배열 상태 출력
            }
        }
    }
}


int main() {
    // 입력
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }

    // 버블 정렬 수행
    bubbleSort();

    // 교환이 한 번도 일어나지 않은 경우 x 출력
    if (cnt == 0) {
        cout << "x" << "\n";
    }

    // 교환 횟수 출력
    cout << cnt;
    return 0;
}