#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'pairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */

int pairs(int k, vector<int> arr) {
    int pairs_count = 0;
    auto prev_state = arr.begin();
    sort(arr.begin(), arr.end());
    
    for(size_t i = 0; i < arr.size() - 1; i++){
        /*
            Perform binary search into the sub-array containing the next k elements.
            If posssible, to reduce the binary search cost start the sub-array to the element subsequent the previous result.
        */
        auto begin = max(arr.begin() + i + 1, prev_state + 1);
        auto end = min(begin + k, arr.end());
        auto result = lower_bound(begin, end, arr[i] + k);

        // Check if found
        if(*result == arr[i] + k){
            prev_state = result;
            pairs_count++;
        } 
    }
    
    return pairs_count;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    copy_n(istream_iterator<int>(cin), n, arr.begin());

    int result = pairs(k, arr);
    cout << result;

    return 0;
}
