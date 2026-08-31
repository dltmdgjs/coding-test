// ZOAC 4 - 브론즈 3
// 알고리즘 분류 : 수학, 사칙연산

#include <bits/stdc++.h>
using namespace std;

int H, W, N ,M;

int main() {
    int count = 0;

    cin >> H >> W >> N >> M;

    for (int i=0; i<H; i+=N+1) {
        for (int j=0; j<W; j+=M+1) {
            count++;
        }
    }

    cout << count;

    return 0;
}