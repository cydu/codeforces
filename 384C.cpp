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
    int n = 0;
    cin >> n;
    vector<int> vec(n);
    int left = 0;
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
        if (vec[i] == 0) {
            ++left;
        }
    }
    long long ans = 0;
    int curr = left;
    for (int i = 0; i < n; ++i) {
        if (vec[i] == 0) {
            --curr;
        } else {
            ans += curr;
        }
    }
    
    long long ans2 = 0;
    curr = n - left;
    for (int i = n - 1; i >= 0; --i) {
        if (vec[i] == 1) {
            --curr;
        } else {
            ans2 += curr;
        }
    }
    //cout << left << " " << ans << " " << ans2 << endl;
    cout << min(ans, ans2) << endl;
    return 0;
}

