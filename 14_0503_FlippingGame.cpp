// http://codeforces.com/problemset/problem/327/A
// 교수님 해설 없이 먼저 풀어본 코드
#include <iostream>
#include <vector>

using namespace std;

/*
    a: 주어진 숫자열을 저장하는 배열, 1 base index
    s: a[1] ~ a[i] 까지의 합을 저장하는 배열, 1 base index
    fs: a[1] ~ a[i] 까지의 값을 Flip 하여 합한 값을 저장하는 배열, 1 base index

    알고리즘:
        - 구간 [i, j] 에서 fs 와 s 의 차를 구하면, Flip 해서 중가하는 양이 된다.
        - 이것을 a 의 전체 핪인, s.back() 과 더해준다.
*/
vector<bool> a(1, 0);
vector<int> s(1, 0);  // sum
vector<int> fs(1, 0);  // flip sum
int mps = 0;

int main() {
    int n, input;
    int ret;
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        a.push_back(input);
        s.push_back(s.back() + input);
        fs.push_back(fs.back() + (input^1));
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int pfs = fs[j] - fs[i-1];
            int ps = s[j] - s[i-1];
            pfs -= ps;
            if (pfs > mps) mps = pfs;
            else if (i == 1 && j == 1) mps = pfs;
        }
    }
    
    ret = s.back() + mps;
    cout << ret << endl;

    return 0;
}