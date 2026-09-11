#include <bits/stdc++.h>
using namespace std;


vector<int> v;

int main() {

    int temp;
    for(int i=0; i<9; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end()); // 개선점 1 : 순열 생성 전, 오름차순 정렬 필요.

    do {
        int sum=0;
        for (int i=0; i<7; i++) {
            sum+=v[i];
        }
        if (sum == 100) {
            break;
        }
    } while(next_permutation(v.begin(), v.end()));

    for (int i=0; i<7; i++) {
        cout << v[i] << '\n';
    }

    return 0;
}