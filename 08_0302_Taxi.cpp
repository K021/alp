// http://codeforces.com/problemset/problem/158/B
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int nn, input;
    int ones = 0, twos = 0, threes = 0, fours = 0;
    int taxi = 0;

    scanf("%d", &nn);
    while (nn--) {
        scanf("%d", &input);
        switch (input) {
        case 1: ones++; break;
        case 2: twos++; break;
        case 3: threes++; break;
        case 4: fours++; break;
        default: 
            throw "invalid input";
            break;
        }
    }

    taxi = fours;
    taxi += threes;
    // 3 팀 태우는 데 사용된 1 제거
    if (ones > threes) ones -= threes;
    else ones = 0;
    // 2 팁 겹쳐서 태움
    taxi += twos / 2 + twos % 2;
    // 2 팀 남은 차에 1 두명 태움
    if (twos % 2 == 1) {
        if (ones > 2) ones -= 2;
        else ones = 0;
    }
    taxi += ones / 4;
    if (ones % 4 != 0) taxi++;

    printf("%d", taxi);

    return 0;
}