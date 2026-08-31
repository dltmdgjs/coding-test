// 클러스터링 문제 - 25215 - 근사 알고리즘

#include <iostream>
#define MAX 1000
using namespace std;


int N, K;
int x[MAX], y[MAX];
int centerIdx[MAX]; // 중심점 인덱스

// 두 점 사이 거리
int distance(int i, int j) {
    int dist = (x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]);
    return dist;
}

// 중심점인지 검사
bool notCentroid(int i, int k) {
    for (int j=1; j<=k; j++) {
        if (i == centerIdx[j]) {
            return false;
        }
    }
    return true;
}

// K개의 중심점 구하기
void centerPoints() {
    // 첫 중심점을 1번 점으로 지정
    int cenCount = 1;
    centerIdx[cenCount] = 1; 

    // k-1개의 중심점 정하기
    while (cenCount != K) {
        int maxDist = 0; // 센터와의 거리 중 가장 큰 값
        int idx = -1; // 센터가 될 점의 인덱스

        // 센터가 아닌 각 점 i에 대해 현재까지 선택된 센터들과의 거리 중 최소거리 구하기
        for (int i=1; i<=N; i++) {
            int min = 1000000; // 최소거리
            if (notCentroid(i, cenCount)) {
                // 점 i와 중심점 k사이 거리 중 가장 가까운 거리 구하기
                for (int k=1; k<=cenCount; k++) {
                    int dist = distance(i, centerIdx[k]); 
                    if (dist < min) {
                        min = dist;
                    }
                }
                // 최소 거리가 가장 큰 점을 선택
                if (maxDist < min) {
                    maxDist = min;
                    idx = i;
                }
            }
        }

        // 센터 추가
        cenCount++;
        centerIdx[cenCount] = idx;
    }
}

// 모든 점에 대해 자신과 가장 가까운 센터까지의 거리를 구했을때 그 중 최댓값
int minDist() {
    int max = -1;

    for (int i=1; i<=N; i++) {
        if (notCentroid(i, K)) {
            // 자신과 가장 가까운 센터까지의 거리 min을 구함
            int min = 1000000;
            for (int k=1; k<=K; k++) {
                int dist = distance(i, centerIdx[k]);
                if (min > dist) {
                    min = dist;
                }
            }
            // 그 중 최댓값으로 업데이트
            if (max < min) {
                max = min;
            }
        }
    }
    return max;
}


int main() {
    cin >> N >> K;
    for (int i=1; i<=N; i++) {
        cin >> x[i] >> y[i];
    }

    // K개의 중심점 구하기
    centerPoints();

    // 자신이 속한 센터와의 거리 중 최댓값 출력
    int R = minDist();

    cout << R << "\n";
    return 0;
}