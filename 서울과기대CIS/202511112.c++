// 외부 정렬 문제 - 25213 - 정렬 알고리즘
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, p;
    cin >> N >> M >> p;  // 전체 데이터 수, 메모리 크기, 병합할 런 개수

    // 데이터 입력
    vector<int> data(N);
    for (int i = 0; i < N; ++i)
        cin >> data[i];

    // 초기 런 생성
    vector<vector<int>> runs;  // 런들을 담는 2차원 벡터
    for (int i = 0; i < N; i += M) {
        int end = min(N, i + M); // 런의 끝 원소 위치 (마지막 런의 범위가 벗어나는걸 방지)
        vector<int> run(data.begin() + i, data.begin() + end); // M개(또는 그 이하)의 데이터 저장
        sort(run.begin(), run.end());  // 런 내부 정렬
        runs.push_back(run); // 전체 런 목록에 추가
    }

    int initialR = runs.size(); // 초기 런 개수
    int K = 0; // 병합 패스 수

    // p개 런씩 병합 반복
    while (runs.size() > 1) { // 런이 하나가 될 때까지
        ++K; // 패스 수 갱신
        vector<vector<int>> newRuns; // 새 런 목록 생성
        
        // 현재 런 목록 내에서 p개씩
        for (int i = 0; i < (int)runs.size(); i += p) {
            // p개 런들을 하나의 런으로 병합
            vector<int> temp; // 병합될 런(임시)
            for (int j = i; j < i + p && j < runs.size(); ++j) {
                temp.insert(temp.end(), runs[j].begin(), runs[j].end());
            }
            sort(temp.begin(), temp.end()); // 정렬
            newRuns.push_back(temp); // 새 런에 추가
        }

        runs = newRuns; // 새 런 집합으로 교체
    }

    // 결과 출력
    cout << initialR << "\n";         // 초기 런 개수
    cout << K << " " << (K + 1) << "\n"; // 병합 패스 수
    for (int x : runs[0]) cout << x << " "; // 최종 정렬된 데이터

    return 0;
}
