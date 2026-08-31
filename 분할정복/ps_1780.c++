// 분할정복 : 종이의 개수

// N×N크기의 행렬로 표현되는 종이가 있다. 
// 종이의 각 칸에는 -1, 0, 1 중 하나가 저장되어 있다. 
// 우리는 이 행렬을 다음과 같은 규칙에 따라 적절한 크기로 자르려고 한다.
// 1. 만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
// 2. (1)이 아닌 경우에는 종이를 같은 크기의 종이 9개로 자르고, 각각의 잘린 종이에 대해서 (1)의 과정을 반복한다.
// 이와 같이 종이를 잘랐을 때, -1로만 채워진 종이의 개수, 0으로만 채워진 종이의 개수, 1로만 채워진 종이의 개수를 구해내는 프로그램을 작성하시오.
// N은 3의 제곱꼴임.

// 이전 2630문제에서 divide함수의 내부를 바꾸면 됨.

#include <iostream>
#define MAX 2188
using namespace std;

int N;
int M[MAX][MAX] = {0,};
int m=0, z=0, p=0;

// void divide(int xi, int yi, int xj, int yj, int N) { 
//     int first = M[xi][yi]; // 좌상단 값
//     bool same = true;
//     if (N!=1) { // 1개이면 검사할 필요 없이 바로 업데이트
//         // 나누어진 한영역에 대해 검사진행
//         for(int x=xi; x<=xj; x++) {
//             for (int y=yi; y<=yj; y++) {
//                 if (first != M[x][y]) {
//                     same = false;
//                     divide(xi,yi,xi+N/3-1,yi+N/3-1,N/3); // 좌상단
//                     divide(xi,yi+N/3,xi+N/3-1,yi+N/3*2-1,N/3);// 좌중상단
//                     divide(xi,yi+N/3*2,xi+N/3-1,yj,N/3); // 우상단
//                     divide(xi+N/3,yi,xi+N/3*2-1,yi+N/3-1,N/3);// 좌중단
//                     divide(xi+N/3,yi+N/3,xi+N/3*2-1,yi+N/3*2-1,N/3);// 중단
//                     divide(xi+N/3,yi+N/3*2,xi+N/3*2-1,yj,N/3);// 우중단
//                     divide(xi+N/3*2,yi,xj,yi+N/3-1,N/3); // 좌하단
//                     divide(xi+N/3*2,yi+N/3,xj,yi+N/3*2-1,N/3);// 좌중하단
//                     divide(xi+N/3*2,yi+N/3*2,xj,yj,N/3); // 우하단
//                     break;
//                 }
//             }
//             if (!same) break;
//         }
//     }
//     // 동일하면 -> 개수 업데이트
//     if (same) {
//         if (first == -1) {
//             m++;
//         } else if (first == 0) {
//             z++;
//         } else if (first == 1) {
//             p++;
//         }
//     }
// }

// 위 divide함수를 수정
// 문제점 : 루프문 내부에서 다시 divide함 -> 중복호출 가능성 존재, 깔끔하게 검사만 하도록 변경
// divide하는 규칙성이 존재하므로 반복문을 통해 호출하도록 변경(하드코딩 X)
// 전체적 흐름 : 좌상단 값이랑 같은지 검사 -> 다 같으면 해당 카운트 증가, 다르면 9등분함.
void divideNew(int x, int y, int size) {
    int first = M[x][y];
    bool same = true;

    // 전체 영역이 같은 수인지 검사
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (M[i][j] != first) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    // 모두 같은 경우 → 해당 수 카운트 증가
    if (same) {
        if (first == -1) m++;
        else if (first == 0) z++;
        else p++;
        return;
    }

    // 다르면 9등분
    int newSize = size / 3;
    for (int dx = 0; dx < 3; dx++) {
        for (int dy = 0; dy < 3; dy++) {
            divideNew(x + dx * newSize, y + dy * newSize, newSize);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> M[i][j];
        }
    }

    divideNew(1, 1, N);

    cout << m << "\n" << z << "\n" << p;
    return 0;
}