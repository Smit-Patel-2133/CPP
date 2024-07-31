#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

void dfs(char node, unordered_map<char, vector<char>>& graph, unordered_map<char, bool>& visited) {
    stack<char> st;
    st.push(node);
    while (!st.empty()) {
        char curr = st.top();
        st.pop();
        if (!visited[curr]) {
            visited[curr] = true;
            for (auto neighbor : graph[curr]) {
                if (!visited[neighbor]) {
                    st.push(neighbor);
                }
            }
        }
    }
}
int count_graph(unordered_map<char, vector<char>> graph) {
    unordered_map<char, bool> visited;
    for (const auto& node : graph) {
        visited[node.first] = false;
    }
    int count = 0;
    for (const auto& node : graph) {
        if (!visited[node.first]) {
            count++;
            dfs(node.first, graph, visited);
        }
    }
    return count;
}

int main() {
    unordered_map<char, vector<char>> mp;
    mp['1'] = {'2'};
    mp['2'] = {'1'};
    mp['3'] = {};
    mp['4'] = {'6'};
    mp['5'] = {'6'};
    mp['6'] = {'4', '5', '7', '8'};
    mp['7'] = {'6'};
    mp['8'] = {'6'};

    cout << count_graph(mp);
    return 0;
}
