#include<iostream>
using namespace std;

long long factorial(long long num){
    if(num==1){
        return num;
    }
return num*factorial(num-1);

}

int main(int argc, char const *argv[])
{
    long long ans=factorial(18);
    cout<<ans;
    return 0;
}
