#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

bool has_path(unordered_map<char, vector<char>> graph, char source, char des, unordered_map<char, bool>& visited) {
    stack<char> st;
    st.push(source);
    while (!st.empty()) {
        char curr = st.top();
        st.pop();
        if (curr == des) {
            return true;
        }
        if (!visited[curr]) {
            visited[curr] = true;
            for (char c : graph[curr]) {
                st.push(c);
            }
        }
    }
    return false;
}

void buildGraph(vector<vector<char>> ed, unordered_map<char, vector<char>>& graph) {
    for (auto a : ed) {
        char first = a[0];
        char second = a[1];
        graph[first].push_back(second);
        graph[second].push_back(first);
    }
}

void printGraph(const unordered_map<char, vector<char>>& graph) {
    for (const auto& pair : graph) {
        cout << pair.first << ": ";
        for (char neighbor : pair.second) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<char>> edge;
    edge.push_back({'i', 'j'});
    edge.push_back({'i', 'k'});
    edge.push_back({'m', 'k'});
    edge.push_back({'k', 'l'});
    edge.push_back({'o', 'n'});

    unordered_map<char, vector<char>> graph;
    buildGraph(edge, graph);
    printGraph(graph);

    unordered_map<char, bool> visited;
    for (auto c : graph) {
        visited[c.first] = false;
    }

    cout << (has_path(graph, 'i', 'o', visited) ? "true" : "false") << endl;

    return 0;
}
