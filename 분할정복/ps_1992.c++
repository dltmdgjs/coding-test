// 분할 정복 - 쿼드트리 문제
// ps_2630과 연계.
#include <iostream>
#include <vector>
using namespace std;

// 흰점 = 0, 검은점 = 1

int N;
vector<string> a;

string divide(int xi, int yi, int N) { 
    char firstColor = a[xi][yi]; // 좌상단 값
    bool same = true;
    if (N!=1) { // 1개이면 검사할 필요 없이 바로 업데이트
        // 나누어진 한영역에 대해 검사진행
        for(int x=xi; x<xi + N; x++) {
            for (int y=yi; y<yi + N; y++) {
                if (firstColor != a[x][y]) {
                    same = false;
                    break;
                }
            }
            if (!same) break;
        }
    }
    if (same) {
        return string(1, firstColor); // 문자 1개 짜리 문자열 반환.
    }

    int half = N/2;
    string res = "(";
    res += divide(xi, yi, half);            // 좌상단
    res += divide(xi, yi + half, half);     // 우상단
    res += divide(xi + half, yi, half);     // 좌하단
    res += divide(xi + half, yi + half, half); // 우하단
    res += ")";
    return res; // N by N에서 완성된 문자열 반환
}

int main() {
    // 한줄씩 string으로 입력받기 때문에 입력 주의해야함.
    cin >> N;
    string s;
    for(int i=0; i<N; i++) {
        cin >> s;
        a.push_back(s);
    }

    cout << divide(0, 0, N);
    return 0;
}