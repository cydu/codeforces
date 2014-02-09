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
    int n, m, x;
    cin >> n >> m;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    map<int, int> bag;
    for (int i = 0; i < m; ++i) {
        cin >> x;
        ++bag[x];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (bag[vec[i]] > 0) {
            --bag[vec[i]]; 
        } else {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}

