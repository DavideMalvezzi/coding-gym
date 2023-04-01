#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

bool update_check(int val, set<int>& check){
    if(val != 0){
        if(check.find(val) != check.end()){
            return false;
        }
        check.insert(val);
    }
    return true;
}

int main() {
    int sudoku[9][9] = {0};
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int r, c, v;
        cin >> r >> c >> v;
        sudoku[r-1][c-1] = v;
    }
    
    for(int i = 0; i < 9; i++){
        set<int> check;
        for(int j = 0; j < 9; j++){
            if(!update_check(sudoku[i][j], check)){
                cout << "WRONG INPUT";
                return 0;
            }
        }
    }
    
    for(int i = 0; i < 9; i++){
        set<int> check;
        for(int j = 0; j < 9; j++){
            if(!update_check(sudoku[j][i], check)){
                cout << "WRONG INPUT";
                return 0;
            }
        }
    }
    
    for(int i = 0; i < 9; i+=3){
        for(int j = 0; j < 9; j+=3){
            set<int> check;
            for(int k = i; k < i + 3; k++){
                for(int l = j; l < j + 3; l++){
                   if(!update_check(sudoku[k][l], check)){
                        cout << "WRONG INPUT";
                        return 0;
                    }   
                }
            }   
        }
    }
    
    cout << "OK";
    
    return 0;
}
