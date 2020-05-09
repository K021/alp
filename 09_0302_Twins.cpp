// http://codeforces.com/problemset/problem/160/A
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, input;
    int sum = 0, tot = 0, half;
    vector<int> coins;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &input);
        coins.push_back(input);
        tot += input;
    }
    half = tot / 2;

    sort(coins.begin(), coins.end(), greater<int>());
    for (int i = 0; i < n; ++i) {
        sum += coins[i];
        if (sum > half) {
            printf("%d", i + 1);
            return 0;
        }
    }

    return 0;
}