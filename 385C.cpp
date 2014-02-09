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

vector<int> prime_list(int n) {
    vector<int> primes;
    vector<char> table(n, 1);
    for (int i = 2; i < n; ++i) {
        if (table[i]) {
            primes.push_back(i);
            for (int j = i + i; j < n; j += i) {
                table[j] = 0;
            }
        }
    }
    return primes;
}

int main(int argc, char* argv[]) {
    int n, m, l, r, mMax;
    cin >> n;
    vector<int> vec(n);
    mMax = 0;
    map<int, int> bag;
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
        ++bag[ vec[i] ];
        mMax = max(mMax, vec[i]);
    }
    vector<int> primes = prime_list(mMax + 3);
    vector<int> primes_nums(primes.size());
    for (int i = 0; i < primes.size(); ++i) {
        for (int j = primes[i]; j <= mMax; j += primes[i]) {
            if (bag.count(j)) {
                primes_nums[i] += bag[j]; 
            }
        }   
    }
    vector<int> pre_sum(primes.size() + 1);
    for (int i = 0; i < primes.size(); ++i) {
        pre_sum[i + 1] = pre_sum[i] + primes_nums[i];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        vector<int>::iterator lit = lower_bound(primes.begin(), primes.end(), l);
        vector<int>::iterator rit = upper_bound(primes.begin(), primes.end(), r);
        int lindex = distance(primes.begin(), lit);
        int rindex = distance(primes.begin(), rit);
        cout << pre_sum[rindex] - pre_sum[lindex] << endl;
    }
    return 0;
}

