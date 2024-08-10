//
// Created by smit1 on 07-08-2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(6);
    v.push_back(5);
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    reverse(v.begin(),v.end());
    for(int i:v){
        cout<< i<<" ";
    }
    return 0;
}