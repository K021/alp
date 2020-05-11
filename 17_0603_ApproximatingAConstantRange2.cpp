// https://codeforces.com/problemset/problem/602/B
// 교수님 버전, Sliding Window
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    a: 주어진 숫자열을 저장하는 배열, a[i] > 0, 1 base index
    rg: 구간 별 range 를 저장하는 배열로, 이 배열의 최대값이 정답이 된다
    st: a[i] 와 연속적으로 중복된 숫자열의 시작 인덱스를 저장하는 배열
        예시
            i:  0 1 2 3 4 5 6 7 8 9 10 11
            a:  0 5 4 5 5 6 7 8 8 8 7  6
            st: 0 1 2 3 3 5 6 7 7 7 10 11
    th1, th2: 구간의 최대 최소, 어떤 것이 최대이냐의 구분이 없다
    is_th: 구간의 최대 최소가 결정되었을 경우 true (구간이 한 숫자로 구성되었을 경우를 구분하기 위함)
    
    알고리즘 (Sliding Window, Dynamic Programing)
        - 구간 [l, r] 의 r 을 늘려 나간다
        - 구간 [l, r-1] 이 한 값으로 이루어져 있을 때 (구간의 최대 최소가 없을 때)
            a[r] 과 th1 을 비교하여 같으면 continue, 다르면 th2 에 추가하고 is_th 바꾸고 continue
        - 구간 [l, r-1] 이 두 값으로 이루어져 있을 때
            a[r] 이 th1, th2 중 하나일 경우 continue
            아닐 경우,
                - th1 = a[r-1], th2 = a[r] 로 바꾸고
                - 이전 구간의 길이 rg 에 넣고
                - l = st[r-1] (a[r-1] 이 연속되는 지점의 시작 인덱스로 바꾸고 continue)
        - r = n 일 때까지 작업을 완료하고 나오면
            a[n] 은 구간 길이 계산에 포함되어 있지 않은 상태이고
            a[n] 이 th1, th2 중 어느 것도 아닐 때는 이전 구간 길이보다 새 구간 길이가 반드시 짧으므로
            a[n] 이 th1, th2 중 하나일 때, 이전 구간 길이에 1 을 더해준 것을 rg 에 넣는다.
        - 출력 로직
            rg 원소 중 최대값이 답
*/

vector<int> a(1, 0);
vector<int> rg;
vector<int> st(1, -1);

int main() {
    int n, inp;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> inp;
        a.push_back(inp);
        if (a[i-1] == inp) st.push_back(st.back());
        else st.push_back(i);  // i == 1 인 경우에는 늘 여기로 오게 된다
    }
    int l = 1, r = 1;
    int th1 = a[1], th2;
    bool is_th = false;
    while (r < n) {
        r++;
        if (is_th) {
            if (a[r] != th1 && a[r] != th2) {
                th1 = a[r-1];
                th2 = a[r];
                rg.push_back(r - l);
                l = st[r-1];
            }
        }
        else if (a[r] != th1) {
            th2 = a[r];
            is_th = true;
        } 
    }
    if (a[r] == th1 || a[r] == th2) rg.push_back(r - l + 1);
    int ret = *max_element(rg.begin(), rg.end());
    cout << ret << endl;
    return 0;
}