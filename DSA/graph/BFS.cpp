// Created by smit1 on 30-07-2024.
#include <iostream>
#include <unordered_map>
#include <vector>
#include<queue>
using namespace std;
void BFS(unordered_map<char,vector<char>> graph,char source){
    queue<char> qu;
    qu.push(source);
    while (!qu.empty()){
        char curr=qu.front();
        qu.pop();
        cout<<curr<<endl;
        for(char c:graph[curr]){
            qu.push(c);
        }
    }
}
int main() {
    unordered_map<char,vector<char>> mp;
    mp['a'] = { 'c','b'};
    mp['b'] = {'d'};
    mp['c'] = {'e'};
    mp['d'] = {'f'};
    mp['e'] = {};
    mp['f'] = {};
    BFS(mp,'a');
    return 0;
}

