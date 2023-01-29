#include <bits/stdc++.h>

using namespace std;

int main() {
    uint32_t n;
    cin >> n;

    vector<uint32_t> calories(n);
    copy_n(istream_iterator<uint32_t>(cin), n, calories.begin());

    uint32_t i = 0;
    std::vector<long> w(calories.size());
    std::generate(w.begin(), w.end(), [&i] {
        return (1UL << i++);
    });
    
    std::sort(calories.begin(), calories.end(), std::greater<uint32_t>());
    uint32_t total = std::inner_product(w.begin(), w.end(), calories.begin(), 0UL);

    cout << total;
}
