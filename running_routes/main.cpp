#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

typedef pair<uint32_t, uint32_t> route;

bool intersect(route r1, route r2){
    return r2.first <= r1.second;
}

int main() {
    uint32_t routes_num;
    cin >> routes_num;

    vector<route> routes(routes_num);
    for(size_t i = 0; i < routes_num; i++){
        route p;
        cin >> p.first >> p.second;
        routes[i] = p;
    }
    
    sort(
        routes.begin(), routes.end(), 
        [] (const auto& lhs, const auto& rhs) {
            return lhs.first < rhs.first;
        }
    );

    int i = 0;
    while(i < routes.size() - 1 && routes.size() > 1){
        if(intersect(routes[i], routes[i + 1])){
            routes[i].second = max(routes[i].second, routes[i + 1].second);
            routes.erase(routes.begin() + i + 1);
            i--;
        }
        i++;
    }

    for(size_t i = 0; i < routes.size(); i++){
        cout << routes[i].first << " " << routes[i].second;
        if(i < routes.size() - 1){
            cout << endl;
        }
    }
    

    return 0;
}
