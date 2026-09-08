// 이분 탐색 - binary search

// 정렬된 데이터에서 값을 빠르게 찾는 알고리즘
// 전체 범위를 매번 절반씩 줄여나감 - logN


#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &b, int target) {
    // 1. left, right 초기값 설정
    int left = 0; int right = b.size() - 1;

    // 반복
    while (left <= right) {
        // 2. mid 값 설정
        int mid = (left + right) / 2;

        // 3. 검사 & left/right 갱신 (일치 시, 반환)
        if (b[mid] > target) {right = mid - 1;}
        else if (b[mid] < target) {left = mid + 1;}
        else if (b[mid] == target) {return b[mid];}
    }

    return -1;
}

int main() {
    vector<int> v;
    int N, temp, target;

    cin >> N >> target;
    for (int i=0; i<N; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    // 이분 탐색은 반드시 정렬되어 있어야 함.
    sort(v.begin(), v.end());

    cout << binary_search(v, target);

    return 0;
}