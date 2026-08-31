// 사과 담기 게임 - 실버 5
// 알고리즘 분류 : 구현, 그리디 알고리즘

#include <bits/stdc++.h>
using namespace std;

int N, M, J;
int ms, me;
int length;

int main() {
    cin >> N >> M;
    cin >> J;
    ms = 1; me = M;
    for (int i=0; i<J; i++) {
        int a; cin >> a;
        // 바구니 영역 내에 있는지 검사
        // 있으면 다음 사과로 넘어감.
        // 없으면 최소거리만큼만 이동함 (바구니 시작,끝 위치와의 차이 중 더 짧은 것 선택 -> length+=...)
        if (a >= ms && a <= me) continue;
        else {
            if (a > me) {
                int dist = (a-me);
                length += dist;
                me += dist;
                ms += dist;
            } else if (a < ms) {
                int dist = (ms-a);
                length += dist;
                me -= dist;
                ms -= dist;
            }
        }
    }

    cout << length;
    return 0;
}