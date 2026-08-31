#include <bits/stdc++.h>

using namespace std;


int a[10];
int b[10][10];

int main() {

    // fill 함수를 사용해 배열을 초기화 할 수 있음. O(n)
    // fill(first, last, val); -> [first, last)범위를 val로 초기화.
    // fill은 배열의 전체를 초기화 할때 사용하는 것이 좋음
    // fill(&a[0], &a[10], 100);
    fill(a, a+10, 100);

    for (int i=0; i<10; i++) {
        cout << i << ": " << a[i] << endl;
    }

    // 2차원 배열은 아래와 같이 사용가능함. (범위 설정 주의)
    fill(&b[0][0], &b[9][10], 2);

    cout << "   ";
    for (int i=0; i<10; i++) {
        cout << "[" << i << "]";
    }
    cout << endl;

    for (int i=0; i<10; i++) {
        cout << "[" << i << "] ";
        for (int j=0; j<10; j++) {
            cout << b[i][j] << "  ";
        }
        cout << endl;
    }



    // -----------------------------------------------------------



    // memset은 fill 보다 간편하지만, 0 또는 -1로만 초기화 가능. (또는 a,b,c.. 알파벳 char)
    memset(a, -1, sizeof(a));
    memset(b, 'a', sizeof(b)); // 특히 2차원 배열의 경우 더 간편함.

    for (int i=0; i<10; i++) {
        cout << i << ": " << a[i] << endl;
    }

    cout << "   ";
    for (int i=0; i<10; i++) {
        cout << "[" << i << "]";
    }
    cout << endl;

    for (int i=0; i<10; i++) {
        cout << "[" << i << "] ";
        for (int j=0; j<10; j++) {
            cout << (char) b[i][j] << "  ";
        }
        cout << endl;
    }



    // -----------------------------------------------------------



    int source_a[3] = {1,2,3};
    int dest_a[3];

    // memcpy로 array의 값을 '깊은 복사'할 수 있음. (vector는 안됨.)
    memcpy(dest_a, source_a, sizeof(source_a));

    // 복사본 출력
    for (int i : dest_a) {
        cout << i << " ";
    }
    cout << endl;

    // 복사된 array 값 일부 수정
    dest_a[0] = 100; 

    // 원본 출력 - 깊은 복사이기 때문에 복사본 수정 시, 원본은 수정되지 않음
    for (int i : source_a) {
        cout << i << " ";
    }
    cout << endl;



    // -----------------------------------------------------------



    // copy는 vector, array 둘 다 깊은 복사 가능함.
    vector<int> source_v {1,2,3};
    vector<int> dest_v(3);

    // copy(복사할 시작주소, 복사할 끝주소, 복사될 시작주소)
    copy(source_v.begin(), source_v.end(), dest_v.begin());
    // 만약 배열이면, copy(a, a+3, b); 와 같이 사용가능



    // -----------------------------------------------------------



    // sort(first, last, [func]); -> 정렬
    int t1[7] = {5,2,6,3,4,8,9};
    sort(t1, t1+7, greater<int>()); // greater<타입>() 으로 내림차순 정렬 가능
    for (int i : t1) {
        cout << i << " ";
    }
    cout << endl;

    // pair기반 vector의 정렬 - first, second 순 오름차순 정렬됨.
    vector<pair<int, int>> v1;
    for (int i=10; i>=1; i--) {
        v1.push_back({i, 10-i});
    }
    sort(v1.begin(), v1.end()); // 만약, first기준 내림차순 하고 싶으면 따로 함수 생성해줌.
    for (auto v : v1) {
        cout << v.first << " : " << v.second << endl;
    }

    // stable_sort()는 안정 정렬 알고리즘임. 
    // -> 같은 값을 가진 요소들의 들어온 순서를 정렬 후에도 보존 
    //    (즉, 같은 값이면 상대적 위치는 바뀌지 않음)

    // sort()는 불안정 정렬 알고리즘임.
    // -> 같은 값을 가진 요소들의 들어온 순서를 보장하진 않음.
    // ex) (2,2), (2,5)의 순서로 들어온 경우, stable_sort 수행 결과는 그대로임
    //     하지만, sort의 결과는 모름.

    return 0;
}