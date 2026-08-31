// 일곱난쟁이 - 브론즈 1
// 알고리즘 분류 : 브루트포스, 정렬

#include <bits/stdc++.h>
using namespace std;

int a[9];


int sum_height(int i, int j) {
    int sum=0;
    for (int k=0; k<9; k++) {
        if (k == i || k == j) {
            continue;
        }
        sum+=a[k];
    }
    return sum;
}

void print(int i, int j) {
    for (int k=0; k<9; k++) {
        if (k == i || k == j) {
            continue;
        }
        cout << a[k] << '\n';
    }
}


int main() {

    // 입력
    for (int i=0; i<9; i++) {
        cin >> a[i];
    }

    // 정렬
    sort(a, a+9);

    // 2개씩 제외해 합 계산
    for (int i=0; i<=7; i++) {
        int h;
        for (int j=i+1; j<=8; j++) {
            h = sum_height(i, j);
            if (h == 100) {
                print(i, j);
                break;
            }
        }
        if (h == 100) {
            break;
        }
    }

    return 0;
}

// 위 풀이 수정 1 - sum_height로 계속 더해보지 말고, 
//             (9개의 합 - (a[i] + a[j])) == 100 인지 검사해도 됨

// 위 풀이 수정 2 - break 두 번 하지 말고 한번에 끝내기 위해 exit(0)를 사용.


// 다른 풀이법 1 - 순열(next_permutation)을 이용 
//              (가능한 이유 : 9!/2! = 18만 정도 밖에 안됨)

//              sort(a, a+9);

//              do {
//                  int sum = 0;
//                  for (int i=0; i<7; i++) sum += a[i];
//                  if (sum == 100) break; 
//              } while (next_permutation(a, a+9));

//              for (int i=0; i<7; i++) {
//                  cout << a[i] << '\n';
//              }



// 다른 풀이법 2 - 순열을 재귀함수로 구현 (사고의 유연성을 위해 연습)

            // void print() {
            //     for (int i=0; i<7; i++) {
            //         cout << a[i] << '\n';
            //     }
            // }

            // void solve() {
            //     int sum = 0;
            //     for (int i=0; i<7; i++) sum += a[i];
            //     if (sum == 100) {
            //          sort(a, a+7);
            //          print();
            //          exit(0);
            //     } 
            // }

            // void makePermutation(int n, int r, int depth) {
            //     if (r==depth) {
            //         [로직]
            //         solve();
            //         return;
            //     }
            //     for (int i=depth; i<n; i++) {
            //         swap(a[i], a[depth]);
            //         makePermutation(n, r, depth + 1);
            //         swap(a[i], a[depth]);
            //     }
            //     return;
            // }
            // ..
            // int main() {
            //     makePermutation(9, 1, 0);
            //}