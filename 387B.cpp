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
    vector<int> need(n);
    for (int i = 0; i < n; ++i) {
        cin >> need[i];
    }
    vector<int> curr(m);
    for (int i = 0; i < m; ++i) {
        cin >> curr[i];
    }
    sort(need.begin(), need.end());
    sort(curr.begin(), curr.end());
    int ans = n;
    for (int i = 0, p = 0; i < need.size(); ++i) {
        while (p < curr.size() && curr[p] < need[i]) {
            ++p; 
        }
        if (p < curr.size() && curr[p] >= need[i]) {
            --ans;
        }
    } 
    cout << ans << endl;
    return 0;
}

