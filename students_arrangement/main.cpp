#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

bool test(vector<int>& a, vector<int>& b){
    int current = 0;
    for(int i = 0; i < a.size(); i++){
        if(current <= a[i]){
            if(a[i] <= b[i]){
                current = b[i];
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
    
    return true;
    
}

int main() {
    int test_num;
    cin >> test_num;

    for (int i = 0; i < test_num; i++) {
        int height_num;
        cin >> height_num;

        vector<int> boys(height_num);
        copy_n(istream_iterator<int>(cin), height_num, boys.begin());
        sort(boys.begin(), boys.end());

        vector<int> girls(height_num);
        copy_n(istream_iterator<int>(cin), height_num, girls.begin());
        sort(girls.begin(), girls.end());
        
        bool res = test(boys, girls) | test(girls, boys);
        if(res){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
  
        cout << endl;
    }

    return 0;
}
