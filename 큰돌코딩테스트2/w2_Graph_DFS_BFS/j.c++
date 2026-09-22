// 기상캐스터 - BOJ 10709

#include <bits/stdc++.h>
using namespace std;
#define MAX 104


int H, W, t[MAX][MAX], idx = 0;
char city[MAX][MAX], temp[MAX][MAX];

int main() {

    fill(&t[0][0], &t[0][0] + MAX*MAX, -1);

    cin >> H >> W;

    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            cin >> city[i][j];
        }
    }


    while (true) {
        bool noCloud = true;

        fill(&temp[0][0],&temp[0][0]+MAX*MAX, '.');

        for (int i=0; i<H; i++) {
            for (int j=0; j<W; j++) {
                if (city[i][j] == 'c' && t[i][j] == -1) {
                    t[i][j] = idx;
                    temp[i][j+1] = 'c';
                    noCloud = false;
                }
            }
        }

        if (noCloud) break;

        for (int i=0; i<H; i++) {
            for (int j=0; j<W; j++) {
                city[i][j] = temp[i][j];
            }
        }

        idx++;
    }

    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            cout << t[i][j] << " ";
        }
        cout << "\n";
    }
    

    return 0;
}