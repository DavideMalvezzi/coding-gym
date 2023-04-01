#include <bits/stdc++.h>

using namespace std;

template< typename T >
typename std::vector<T>::iterator insert_sorted( std::vector<T> & vec, T const& item ){
    return vec.insert
        ( 
            std::upper_bound( vec.begin(), vec.end(), item ),
            item 
        );
}

float median(vector<int> window){
    if(window.size() % 2 == 0){
        return float(window[window.size() / 2] + window[window.size() / 2 - 1]) / 2;
    }
    return window[window.size() / 2];
}

int activityNotifications(vector<int> expenditure, int d) {
    vector<int> window;
    copy_n(expenditure.begin(), d, back_inserter(window));
    sort(window.begin(), window.end());
    
    int notifications = 0;
    for(int i = d; i < expenditure.size(); i++){
        float m = median(window);
        if(expenditure[i] >= 2 * m){
            notifications++;
        }
        
        int elem = expenditure[i - d];
        window.erase(lower_bound(window.begin(), window.end(), elem));
        insert_sorted(window, expenditure[i]);
    }
    
    return notifications;
}

int main(){
    int n, d;
    cin >> n >> d;
    vector<int> expenditure(n);
    
    for (int i = 0; i < n; i++) {
        cin >> expenditure[i];
    }

    int result = activityNotifications(expenditure, d);
    cout << result;

    return 0;
}