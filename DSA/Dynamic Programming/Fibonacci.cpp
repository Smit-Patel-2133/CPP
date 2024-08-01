//
// Created by smit1 on 01-08-2024.
//
#include <iostream>
#include <unordered_map>
using namespace std;
//recursion

//int fib(int n){
//    if (n<=2)
//        return 1;
//    return fib(n-1)+ fib(n-2);
//}

//

int fib(int n, unordered_map<int, int> &memo) {
    if (n <= 2)
        return 1;
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }
    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
    return memo[n];
}

int main() {
    unordered_map<int, int> memo;
    cout << "Fibonacci of 50: " << fib(50, memo) << endl;

    return 0;
}