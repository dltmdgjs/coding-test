// 경사로 - 골드 3
// 알고리즘 분류 : 구현

// 내 구현 -> 행 열 구분해 각각 로직 구현해 구함
// 더 쉬운 구현 -> N*N Map을 주성분 대칭시키면 같은 로직을 행/열 구분 없이 구현 가능함.

#include <bits/stdc++.h>
using namespace std;


int N, L, a[100][100];

int main() {
    cin >> N >> L;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    // 행
    for (int i=0; i<N; i++) {
        bool flag = true;
        vector<int> v;
        int prev = a[i][0];
        v.push_back(0);
        for (int k=1; k<N; k++) {
            int d = abs(prev - a[i][k]);
            if (d > 1) {flag = false; break;}
            else if (d == 0) {v.push_back(k); prev = a[i][k];}
            else if (d == 1) {
                if(prev>a[i][k]) {
                    for (int l=1; l<L; l++) {
                        if (k+l >= N || a[i][k+l] != a[i][k]) {
                            flag = false;
                            break;
                        }
                    }
                    k += L-1;
                    v.clear();
                    // v.push_back(k);
                    prev = a[i][k]; 
                }
                else {
                    if (v.size() < L) {
                        flag = false;
                        break;
                    } 
                    v.clear();
                    v.push_back(k);
                    prev = a[i][k]; 
                } 
            }
        }

        if (flag) {
            cnt++;
        }
    }

    // 열
    for (int i=0; i<N; i++) {
        bool flag = true;
        vector<int> v;
        int prev = a[0][i];
        v.push_back(0);
        for (int k=1; k<N; k++) {
            int d = abs(prev - a[k][i]);
            if (d > 1) {flag = false; break;}
            else if (d == 0) {v.push_back(k); prev = a[k][i];}
            else if (d == 1) {
                if(prev>a[k][i]) {
                    for (int l=1; l<L; l++) {
                        if (k+l >= N || a[k+l][i] != a[k][i]) {
                            flag = false;
                            break;
                        }
                    }
                    k += L-1;
                    v.clear();
                    // v.push_back(k);
                    prev = a[k][i]; 
                }
                else {
                    if (v.size() < L) {
                        flag = false;
                        break;
                    } 
                    v.clear();
                    v.push_back(k);
                    prev = a[k][i]; 
                } 
            }
        }

        if (flag) {
            cnt++;
        }
    }

    cout << cnt;


    return 0;
}



// 다른 풀이 - map 반전 이용, 음수 변수를 이용
#include<bits/stdc++.h>
using namespace std; 

int n, l, a[104][104], b[104][104], ret; 

void solve(int a[104][104]){
    for(int i = 0; i < n; i++){
        int cnt = 1; // 동일한 높이 블록의 연속된 개수(길이)
        int j;  
        for(j = 0; j < n - 1; j++){
            if(a[i][j] == a[i][j + 1])cnt++; 
            else if(a[i][j] + 1 == a[i][j + 1] && cnt >= l) cnt = 1; 
            else if(a[i][j] - 1 == a[i][j + 1] && cnt >= 0) cnt = -l + 1; // 음수를 이용하여 경사로가 반대로 놓여야 하는 경우 체크
            else break; 
        }
        if(j == n - 1 && cnt >= 0) ret++; 
    }
    return; 
} 

int main(){
    scanf("%d %d", &n, &l);
    for(int i = 0; i < n; i++){ 
        for(int j = 0; j < n; j++){
            scanf("%d", &a[i][j]); 
            b[j][i] = a[i][j];
        }
    }    
    solve(a); solve(b);  
    printf("%d\n", ret);  
    return 0; 
}