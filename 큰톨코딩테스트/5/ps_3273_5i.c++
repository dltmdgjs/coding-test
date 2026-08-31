#include <bits/stdc++.h>
using namespace std;

int n, x, res;
vector<int> v;

int main() {
    
    cin >> n;
    for (int i=0; i<n; i++) {
        int t; cin >> t;
        v.push_back(t);
    }
    cin >> x;

    sort(v.begin(), v.end());

    int left = 0, right = n-1;
    while (left < right) {
        int sum = v[left] + v[right];
        if (sum > x) {right--;}
        else if (sum < x) {left++;}
        else if (sum == x) {res++; left++;}
    }

    cout << res;

    return 0;
}