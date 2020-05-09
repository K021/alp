// http://codeforces.com/problemset/problem/189/a
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> d(50000, -1);  // 조합이 불가능한 갑을 표시하기 위해 -1 을 사용한다.
    int n, a, b, c;

    cin >> n >> a >> b >> c;

    d[0] = 0;  // n = 0 일 때는 나오지 않지먄, 앞으로 나올 계산을 위해 필요한 스타트
    for (int i = 1; i <= n; ++i) {
        // 다음의 세 가지 경우 고려
        // 1. d[i-x] 의 인덱스가 존재할 때
        // 2. d[i-x] 의 값이 존재할 때
        // 3. d[i] 보다 d[i-x] 의 값이 클 때
        if (i >= a) if (d[i-a] >= 0) d[i] = d[i-a] + 1;
        if (i >= b) if (d[i-b] >= 0) if (d[i-b] >= d[i]) d[i] = d[i-b] + 1;
        if (i >= c) if (d[i-c] >= 0) if (d[i-c] >= d[i]) d[i] = d[i-c] + 1;
    }

    cout << d[n] << endl;

    return 0;
}