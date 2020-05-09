// http://codeforces.com/problemset/problem/734/B
#include <iostream>

using namespace std;

int main() {
    int n2, n3, n5, n6;
    int min256, left2;
    long long ret;
    cin >> n2 >> n3 >> n5 >> n6;
    if (n5 < n6) min256 = n5;
    else min256  = n6;
    // n2 와 숫자 2 를 헷갈리면 안 된다
    if (min256 < n2) {
        left2 = n2 - min256;
        if (left2 < n3)
            cout << (long long)256 * min256 + (long long)32 * left2 << endl;
        else 
            cout << (long long)256 * min256 + (long long)32 * n3 << endl;
    }
    else {
        cout << (long long)256 * n2 << endl;
    }
    return 0;
}