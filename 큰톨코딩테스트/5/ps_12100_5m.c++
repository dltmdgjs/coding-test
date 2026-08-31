#include <bits/stdc++.h>
using namespace std;
// 상1 하2 좌3 우4

int N, res;
int arr[20][20];


void move(vector<int> b) {
    // 원본 복사
    int temp[20][20];
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            temp[i][j] = arr[i][j];
        }
    }

    // TODO : 큐와 스택으로 구현했으면 더 쉬웠을지도..
    // TODO : 행렬을 회전시켰으면 굳이 상하좌우 나누지 않았어도 됨
    for (int k=0; k<5; k++) {
        if (b[k] == 1) { // 상
            for (int j=0; j<N; j++) {
                vector<int> v;
                for (int i=0; i<N; i++) {
                    if (temp[i][j] > 0) {v.push_back(temp[i][j]);}
                    temp[i][j] = 0;
                }

                if (v.size() == 0) {continue;}

                int past = 0; // 인덱스
                for (int i=1; i<v.size(); i++) {
                    if (v[i] == 0) continue;
                    if (v[i] == v[past]) {
                        v[i] = 0;
                        v[past] *= 2;
                    }
                    past = i;
                }

                vector<int> v1;
                for (int i=0; i<v.size(); i++) {
                    if (v[i]>0) {v1.push_back(v[i]);}
                }

                for (int i=0, w=0; i<v1.size(); i++, w++) {
                    temp[i][j] = v1[w];
                }
            }
        } else if (b[k] == 2) { // 하
            for (int j=0; j<N; j++) {
                vector<int> v;
                for (int i=N-1; i>=0; i--) {
                    if (temp[i][j] > 0) {v.push_back(temp[i][j]);}
                    temp[i][j] = 0;
                }

                if (v.size() == 0) {continue;}

                int past = 0; // 인덱스
                for (int i=1; i<v.size(); i++) {
                    if (v[i] == 0) continue;
                    if (v[i] == v[past]) {
                        v[i] = 0;
                        v[past] *= 2;
                    }
                    past = i;
                }

                vector<int> v1;
                for (int i=0; i<v.size(); i++) {
                    if (v[i]>0) {v1.push_back(v[i]);}
                }

                for (int i=N-1, w=0; i>(N-v1.size()); i--, w++) {
                    temp[i][j] = v1[w];
                }
            }
        } else if (b[k] == 3) { // 좌
            for (int i=0; i<N; i++) {
                vector<int> v;
                for (int j=0; j<N; j++) {
                    if (temp[i][j] > 0) {v.push_back(temp[i][j]);}
                    temp[i][j] = 0;
                }

                if (v.size() == 0) {continue;}

                int past = 0; // 인덱스
                for (int j=1; j<v.size(); j++) {
                    if (v[j] == 0) continue;
                    if (v[j] == v[past]) {
                        v[j] = 0;
                        v[past] *= 2;
                    }
                    past = j;
                }

                vector<int> v1;
                for (int j=0; j<v.size(); j++) {
                    if (v[j]>0) {v1.push_back(v[j]);}
                }

                for (int j=0, w=0; j<v1.size(); j++, w++) {
                    temp[i][j] = v1[w];
                }
            }
        } else if (b[k] == 4) { // 우
            for (int i=0; i<N; i++) {
                vector<int> v;
                for (int j=N-1; j>=0; j--) {
                    if (temp[i][j] > 0) {v.push_back(temp[i][j]);}
                    temp[i][j] = 0;
                }

                if (v.size() == 0) {continue;}

                int past = 0; // 인덱스
                for (int j=1; j<v.size(); j++) {
                    if (v[j] == 0) continue;
                    if (v[j] == v[past]) {
                        v[j] = 0;
                        v[past] *= 2;
                    }
                    past = j;
                }

                vector<int> v1;
                for (int j=0; j<v.size(); j++) {
                    if (v[j]>0) {v1.push_back(v[j]);}
                }

                for (int j=N-1, w=0; j>(N-v1.size()); j--, w++) {
                    temp[i][j] = v1[w];
                }
            }
        }
    }

    // 계산
    int mx = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (temp[i][j] > mx) {
                mx = temp[i][j];
            }
        }
    }

    res = max(res, mx);
}

void recur(vector<int> b) {
    if (b.size() == 5) {
        // 계산 및 최댓값 갱신
        move(b);
        return;
    }
    for (int i=1; i<=4; i++) {
        b.push_back(i);
        recur(b);
        b.pop_back();
    }
}

int main() {

    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }

    vector<int> b;
    recur(b);

    cout << res;

    return 0;
}