#include <iostream>

using namespace std;

int main() {
    int N, x;
    int index1 = -1;
    int index2 = -1;
    int result1, result2;
    cin >> N >> x;
    // 이진탐색
    int left = 0, right = N-1;
    int mid = (left + right) / 2;
    int i=1;
    while (left <= right) {
        if(x==mid) {
            index1 = x;
            result1 = i;
            break;
        } else {
            if(x<mid) {
                right = mid - 1;
                mid = (left + right) / 2;
            } else {
                left = mid + 1;
                mid = (left + right) / 2;
            }
        }
        i++;
    }
    // 탐색실패
    if (index1 == -1 or left > right) {
        index1 = -1;
        result1 = i-1;
    }
    // 순차탐색
    for(int i=0; i<N; i++) {
        if(x==i) {
            index2 = x;
            result2 = i+1;
            break;
        }
    }
    // 탐색실패
    if (index2 == -1) {
        index2 = -1;
        result2 = N;
    }

    cout << index2 << " " << result2 << "\n";
    cout << index1 << " " << result1 << "\n";
    
    return 0;
}