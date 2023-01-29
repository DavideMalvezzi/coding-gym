#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h>

using namespace std;


int main() {
    uint32_t n_samples, duration;
    cin >> n_samples >> duration;

    vector<uint32_t> samples(n_samples);
    copy_n(istream_iterator<uint32_t>(cin), n_samples, samples.begin());

    uint32_t tot = inner_product(
        samples.begin(), samples.end() - 1, 
        samples.begin() + 1, 
        duration,      
        plus<uint32_t>(),
        [duration](const uint32_t& aa, const uint32_t& bb)
        {
            return min(bb - aa, duration);
        }
    );

    
    cout << tot;
    
    return 0;
}