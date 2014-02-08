#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int arg_num, char* argv[]) {
    int n, m;
    cin >> n >> m;
    vector<int> vec(m);
    for (int i = 0; i < m; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int ans = 1e9;
    for (int i = 0; i + n - 1 < m; ++i) {
        ans = min(ans, vec[i - 1 + n] - vec[i] ); 
    }
    cout << ans << endl;
    return 0;
}

