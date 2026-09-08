// Fenwick Tree - 팬윅트리

// Fenwick Tree는 여러 크기의 부분 합을 저장해 두고, 이진수의 lowbit을 이용해서 필요한 구간만 빠르게 이동하는 자료구조다.

// 구간 합을 빠르게 구하고(logN), 값 변경도 빠르게 처리하는(logN) 자료구조. 
// Binary Indexed Tree라고도 불림.

// 누적 합을 이용하면 구간 합을 쉽게 구할 수 있지만,
// 누적 합은 정적 배열에 대해서만 가능하므로,
// 배열의 값 변경도 함께 있다면 팬윅트리를 이용하여야 한다.

// 팬윅트리의 핵심은 여러 구간의 합을 미리 나눠서 저장한다는 것임.



// 팬윅트리의 가장 중요한 공식 : i & -i == lowbit
// lowbit은 i의 이진 표현에서 가장 오른쪽에 있는 비트 1의 값을 의미함.

// 예를 들어
// 1 = 0001 → lowbit = 1
// 2 = 0010 → lowbit = 2
// 3 = 0011 → lowbit = 1
// 4 = 0100 → lowbit = 4
// 5 = 0101 → lowbit = 1
// 6 = 0110 → lowbit = 2
// 8 = 1000 → lowbit = 8

// 따라서 tree[i]는 i에서 끝나고, lowbit(i)개 원소를 포함하는 구간의 합을 의미함.
// ex) tree[6] = 6에서 끝나고, 2개의 원소를 포함하는 구간의 합 = arr[5] + arr[6]



// 그래서 1~특정 구간의 합은 어떻게 구하는 가?
// 1~6까지의 구간의 합을 구하는 방법
// tree[6] + tree[4]
// 왜 tree[4]인가? 
// -> 인덱스 이동 공식 : i -= (i & -i), 즉 현재 i에서 lowbit(i)를 빼면 됨.

// 이를 코드로 표현하면
// long long sum(int i) {
//     long long result = 0;

//     while (i > 0) {
//         result += tree[i];
//         i -= i & -i;
//     }

//     return result;
// }

// 참고) 3~6까지의 구간의 합을 구하고 싶다면, 누적합 개념을 이용하자.
// (1~6까지 합) - (1~2까지의 합). 



// 그럼 값 변경은 어떻게 하는 가?
// arr[3]의 값을 변경하고 싶다면, arr[3]을 포함하는 다른 모든 tree[]의 값들도 같이 변경해야함.
// -> 인덱스 이동 공식 : i += (i & -i), 즉 현재 i에서 lowbit(i)를 더하면 됨.

// 이를 코드로 표현하면
// void update(int i, long long diff) {
//     while (i <= n) {
//         tree[i] += diff;
//         i += i & -i;
//     }
// }

// 참고) diff = 변경된arr[i] - 과거arr[i]

// 참고) 팬윅트리는 보통 1번 인덱스부터 사용 (lowbit 비트연산 때문)

// 아래는 전체 코드임.
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<long long> tree;

void update(int i, long long diff) {
    while (i <= n) {
        tree[i] += diff;
        i += i & -i;
    }
}

long long sum(int i) {
    long long result = 0;

    while (i > 0) {
        result += tree[i];
        i -= i & -i;
    }

    return result;
}

long long rangeSum(int left, int right) {
    return sum(right) - sum(left - 1);
}