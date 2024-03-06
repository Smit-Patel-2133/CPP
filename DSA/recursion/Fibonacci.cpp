//time complexity  O(2^n)

// #include <iostream>
// using namespace std;
// int fibonacci(int num)
// {
//     if (num <= 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return fibonacci(num - 1) + fibonacci(num - 2);
//     }
// }
// int main(int argc, char const *argv[])
// {
//     int ans = fibonacci(60);
//     cout << ans;
//     return 0;
// }



//time Complexity is O(n)


#include <iostream>
#include <vector>

std::vector<long long> memo;

long long fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    if (memo[n] != -1)
    {
        return memo[n];
    }
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main()
{
    int n = 60;
    memo.resize(n + 1, -1);
    long long ans = fibonacci(n);
    std::cout << ans << std::endl;
    return 0;
}
