//
// Created by smit1 on 08-08-2024.
//
#include <iostream>
#include <vector>
using namespace std;
 bool canSum(int target,vector<int> vt){
     if(target==0) return true;
     if(target<0) return false;
     for(int i:vt){
         if(canSum(target-i,vt)){
             return true;
         }
     }
     return false;
 }
int main(){
    vector<int> v{2,3};
    int target=7;
    cout<<canSum(target,v);

    return 0;
}