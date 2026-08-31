// 디지털 티비 - 브론즈 1
// 알고리즘 분류 - 구현

#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, k1, k2;
    cin >> N;

    vector<string> v(N);
    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        if (s.compare("KBS1")==0) {
            k1 = i;
        }
        if (s.compare("KBS2")==0) {
            k2 = i;
        }
        v.push_back(s);
    }

    // kbs1 옮기기
    // 1. kbs1으로 화살표 옮기기
    for (int i=0; i<k1; i++) {
        cout << 1;
    }
    // 2. 1로 옮기기
    for (int i=0; i<k1; i++) {
        cout << 4;
    }

    // KBS2 위치 수정 (k1 > k2인 경우에만)
    if (k1 > k2) k2 += 1;

    // kbs2 옮기기
    // 1. kbs2으로 화살표 옮기기
    for (int i=0; i<k2; i++) {
        cout << 1;
    }
    // 2. 2로 옮기기
    for (int i=1; i<k2; i++) {
        cout << 4;
    }

    return 0;
}