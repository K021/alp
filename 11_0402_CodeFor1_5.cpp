// http://codeforces.com/problemset/problem/768/b
// 교수님 설명대로 작성한 코드. 얘도 시간이 오래 걸림
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int order;
vector<char> keys;
vector<long long> sums;
// n 의 binary 표현의 인덱스에서, 처음부터 그 인덱스까지의 합을 나타내는 sum 배열의 인덱스 쌍을 저장하는 배열.
// bts 의 원소가 bin 인덱스, bts 의 인덱스가 sum 의 인덱스와 일치한다.
// bin to sum 의 약자
vector<long long> bts;  

vector<char> bin(long long num) {
    vector<char> keys_rvsd;
    vector<char> keys;
    int remainder;
    long long quotient;

    do {
        quotient = num / 2;
        remainder = num % 2;
        keys_rvsd.push_back(remainder);
        num = quotient;
    } while(num != 0);

    int sz = keys_rvsd.size();
    keys.push_back(0);
    for (int i = 0; i < sz; ++i) {
        keys.push_back(keys_rvsd[sz-i-1]);
    }

    return keys;
}

long long get_sum_by_idx(long long nidx) {
    // 1 번 부터 nidx 까지의 합을 구한다
    if (nidx == 0) return 0;

    long long sum_ = 0;
    int ord = log2(nidx);
    long long ordi = pow(2, ord) - 1; 

    sum_ = sums[ord];
    if (nidx == ordi) return sum_;
    if (nidx == ordi + 1) return sum_ + keys[ord + 1];
    else return sum_ + keys[ord + 1] + get_sum_by_idx(nidx - ordi - 1);

    return 0;
}

int main() {
    long long n, suml, sumr, ans;
    long long l, r;

    cin >> n >> l >> r;

    // n 의 binary 표현. 원소가 거꾸로 들어있어서 keys_rvsd.back() 으로 꺼낼 수 있도록 했다.
    keys = bin(n);
    order = keys.size() - 1;

    // 부분합 sum 벡터 생성
    sums.push_back(0);
    sums.push_back(1);
    for (int i = 2; i <= order; ++i) {
        sums.push_back(sums.back() * 2 + keys[i]);
    }

    suml = get_sum_by_idx(l-1);
    sumr = get_sum_by_idx(r);
    ans = sumr - suml;

    printf("%lld", ans);

    return 0;
}