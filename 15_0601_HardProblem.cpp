// https://codeforces.com/problemset/problem/706/C
// 교수님 섧명 전에 내가 먼저 풀어본 코드
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
    words: 주어진 단어 문자열들을 저장하는 배열, 1 base index
    rvsd: 주어진 단어 문자열들을 reversed 형태로 저장하는 배열, 1 base index
    c: 각 단어를 reverse 하는데 들어가는 에너지 값 배열, 1 base index
    D: i 번째 단어까지 고려했을 때 최소한의 누적 에너지 값을 저장하는 배열, 1 base index
        D[i][0]: i 번째 단어를 그대로 사용할 때 누적 에너지
        D[i][0]: i 번째 단어를 reverse 할 때 누적 에너지
        * 이 값이 음수이면 불가능한 경우를 의미한다
    
    알고리즘:
        초기값
            - D[0] = {0, 0}
        i 구간 로직 
            (w w: i-1 구간의 word 와 i 구간의 word 를 사용할 때)
            - w w, r w 모두 오름차순 && w, r 모두 음수가 아닐 때
                d[0] = min(D.back()[0], D.back()[1]);
            - w w 만 오름차순 && w 가 음수가 아닐 때
                d[0] = D.back()[0];
            - r w 만 오름차순 && r 가 음수가 아닐 때
                d[0] = D.back()[1];
            - w w, r w 모두 불가능할 때
                d[0] = -1; 
            
            - i 구간이 reversed 를 사용하는 경우에도 같은 방식으로 진행

            - d[0], d[1] 모두 음수일 때 
                -1 출력 후 종료
        출력 로직
            - D.back()[0], D.back()[1] 중 최솟값 사용
            - 둘 중 하나가 음수이면 나머지 하나 사용 (둘 다 음수일 경우는 없음)
*/

vector<string> words(1, "");
vector<string> rvsd(1, "");
vector<long long> c(1, 0);
vector<long long> d(2, 0);
vector<vector<long long> > D(1, d);

int main() {
    int n, input;
    string s;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        c.push_back(input);
    }
    for (int i = 0; i < n; ++i) {
        cin >> s;
        words.push_back(s);
        reverse(s.begin(), s.end());
        rvsd.push_back(s);
    }

    for (int i = 1; i <= n; ++i) {
        if (words[i-1].compare(words[i]) <= 0 && D.back()[0] >= 0) {
            if (rvsd[i-1].compare(words[i]) <= 0 && D.back()[1] >= 0)  
                d[0] = min(D.back()[0], D.back()[1]);  // w w, r w 모두 오름차순
            else d[0] = D.back()[0]; // w w 만 오름차순
        }
        else {
            if (rvsd[i-1].compare(words[i]) <= 0 && D.back()[1] >= 0)  // r w 만 오름차순
                d[0] = D.back()[1];  
            else d[0] = -1;  // w w, r w 모두 불가능
        }
        if (words[i-1].compare(rvsd[i]) <= 0 && D.back()[0] >= 0) { 
            if (rvsd[i-1].compare(rvsd[i]) <= 0 && D.back()[1] >= 0) 
                d[1] = min(D.back()[0], D.back()[1]) + c[i];  // w r, r r 모두 오름차순
            else d[1] = D.back()[0] + c[i];  // w r 만 오름차순
        }
        else {
            if (rvsd[i-1].compare(rvsd[i]) <= 0 && D.back()[1] >= 0) 
                d[1] = D.back()[1] + c[i];    // r r 만 오름차순
            else d[1] = -1;  // w w, r w 모두 불가능
        }
        if (d[0] < 0 && d[1] < 0) {
            cout << "-1" << endl; 
            return 0;
        }
        D.push_back(d);
    }
    long long ret = min(D.back()[0], D.back()[1]);
    if (D.back()[0] < 0) ret = D.back()[1];
    if (D.back()[1] < 0) ret = D.back()[0];
    cout << ret << endl;

    return 0;
}