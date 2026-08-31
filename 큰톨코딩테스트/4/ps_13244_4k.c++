// Tree - 공드 4
// 알고리즘 분류 : 

#include <bits/stdc++.h>
using namespace std;


int T;

bool check1() {
    // 아무 시작점에서 탐색시작
    // 전체 다 방문 가능하면 true 반환
    // 아니면 false 반환
}

bool check2() {
    // 전체 간선에 대해 반복
        // 해당 간선 삭제
        // 전체 정점 탐색 가능한지 체크
        // 가능하면 바로 false 반환
    // true 반환
}

bool check3() {
    // 아무 정점간에 엣지 1개 추가
    // 사이클 판별
    // 사이클 없으면 false, 있으면 true 반환
}

int main() {
    cin >> T;

    while (T) {
        T--;
        int N; cin >> N; // 정점 수
        int M; cin >> M; // 간선 수
        vector<pair<int, int>> v; // 간선 
        for (int i=0; i<M; i++) {
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }
        if (check1()) {
            if (check2()) {
                if (check3()) {
                    cout << "tree";
                    continue;
                }
            }
        }
        cout << "graph";
    }


    return 0;
}