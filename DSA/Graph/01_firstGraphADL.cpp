#include <bits/stdc++.h>
using namespace std;

int slotScore(string &original, string &guess)
{
    int perfectHit = 0;
    int pseudoHit = 0;
    unordered_set<int> perfectHitSlots;
    unordered_set<char> pseudoHitColors; // To track colors for pseudo hits

    // Calculate perfect hits
    for (int i = 0; i < original.size(); i++)
    {
        if (original[i] == guess[i])
        {
            perfectHit += 2;
            perfectHitSlots.insert(i);
        }
    }

    // Calculate pseudo hits
    for (int i = 0; i < original.size(); i++)
    {
        if (perfectHitSlots.find(i) == perfectHitSlots.end())
        {
            size_t found = original.find(guess[i]);
            if (found != string::npos && pseudoHitColors.find(guess[i]) == pseudoHitColors.end())
            {
                pseudoHit += 1;
                pseudoHitColors.insert(guess[i]); // Mark color as counted
            }
        }
    }

    return perfectHit + pseudoHit;
}

int main()
{
    string original = "RGBY";
    string guess = "GGRR";

    int result = slotScore(original, guess);

    cout << "Total Score: " << result << endl;

    return 0;
}
