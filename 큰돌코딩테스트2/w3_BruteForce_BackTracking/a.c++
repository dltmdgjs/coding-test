// 치킨 배달 - BOJ 15686

// 1. 치킨집 위치를 저장할 공간 필요.
// 2. 잡의 위치를 저장할 공간 필요.
// 3. 최대 M개를 고른다는 것은 1개에서 M개를 고르는 경우의 수를 나눠하 한다는 의미이고.
// 4. 각 M_i에서 치킨집 M_i개를 선택하는 조합도 생각해야하고, 
// 5. 그 조합에서 도시의 치킨거리를 구해 갱신해 나가야 함.

// 개선점 1 : 1~M으로 경우를 분할할 필요가 없음. M개가 되는 조합으로 전부 그 하위의 경우를 커버가능함. (치킨집을 더 선택한다 해도 값이 바뀌지는 않으니..)
// 다만 문제에서 만약 선택된 치킨집을 출력하라는 요구가 있을 경우에는 현재 내 코드가 더 직관적이고 유리함.

#include <bits/stdc++.h>
using namespace std;

int N, M, total_distance = 98765432;
vector<pair<int, int> > c, h; // 치킨집과 집의 위치 

void calculate_total_distance(vector<pair<int, int> > &a) {
    int sum = 0;
    for (pair<int, int> house : h) {
        int distance = 98765432;
        for (pair<int, int> chicken : a) {
            int temp = abs(house.first - chicken.first) + abs(house.second - chicken.second);
            distance = min(distance, temp);
        }
        sum += distance;
    }
    total_distance = min(total_distance, sum);
}

void combi(vector<pair<int, int> > &a, int start, int count) {
    if (a.size() == count) {
        // 4. 해당 조합에서 도시의 치킨거리 계산 -> 갱신
        calculate_total_distance(a);
        return;
    }
    
    for (int i=start; i<c.size(); i++) {
        a.push_back(c[i]);
        combi(a, i+1, count);
        a.pop_back();
    }

    return;
}

int main() {
    // 1. 도시 정보 입력 받기
    cin >> N >> M;

    int num;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> num;
            if (num == 1) {
                h.push_back({i, j}); // 집 위치 저장
            } else if (num == 2) {
                c.push_back({i, j}); // 치킨집 위치 저장
            }
        }
    }

    // 2. 1~M까지 증가시키며 케이스를 나눔 (최대 M개의 치킨집을 남기는 상황)
    for (int i=1; i<=M; i++) {
        // 3. i개의 치킨집 조합 생성하기.
        vector<pair<int, int> > v;
        combi(v, 0, i);
    }

    cout << total_distance;

    return 0;
}

