#include <bits/stdc++.h>
using namespace std;

int n, m, a[54][54], result = 987654321;
vector<vector<int>>chickenList;
vector<pair<int, int>> _home, chicken;

// 차이점 1 : 나는 조합을 만들어 낸 직후 치킨거리를 바로 계산함.
// 여기에서는 조합을 전부 생성해 벡터에 저장(인덱스만)하고,
// 메인 함수에서 각 조합의 치킨거리를 계산함.

// 차이점 2 : 나는 '최대 M개'를 1~M개를 모두 검사해야 한다고 생각했지만,
// 해설에서는 정확히 M개의 치킨집만 선택함.
// 치킨집을 더 남긴다고 도시의 치킨거리가 증가할 수는 없기 때문에
// 최소값을 구하는 이 문제에서는 M개를 선택한 경우만 검사하면 됨.

// 차이점 3 : 나는 선택한 치킨집의 좌표 자체를 조합 벡터에 저장하지만,
// 해설에서는 chicken 벡터의 인덱스를 저장함.

// 차이점 4 : 조합 생성 시 나는 start부터 탐색하고,
// 해설에서는 start + 1부터 탐색함.
// 초기값이 각각 0과 -1이므로 실질적인 동작은 동일함.

void combi(int start, vector<int> v){
    if(v.size() == m){
        chickenList.push_back(v);
        return;
    }
    for(int i = start + 1; i < chicken.size(); i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 1)_home.push_back({i, j});
            if(a[i][j] == 2)chicken.push_back({i, j});
        }
    }

    vector<int> v;
    combi(-1, v);

    for(vector<int> cList : chickenList){
        int ret = 0;
        for(pair<int, int> home : _home){
            int _min = 987654321;
            for(int ch : cList){
                int _dist = abs(home.first - chicken[ch].first) + abs(home.second - chicken[ch].second);
                _min = min(_min, _dist);
            }
            ret += _min;
        }
        result = min(result, ret);
    }

    cout << result << "\n";
    return 0;
}
