// 문제 : 동전 0
// 알고리즘 분류 : 그리디

// 몫과 나머지를 이용한 풀이.
// 1. N과 K를 입력받는다.
// 2. 동전을 N번 입력받는다.(오름차순)
// 3. 동전을 큰 것부터 한개씩 써가며 나눈 몫을 count에 더하고 나머지를 K로 갱신한다.
// 4. K(나머지)가 0에 도달하면 멈춘다.

#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K;
    int count = 0;

    cin >> N >> K;
    int coin[N];

    for(int i=0;i<N;i++) {
        cin >> coin[i];
    }

    for (int i=(N-1); i>=0; i--) {
        count += K / coin[i];
        K = K % coin[i];
        if (K == 0) break;
    }

    cout << count << endl;
    return 0;
}



// 다른 풀이 1

// 1. N과 K를 입력받는다.
// 2. 동전을 N번 입력받는다.(오름차순)
// 3. 동전을 큰 것부터 한개씩 써가며 개수를 센다. (임시값과 목표값을 비교)
//    이때 원하는 값을 넘으면 다음으로 큰 동전을 쓴다.
// 4. 원하는 값에 도달하면 멈춘다.

#include <iostream>
using namespace std;


int main() {
    int N,K;
    int count = 0;
    int tempValue = 0;

    cin >> N >> K;
    int coin[N];

    for(int i=0;i<N;i++) {
        cin >> coin[i];
    }

    for (int i=N-1; i>=0; i--) {
        while(1) {
            if (tempValue < K) {
                tempValue += coin[i];
                count++;
            } else if (tempValue > K) {
                tempValue -= coin[i];
                count--;
                break;
            }  else break;
        }
        if (tempValue == K) break;
    }

    cout << count << endl;
    return 0;
}



// 다른 풀이 2

// 1. N과 K를 입력받는다.
// 2. 동전을 N번 입력받는다.(오름차순)
// 3. 동전을 큰 것부터 한개씩 써가며 개수를 센다.(목표값에서 동전을 뺌.)
//    이때 K값이 0보다 작아지면 다음으로 큰 동전을 쓴다.
// 4. K값이 0에 도달하면 멈춘다.

#include <iostream>
using namespace std;


int main() {
    int N,K;
    int count = 0;

    cin >> N >> K;
    int coin[N];

    for(int i=0;i<N;i++) {
        cin >> coin[i];
    }

    for (int i=(N-1); i>=0; i--) {
        while(K > 0) {
            K -= coin[i];
            count++;
        }
        if (K == 0) break;
        else {
            K += coin[i];
            count--;
        }
    }

    cout << count << endl;
    return 0;
}