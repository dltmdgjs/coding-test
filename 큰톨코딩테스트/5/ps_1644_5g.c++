// 소수의 연속합 - 골드 3
// 알고리즘 분류 : 수학, 정수론, 투 포인터, 소수판정, 에라토스테네스의 체

#include <bits/stdc++.h>
using namespace std;
#define MAX 4000001

int N, cnt;
vector<int> v; // 소수 (1~N)
bool visited[MAX]; 

int main() {
    cin >> N;

// 에라토스테네스 체 - 소수 구하기 
// (원리 : 해당 수를 방문한적 없으면 무조건 소수임. 
//        소수의 배수를 모두 방문처리 -> 그 수들은 소수가 아님)
    for (int i=2; i<=N; i++) {
        // 소수가 아니면 continue;
        if (visited[i]) continue; 
        // 소수이면 저장 후 모든 배수들을 방문처리
        v.push_back(i); 
        int k = 1;
        while (i*k<=N) {
            visited[i*k] = true;
            k++;
        }
    }

// 아래 코드는 투 포인터를 사용하여 시간을 더 개선할 수 있음 (투 포인터 - 가변 길이의 구간 누적합을 O(N)으로 탐색 가능하게 됨.)
// 개선 후 코드
    int start = 0, end = 0;
    int sum = 0;
    while (true) {
        if (sum >= N) {sum -= v[start]; start++;}
        else if (end == v.size()) {
            break;
        } else {
            sum += v[end]; end++;
        }
        if (sum == N) {cnt++;}
    }

// 개선 전 코드
    // for (int i=0; i<v.size(); i++) {
    //     int sum = v[i];
    //     if (sum == N) {cnt++; continue;}
    //     for (int j=i+1; j<v.size(); j++) {
    //         sum += v[j];
    //         if (sum == N) {cnt++; break;}
    //         if (sum > N) {break;}
    //     }
    // }

    cout << cnt;

    return 0;
}