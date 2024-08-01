#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

int dfs(char node, unordered_map<char, vector<char>>& graph, unordered_map<char, bool>& visited) {
    stack<char> st;
    int Node=0;
    st.push(node);
    while (!st.empty()) {
        char curr = st.top();
        st.pop();
        if (!visited[curr]) {
            visited[curr] = true;
            Node++;
            for (auto neighbor : graph[curr]) {
                if (!visited[neighbor]) {
                    st.push(neighbor);
                }
            }
        }
    }
    cout<<Node<<endl;
    return Node;
}
int LargestGraph(unordered_map<char, vector<char>> graph) {
    unordered_map<char, bool> visited;
    for (const auto& node : graph) {
        visited[node.first] = false;
    }
    int largest = 0;
    for (const auto& node : graph) {
        if (!visited[node.first]) {
            largest=max(largest,dfs(node.first, graph, visited));
        }
    }
    return largest;
}

int main() {
    unordered_map<char, vector<char>> mp;
    mp['0'] = {'1','5','8'};
    mp['1'] = {'0'};
    mp['2'] = {'4','3'};
    mp['3'] = {'4','2'};
    mp['4'] = {'3','2'};
    mp['5'] = {'0','8'};
    mp['8'] = {'0','5'};


    cout << LargestGraph(mp);
    return 0;
}
