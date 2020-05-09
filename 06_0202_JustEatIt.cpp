// http://codeforces.com/problemset/problem/1285/b
#include <iostream>
#include <vector>

using namespace std;

int ncases;
int n, input;
long long totsum, max_partsum;
vector<long long> max_ps = {0, 0}; 
vector<long long> min_ps = {0, 0};
vector<long long> max_ps_idx = {0, 0};
vector<long long> min_ps_idx = {0, 0};

vector<int> tastes;
vector<long long> ps;

// void check_and_print() {
//     for (int k = n-1; k >= 1; --k) {
//         for (int i = n; i >= k; --i) {
//             partsum = ps[i] - ps[i-k];
//             if (partsum >= totsum) {
//                 cout << "NO" << endl;
//                 return;
//             }
//         }
//     }
//     cout << "YES" << endl;
// }

// void check_and_print() {
//     for (int j = n; j >= 1; --j) {
//         if (ps[n] > max_ps) max_ps = ps[n];
//         else if (ps[n] < min_ps) min_ps = ps[n];
//     }
//     partsum = max_ps - min_ps;
//     if (partsum >= totsum) cout << "NO" << endl;
//     else cout << "YES" << endl;
// }

int main() {    
    cin >> ncases;
    while (ncases--) {
        totsum = 0;
        max_partsum = 0;
        tastes = vector<int>(1, 0);
        ps = vector<long long>(1, 0);
        max_ps = vector<long long>(2, 0);
        min_ps = vector<long long>(2, 0);
        max_ps_idx = vector<long long>(2, 0);
        min_ps_idx = vector<long long>(2, 0);
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> input;
            tastes.push_back(input);
            ps.push_back(ps[i-1] + input);
        }
        totsum = ps.back();
        cout << "=====================================" << endl;
        for (int j = n; j >= 1; --j) {
            if (ps[j] > max_ps[0]) {
                max_ps[0] = ps[j];
                max_ps_idx[0] = j;
            }
            else if (ps[j] < max_ps[0] && ps[j] > max_ps[1]) {
                max_ps[1] = ps[j];
                max_ps_idx[1] = j;
            }
            else if (ps[j] < min_ps[0]) {
                min_ps[0] = ps[j];
                min_ps_idx[0] = j;
            }
            else if (ps[j] > min_ps[0] && ps[j] < min_ps[1]) {
                min_ps[1] = ps[j];
                min_ps_idx[1] = j;
            }
            cout << "max_ps[0]: " << max_ps[0] << ", max_ps_idx[0]: " << max_ps_idx[0] << endl;
            cout << "max_ps[1]: " << max_ps[1] << ", max_ps_idx[1]: " << max_ps_idx[1] << endl;
            cout << "min_ps[0]: " << min_ps[0] << ", min_ps_idx[0]: " << min_ps_idx[0] << endl;
            cout << "min_ps[1]: " << min_ps[1] << ", min_ps_idx[1]: " << min_ps_idx[1] << endl;
            cout << endl;
        }
        cout << "max_ps[0]: " << max_ps[0] << ", max_ps_idx[0]: " << max_ps_idx[0] << endl;
        cout << "max_ps[1]: " << max_ps[1] << ", max_ps_idx[1]: " << max_ps_idx[1] << endl;
        cout << "min_ps[0]: " << min_ps[0] << ", min_ps_idx[0]: " << min_ps_idx[0] << endl;
        cout << "min_ps[1]: " << min_ps[1] << ", min_ps_idx[1]: " << min_ps_idx[1] << endl;

        if (min_ps_idx[0] != 0 && max_ps_idx[0] != n) {
            max_partsum = max_ps[0] - min_ps[0];
        }
        else {
            int a = max_ps[1] - min_ps[0];
            int b = max_ps[0] - min_ps[1];
            if (a > b) max_partsum = a;
            else max_partsum = b;
        }
        if (max_partsum >= totsum) cout << "NO" << endl;
        
        else cout << "YES" << endl;
    }
    return 0;
}