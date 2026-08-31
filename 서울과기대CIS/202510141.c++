#include <iostream>
#include <algorithm>

using namespace std;

// 정렬 비교함수
bool compare(double *a, double *b) {
    return a[1]/a[0] > b[1]/b[0];
}

int main() {
    int N, C; // 물건 개수, 가방 한계 무게
    cin >> N >> C;
    // double arr[N][3]; // 물건 배열 (물건 무게, 가치, 비율)
    double arr[N][2]; // 물건 배열 (물건 무게, 가치)

    // 무게, 가치 입력
    for (int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1];
        // arr[i][2] = 0; // 비율 초기화
    }

    // 가치/무게 기준 내림차순 정렬
    double* graph[N];
    for (int i = 0; i < N; i++) {
        graph[i] = arr[i];
    }
    sort(graph, graph + N, compare);
    
    double w = 0; // 현재 무게
    double v = 0; // 현재 가치
    int i=0;
    // 가방에 물건을 넣음
    while (w+arr[i][0] <= C && i < N) {
        w += arr[i][0];
        v += arr[i][1];
        // arr[i][2] = 1;
        i++;
    }
    // 남은 공간이 있으면 비율만큼 가치 더함
    if (C-w > 0 && i < N) {
        v += (C-w) * (arr[i][1]/arr[i][0]);
        // arr[i][2] = (C-w)/arr[i][0];
    }

    // 소수점 두번째 자리까지 반올림하여 전체 가치 출력
    cout.precision(2);
    cout << fixed;
    cout << v;
    
    return 0;
}