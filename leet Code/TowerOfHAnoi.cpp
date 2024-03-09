// #include <iostream>
// #include <vector>

// using namespace std;

// void towerOfHanoiHelper(int n, int source, int auxiliary, int destination, vector<vector<int>> &moves)
// {
//     if (n == 1)
//     {
//         // Base case: Move the disk directly
//         vector<int> currMove = {source, destination};
//         moves.push_back(currMove);
//         return;
//     }

//     // Move n-1 disks from source to auxiliary using destination as the auxiliary rod
//    towerOfHanoiHelper(n - 1, source, destination, auxiliary, moves);

//     // Move the nth disk from source to destination
//     vector<int> currMove = {source, destination};
//     moves.push_back(currMove);

//     // Move the n-1 disks from auxiliary to destination using source as the auxiliary rod
//     towerOfHanoiHelper(n - 1, auxiliary, source, destination, moves);
// }

// vector<vector<int>> towerOfHanoi(int n)
// {
//     vector<vector<int>> moves;
//     towerOfHanoiHelper(n, 1, 2, 3, moves);
//     return moves;
// }

// int main()
// {
//     int N;
//     cout << "Enter the number of disks: ";
//     cin >> N;

//     vector<vector<int>> moves = towerOfHanoi(N);

//     cout << "Output:" << endl;
//     for (const auto &move : moves)
//     {
//         for (int value : move)
//         {
//             cout << value << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }





// // steps
// #include <iostream>
// #include <vector>

// using namespace std;

// void towerOfHanoiHelper(int n, int source, int auxiliary, int destination, vector<vector<int>> &moves)
// {
//     if (n == 1)
//     {
//         // Base case: Move the disk directly
//         vector<int> currMove = {source, destination};
//         moves.push_back(currMove);
//         cout << "Move disk " << n << " from rod " << source << " to rod " << destination << endl;
//         return;
//     }

//     // Move n-1 disks from source to auxiliary using destination as the auxiliary rod
//     cout << "Before recursion: Move " << n - 1 << " disks from " << source << " to " << auxiliary << " using " << destination << " as auxiliary." << endl;
//     towerOfHanoiHelper(n - 1, source, destination, auxiliary, moves);
//     cout << "After recursion: Moved " << n - 1 << " disks from " << source << " to " << auxiliary << " using " << destination << " as auxiliary." << endl;

//     // Move the nth disk from source to destination
//     vector<int> currMove = {source, destination};
//     moves.push_back(currMove);
//     cout << "Move disk " << n << " from rod " << source << " to rod " << destination << endl;

//     // Move the n-1 disks from auxiliary to destination using source as the auxiliary rod
//     cout << "Before recursion: Move " << n - 1 << " disks from " << auxiliary << " to " << destination << " using " << source << " as auxiliary." << endl;
//     towerOfHanoiHelper(n - 1, auxiliary, source, destination, moves);
//     cout << "After recursion: Moved " << n - 1 << " disks from " << auxiliary << " to " << destination << " using " << source << " as auxiliary." << endl;
// }

// vector<vector<int>> towerOfHanoi(int n)
// {
//     vector<vector<int>> moves;
//     towerOfHanoiHelper(n, 1, 2, 3, moves);
//     return moves;
// }

// int main()
// {
//     int N;
//     cout << "Enter the number of disks: ";
//     cin >> N;

//     vector<vector<int>> moves = towerOfHanoi(N);

//     cout << "Output:" << endl;
//     for (const auto &move : moves)
//     {
//         for (int value : move)
//         {
//             cout << value << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }



// road
#include <iostream>
#include <vector>

using namespace std;

void printRodCapacities(const vector<int> &rod1, const vector<int> &rod2, const vector<int> &rod3)
{
    cout << "Rod 1: ";
    for (int disk : rod1)
    {
        cout << disk << " ";
    }
    cout << endl;

    cout << "Rod 2: ";
    for (int disk : rod2)
    {
        cout << disk << " ";
    }
    cout << endl;

    cout << "Rod 3: ";
    for (int disk : rod3)
    {
        cout << disk << " ";
    }
    cout << endl
         << endl;
}

void moveDisk(int disk, int source, int destination, vector<vector<int>> &moves,
              vector<int> &rod1, vector<int> &rod2, vector<int> &rod3)
{
    moves.push_back({disk, source, destination});
    switch (source)
    {
    case 1:
        rod1.pop_back();
        break;
    case 2:
        rod2.pop_back();
        break;
    case 3:
        rod3.pop_back();
        break;
    }

    switch (destination)
    {
    case 1:
        rod1.push_back(disk);
        break;
    case 2:
        rod2.push_back(disk);
        break;
    case 3:
        rod3.push_back(disk);
        break;
    }
}

void towerOfHanoiHelper(int n, int source, int auxiliary, int destination, vector<vector<int>> &moves,
                        vector<int> &rod1, vector<int> &rod2, vector<int> &rod3)
{
    if (n == 1)
    {
        // Base case: Move the disk directly
        moveDisk(1, source, destination, moves, rod1, rod2, rod3);
        cout << "Move disk " << n << " from rod " << source << " to rod " << destination << endl;
        printRodCapacities(rod1, rod2, rod3);
        return;
    }

    // Move n-1 disks from source to auxiliary using destination as the auxiliary rod
    cout << "Before recursion: Move " << n - 1 << " disks from " << source << " to " << auxiliary << " using " << destination << " as auxiliary." << endl;
    towerOfHanoiHelper(n - 1, source, destination, auxiliary, moves, rod1, rod2, rod3);
    cout << "After recursion: Moved " << n - 1 << " disks from " << source << " to " << auxiliary << " using " << destination << " as auxiliary." << endl;

    // Move the nth disk from source to destination
    moveDisk(n, source, destination, moves, rod1, rod2, rod3);
    cout << "Move disk " << n << " from rod " << source << " to rod " << destination << endl;
    printRodCapacities(rod1, rod2, rod3);

    // Move the n-1 disks from auxiliary to destination using source as the auxiliary rod
    cout << "Before recursion: Move " << n - 1 << " disks from " << auxiliary << " to " << destination << " using " << source << " as auxiliary." << endl;
    towerOfHanoiHelper(n - 1, auxiliary, source, destination, moves, rod1, rod2, rod3);
    cout << "After recursion: Moved " << n - 1 << " disks from " << auxiliary << " to " << destination << " using " << source << " as auxiliary." << endl;
}

vector<vector<int>> towerOfHanoi(int n)
{
    vector<vector<int>> moves;
    vector<int> rod1, rod2, rod3;
    for (int i = n; i >= 1; --i)
    {
        rod1.push_back(i);
    }

    towerOfHanoiHelper(n, 1, 2, 3, moves, rod1, rod2, rod3);
    return moves;
}

int main()
{
    int N;
    cout << "Enter the number of disks: ";
    cin >> N;

    vector<vector<int>> moves = towerOfHanoi(N);

    cout << "Final Rod Configuration:" << endl;
    vector<int> rod1, rod2, rod3;
    printRodCapacities(rod1, rod2, rod3);

    cout << "Output:" << endl;
    for (const auto &move : moves)
    {
        for (int value : move)
        {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}
