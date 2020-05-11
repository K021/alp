// https://codeforces.com/problemset/problem/602/B
// 교수님 설명 전에 풀어본 코드
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    a: 주어진 숫자열을 저장하는 배열, a[i] > 0, 1 base index
    lm: i 구간을 포함하는 이전 영역의 최솟값 저장, -1 은 미정
    st: a[i] 와 연속적으로 중복된 숫자열의 시작 인덱스를 저장하는 배열
        예시
            i:  0 1 2 3 4 5 6 7 8 9 10 11
            a:  0 5 4 5 5 6 7 8 8 8 7  6
            st: 0 1 2 3 3 5 6 7 7 7 10 11
    D: a[1] ~ a[i] 까지의 최대 Constant Range 를 저장하는 배열
        D[i][0]: i 구간이 포함되지 않을 때
        D[i][1]: i 구간이 포함될 때
    
    알고리즘
        초기값
            - D[0] = {0, 0}
            - D[1] = {0, 1}  (n == 1 일 때, 그 이전은 없고, i 구간이 포함되면 1 이므로)
        i 구간 로직 (i >= 2)
            - D[i][1]
                - D.back()[1] 에 이어질 수 있는지 적합성 판단
                    - lm[i-1] 이 양수일 때
                        a[i] 가 lm[i-1] 또는 lm[i-1]+1 이면 적합
                        lm[i] 은 lm[i-1] 와 같다
                    - lm[i-1] 이 음수일 때 (0 일 때는 없음, a[i] > 0 이기 때문)
                        이전 구간에 a[i-1] 한 숫자만 있는 경우이므로,
                        a[i-1], a[i] 중 작은 값을 lm[i] 에 저장
                - 적합한 경우 
                    D[i][1] = D.back()[1] + 1
                - 적합하지 않은 경우 (a[i-1] 과 a[i] 가 무조건 1 차이)
                    a[i-1], a[i] 로 구성된 새로운 구간의 길이 계산
                    D[i][1] = i - st[i-1] + 1;
                    a[i-1], a[i] 중 작은 값을 lm[i] 에 저장
            - D[i][0]
                - D[i][1] 이 D.back()[1] 에 이어질 수 있는 경우 (위의 적합성 판단이 참인 경우)
                    D[i-1][1], D[i-1][0] 중 작은 값이 D[i][0]
                - 그렇지 않은 경우
                    D[i][0] = D[i-1][0]
*/

vector<int> a(1, 0);
vector<int> d(2, 0);
vector<vector<int> > D(1, d);
vector<int> lm(1, -1);  // i 를 포함하는 이전 영역의 최솟값 저장, -1 은 미정
vector<int> st(1, -1);  // a[i] 와 연속적으로 중복된 숫자열의 시작 인덱스를 저장하는 배열

int main() {
    int n, inp;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> inp;
        a.push_back(inp);
        if (a[i-1] == inp) st.push_back(st.back());
        else st.push_back(i);  // i == 1 인 경우에는 늘 여기로 오게 된다
    }

    d[0] = 0;
    d[1] = 1;
    D.push_back(d);
    lm.push_back(-1);
    for (int i = 2; i <= n; ++i) {
        if (lm[i-1]) {  // lm 이 유효한 값일 때 (이전 구간이 두 개의 서로 다른 수로 구성될 때)
            if (a[i] == lm[i-1] || a[i] == lm[i-1]+1) { // 이전 구간 확장이 적합할 때
                d[1] = D.back()[1] + 1;
                lm.push_back(lm.back());
                d[0] = D.back()[0];  // 이 부분은 생략 가능, d[0] 에 그 이전 값이 남아있기 때문
            }
            else {  // 이전 구간이 i 에서 끊길 때
                d[1] = i - st[i-1] + 1;
                lm.push_back(min(a[i-1], a[i]));
                d[0] = max(D.back()[1], D.back()[0]);
            }
        }
        else {  // lm 이 유효한 값이 아닐 때 (이전 구간이 하나의 수로 구성되어 있을 때)
            d[1] = D.back()[1] + 1;
            if (a[i-1] != a[i]) lm.push_back(min(a[i-1], a[i]));
            else lm.push_back(-1);
            d[0] = D.back()[0];  // 이 부분은 생략 가능, d[0] 에 그 이전 값이 남아있기 때문
        }
        D.push_back(d);
    }
    int ret = max(D.back()[0], D.back()[1]);
    cout << ret << endl;
    
    return 0;
}