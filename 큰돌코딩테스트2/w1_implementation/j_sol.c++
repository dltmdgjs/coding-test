#include <bits/stdc++.h>
using namespace std;
int t, n;
string a, b;
int main(){

    cin >> t;

    while(t--){
        map<string, int> _map;
        cin >> n;

         for(int i = 0; i < n; i++){
            cin >> a >> b;
            _map[b]++;
        }

        // 개선점 1 : 경우의 수 계산. (이분법 적으로 사고, 입거나 안입거나.)

        // 옷을 반드시 입어야 함 -> 전체 경우의 수에서 옷을 아예 안입는 경우를 제외하면 됨.
        // 전체 경우의 수 = 각 종류를 [입거나(몇가지) + 안입거나(1가지)] 하는 수를 곱하면 됨.

        // ex. 상의가 2벌, 하의가 3벌이면, (2+1) * (3+1) = 12가지 이고,
        // 아예 안입는 경우 1가지를 제외하면 최종 답은 11임.
        long long ret = 1;
        for(auto c : _map){
            ret *= ((long long)c.second + 1);
        }
        ret--;

        cout << ret << "\n";
    }
    return 0;
}
