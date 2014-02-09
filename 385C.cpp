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
#include <string.h>
typedef long long lld;

using namespace std;

const static int MAXN = 10000001;
bool prime_table[MAXN];
int vec[MAXN];
int sum[MAXN];
int mMax;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);

    int n, m, l, r, x;
    cin >> n;
    mMax = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        ++vec[x];
        mMax = max(mMax, x);
    }
    ++mMax;

    memset(prime_table, true, mMax);
    for (int i = 2; i < mMax; ++i) {
        if (prime_table[i]) {
            sum[i] += vec[i];
            for (int j = i + i; j < mMax; j += i) {
                prime_table[j] = false;   
                sum[i] += vec[j];
            }
        }
    }
    
    vector<int> primes;
    vector<int> primes_nums;
    for (int i = 0; i < mMax; ++i) {
        if (sum[i] > 0) {
            primes.push_back(i);
            primes_nums.push_back(sum[i]);
            //cout << "prime: " << i << " " << sum[i] << endl;
        }
    }
    
    vector<int> primes_sums(primes_nums.size() + 1);
    for (int i = 0; i < primes_nums.size(); ++i) {
        primes_sums[i + 1] = primes_sums[i] + primes_nums[i];
    }
    
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        vector<int>::iterator lit = lower_bound(primes.begin(), primes.end(), l);
        vector<int>::iterator rit = upper_bound(primes.begin(), primes.end(), r);
        int lindex = distance(primes.begin(), lit);
        int rindex = distance(primes.begin(), rit);
        //cout << "query: " << lindex << " " << rindex << endl;
        cout << primes_sums[rindex] - primes_sums[lindex] << endl;
    }
    return 0;
}

