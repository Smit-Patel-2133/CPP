#include <iostream>
#include <vector>

using namespace std;

void kSubFromN(int n, int k, std::vector<int> &temp)
{
    if (n <= 0)
    {
        temp.push_back(n);
        cout << "hello 2" << endl;
        return;
    }
    else
    {
        cout << "hello 1" << endl;
        temp.push_back(n);
        kSubFromN(n - k, k, temp);
    }
    return;
}

void nAddInK(int n,int k, std::vector<int> &temp,int ad)
{
    if (k == n)
    {
        temp.push_back(k);
        cout << "hello 3" << endl;
        return;
    }
    else
    {
        temp.push_back(k);
        cout << "hello 4" << endl;
        nAddInK(n, k + ad, temp,ad); // Corrected the recursive call
    }
    return;
}

std::vector<int> printSeries(int n, int k)
{
    std::vector<int> ans;
    kSubFromN(n, k, ans);
    nAddInK(n,ans.back()+k,ans,k);
   return ans;
}

int main()
{
    int N = 5;
    int K = 2;

    std::vector<int> result = printSeries(N, K);
cout<<result.back()<<endl;
    // Print the result
    for (int num : result)
    {
        std::cout << num << " ";
    }

    return 0;
}
