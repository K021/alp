// http://codeforces.com/problemset/problem/466/c
// int 의 크기가 최대 2*10^9 정도 이므로, 이 문제는 합을 구할 때 long long 을 사용해야 한다.
// int 의 최대 크기 : 2147486347
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int arrlen;
    int num;
    long long totsum, one_thd, two_thd;
    int njs = 0;
    long long result = 0;
    vector<int> arr = {0};
    vector<long long> ps = {0}; 
    vector<int> njs_on_the_right = {0};
    cin >> arrlen;
    if (arrlen < 3) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= arrlen; ++i) {
        cin >> num;
        arr.push_back(num);
        ps.push_back(ps[i-1] + num);
        njs_on_the_right.push_back(0);
    }
    totsum = ps.back();
    if (totsum % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    one_thd = totsum / 3;
    two_thd = one_thd * 2;
    for (int j = arrlen - 1; j >= 2; --j) {
        if (ps[j] == two_thd) njs++;
        njs_on_the_right[j] = njs;
    }
    for (int i = arrlen - 2; i >= 1; --i) {
        if (ps[i] == one_thd) {
            result += njs_on_the_right[i+1];
        }
    }
    cout << result << endl;
    return 0;
}