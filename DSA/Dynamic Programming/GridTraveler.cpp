#include <iostream>
#include <unordered_map>
using namespace std;
//recursion
//int gridTraveler(int row,int col){
//    if(row==0 || col ==0){
//        return 0;
//    }
//    if(row==1 && col==1){
//        return 1;
//    }
//    return gridTraveler(row-1,col)+ gridTraveler(row,col-1);
// }





// Custom hash function for pair<int, int>
struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1, T2> &p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

//}

int gridTraveler(int row, int col, unordered_map<pair<int, int>, int, pair_hash> &mp) {
    if (row == 0 || col == 0) return 0;
    if (row == 1 && col == 1) return 1;
    if (mp.find(make_pair(row, col)) != mp.end()  || mp.find(make_pair(col, row)) != mp.end()) {
        return mp[make_pair(row, col)];
    }
    mp[make_pair(row, col)] = gridTraveler(row - 1, col, mp) + gridTraveler(row, col - 1, mp);
    return mp[make_pair(row, col)];
}

int main() {
    unordered_map<pair<int, int>, int, pair_hash> mp;
    cout << gridTraveler(2, 3, mp) << endl; // Should print the number of ways to travel a 2x3 grid

    return 0;
}
