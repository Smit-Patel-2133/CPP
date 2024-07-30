#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

bool has_path(unordered_map<char, vector<char>> graph, char source, char des) {
    queue<char> qu;
    qu.push(source);
    while(!qu.empty()){
        char curr = qu.front();
        qu.pop();
        if(curr==des){
            return true;
        }
        for(char c:graph[curr]){
            qu.push(c);
        }
    }
    return false;
}

int main() {
    unordered_map<char, vector<char>> mp;
    mp['a'] = {'b', 'c'};
    mp['b'] = {'d'};
    mp['c'] = {'e'};
    mp['d'] = {'f'};
    mp['e'] = {};
    mp['f'] = {};
    mp['g']={'e'};

    cout << (has_path(mp, 'a', 'e') ? "true" : "false") << endl;
    return 0;
}
