// http://codeforces.com/problemset/problem/189/a
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> d(50000, -1);
    int n, a, b, c;

    cin >> n >> a >> b >> c;

    d[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (i >= a) if (d[i-a] >= 0) d[i] = d[i-a] + 1;
        if (i >= b) if (d[i-b] >= 0) if (d[i-b] >= d[i]) d[i] = d[i-b] + 1;
        if (i >= c) if (d[i-c] >= 0) if (d[i-c] >= d[i]) d[i] = d[i-c] + 1;
    }

    cout << d[n] << endl;

    return 0;
}