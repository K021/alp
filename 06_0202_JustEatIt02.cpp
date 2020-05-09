// http://codeforces.com/problemset/problem/1285/b
#include <iostream>
#include <vector>

using namespace std;

int ncases;
int n, input;
long long totsum, max_partsum, ps1, ps2, mps;

vector<int> tastes;
vector<long long> ps;
vector<long long> ps_max_right;

void check_and_print() {
        mps = 0, ps1 = 0;
        ps_max_right = vector<long long>(n+1, 0);
        // j = [2, n] 의 범위에서 ps 의 최대값을 찾는다
        // n 에서부터 내림차순으로 검색하여, [j, n] 사이에서의 최대값을 ps_max_right[j] 에 저장한다
        for (int j = n; j >= 2; --j) {
            if (ps[j] > mps) mps = ps[j];
            ps_max_right[j] = mps;
        }
        // i = [1, n-1] 의 범위에서, [i+1, n] 사이의 최대 ps 인 ps_max_right[i+1] 과 비교한다
        // 그 차이를 totsum 과 비교한다
        // 이렇게 하면, 크기가 1 인 구간에서 n-1 인 모든 구간 중 최대합의 구간만을 비교할 수 있다.
        for (int i = 1; i <= n-1; ++i) {
            max_partsum = ps_max_right[i+1] - ps[i];
            if ((ps_max_right[i+1] - ps[i]) >= totsum) {
                cout << "NO" << endl;
                return;
            }
        }
        mps = 0, ps2 = 0;
        ps_max_right = vector<long long>(n+1, 0);
        // j = [1, n-1], i = [0, n-2] 에서 같은 작업을 수행한다
        for (int j = n-1; j >= 1; --j) {
            if (ps[j] > mps) mps = ps[j];
            ps_max_right[j] = mps;
        }
        for (int i = 0; i <= n-2; ++i) {
            if ((ps_max_right[i+1] - ps[i]) >= totsum) {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
}

int main() {    
    cin >> ncases;
    while (ncases--) {
        totsum = 0;
        max_partsum = 0;
        tastes = vector<int>(1, 0);
        ps = vector<long long>(1, 0);

        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> input;
            tastes.push_back(input);
            ps.push_back(ps[i-1] + input);
        }
        totsum = ps.back();
        check_and_print();
    }
    return 0;
}