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

bool check(const vector<int> &vec, int len) {
    if (len >= vec.size()) {
        return true;
    }
    if (len <= 0) {
        return false;
    }
    vector<int> tmp;  
    make_heap(tmp.begin(), tmp.end(), less<int>());
    for (int i = vec.size() - 1; i >= 0; --i) {
        if (tmp.size() < len) {
            tmp.push_back(vec[i]);
            push_heap(tmp.begin(), tmp.end(), less<int>());
        } else {
            pop_heap(tmp.begin(), tmp.end(), less<int>());
            if (tmp.back() < 1) {
                return false;
            }
            tmp.back() = min(tmp.back() - 1, vec[i]);
            push_heap(tmp.begin(), tmp.end(), less<int>());
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int left = 1;
    int right = n;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        bool ret = check(vec, mid);
        if (ret && (mid == 1 || !check(vec, mid - 1))) {
            left = mid;
            break;
        }
        if (ret) {
            right = mid - 1;
        } else {
            left = mid + 1; 
        }
    }
    cout << left << endl;
    return 0;
}

