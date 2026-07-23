#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // Convert wordList to a hash set for O(1) lookups and deletions.
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> result;
        
        // If the endWord is not in the dictionary, no transformation sequence is possible.
        if (dict.find(endWord) == dict.end()) {
            return result;
        }

        // Map to store parent pointers for each word to reconstruct paths backward.
        unordered_map<string, vector<string>> parents;
        unordered_set<string> currentLevel;
        currentLevel.insert(beginWord);

        bool found = false;
        dict.erase(beginWord);

        // Perform Breadth-First Search (BFS) to find the shortest transformation sequences.
        while (!currentLevel.empty() && !found) {
            // Remove words of the current level from the dictionary to prevent cycles
            // and ensure we only traverse via shortest paths.
            for (const string& w : currentLevel) {
                dict.erase(w);
            }
            
            unordered_set<string> nextLevel;
            for (const string& word : currentLevel) {
                string temp = word;
                for (int i = 0; i < temp.length(); ++i) {
                    char originalChar = temp[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == originalChar) continue;
                        temp[i] = c;
                        
                        // Check if the modified word exists in the dictionary.
                        if (dict.find(temp) != dict.end()) {
                            nextLevel.insert(temp);
                            parents[temp].push_back(word);
                            if (temp == endWord) {
                                found = true;
                            }
                        }
                    }
                    temp[i] = originalChar;
                }
            }
            currentLevel = nextLevel;
        }

        // If endWord was never reached, return an empty result.
        if (!found) {
            return result;
        }

        // Backtrack using Depth-First Search (DFS) starting from endWord to beginWord.
        vector<string> path;
        path.push_back(endWord);
        dfs(endWord, beginWord, parents, path, result);
        return result;
    }

private:
    void dfs(const string& word, const string& beginWord, unordered_map<string, vector<string>>& parents, vector<string>& path, vector<vector<string>>& result) {
        if (word == beginWord) {
            vector<string> validPath = path;
            reverse(validPath.begin(), validPath.end());
            result.push_back(validPath);
            return;
        }
        for (const string& parent : parents[word]) {
            path.push_back(parent);
            dfs(parent, beginWord, parents, path, result);
            path.pop_back();
        }
    }
};