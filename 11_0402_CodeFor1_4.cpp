// http://codeforces.com/problemset/problem/768/b
// 교수님 설명대로 작성한 코드. 얘도 시간이 오래 걸림
#include <iostream>
#include <vector>

using namespace std;

int order;
vector<char> keys_rvsd;
/*
    vector<long long> sums
      - 미리 구해진 합을 저장하고 있는 벡터.
*/
vector<long long> sums;
/* 
    vector<long long> bts (binary to sum 의 약자)
      - n 을 문제에서 요구한 방식대로 변형하여 만들어낸 binary 값의 인덱를 bidx 라고 하고,
        처음부터 그 인덱스까지의 합을 나타내는 sum 배열의 인덱스를 sidx 라고 하면,
        bts[sidx] == bidx 가 된다.
      - 주어진 bidx 의 바로 왼쪽의 bidx 를 찾아서, sidx 와 매칭한 후,
        sums[sidx] 로 합을 구하기 위한 벡터이다.
*/
vector<long long> bts;  

vector<char> bin(long long num) {
    /* 
        기능: n 을 입력받아 binary 값으로 변경해서 주는 함수.
        출력: 0 번 인덱스에는 0, 1 번 인덱스부터 binary 값이 역순으로 들어있는 벡터. (나중에 keys_rsvd.back() 으로 꺼내 쓰기 위함)
        예시: 12 를 받았을 경우, bin 값은 1100 이 되는데,
        이때, 벡터 [0, 0, 0, 1, 1] 이 출력된다.
    */
    vector<char> keys_rvsd;
    int remainder;
    int quotient;

    keys_rvsd.push_back(0);
    do {
        quotient = num / 2;
        remainder = num % 2;
        keys_rvsd.push_back(remainder);
        num = quotient;
    } while(num != 0);
    return keys_rvsd;
}

long long get_sum_by_idx(long long nidx) {
    /*
        기능: l, r 과 같이 인덱스가 주어졌을 때, 처음부터 그 인덱스까지의 합을 구해주는 함수. (인덱스를 포함한다)
        출력: 합산한 값
        주의: sums 벡터와 bts 벡터가 이미 만들어져 있다고 가정.
    */
    int sum_ = 0;
    int sumidx = 0;
    for (int sidx = 1; sidx < bts.size(); ++sidx) {
        if (nidx == bts[sidx]) {
            return sums[sidx];
        }
        else if (nidx < bts[sidx]) {
            sum_ += sums[sidx - 1];
            return sum_ + get_sum_by_idx(nidx - bts[sidx - 1]);
        }
    }
    return 0;
}

int main() {
    long long n, suml, sumr, ans;
    int l, r;

    cin >> n >> l >> r;

    // printf("%lld, %d, %d\n", n, l, r);

    // n 의 binary 표현. 원소가 거꾸로 들어있어서 keys_rvsd.back() 으로 꺼낼 수 있도록 했다.
    keys_rvsd = bin(n);
    order = keys_rvsd.size() - 1;  // log2(n)

    // printf("keys_rsvd: [ ");
    // for (int i = keys_rvsd.size()-1; i >= 0; --i) {
    //     printf("%d ", keys_rvsd[i]);
    // }
    // printf("]\n");

    // 부분합 sum 벡터 생성
    sums.push_back(0);
    sums.push_back(keys_rvsd.back());
    keys_rvsd.pop_back();
    long long bfr_sum;
    int key;
    for (int i = 2; i <= order; ++i) {
        bfr_sum = sums.back();
        key = keys_rvsd.back();
        keys_rvsd.pop_back();
        // printf("key: %d, bfr_sum: %lld\n", key, bfr_sum);
        sums.push_back(bfr_sum + key);
        sums.push_back(bfr_sum * 2 + key);
    }

    // printf("sums idx: [ ");
    // for (int i = 0; i < sums.size(); ++i) {
    //     printf("%d ", i);
    // } 
    // printf("]\n");
    // printf("sums val: [ ");
    // for (int i = 0; i < sums.size(); ++i) {
    //     printf("%lld ", sums[i]);
    // } 
    // printf("]\n");

    // bts 벡터 생성
    bts.push_back(0);
    bts.push_back(1);
    long long bfrpls1;
    for (int i = 2; i <= order; ++i) {
        bfrpls1 = bts.back() + 1;
        bts.push_back(bfrpls1);
        bts.push_back(bfrpls1 * 2 - 1);
    }

    // printf("bts idx: [ ");
    // for (int i = 0; i < bts.size(); ++i) {
    //     printf("%d ", i);
    // } 
    // printf("]\n");
    // printf("bts val: [ ");
    // for (int i = 0; i < bts.size(); ++i) {
    //     printf("%lld ", bts[i]);
    // } 
    // printf("]\n");

    suml = get_sum_by_idx(l-1);
    sumr = get_sum_by_idx(r);
    // printf("suml: %lld, sumr: %lld\n", suml, sumr);
    ans = sumr - suml;

    printf("%lld", ans);

    return 0;
}