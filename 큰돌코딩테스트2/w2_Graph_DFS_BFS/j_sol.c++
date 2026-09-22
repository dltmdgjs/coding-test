#include <bits/stdc++.h>
using namespace std;  


int n, m, a[104][104];
string s; 

int main () {
    // 내 코드와의 차이점 : 난 시간이 지남에 따른 도시의 상태변화를 직접 업데이트함.
    // 하지만 해설 코드는 구름이 있는 위치에서 그 오른쪽을 탐색하여 시간을 반영함.
    // 해당 문제는 해설 코드 방식이 더 적절하긴 하지만, 삼성 코테의 경우 내 풀이 식으로 진행되어야 하는 경우가 많음.

    cin >> n >> m; 
    for(int i = 0; i < n; i++){
        cin >> s; 
        for(int j = 0; j < m; j++){ 
            if(s[j] == '.')a[i][j] = -1;
            else a[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++){ 
        for(int j = 0; j < m; j++){
            if(a[i][j] == 0){ 
                int cnt = 1;
                while(a[i][j + 1] == -1){
                    a[i][j + 1] = cnt++;
                    j++;
                } 
            }
        } 
    } 

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << a[i][j] << " ";
        cout << "\n";
    } 
    return 0;
}
