#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool has_path(unordered_map<char, vector<char>> graph, char source, char des) {
    if (source == des) {
        return true;
    }
    for(char c : graph[source]) {
        if (has_path(graph, c, des) == true) {
            return true;
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

    cout << (has_path(mp, 'a', 'g') ? "true" : "false") << endl;
    return 0;
}
