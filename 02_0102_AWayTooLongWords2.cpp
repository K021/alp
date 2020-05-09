// http://codeforces.com/problemset/problem/71/A
#include <iostream>
#include <string>

using namespace std;

int main() {
    int number_of_cases;
    string word;
    cin >> number_of_cases;
    for (; number_of_cases > 0; --number_of_cases) {
        cin >> word;
        int len = word.length();
        if (len <= 10) cout << word << endl;
        else cout << word[0] << len-2 << word[len-1] << endl;
    }
    return 0;
}