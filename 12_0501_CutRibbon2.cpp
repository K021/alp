// http://codeforces.com/problemset/problem/189/a
#include <iostream>
#include <vector>

using namespace std;

vector<int> D(5000, -1);

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    D[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (i-a >= 0 && D[i-a] >= 0) D[i] = D[i-a] + 1;
        if (i-b >= 0 && D[i-b] >= 0 && D[i-b] >= D[i]) D[i] = D[i-b] + 1;
        if (i-c >= 0 && D[i-c] >= 0 && D[i-c] >= D[i]) D[i] = D[i-c] + 1;
    }
    cout << D[n] << endl;
    return 0;
}