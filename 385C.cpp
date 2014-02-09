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
        vector<int> &primes_nums) {
    int pn = primes.size();
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < pn && primes[j] <= vec[i]; ++j) {
            int num  = 1;
            while (vec[i] % primes[j] == 0) {
                vec[i] /= primes[j];
                primes_nums[j] += num;
                num = 0;
                //cout << primes[j] << " ";
            } 
        }
        //cout << endl;
    }
}

class SegmentTree {
public:
    explicit SegmentTree(int n) {
        _m = get_m(n);
        _vec.clear();
        _vec.resize(_m * 2 + 4);
    }

    void add(int key, int value) {
        if (value == 0) {
            return;
        }
        for (key += _m; key > 0; key >>= 1) {
            _vec[key] += value;
        }
    }

    int query(int l, int r) {
        int ans = 0;
        for (l += _m - 1, r += _m; l >> 1 != r >> 1; l >>= 1, r >>= 1) {
            if (l % 2 == 0) {
                ans += _vec[l + 1];
            }
            if (r % 2 == 1) {
                ans += _vec[r - 1];
            }
        }
        return ans;
    }

private:
    int get_m(int n) {
        int m = 8;
        while (m < n) {
            m *= 2;
        }
        return --m;
    }
    vector<int> _vec;
    int _m;
};

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
    vector<int> primes_nums(primes.size());
    prime_solve(vec, primes, primes_nums);
    SegmentTree tree(primes.size() + 2);
    for (int i = 0; i < primes.size(); ++i) {
        tree.add(i + 1, primes_nums[i]);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        vector<int>::iterator lit = lower_bound(primes.begin(), primes.end(), l);
        vector<int>::iterator rit = upper_bound(primes.begin(), primes.end(), r);
        int sum = tree.query(distance(primes.begin(), lit) + 1, distance(primes.begin(), rit) + 1);
        cout << sum << endl;
    }
    return 0;
}

