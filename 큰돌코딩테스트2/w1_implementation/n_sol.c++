#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;

ll a, b, c;


// 차이점 : 여기에선 반복문이 아닌 재귀 호출을 이용함.
// 자세한 차이는 아직 잘 모르겠음 (동작 원리가 이해 안감..)
ll go(ll a, ll b){
    if(b == 1) {
        return a % c;
    }

    ll ret = go(a, b / 2);
    ret = (ret * ret) % c;

    if(b % 2) {
        ret = (ret * a)% c;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;

    cout << go(a, b) << "\n";

    return 0;
}
