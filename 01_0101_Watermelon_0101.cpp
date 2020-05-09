// codeforce 4A
// http://codeforces.com/problemset/problem/4/A
#include <iostream>

using namespace std;

int main() {
    int number;

    cin >> number;
    if (number < 4) cout << "NO" << endl;
    else if ((number & 1) == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}