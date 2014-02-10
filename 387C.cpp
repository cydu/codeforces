#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <math.h>

using namespace std;

typedef long long lld;
typedef pair<int, int> pii;

string p;

bool mgreater(int l, int m, int r) {
    if (m - l == r - m) {
        int n = m - l;
        for (int i = 0; i < n; ++i) {
            if (p[i + l] != p[i + m]) {
                return p[i + l] > p[i + m];
            }
        }
        return true;
    } 
    return m - l > r - m;
}

int solve(int l, int r) {
    pii key = pii(l, r);
    if (l >= r || l >= p.length()) {
        return 0;
    }
    if (p[l] == '0') {
        return -1;
    }
    int ans = 1;
    for (int m = l + (r - l + 1) / 2; m < r; ++m) {
        if (m + 1 < r && p[m + 1] >= p[m]) {
            continue;
        }
        if (p[m] != 0 && mgreater(l, m, r)) {
            int left = solve(l, m);
            int right = solve(m, r);
            if (left > 0 && right > 0) {
                //cout << p.substr(l, m - l) << " " << p.substr(m, r - m) << " " << left << " " << right << endl;
                return left + right; 
            }
        }
    }
    return ans;
}

int main(int argc, char* argv[]) {
    cin >> p;
    int ans = solve(0, p.length());
    cout << ans << endl;
    return 0;
}

