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

bool check(vector<string> &vec, int i, int j, int n) {
    if (vec[i][j] != '.') {
        return false;
    }
    static int dx[] = {-1, 0, 0, 1};
    static int dy[] = {0, -1, 1, 0};
    for (int k = 0; k < 4; ++k) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x >= 0 && x < n && y >= 0 && y < n && vec[x][y] == 'C') {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    int n, ans;
    cin >> n;
    vector<string> vec(n, string(n, '.'));
    ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (check(vec, i, j, n)) {
                ++ans;
                vec[i][j] = 'C';
            }
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; ++i) {
        cout << vec[i] << endl;
    }
    return 0;
}

