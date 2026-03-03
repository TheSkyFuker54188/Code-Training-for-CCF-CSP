#include <iostream>
#include <vector>
#include <unordered_set>
#include <functional>
using namespace std;

typedef long long ll;

int matchRequirement[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void constructNumbers(int remaining, ll currentValue, bool hasDigits, vector<ll> &result)
{
    if (remaining <= 0)
    {
        if (hasDigits)
            result.emplace_back(currentValue);
        return;
    }

    if (!hasDigits)
    {
        if (remaining == matchRequirement[0])
            result.emplace_back(0);

        for (int digit = 1; digit <= 9; ++digit)
        {
            int cost = matchRequirement[digit];
            if (remaining >= cost)
                constructNumbers(remaining - cost, digit, true, result);
        }
    }
    else
    {
        for (int digit = 0; digit <= 9; ++digit)
        {
            int cost = matchRequirement[digit];
            if (remaining >= cost)
                constructNumbers(remaining - cost, currentValue * 10 + digit, true, result);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int totalMatches;
    cin >> totalMatches;

    if (totalMatches < 4)
    {
        cout << 0;
        return 0;
    }

    int matchesForDigits = totalMatches - 4;

    vector<vector<ll>> possibleDigits(matchesForDigits + 1);

    for (int matches = 1; matches <= matchesForDigits; ++matches)
    {
        constructNumbers(matches, 0, false, possibleDigits[matches]);
    }

    vector<unordered_set<ll>> quickLookup(matchesForDigits + 1);

    for (int i = 1; i <= matchesForDigits; ++i)
    {
        for (const auto &value : possibleDigits[i])
        {
            quickLookup[i].insert(value);
        }
    }

    ll counter = 0;

    for (int leftMatches = 1; leftMatches <= matchesForDigits; ++leftMatches)
    {
        for (int middleMatches = 1; leftMatches + middleMatches <= matchesForDigits; ++middleMatches)
        {
            int rightMatches = matchesForDigits - leftMatches - middleMatches;

            if (rightMatches < 1)
                continue;

            for (const auto &leftValue : possibleDigits[leftMatches])
            {
                for (const auto &middleValue : possibleDigits[middleMatches])
                {
                    ll rightValue = leftValue + middleValue;

                    if (quickLookup[rightMatches].find(rightValue) != quickLookup[rightMatches].end())
                    {
                        counter++;
                    }
                }
            }
        }
    }

    cout << counter;
    return 0;
}
