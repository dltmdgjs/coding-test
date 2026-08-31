// 문제 : 단지번호붙이기
// 알고리즘 분류 : 그래프(BFS, DFS)

// 집 : 1, 빈 집 : 0
// 순차적으로 집인지 탐색
// 집인 경우 상하좌우 탐색. 집이면 방문.(count[i]++) (i == i번째 단지)
// 방문한 집은 0으로 교체, 방문이 끝나면 다시 순차적으로 집인지 탐색. (i++)
// 범위 체크 : 집 방문(상하좌우)시 정사각형을 벗어나는 경우 제외함.

// 틀린이유
// 1. 그룹 수는 25보다 많을 수 있음.
// 2. 숫자를 입력받을 경우 cin >> K; 로 입력받으면 한 자리 씩 입력받지 못함.
//    -> scanf를 이용하여 한 자리 씩 입력가능 -> scanf("%1d", &K);


// 다른 풀이
// 1. dfs 구현 시, 상하좌우를 방문할 때 미리 배열로 상하좌우에 대한 인덱스을 저장해 반복문으로 풀이 가능

// int di[4] = {-1, 0, 1, 0}; 
// int dj[4] = {0, 1, 0, -1};

// void dfs(int i, int j) {
//     if (home[i][j] == 1) {
//         home[i][j] == 0;
//         groupMemberCount[groupCount]++;
//         for (int k=0; k<4; k++) {
//             int ni = i + di[k];
//             int nj = j + dj[k];
//             if (nj >= N || ni < 0 || nj >= N || nj < 0) continue;
//             dfs(ni, nj);
//         }
//     }
// }

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int home[26][26] = {0,};
int groupMemberCount[625] = {0,};
int groupCount = 0;

void dfs(int i, int j)
{
    if (home[i][j] == 1)
    {
        groupMemberCount[groupCount]++;
        home[i][j] = 0;
        // 상하좌우 방문
        if (i - 1 >= 0)
        {
            dfs(i - 1, j);
        }
        if (i + 1 <= N - 1)
        {
            dfs(i + 1, j);
        }
        if (j - 1 >= 0)
        {
            dfs(i, j - 1);
        }
        if (j + 1 <= N - 1)
        {
            dfs(i, j + 1);
        }
    }
}

int main()
{

    // 입력
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int k;
            scanf("%1d", &k); // 한자리씩 입력받기.
            home[i][j] = k;
        }
    }

    // 단지 만들기
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (home[i][j] == 1)
            {
                groupCount++;
                dfs(i, j);
            }
        }
    }

    // 정렬
    vector<int> v;
    for (int i = 1; i <= groupCount; i++)
    {
        v.push_back(groupMemberCount[i]);
    }
    sort(v.begin(), v.end());

    // 출력
    cout << groupCount << "\n";
    for (int i : v) {
        cout << i << "\n";
    }
    return 0;
}