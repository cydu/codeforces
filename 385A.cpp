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
    int n, c, x, last, earn;
    cin >> n >> c;
    vector<int> vec(n);
    cin >> last;
    earn = 0;
    for (int i = 1; i < vec.size(); ++i) {
        cin >> x;
        earn = max(earn, last - x - c);
        last = x;
    }
    cout << earn << endl;
    return 0;
}

