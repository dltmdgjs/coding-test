#include <bits/stdc++.h>
using namespace std;  
typedef long long ll;


const ll INF = 1e18;   
int n, c, a[1004];
vector<pair<int, int>> v; // map은 정렬이 안되어서 정렬을 위해 벡터를 사용한 것까지는 잘 했음.
map<int, int> mp, mp_first; // 개선점 1 : 하지만, 정렬 기준에는 동일 빈도 시 기존 순서를 유지해야하는 제약이 있어, 따로 순서 맵을 만들어 정렬함수에 활용했어야 함.
// 이런 추가적인 조건을 뒤늦게 알아차려도 귀찮아 하지 말고 망설이지 말고 떠오르는 아이디어를 빠르게 적용해야함.

bool cmp(pair<int,int> a, pair<int, int> b){
    if(a.first == b.first){
        return mp_first[a.second] < mp_first[b.second];
    }
    return a.first > b.first;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> c; 

    for(int i = 0; i < n; i++){
        cin >> a[i];mp[a[i]]++;
        if(mp_first[a[i]] == 0) mp_first[a[i]] = i + 1; 
    } 

    for(auto it : mp){
        v.push_back({it.second, it.first});
    }

    sort(v.begin(), v.end(), cmp);

    for(auto i : v){
        for(int j = 0; j < i.first; j++){
            cout << i.second << " ";
        }
    } 
     
    return 0;
}
