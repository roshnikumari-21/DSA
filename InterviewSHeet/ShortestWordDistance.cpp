#include <bits/stdc++.h>
using namespace std;


int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
    int index1 = -1, index2 = -1;
    int minDist = INT_MAX;

    for (int i = 0; i < wordsDict.size(); ++i) {
        if (wordsDict[i] == word1) {
            index1 = i;
        }
        if (wordsDict[i] == word2) {
            index2 = i;
        }
        if (index1 != -1 && index2 != -1) {
            minDist = min(minDist, abs(index1 - index2));
        }
    }
    return minDist;
}

int main() {
    vector<string> wordsDict = {"practice", "makes", "perfect", "coding", "makes"};
    string word1 = "coding";
    string word2 = "practice";

    cout << "Shortest Distance: " << shortestDistance(wordsDict, word1, word2) << endl;
    return 0;
}
