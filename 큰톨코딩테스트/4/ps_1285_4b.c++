// 시간초과.. 다른 로직, 아이디어가 필요함. 최적화 하는 방법을 생각하자

#include <bits/stdc++.h>
using namespace std;

int N, mn = 987654321;
char a[20][20];


void go(int i, int j, char t[20][20]) {
    int cnt = 0;
    for (int k=0; k<N; k++) {
        if (i & (1<<k)) {
            // 뒤집기
            for (int l=0; l<N; l++) {
                if (t[k][l] == 'T') t[k][l] = 'H';
                else t[k][l] = 'T';
            }

        }
        if (j & (1<<k)) {
            // 뒤집기
            for (int l=0; l<N; l++) {
                if (t[l][k] == 'T') t[l][k] = 'H';
                else t[l][k] = 'T';
            }
        }
    }

    for (int l=0; l<N; l++) {
        for (int m=0; m<N; m++) {
            if (cnt > mn) return;
            if (t[l][m] == 'T') {
                cnt++;
            }
        }
    }

    mn = min(cnt, mn);
    return;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> a[i][j];
        }
    }

    for (int i=1; i < (1 << N); i++) {
        for (int j=1; j < (1<<N); j++) {
            go(i, j, a);
            if (mn == 2) {cout << mn; return 0;}
        }
    }

    cout << mn;
    return 0;
}

// 브루트포스 -> 행과 열을 뒤집는 모든 경우의 수를 계산...

// 이중 combi?
// 비트마스킹? : 20이하의 자연수 N 이니 해볼만 함.