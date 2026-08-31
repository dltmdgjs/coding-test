// 큰 수 A+B (2) - 실버 3
// 알고리즘 분류 : 수학, 문자열, 사칙연산, 임의 정밀도 / 큰 수 연산


#include <bits/stdc++.h>
using namespace std;

string a, b;
vector<int> v1, v2, r;
int olim;

int main() {
    cin >> a >> b;
    // cout << a.size() << ", " << b.size();
    for (int i=a.size()-1; i>=0; i--) {
        v1.push_back(a[i]-'0');
        // cout << a[i]-'0';
    }
    for (int i=b.size()-1; i>=0; i--) {
        v2.push_back(b[i]-'0');
    }

    int mx = max(a.size(), b.size());

    for (int i=0; i<mx; i++) {
        int sum = olim;
        if (i >= v1.size()) {
            sum += v2[i];
        } else if (i >= v2.size()) {
            sum += v1[i];
        } else {
            sum += v1[i] + v2[i];
        }
        olim = sum/10;
        r.push_back(sum%10);
    }
    if (olim > 0) {
        r.push_back(olim);
    }

    for (int i=r.size()-1; i>=0; i--) {
        cout << r[i];
    }

    return 0;
}