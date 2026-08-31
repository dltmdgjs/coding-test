// 보석 도둑 - 골드 2
// 알고리즘 분류 : 자료구조, 그리디, 정렬, 우선순위 큐

#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

struct T{
    ll M, V; // 무게, 가격
    // 무게 오름차순, 가격 내림차순 정렬
    bool operator < (const T& other) const {
        if (M > other.M) {return true;}
        if (M == other.M) {
            return V < other.V;
        }
        return false;
    }
};

int N, K;
priority_queue<T> jewel;
vector<int> bag; //1개의 가방에는 최대 1개의 보석만 넣을 수 있음.
priority_queue<int> pq; // 후보 가치. (내림차순)
ll res; // 결과

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // 입력
    cin >> N >> K;
    for (int i=0; i<N; i++) {
        ll mi, vi; cin >> mi >> vi;
        jewel.push({mi, vi});
    }
    for (int i=0; i<K; i++) {
        int ci; cin >> ci;
        bag.push_back(ci);
    }

    // 정렬 - 가방 (오름차순)
    sort(bag.begin(), bag.end());

    // 각 가방에 대한 후보군을 생성함.
    for (int b : bag) {
        // 가방 용량보다 같거나 작은 보석들을 우선순위 큐(내림차순)에 넣음
        while (jewel.size()) {
            T u = jewel.top();
            if (u.M <= b) {
                jewel.pop();
                pq.push(u.V);
            } else {
                break;
            }
        }
        if (pq.size()) {
            res += pq.top(); pq.pop(); // 후보군 중 가장 가치가 큰 보석을 넣음.
        }
        // 이전에 넣은 보석들이 다음 주머니에서도 쓰일 수 있음을 보장함 (용량 오름차순 정렬 되었으므로..)
    }

    cout << res;
    return 0;
}


// idea : 각 가방에 들어갈 수 있는 보석들(후보군) 중 가장 가치가 높은 보석을 넣자.
// sort : 가방 - 용량 오름차순 정렬, 보석 - 무게 오름차순, 가치 내림차순 정렬
// 후보군 자료구조 : 우선순위 큐 (가치 내림차순 정렬 (top이 가장 큰 값으로))