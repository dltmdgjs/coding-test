// 컵라면 - 골드 2
// 알고리즘 분류 : 그리디, 우선순위 큐(최소 힙)

// 5-a (2109)와 비슷한 문제.

#include <bits/stdc++.h>
using namespace std;

struct T {
    unsigned long long d, r;
    bool operator<(const T& other) const { // 데드라인 오름차순, 보상 내림차순 정렬
        if (d > other.d) return true;
        if (d == other.d) return  r < other.r;
        return false;
    }
};

priority_queue<T> pq; // 개선점 : 입력 받을 때 우선순위 큐를 활용하는 것 보다, vector로 입력받고 sort로 정렬하는 것이 더 시간효율적임(pq는 입력 시 매번 정렬하기 때문)
unsigned long long N, total, t=1;

int main() {
    cin >> N;

    for (int i=0; i<N; i++) {
        unsigned long long td, tr; cin >> td >> tr;
        T u = {td, tr};
        pq.push(u);
    }

    priority_queue<int, vector<int>, greater<>> temp; // 보상 오름차순 정렬
    while (pq.size()) {
        T u = pq.top(); pq.pop();
        temp.push(u.r);
        if (temp.size() > u.d) {
            temp.pop();
        }
    }

    while (temp.size()) {
        total += temp.top(); temp.pop();
    }
    cout << total;
    return 0;
}