// 문제 : 유기농 배추
// 알고리즘 분류 : DFS

// 인접 기준 : 상하좌우만 인접, 대각선은 인접 X.
// 필요한 지렁이 수 = 인접한 배추들의 그룹 수.
// BFS 또는 DFS를 이용하여 배추를 순차적으로 탐색하고 그룹의 수를 카운팅.

// 풀이방법 : DFS를 이용.
// 1. 테스트 케이스 개수 입력.
// 2. 배추밭의 가로, 세로 길이, 배추 개수를 입력.
// 3. 배추 개수 만큼 위치 입력 받음. -> 그 위치에 1을 배열에 저장.
// 4. dfs로 0,0부터 탐색. -> 배추이면(1이면) count[i]++ 및 0으로 변경, 재귀적으로 dfs(상하좌우) 탐색.
// 5. 한 dfs가 끝나면 다음 위치로 이동해 배추이면(1이면) count[i]++ 및 dfs시행.
// 6. 2~5 과정을 테스트 케이스 개수만큼 반복. 후 count[i] 출력.

#include <iostream>
using namespace std;

// 배열은 기본적으로 포인터 -> 기본적으로 call by reference임.
// 그래서 2차원 배열을 매개변수로 선언 시 참조형으로 선언 불가함.
void dfs(int a, int b, int field[][51], int M, int N)
{
    if (field[a][b] == 1)
    {
        field[a][b] = 0;
        // 상하좌우
        if (a > 0)
        {
            dfs(a - 1, b, field, M, N);
        }
        if (a < M - 1)
        {
            dfs(a + 1, b, field, M, N);
        }
        if (b > 0)
        {
            dfs(a, b - 1, field, M, N);
        }
        if (b < N - 1)
        {
            dfs(a, b + 1, field, M, N);
        }
    }
}

int test(int M, int N, int K)
{
    int count = 0;

    int field[51][51] = {0, };

    for (int j = 0; j < K; j++)
    {
        int a, b;
        cin >> a >> b;
        field[a][b] = 1;
    }

    for (int a = 0; a < M; a++)
    {
        for (int b = 0; b < N; b++)
        {
            if (field[a][b] == 1)
            {
                count++;
                dfs(a, b, field, M, N);
            }
        }
    }

    return count;
}

int main()
{
    int T;
    cin >> T;
    int count[T];
    for (int i = 0; i < T; i++)
    {

        int M, N, K;
        cin >> M >> N >> K;

        count[i] = test(M, N, K);
    }

    for (int i = 0; i < T; i++)
    {
        cout << count[i] << "\n";
    }

    return 0;
}
