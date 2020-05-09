// http://codeforces.com/problemset/problem/768/b
// 이 코드는 메모리가 터진다.
#include <iostream>
#include <list>

using namespace std;

list<long long> div(long long n) {
    list<long long> a;
    list<long long> b;
    if (n == 1) {
        a.push_back(1);
        return a;
    }
    a = div(n / 2);
    b.assign(a.begin(), a.end());
    a.push_back(n % 2);
    a.splice(a.end(), b);
    return a;
}

int main() {
    long long n;
    int l, r;
    int idx = 0;
    int sum = 0;
    list<long long> ans;
    list<long long>::iterator it;

    cin >> n >> l >> r;
    ans = div(n);

    for (it = ans.begin(); it != ans.end(); ++it) {
        idx++;
        if (idx > r) break;
        if (idx >= l && *it) sum++;
    }
    printf("%d", sum);

    return 0;
}