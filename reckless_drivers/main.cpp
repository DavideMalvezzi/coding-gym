#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;


int main() {
    uint32_t n_samples, duration;
    cin >> n_samples >> duration;

    vector<uint32_t> samples(n_samples);
    for(uint32_t i = 0; i < n_samples; i++){
        cin >> samples[i];
    }
    
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