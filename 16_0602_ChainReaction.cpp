// https://codeforces.com/problemset/problem/607/a
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    becons: 비컨 정보를 pair<int, int> 형태로 담고 있는 배열, 1 base index
    D: i 번째 비컨까지 있을 때, 살아남은 비컨 수를 저장하는 배열, 1 base index
        D[i][0]: i 번째 비컨을 파괴했을 때 살아남은 비컨 수
        D[i][1]: i 번째 비컨을 사용했을 때 살아남은 비컨 수
    
    int foreidx(int idx)
        : i 구간의 인덱스, i 를 받아서, 그 비컨을 사용했을 때에도 파괴되지 않는 가장 오른쪽 비컨의 인덱스를 가져오는 함수

    알고리즘
        초기값
            - D[0] = {0, 0}
        i 구간 로직
            - d[0]: i 구간 비컨을 파괴했을 때의 값
                - i-1 구간 비컨을 사용했을 때의 값을 가져온다
            - d[1]: i 구간 비컨을 사용했을 때의 값
                - i 구간 비컨을 사용했을 때에도 파괴되지 않는 구간의 비컨을 사용했을 때의 값을 가져오고, +1 한다.
        출력 로직
            - 맨 오른쪽에 비컨을 하나 추가할 수 있다는 것은
            - 오른쪽 부터 x 개의 비컨을 원하는 만큼 파괴할 수 있다는 것이다
            - 따라서, D[1][0] ~ D[n][0] 과 D[n][1] 중에 최대값을 고르면, 가장 많이 비컨이 살아남은 경우의 수가 된다
            - n 에서 그 값을 빼주면 비컨이 가장 적게 파괴된 값이 된다.
*/

vector<pair<int, int> > becons(1, make_pair(0, 0));
vector<int> d(2, 0);
vector<vector<int> > D(1, d);

int foreidx(int idx) {  // 이걸 바이너리 서치로 개선할 수 있다
    int th = becons[idx].first - becons[idx].second;
    if (th <= 0 || idx == 1) return 0;
    for (int i = idx-1; i >= 0; --i) {
        if (becons[i].first < th) return i;
    }
    return 0;
}

int main() {
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        becons.push_back(make_pair(a, b));
    }
    sort(becons.begin(), becons.end());

    for (int i = 1; i <= n; ++i) {
        d[0] = D.back()[1];
        d[1] = D[foreidx(i)][1] + 1;
        D.push_back(d);
    }

    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        if (D[i][0] > ret) ret = D[i][0];
    }
    if (D[n][1] > ret) ret = D[n][1];
    cout << n-ret << endl;

    return 0;
}