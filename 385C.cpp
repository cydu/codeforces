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

void prime_solve(vector<int> vec, const vector<int> &primes, 
        map<int, int> &primes_nums) {
    int pn = primes.size();
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < pn && primes[j] <= vec[i]; ++j) {
            int num  = 1;
            while (vec[i] % primes[j] == 0) {
                vec[i] /= primes[j];
                primes_nums[primes[j]] += num;
                num = 0;
                //cout << primes[j] << " ";
            } 
        }
        //cout << endl;
    }
}

int main(int argc, char* argv[]) {
    int n, m, l, r, mMax;
    cin >> n;
    vector<int> vec(n);
    mMax = 0;
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
        mMax = max(mMax, vec[i]);
    }
    vector<int> primes = prime_list(mMax + 3);
    map<int, int> primes_nums;
    prime_solve(vec, primes, primes_nums);
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        auto lit = primes_nums.lower_bound(l);
        auto rit = primes_nums.upper_bound(r);
        int sum = 0;
        for (; lit != rit; ++lit) {
            sum += lit->second;
            //cout << lit->first << " " << lit->second << endl;
        }
        cout << sum << endl;
    }
    return 0;
}

