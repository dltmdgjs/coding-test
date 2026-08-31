// 분할 정복 - 색종이 만들기 문제
// 같은 색으로 이루어진 정사각형의 개수를 구하여라 (하양, 파랑)
// 입력 - N(크기, 2의 제곱 단위), 색상(0-하양,1-파랑)
// 출력 - 하얀색 종이 수 \n 파란색 종이 수

#include <iostream>
#define MAX 129
using namespace std;

int N;
int M[MAX][MAX] = {0,};
int white=0, blue=0;

// 함수 부분 개선 필요? - 일단 맞음
void divide(int xi, int yi, int xj, int yj, int N) { 
    int firstColor = M[xi][yi]; // 좌상단 값
    bool same = true;
    if (N!=1) { // 1개이면 검사할 필요 없이 바로 업데이트
        // 나누어진 한영역에 대해 검사진행
        for(int x=xi; x<=xj; x++) {
            for (int y=yi; y<=yj; y++) {
                if (firstColor != M[x][y]) {
                    same = false;
                    divide(xi,yi,xi+N/2-1,yi+N/2-1,N/2); // 좌상단
                    divide(xi,yi+N/2,xi+N/2-1,yj,N/2); // 우상단
                    divide(xi+N/2,yi,xj,yi+N/2-1,N/2); // 좌하단
                    divide(xi+N/2,yi+N/2,xj,yj,N/2); // 우하단
                    break;
                }
            }
            if (!same) break;
        }
    }
    
    // 동일하면 -> 개수 업데이트
    if (same) {
        if (firstColor) blue++;
        else white++;
    }
}
// 각 N만큼의 영역에 대해 내부의 정사각형의 색상이 동일한지 검사
// 동일하면 -> 그 영역은 더 이상 분할 하지 않고 개수 업데이트
// 동일하지 않으면 -> 다시 분할 후 검사 (재귀호출?)

int main() {
    cin >> N;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> M[i][j];
        }
    }

    divide(1, 1, N, N, N);

    cout << white << "\n" << blue;

    return 0;
}

