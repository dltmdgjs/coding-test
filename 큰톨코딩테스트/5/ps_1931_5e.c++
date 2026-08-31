// 회의실 배정 - 골드 5
// 알고리즘 분류 : 그리디, 정렬

// 라인 스위핑 - 구간 관련 문제는 정렬을 하라.
#include <bits/stdc++.h>
using namespace std;

struct T {
    int start, end;
};

int N;
vector<T> v;

bool compare(T a, T b) {
    if (a.end < b.end) {
        return true;
    } else if (a.end == b.end) {
        return a.start < b.start;
    }
    return false;
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        int t1, t2; cin >> t1 >> t2;
        v.push_back({t1, t2});
    }

    // 정렬 - 종료시간 오름차순, 시작시간 오름차순
    sort(v.begin(), v.end(), compare);

    // 배정 (일단 맨 처음 1개 배정함.)
    int cnt = 1;
    int now = v[0].end; 
    for (int i=1; i<N; i++) {
        // 현재 시간이 시작시간보다 크다면 다음 회의를 검사
        if (now > v[i].start) {continue;}
        // 같거나 작으면 회의 배정 (현재시간을 종료시간으로 갱신)
        else {
            now = v[i].end; cnt++;
        }
    }

    cout << cnt;

    return 0;
}


// 문제 풀이에 왕도는 없음, 정렬하는 방법들을 여러가지 생각하고 반례들을 생각하면서 올바른 정렬방식을 찾는 것임.
// 어떤 것을 정렬할까? start, end, size(end-start) ....
// end를 기준으로 오름차순 정렬할까? -> 오 되네.. 이런식으로...