// *** 큰돌의 코딩 테스트 week 0 ***

#include <bits/stdc++.h>  // 맥북은 이것을 사용하기 위해 별도의 파일 작성이 필요함. (큰돌 알고리즘 교안 참조)
// 위 라이브러리는 다른 것을 include 할 필요 없이 필요한 모든 라이브러리를 사용할 수 있게 해줌.

using namespace std;

// ** 순열 (재귀함수)
int a[3] = {2,1,3};
int n = 3, r = 3;
void makePermutation(int n, int r, int depth) {
    // 기저조건
    if (r == depth) {
        // 로직 작성
        for (int i : a) {
            cout << i << " ";
        }
        cout << '\n';
        return;
    }
    // 재귀 호출
    for (int i=depth; i<n; i++) {
        swap(a[i], a[depth]);
        makePermutation(n, r, depth+1);
        swap(a[i], a[depth]);
    }
    return;
}

// ** 조합 (재귀함수)
int n = 5, k = 3; // 5개 중 3개를 뽑음
int a[5] = {1, 2, 3, 4, 5};
void combi(int start, vector<int> &b) {
    // 기저조건
    if (b.size() == k) {
        // print vector
        for(int i : b) cout << i << " ";
        cout << '\n';
        return;
    }
    // 재귀호출
    for (int i=start; i<n; i++) {
        b.push_back(i);
        combi(i+1, b);
        b.pop_back();
    }
    return;
}

// ** split() 함수
vector<string> split(const string& input, string delimeter) {
    vector<string> result;
    auto start = 0;
    auto end = input.find(delimeter);
    while (end != string::npos) {
        result.push_back(input.substr(start, end-start)); // .substr(위치, 크기) : start부터 end-start 만큼의 문자열을 자름
        start = end+delimeter.size();
        end = input.find(delimeter, start);
    }
    result.push_back(input.substr(start, end-start));
    return result;
}









int main() {

    // **** 메모리, 주소, 포인터, array to pointer decay(부식) ****
    vector<int> i;
    int temp;
    for (int k=0; k<3; k++) {
        cin >> temp;
        i.push_back(temp);
    }
    sort(i.begin(),i.end());
    // sort(i.rbegin(), i.rend());
    for (auto j=i.begin(); j!=i.end(); j++) {
        cout << *j << endl;
    }


    int t[5];
    for (int j=0; j<5; j++) {
        cin >> t[j];
    }
    sort(t, t+5);
    for (int j=0; j<5; j++) {
        cout << t[j] << " -> 값 (배열 형식 이용)" << endl; // 값 (배열 형식 이용)
        cout << *(t+j) << " -> 값 (역참조 연산자 * 이용)" << endl; // 값 (역참조 연산자 * 이용)
        cout << &t[j] << " -> 주소값" << endl; // 주소값
        cout << &*(t+j) << " -> 주소값" << endl; // 주소값
        cout << sizeof(t[j]) << " -> 값 공간의 크기" << endl; // 값 공간의 크기
        cout << sizeof(&t[j]) << " -> 주소값 공간의 크기 (포인터의 크기)" << endl; // 주소값 공간의 크기 (포인터의 크기)
        cout << "--------------------" << endl;
    }

    int a[5];
    int *p = a; // array to pointer decay (a는 배열의 크기정보를 제외한 배열의 시작 주소값)




    // **** 중복된 요소 제거하기 (unique) ****
    // vector<int> v1 = {1,1,2,2,3,3,4,4,5,5};
    vector<int> v1 = {2, 2, 1, 1, 2, 2, 3, 3, 5, 5, 4, 4};
    // unique는 반드시 sort와 같이 쓸 것 (위 처럼 정렬이 안된 상황에서 unique시도 시, 제대로 안됨)
    sort(v1.begin(), v1.end()); // 오름차순 정렬
    v1.erase(unique(v1.begin(), v1.end()), v1.end()); // 중복요소 제거
    // unique의 반환값 : 중복되지 않은 요소로 채운 지점 바로 다음 주소값.
    for (int e : v1) {
        cout << e << " ";
    }

    

    // **** 순열 (next_permutation) ****
    int a[3] = {2,1,3};
    sort(a, a+3); // next_permutation 사용 전, 반드시 오름차순 정렬할 것.
    vector<int> v;
    for (int i : a) v.push_back(i);
    do {
        // print vector
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    } while (next_permutation(v.begin(), v.end())); // (다음 순열로..)
    



    // **** 순열 (재귀함수) ****
    // 아래 변수들 전역으로 선언.
    // int a[3] = {1,2,3};
    // int n = 3, r = 3;
    // 정렬하지 않아도 되나봄
    makePermutation(n, r, 0);
    // 보통 next_permutation과 sort 조합을 사용하는게 쉬움




    // **** 조합 (중첩 for문) ****
    int a[5] = {1,2,3,4,5};
    int n = 5; int k = 3;
    // 5개 중 3개를 뽑으므로 3중첩 함.
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            for (int k=j+1; k<n; k++) {
                cout << i << " " << j << " " << k << endl;
            }
        }
    }
    // 차근차근 올라가면서 뽑음.




    // **** 조합 (재귀함수) ****
    vector<int> b;
    combi(0, b);




    // **** split **** (특정 문자(열)을 기준으로 분리하기)
    // c++ 에서는 split 함수를 지원하지 않으므로 만들어야 함.
    string str = "apple->banana->orange->grape";
    vector<string> fruits = split(str, "->");
    for (const string& fruit : fruits) {
        cout << fruit << endl;
    }



    return 0;
}