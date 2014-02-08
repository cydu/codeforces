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
    string s;
    cin >> s;
    int last = -1;
    int ans = 0;
    string::size_type p = s.find("bear", 0);
    while (p != std::string::npos) {
        ans += (p - last) * (s.length() - p - 3);
        last = p;
        p = s.find("bear", p + 1);
    }
    cout << ans << endl;
    return 0;
}

