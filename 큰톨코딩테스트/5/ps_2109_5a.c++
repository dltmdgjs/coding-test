// 순회 강연
// 알고리즘 분류 : 자료구조, 그리디, 정렬, 우선순위 큐

// 그리디 -> 정렬 , 우선순위 큐 활용하자.

// 내 풀이 (사실 이것도 힌트 얻어서 한거임...) 다시 풀어보기..
#include <bits/stdc++.h>
using namespace std;

int n, k, sum, day[10001];
vector<pair<int,int>> v;

bool compare(pair<int,int> a, pair<int,int> b) {
    if (a.first > b.first) {return true;}
    return false;
}

int main() {
    // 입력
    cin >> n;
    for (int i=0; i<n; i++) {
        int p, d;
        cin >> p >> d;
        v.push_back({p, d});
    }

    // 정렬 수행.
    sort(v.begin(), v.end(), compare);

    // 로직
    for (auto i : v) {
        k=i.second;
        if (day[i.second] == 0) day[i.second] = i.first;
        else {
            k--;
            while (k > 0) {
                if (day[k] == 0) {day[k] = i.first; break;}
                k--;
            }
        }
    }
    for (int i=1; i<10001; i++) {
        sum += day[i];
    }
    cout << sum;
    
    return 0;
}



// 선생님 풀이 (우선순위 큐)
#include <bits/stdc++.h>
using namespace std;

// priority_queue<int> pq; -> 오름차순 정렬됨 (top이 가장 큰 값임.)
priority_queue<int, vector<int>, greater<>> pq; // -> 오름차순 정렬됨 (top이 가장 작은 값)
int n, sum;
vector<pair<int, int>> v;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        int d, p; cin >> p >> d;
        v.push_back({d, p});
    }

    // 정렬 (d 오름차순, p 오름차순)
    sort(v.begin(), v.end());

    // 우선순위 큐
    for (auto i : v) {
        pq.push(i.second); // p를 삽입한다 (자동으로 오름차순 정렬되어 가장 작은 값이 top으로 옴.)
        if (pq.size() > i.first) pq.pop(); // 큐의 크기가 d보다 크다면, pop을 해서 가장 작은걸 없앰.
    }

    while(pq.size()) {
        sum += pq.top();
        pq.pop();
    }

    cout << sum;

    return 0;
}