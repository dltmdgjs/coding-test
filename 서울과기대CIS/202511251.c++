// 통채우기 문제 - 25214 - 근사 알고리즘

#include <iostream>
#define MAX 1000
using namespace std;


int n, C;
int W[MAX];

// 최초 적합
int FirstFit() {
    // 첫값 새 통에 넣기
    int count = 1;
    int Box[MAX] = {0,};
    Box[0] = W[0];
    
    // 통을 왼쪽부터 보면서 들어갈 수 있는 통이 있으면 바로 넣음
    for (int i=1; i<n; i++) {
        for (int j=0; j<count; j++) {
            if (Box[j] + W[i] <= C) {
                Box[j] += W[i];
                break;
            }
            if (j == count-1 && Box[j] + W[i] > C) {
                Box[j+1] += W[i];
                count++;
                break;
            }
        }
    }

    return count;
}

// 최선 적합
int BestFit() {
    // 첫값 새 통에 넣기
    int count = 1;
    int Box[MAX] = {0,};
    Box[0] = W[0];

    // 통 중에 물건을 넣을 수 있고, 남는 공간이 가장 작은 통에 넣음
    for (int i=1; i<n; i++) {
        int empty = 10000000;
        int idx = -1;
        for (int j=0; j<count; j++) {
            if (Box[j]+W[i] <= C) {
                if (empty > C-Box[j]-W[i]) {
                    empty = C-Box[j]-W[i];
                    idx = j;
                }
            }
        }
        if (idx == -1) {
            Box[count] += W[i];
            count++;
        } else {
            Box[idx] += W[i];
        }
    }

    return count;
}

// 다음 적합
int NextFit() {
    // 첫값 새 통에 넣기
    int count = 1;
    int Box[MAX] = {0,};
    Box[0] = W[0];

    // 이전에 넣은 통에 여유가 있으면 넣고 아니면 새 통에 넣음
    for (int i=1; i<n; i++) {
        if (Box[count-1] + W[i] <= C) {
            Box[count-1] += W[i];
        } else {
            Box[count] += W[i];
            count++;
        }
    }

    return count;
}


int main() {

    cin >> n >> C;
    for (int i=0; i<n; i++) {
        cin >> W[i];
    }

    int r1 = FirstFit();
    int r2 = BestFit();
    int r3 = NextFit();

    cout << r1 << " " << r2 << " " << r3; 

    return 0;
}