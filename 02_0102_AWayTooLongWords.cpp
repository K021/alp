// http://codeforces.com/problemset/problem/71/A
#include <stdio.h>
// strlen 검사 -> cplusplus.com 참조 
// -> 헤더 확인 및, 문자열 마지막 널문자 세는지 아닌지 확인
#include <string.h>

int main() {
    int ncase, len;
    char buf[200];
    scanf("%d", &ncase);
    for (; ncase > 0; --ncase) {
        scanf("%s", buf);  // cplusplus 설명서를 확인하면, 아무 공백문자를 기준으로 나누어 받는 것을 알 수 있다.
        len = strlen(buf);
        if (len <= 10) printf("%s\n", buf);
        else printf("%c%d%c\n", buf[0], len-2, buf[len-1]);
    }
    return 0;
}