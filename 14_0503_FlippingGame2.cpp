// http://codeforces.com/problemset/problem/327/A
// 교수님의 동적 프로그래밍 버전
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    a: 주어진 숫자열을 그대로 저장하는 배열, 1 base index
    D: D[i] 가 a[1] ~ a[i] 까지 Flipping Game 의 3가지 상태를 저장하는 배열, 1 base index
        D[i][0] : i 번째 아무 것도 하지 않고, [1, i-1] 동안도 아무 것도 하지 않았을 때
            - D[i-1][0] 에 a[i] 합산
        D[i][1] : i 번째 Flip 하고, [1, i-1] 사이에 Flip 을 시작했거나, 아무 것도 하지 않았을 때
            - D[i-1][0] 또는 D[i-1][1] 중 큰 것에 a[i]^1 합산
        D[i][2] : i 번째 아무 것도 하지 않고, [1, i-1] 사이에 Flip 이 시작했다 끝났을 때
            - D[i-1][1] 또는 D[i-1][2] 중 큰 것에 a[i] 합산
*/

vector<int> a(1, 0);
vector<int> d(3, 0);
vector<vector<int>> D(1, d);

int main() {
    int n, input;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        a.push_back(input);
    }

    for (int i = 1; i <= n; ++i) {
        d[0] = D.back()[0] + a[i];
        d[1] = max(D.back()[0], D.back()[1]) + (a[i]^1);
        d[2] = max(D.back()[1], D.back()[2]) + a[i];
        if (i == 1) d[2] = 0;  // 맨 처음에는 '그 이전에 Flip 이 시작했다 끝난 경우'가 없으므로
        D.push_back(d);
    }
    
    int ret = max(D.back()[1], D.back()[2]);  // D.back()[0] 은 끝날 때까지 아무 것도 안 한 것이므로, 제외
    cout << ret << endl;

    return 0;
}