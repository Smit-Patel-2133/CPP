#include<iostream>
using namespace std;
#include "namespace.h"
using namespace Student;
int main(){
    cout<<"value of x :"<<x;
    int a=Student::x;
    int b=30;
    
    cout<<endl<<hello(a,b);
 return 0;   
}