// 트럭 주차 - 브론즈 2
// 알고리즘 분류 : 구현, 시뮬레이션

#include <bits/stdc++.h>
using namespace std;


int T[101];
int sum;

int main() {

    int A, B, C;
    cin >> A >> B >> C;

    for (int i=0; i<3; i++) {
        int a ,b;
        cin >> a >> b;
        for (int j=a; j<b; j++) {
            T[j]++;
        }
    }

    for (int i=1; i<101; i++) {
        if (T[i] == 1) {
            sum+=T[i]*A;
        } else if (T[i] == 2) {
            sum+=T[i]*B;
        } else if (T[i] == 3) {
            sum+=T[i]*C;
        }
    }

    cout << sum;

    return 0;
}

// counting star : 맵(string) 또는 배열(int)