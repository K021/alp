// http://codeforces.com/problemset/problem/455/a
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    nums: 입력된 숫자열을 받아, 오름차순으로 저장할 배열
    sns: 같은 숫자의 중복이 없게 오름차순으로 저장할 배열
    cnts: cnts[i] 가 sns[i] 의 갯수를 저장하도록 하는 배열
    D: sns 가 i 번째까지만 있다고 할때, 
        D[i][0] -> i 번째 숫자를 안 썼을 때의 최대 점수
        D[i][1] -> i 번째 숫자를 썼을 때의 최대 점수
*/
vector<int> nums;
vector<int> sns;  // sorted numbers
vector<long long> cnts;  // counts
vector<long long> d(2, 0);
vector<vector<long long> > D(1, d);

int main() {
    int n, a;
    long long ret;

    cin >> n;
    while (n--) {
        cin >> a;
        nums.push_back(a);
    }
    sort(nums.begin(), nums.end());
    sns.push_back(nums[0]);
    cnts.push_back(1);
    for (int i = 1; i < nums.size(); ++i) {
        if (sns.back() == nums[i]) cnts.back()++;
        else {
            sns.push_back(nums[i]);
            cnts.push_back(1);
        }
    }

    D[0][0] = 0;
    D[0][1] = sns[0] * cnts[0];  // 이것 때문에 cnts 는 long long 타입이어야 한다.
    for (int i = 1; i < sns.size(); ++i) {
        d[0] = max(D.back()[0], D.back()[1]);
        if (sns[i-1] < sns[i] - 1) d[1] = d[0];
        else d[1] = D.back()[0];
        d[1] += sns[i] * cnts[i];
        D.push_back(d);
    }

    ret = max(D.back()[0], D.back()[1]);
    cout << ret << endl;

    return 0;
}