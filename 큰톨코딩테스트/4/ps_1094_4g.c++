// 막대기 - 실버 5
// 알고리즘 분류 : 수학, 비트마스킹

// #include <bits/stdc++.h>
// using namespace std;


// int X, cnt, stick = 64;
// vector<int> v;

// int main() {

//     cin >> X;

//     if (X == 64) {cout << 1; return 0;}

//     while(true) {
//         // 반 갈라 하나만 저장소에 집어넣음.
//         if (!v.empty()) v.pop_back();
//         stick /= 2;
//         v.push_back(stick);
//         // 저장소의 합이 X보다 크거나 같으면 그대로 둠, 작으면 나머지 반 집어넣음.
//         int sum = 0;
//         for (int i : v) {
//             sum+=i;
//         }
//         if (sum < X){
//             v.push_back(stick);
//         } 
//         // 저장소의 합이 X와 같으면 break; 
//         else if (sum == X) break;
//     }

//     cout << v.size();

//     return 0;
// }


// 비트마스킹으로 풀어보자
// 2^6 => 1000000 = (1<<6)

#include <bits/stdc++.h>
using namespace std;
int X, cnt;
int main() {
    cin >> X;
    for (int i=0; i<7; i++) { if (X & (1<<i)) cnt++; }
    cout << cnt;
    return 0;
}