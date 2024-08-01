#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

int BFS(unordered_map<char, vector<char>> graph, char source,char target, unordered_map<char, bool>& visited) {
    queue<pair<char, int>> qu;
    qu.push(make_pair(source, 0));
    visited[source] = true;

    while (!qu.empty()) {
        char current = qu.front().first;
        int level = qu.front().second;
        qu.pop();
    if(current==target){
        return level;
    }
        for (char neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                qu.push(make_pair(neighbor, level + 1));
            }
        }
    }

    // Example: Return the level of the last node (for demonstration purposes)
    // This can be modified based on what you need BFS to return
    return 0;
}

void buildGraph(vector<vector<char>> ed, unordered_map<char, vector<char>>& graph) {
    for (auto a : ed) {
        char first = a[0];
        char second = a[1];
        graph[first].push_back(second);
        graph[second].push_back(first);
    }
}


int main() {
    vector<vector<char>> edge;
    edge.push_back({'w', 'x'});
    edge.push_back({'x', 'y'});
    edge.push_back({'z', 'y'});
    edge.push_back({'z', 'v'});
    edge.push_back({'w', 'v'});

    unordered_map<char, vector<char>> graph;
    buildGraph(edge, graph);

    unordered_map<char, bool> visited;
    for (auto c : graph) {
        visited[c.first] = false;
    }

    cout << "BFS result: " << BFS(graph, 'w', 'z',visited) << endl;

    return 0;
}
