// 힙 정렬 - 25210 - 정렬 알고리즘
#include <iostream>
#define MAX 1000
using namespace std;

int N; // N: 원소 개수
int arr[MAX]; // 원소 배열(힙) (1부터 시작)


// 배열 상태 출력 함수
void showArr() {
    for (int i=1; i<=N; i++) {
        if (i == N) {
            cout << arr[i];
        } else {
            cout << arr[i] << "_";
        }
    }
    cout << "\n";
}

// DownHeap 함수
void DownHeap(int heapSize) {
    int crt = 1; // 현재 노드 인덱스
    while(2*crt <= heapSize) { // 종료 조건 - 자식 노드가 없을 때까지
        int child = 2*crt; // 왼쪽 자식 노드 인덱스

        // 더 큰 자식 노드 인덱스 찾기
        // 오른쪽 자식 노드가 존재하고, 오른쪽 자식 노드가 더 크면
        if (child+1 <= heapSize && arr[child] < arr[child+1]) { 
            child++; // 오른쪽 자식 노드로 변경
        }

        // 현재 노드와 더 큰 자식 노드 비교 - 힙 조건 미 충족 시 교환
        if (arr[crt] >= arr[child]) { // 현재 노드가 자식 노드보다 크면 
            break; // 종료
        }
        else { // 작으면
            // 자식들 중 큰 것과 교환 swap(arr[child], arr[crt]);
            int temp = arr[child];
            arr[child] = arr[crt];
            arr[crt] = temp;
            // 현재 노드 인덱스를 교환한 노드의 인덱스로 변경 -> 계속 진행
            crt = child;
        }
    }
}

// 힙 정렬 함수
void heapSort() {
    int heapSize = N; // 힙 크기 초기화

    // 마지막 노드와 첫 노드 교환 후 DownHeap 수행
    for (int i=1; i<=N-1; i++) {
        // 마지막 노드와 첫 노드 교환 (swap)
        int temp = arr[heapSize];
        arr[heapSize] = arr[1];
        arr[1] = temp;

        // 배열 상태 출력
        showArr(); 

        // 힙 크기 감소 (먼저해야, DownHeap시 마지막 원소와의 교환이 일어나지 않음)
        heapSize--;

        // DownHeap 수행
        DownHeap(heapSize);
    }
}

int main() {
    // 입력
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> arr[i];
    }

    // 힙 정렬 수행
    heapSort();
    return 0;
}