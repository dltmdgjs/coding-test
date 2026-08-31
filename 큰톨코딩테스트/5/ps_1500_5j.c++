// 운영체제 스케줄링 알고리즘 관련 
//    - optimal 알고리즘 : 더이상 참조되지 않거나 가장 나중에 참조되는 것을 스왑
#include <bits/stdc++.h>
using namespace std;

int n, k, res;
map<string, int> mp;
vector<string> v;
map<string, int> memory; // 제품명, 인덱스


int main() {

    cin >> n >> k;
    for (int i=0; i<k; i++) {
        string s; cin >> s;
        v.push_back(s);
        if (mp.find(s) != mp.end()) {
            mp[s] = i;
        } else {
            mp.insert({s, i}); // 마지막으로 나온 번쨰 수 
        }
    }



    for (int i=0; i<k; i++) {
        if (memory.find(v[i]) != memory.end()) {
            continue;
        } 
        if (memory.size() == n) {
            int idx = -1;
            string target;
            for (auto t : memory) {
                if (t.second < i) {
                    target = t.first;
                    break;
                }
                if (idx < t.second) {
                    idx = t.second;
                    target = t.first;
                }
            }
            //교체
            memory.erase(target);
            memory.insert({v[i], mp[v[i]]});
            res++;
        } 
        else if (memory.size() < n) {
            memory.insert({v[i], mp[v[i]]});
        }
    }

    cout << res;

    return 0;
}