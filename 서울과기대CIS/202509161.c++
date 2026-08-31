#include <iostream>

using namespace std;

int main()
{
    int N, x;
    cin >> N >> x;

    // 순차탐색
    for (int i = 0; i < N; i++)
    {
        // 탐색 성공
        if (x == i)
        {
            cout << i;
            break;
        }
        // 탐색 실패
        else
        {
            if (i == N - 1)
            {
                cout << i;
            }
            else
            {
                cout << i << " ";
            }
        }
    }
    cout << "\n";

    // 이진탐색
    int left = 0;
    int right = N - 1;
    int mid = (left + right) / 2;
    while (left <= right)
    {
        // 탐색 성공
        if (x == mid)
        {
            cout << mid;
            break;
        }
        // 탐색 실패
        else
        {
            // 출력
            if (left == right)
            {
                cout << mid;
            }
            else
            {
                cout << mid << " ";
            }
            // left, right, mid 수정
            if (x < mid)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
            mid = (left + right) / 2;
        }
    }

    return 0;
}