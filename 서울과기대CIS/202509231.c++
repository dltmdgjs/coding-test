#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v; // 선택된 피벗 요소 저장

// median-of-three 함수
int medianOfThree(int *arr, int l, int m, int r) {
    int A = arr[l], B = arr[m], C = arr[r];
    if (A < B) {
        if (B < C) return m;           // A < B < C
        else if (A < C) return r;      // A < C <= B
        else return l;                 // C <= A < B
    } else if (A > B) {
        if (A < C) return l;           // B < A < C
        else if (B < C) return r;      // B < C <= A
        else return m;                 // C <= B < A
    } else {
        return m; // A == B: 중앙(중간 인덱스) 선택
    }
}

// quickSort 함수
void quickSort(int *arr, int start, int end)
{
    if (start >= end) return; // 원소가 1개인 경우 종료

    // median-of-three로 피벗 인덱스 결정
    int mid = (start + end) / 2;
    int pidx = medianOfThree(arr, start, mid, end);

    // 피벗을 맨 앞으로 이동
    swap(arr[start], arr[pidx]);
    int pivot = arr[start];

    // 선택된 피벗 저장
    v.push_back(pivot);

    int left = start + 1;   // 첫 비교는 start+1부터
    int right = end;

    while (true) {
        while (left <= end && arr[left] < pivot) ++left;  // pivot보다 작은 동안 전진
        while (right >= start + 1 && arr[right] > pivot) --right; // pivot보다 큰 동안 후퇴

        if (left < right) {
            if (arr[left] == arr[right]) {
                // 값이 같으면 교환X.
                ++left; --right;
            } else {
                swap(arr[left], arr[right]);
            }
        } else {
            break;
        }
    }
    swap(arr[start], arr[right]);

    // 왼쪽/오른쪽 요소들 재귀 호출
    quickSort(arr, start, right - 1);
    quickSort(arr, right + 1, end);
}

int main()
{
    int N;
    int arr[100001];

    cin >> N;
    for (int i = 0; i < N; i++) 
        cin >> arr[i];

    quickSort(arr, 0, N - 1);

    // 선택된 피벗 출력
    for (int i = 0; i < v.size(); ++i) {
        if (i) cout << "_";
        cout << v[i];
    }
    cout << "\n";

    // 정렬된 요소 출력
    for (int i = 0; i < N; ++i) {
        if (i) cout << "_";
        cout << arr[i];
    }
    return 0;
}
