// http://codeforces.com/problemset/problem/118/A
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string word;
    string result;
    cin >> word;
    for (int i = 0; i < word.length(); ++i) {
        if (word[i] == 'a' ||
            word[i] == 'e' ||
            word[i] == 'i' ||
            word[i] == 'o' ||
            word[i] == 'u' ||
            word[i] == 'y' ||
            word[i] == 'A' ||
            word[i] == 'E' ||
            word[i] == 'I' ||
            word[i] == 'O' ||
            word[i] == 'U' ||
            word[i] == 'Y') {
                continue;
        }
        else {
            result += '.';
            result += tolower(word[i]);
        }
    }
    cout << result << endl;
    return 0;
}