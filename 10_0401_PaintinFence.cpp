// http://codeforces.com/problemset/problem/488/c
#include <iostream>
#include <vector>

using namespace std;

vector<int> fences;

int stroke(int start, int end, int bottom) {
    // start: fence 의 시작 인덱스
    // end: fence 의 마지막 인덱스 + 1
    // bottom: fence 에서 이미 horizontal 로 칠한 높이 
    int vnum, hnum, min_;
    int nstart;
    vnum = end - start;  // fence 의 갯수가 곧 vertical 로 칠하는 수
    // [start, end) 에서 fence 의 최소 높이 구하기
    min_ = fences[start];
    for (int i = start + 1; i < end; ++i) {
        if (min_ > fences[i]) min_ = fences[i];
    }
    hnum = min_ - bottom;
    // [start, end) 에서 horizontal 로 칠하고 남은 부분 재귀로 보냄.
    for (int idx = start; idx < end;) {
        // min_ 이하는 이미 칠했으므로 건너뜀
        if (fences[idx] <= min_) idx++;
        else {
            nstart = idx;
            while (idx < end && fences[idx] != min_) idx++;
            hnum += stroke(nstart, idx, min_);
        }
    }
    if (vnum < hnum) return vnum;
    else return hnum;
}

int main() {
    int n, input;
    cin >> n;  // fence 의 갯수
    for (int i = 0; i < n; ++i) {
        cin >> input;
        fences.push_back(input);
    }
    cout << stroke(0, n, 0) << endl;
    return 0;
}