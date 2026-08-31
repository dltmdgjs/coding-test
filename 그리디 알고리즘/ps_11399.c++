// 문제 : ATM
// 알고리즘 분류 : 그리디

// 방법 1 : 수학적으로 풀기
// 1. 받은 수를 정렬한다. (오름차순)
// 2. result += (N-i) * v[i] 를 반복한다. (i=0; i<N)
// 3. result를 출력한다.

// 방법 2 : 각 수를 갱신하기
// 1. 받은 수를 정렬한다. (오름차순)
// 2. v[i] += v[i-1] 로 갱신한다.
// 3. 갱신한 수를 모두 더하여 출력한다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    vector<int> v;
    int P_total = 0;

    cin >> N;

    for (int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    for (int i=0; i<N; i++) {
        P_total += (N-i) * v[i];
    }

    cout << P_total << "\n";

    return 0;
}



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    vector<int> v;
    int P_total = 0;

    cin >> N;

    for (int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());
    P_total = v[0];

    for (int i=1; i<N; i++) {
        v[i] += v[i-1];
        P_total += v[i];
    }

    cout << P_total << "\n";

    return 0;
}