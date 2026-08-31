// 기상캐스터 - 실버 5
// 알고리즘 분류 : 구현, 시뮬레이션


// 내 풀이
// #include <bits/stdc++.h>
// using namespace std;

// int h, w, r[101][101];
// char a[101][101];
// bool visited[101][101];

// int main() {
//     fill(&r[0][0], &r[0][0]+101*101, -1);

//     cin >> h >> w;
//     for (int i=0; i<h; i++) {
//         string s;
//         cin >> s;
//         for (int j=0; j<w; j++) {
//             a[i][j] = s[j];
//         }
//     }

//     for (int cnt=0; cnt<w; cnt++) {

//         // 구름 체크해 갱신
//         for (int i=0; i<h; i++) {
//             for (int j=0; j<w; j++) {
//                 if (a[i][j] == 'c' && !visited[i][j]) {
//                     r[i][j] = cnt;
//                     visited[i][j] = true;
//                 }
//             }
//         }

//         // 임시 복사
//         char tmp[101][101];
//         for (int i=0; i<h; i++) {
//             for (int j=0; j<w; j++) {
//                 tmp[i][j] = a[i][j];
//             }
//         }

//         // 동쪽으로 1칸 이동
//         for (int i=0; i<h; i++) {
//             for (int j=0; j<w; j++) {
//                 if (tmp[i][j] == 'c') {
//                     a[i][j] = '.';
//                     if (j+1<w) a[i][j+1] = 'c';
//                 }
//             }
//         }
//     }

//     for (int i=0; i<h; i++) {
//         for (int j=0; j<w; j++) {
//             cout << r[i][j] << " ";
//         }
//         cout << '\n';
//     }

// }


// -------------------------------------------------------------

// 다른 풀이
#include <bits/stdc++.h>
using namespace std;  

int n, m, a[104][104];
string s; 

int main () {
    // 입력
	cin >> n >> m; 
	for(int i = 0; i < n; i++){
		cin >> s; 
		for(int j = 0; j < m; j++){ 
			if(s[j] == '.')a[i][j] = -1;
			else a[i][j] = 0;
		}
	}

    // 로직
	for(int i = 0; i < n; i++){ 
		for(int j = 0; j < m; j++){
            // 구름이 처음 있는 지점인 경우
			if(a[i][j] == 0){
				int cnt = 1;
                // 동쪽으로 쭉 갱신 (범위 주의)
				while(a[i][j + 1] == -1 && j+1 < m){
					a[i][j + 1] = cnt++;
					j++;
				}
			}
		}
	}

    // 출력
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) cout << a[i][j] << " ";
		cout << "\n";
	} 
	return 0;
}