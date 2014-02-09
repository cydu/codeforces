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
    int sh, ss, th, ts;
    char c;
    cin >> sh >> c >> ss;
    cin >> th >> c >> ts;
    int sec = sh * 60 + ss;
    sec -= ts;
    sec -= th * 60;
    if (sec < 0) {
        sec += 24*60;
    }
    printf("%02d:%02d\n", sec / 60, sec % 60);
    return 0;
}

