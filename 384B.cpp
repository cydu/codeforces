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
typedef long long lld;

using namespace std;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    int n, m, k, x;
    cin >> n >> m >> k;
    for (int i = m * n - 1; i >= 0; --i) {
        cin >> x;
    }
    cout << m * (m - 1) / 2 << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            if (k == 0) {
                cout << i + 1 << " " << j + 1<< endl;
            } else {
                cout << j + 1 << " " << i + 1<< endl;
            }
        }
    }
    return 0;
}

