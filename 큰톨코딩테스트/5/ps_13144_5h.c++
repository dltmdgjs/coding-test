// 틀림 (26.05.15)
// List of Unique Numbers

#include <bits/stdc++.h>

using namespace std;


int main() {


    return 0;
}

// 브루트 포스를 사용 -> O(N^2)이므로 연산 횟수가 100억이 되므로 1초안에 해결 불가능

// 투 포인터를 사용 -> 두 포인터가 최대 N번씩만 이동하므로 O(N), 1초안에 해결 가능

// 투 포인터
    // left, right 옮기는 정책 세우기
        // left : right를 옮겼을때 중복되는 수를 찾았다면, left를 앞전에 그 수가 나온 뒤의 위치로 옮김.
        // right : 중복되는 수가 나오기 전까지 계속 옮김.

    // 개수 세는 정책 세우기
        // left에서 시작하는 연속하는 수열의 개수는 (right-left+1)개임

    // 중복 체크 정책 세우기
        // boolean 배열로 숫자가 나왔는지 체크함.