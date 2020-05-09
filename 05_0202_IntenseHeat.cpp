// http://codeforces.com/problemset/problem/1003/c
// (prefix 배열이나 heat 배열이 정수 배열이라고 할 때)
// avg 계산을 할 때, double 로 계산되도록 형변환을 해줘야 한다. 
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, min_k, num;
    double avg, maxavg = 0;
    vector<int> heats = {0};
    vector<int> ps = {0};
    cin >> n >> min_k;
    for (int i = 1; i <= n; ++i) {
        cin >> num;
        heats.push_back(num);
        ps.push_back(ps[i-1] + num);
    }
    for (int k = min_k; k <= n; ++k) {
        for (int i = n; i >= k; --i) {
            avg = ((double)ps[i] - ps[i-k]) / (k);
            if (avg > maxavg) maxavg = avg;
        }
    }
    cout.precision(10);
    cout << maxavg << endl;
    return 0;
}