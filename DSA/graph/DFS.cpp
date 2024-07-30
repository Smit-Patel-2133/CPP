// Created by smit1 on 30-07-2024.
#include <iostream>
#include <unordered_map>
#include <vector>
#include<stack>
using namespace std;
void DFS(unordered_map<char,vector<char>> graph,char source){
    stack<char> st;
    st.push(source);
    while(!st.empty()){
        char curr=st.top();
        st.pop();
        cout<<curr<<endl;
        for( char i:graph[curr]){
            st.push(i);
        }
    }
}
int main() {
    unordered_map<char,vector<char>> mp;
    mp['a'] = {'b', 'c'};
    mp['b'] = {'d'};
    mp['c'] = {'e'};
    mp['d'] = {'f'};
    mp['e'] = {};
    mp['f'] = {};
    DFS(mp,'a');
    return 0;
}
