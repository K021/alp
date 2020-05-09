// http://codeforces.com/problemset/problem/768/b
// 이 코드는 메모리가 터진다.
#include <iostream>
#include <vector>

using namespace std;

vector<int> bin(long long num) {
    vector<int> nums_reversed;
    vector<int> nums;
    int remainder;
    int quotient;
    do {
        quotient = num / 2;
        remainder = num % 2;
        nums.push_back(remainder);
        num = quotient;
    } while(num != 0);
    for (int i = nums.size()-1; i >= 0; --i) {
        nums_reversed.push_back(nums[i]);
    }
    return nums_reversed;
}

vector<int> div(vector<int> nums) {
    vector<int> a;
    int my_center;
    if (nums.size() == 1) {
        return nums;
    }
    my_center = nums.back();
    nums.pop_back();
    nums = div(nums);
    a.insert(a.end(), nums.begin(), nums.end());
    a.push_back(my_center);
    a.insert(a.end(), nums.begin(), nums.end());
    return a;
}

int main() {
    long long num;
    int l, r;
    int idx = 0;
    int sum = 0;
    vector<int> ans;

    cin >> num >> l >> r;
    ans = div(bin(num));

    for (int i = l - 1; i < r; ++i) {
        sum += ans[i];
    }
    printf("%d", sum);

    return 0;
}