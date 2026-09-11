// 일곱 난쟁이 - BOJ 2309

// 핵심 : 키의 합이 100이 되는 조합을 찾으면 됨.

// 일단 브루트 포스 + 조합으로 풀어보자.
// 근데 9C7 = 9C2이므로 2개를 골라서 전체 합에서 빼는 방식으로 검사하면 됨.
// 정렬된 채로 출력해야함. -> 뭔가 코드 개선의 힌트일수도. -> 순열(next_permutation)을 이용.

#include <bits/stdc++.h>
using namespace std;

vector<int> height;
int total;

void combi(vector<int> &a, int start) {
    if (a.size() == 2 && total - (height[a[0]]+height[a[1]]) == 100) {
        for (int i=0; i<9; i++) {
            if (i == a[0] || i == a[1]) {continue;}
            cout << height[i] << '\n';
        }
        exit(0);
    }

    for (int i=start; i<9; i++) {
        a.push_back(i);
        combi(a, i+1);
        a.pop_back();
    }
}

int main() {

    int input;

    for (int i=0; i<9; i++) {
        cin >> input;
        height.push_back(input);
        total+=input;
    }

    sort(height.begin(), height.end());

    vector<int> v;

    combi(v, 0);

    return 0;
}