#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<bool> visited(n, false);
        visited[0] = true;

        queue<int> keysQueue;
        keysQueue.push(0);

        while (!keysQueue.empty())
        {
            int currentRoom = keysQueue.front();
            keysQueue.pop();

            for (int key : rooms[currentRoom])
            {
                if (!visited[key])
                {
                    visited[key] = true;
                    keysQueue.push(key);
                }
            }
        }

        for (bool roomVisited : visited)
        {
            if (!roomVisited)
                return false;
        }

        return true;
    }
};

int main()
{
    Solution sol;

    // Example usage:
    vector<vector<int>> rooms = {{1,3}, {}, {3}, {2}};
    bool result = sol.canVisitAllRooms(rooms);

    if (result)
    {
        cout << "All rooms can be visited." << endl;
    }
    else
    {
        cout << "Some rooms cannot be visited." << endl;
    }

    return 0;
}
