#include <iostream>
using namespace std;

void canReverse(int a) {
    if (a == 1) {
        cout << 1 << ' ';
    } else if (a == 2) {
        cout << 5 << ' ';
    } else if (a == 5) {
        cout << 2 << ' ';
    } else if (a == 8) {
        cout << 8 << ' ';
    } else {
        cout << '?' << ' ';
    }
}


int main() {
    int array[21][21];
    int N;
    char W;

    // 입력
    cin >> W >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++){
            cin >> array[i][j];
        }
    }

    // L, R -> i를 N-i-1와 변경 (1=1,8=8,2=5,5=2,이외=?)
    if (W == 'L' || W == 'R') {
        for (int i=0; i<N; i++) {
            for (int j=N-1; j>=0; j--) {
                canReverse(array[i][j]);
            }
            cout << '\n';
        }
    }

    // U, D -> j를 N-J-1와 변경 (1=1,8=8,2=5,5=2,이외=?)
    else if (W == 'U' || W == 'D') {
        for (int i=N-1; i>=0; i--) {
            for (int j=0; j<N; j++) {
                canReverse(array[i][j]);
            }
            cout << '\n';
        }
    }
    
}