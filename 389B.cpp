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

bool check_cross(vector<string> &vec, int i, int j) {
    if (vec[i][j] != '#') {
        return true;
    }
    if (i + 2 >= vec.size() || j - 1 < 0 || j + 1 >= vec.size() ) {
        return false;
    }
    vec[i][j] = '.';
    for (int k = -1; k <= 1; ++k) {
        if (vec[i + 1][j + k] == '#') {
            vec[i + 1][j + k] = '.';
        } else {
            return false;
        }
    }
    if (vec[i + 2][j] == '#') {
        vec[i + 2][j] = '.';
    } else {
        return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    int n;
    cin >> n;
    vector<string> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!check_cross(vec, i, j)) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}

