#include <bits/stdc++.h>
using namespace std;


int N, K, L, cnt=1;
int direction[10000]; // 시간 별 방향 (L왼, D오)
int d=4; //상하좌우 1234
int arr[20][20];
// int dy[4] = {-1, 1, 0, 0}; // 상하좌우
// int dx[4] = {0, 0, -1, 1};
// TODO : 모듈러 연산으로 방향 전환 쉽게 구현 가능
// ex) 3에서 오른쪽 0으로 전환 -> (3+1)%4 = 0
// ex) 3에서 왼쪽 2로 전환 -> (3+3)%4 = 2
// 0
//3 1
// 2

int main() {

    cin >> N; 
    cin >> K;
    for (int i=0; i<K; i++) {
        int y, x; cin >> y >> x;
        arr[y-1][x-1] = 1;
    }

    cin >> L;
    for (int i=0; i<L; i++) {
        int t; char c; cin >> t >> c;
        if (c == 'L') {
            direction[t] = 1;
        } else {
            direction[t] = 2;
        }
    }

    int rh=0, ch=0; // 뱀 머리 위치
    // int rt=0, ct=0; // 뱀 꼬리 위치
    // 뱀 몸통은 스택으로 관리
    deque<pair<int, int>> snake;
    snake.push_back({0, 0});
    arr[0][0] = -1;
    while(true) {
        
        // 이동 (경계 및 몸통 조건 체크)
        if (d==1) {rh--;} 
        else if (d==2) {rh++;} 
        else if (d==3) {ch--;} 
        else if (d==4) {ch++;}
        if (ch < 0 || ch >= N || rh < 0 || rh >= N || arr[rh][ch] == -1) {break;}
        else {
            // 사과 - 사과 있으면 꼬리 그대로, 없으면 꼬리 삭제(-1 -> 0)
            if (arr[rh][ch] == 0) {
                int ty, tx;
                tie(ty, tx) = snake.front(); 
                snake.pop_front();
                arr[ty][tx] = 0;
            }
            snake.push_back({rh, ch});
            arr[rh][ch] = -1;
        }
        
        // 방향 갱신
        if (direction[cnt] == 1) {
            if (d==1) {d=3;} 
            else if (d==2) {d=4;} 
            else if (d==3) {d=2;} 
            else if (d==4) {d=1;}
        } else if (direction[cnt] == 2) {
            if (d==1) {d=4;} 
            else if (d==2) {d=3;} 
            else if (d==3) {d=1;} 
            else if (d==4) {d=2;}
        }
        cnt++;
    }

    cout << cnt;

    return 0;
}