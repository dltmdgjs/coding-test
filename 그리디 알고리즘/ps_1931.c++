// 문제 : 회의실 배정
// 알고리즘 분류 : 그리디 (현재의 최선의 선택이 전체 최적해가 됨.)

// 1. 회의가 끝나는 시간을 기준으로 오름차순 정렬
// 2. 회의가 끝나는 시간이 같다면 시작시간이 빠른 순으로 정렬
// 3. 끝나는 시간이 빠른 회의부터 선택하는데 시작시간이 이전 회의의 끝나는 시간보다 빠르면 선택하지 않고 다음으로 넘어감.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector< pair<int, int> > v;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second < p2.second) {
        return true;
    }
    if (p1.second == p2.second && p1.first <= p2.first) {
        return true;
    }
    return false;
}

int main() {
    // 입력
    cin >> N;
    for (int i=0; i<N; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        v.push_back(p);
    }

    // 오름차순 정렬(끝나는 시간 기준)
    sort(v.begin(), v.end(), compare);
    
    int count = 1;
    pair<int, int> meetingInProgress = v[0];
    for (int i=1; i<N; i++) {
        // 현재 진행중인 회의의 끝나는 시간보다 시작시간이 같거나 큰 경우.
        if (v[i].first >= meetingInProgress.second) {
            count++;
            meetingInProgress = v[i];
        }
    }

    cout << count << "\n";
    return 0;
}
