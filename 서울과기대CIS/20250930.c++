#include <iostream>
#include <algorithm>
using namespace std;

// 각 정점의 부모 노드를 가리키는 배열
long long int parent[100001];

bool compare(long long int *a, long long int *b) {
    return a[2] < b[2];
}

// 찾기 함수
int find(long long int parent[], int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent, parent[x]);
}

// 유니온 함수
void union_parent(long long int parent[], int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    // 더 작은 쪽을 부모로 설정함.
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    long long int n, m;
    cin >> n >> m; 
    long long int arr[m][3];

    // u, v, w 입력
    for (int i=0; i<m; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    // w 기준 오름차순 정렬
    long long int* graph[m];
    for (int i = 0; i < m; i++) {
        graph[i] = arr[i];
    }
    sort(graph, graph + m, compare);

    // 부모 노드 배열 초기화
    for (int i=1; i<=n; i++) {
        parent[i] = i;
    }

    long long int value = 0;
    long long int count = 0;
    for (int i=0; i<m; i++) {
        if (find(parent, graph[i][0]) != find(parent, graph[i][1])) {
            // 다르면 유니온(union) 후 가중치 더함
            union_parent(parent, graph[i][0], graph[i][1]);
            value += graph[i][2]; // 가중치 업데이트
            count++; // 간선 개수 증가
            cout << graph[i][0] << " " << graph[i][1] << " " << graph[i][2] << "\n";
        }
        // 선택된 간선의 개수가 n-1이면 종료.
        if (count == n-1) break;
    }

    // 최종 가중치 출력
    cout << value;

    return 0;
}