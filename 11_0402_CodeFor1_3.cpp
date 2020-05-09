// http://codeforces.com/problemset/problem/768/b
// 교수님 설명대로 작성한 코드. 얘는 시간이 오래 걸림
#include <iostream>
#include <vector>

using namespace std;

int lorder, rorder;
vector<long long> sums;
vector<char> key;
vector<long long> order_to_index;

vector<long long> oti(int order) {
    vector<long long> order_to_index = {0};
    if (order == 0) return order_to_index;
    for (int i = 1; i <= order; ++i) {
        order_to_index.push_back((order_to_index[i-1]+1) * 2 - 1);
    }
    return order_to_index;
}

vector<char> bin(long long num) {
    vector<char> nums_reversed;
    vector<char> nums;
    int remainder;
    int quotient;
    do {
        quotient = num / 2;
        remainder = num % 2;
        nums.push_back(remainder);
        num = quotient;
    } while(num != 0);
    nums_reversed.push_back(0);  // 1-indexed
    for (int i = nums.size()-1; i >= 0; --i) {
        nums_reversed.push_back(nums[i]);
    }
    return nums_reversed;
}

int get_order(int n) {
    int order = 0;
    n++;
    while (n != 1) {
        n = n/2;
        order++;
    }
    return order;
}

int get_part_sum(int i) {
    long long ps;
    long long remainder;
    int ord = get_order(i);
    ps = sums[ord];
    remainder = i - order_to_index[ord];
    if (remainder == 0) return ps;
    if (remainder == 1) return ps + key[ord+1];
    else return ps + key[ord+1] + get_part_sum(remainder - 1);
}

int main() {
    long long n, suml, sumr, ans;
    int l, r;

    cin >> n >> l >> r;
    lorder = get_order(l);
    rorder = get_order(r);
    key = bin(n);
    order_to_index = oti(key.size() - 1);
    sums.push_back(0);
    int size = key.size();
    for (int i = 1; i < size; ++i) {
        sums.push_back(sums[i-1] * 2 + key[i]);
    }

    suml = get_part_sum(l-1);
    sumr = get_part_sum(r);
    ans = sumr - suml;

    printf("%lld", ans);

    return 0;
}