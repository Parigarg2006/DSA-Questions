#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    /**
     * Finds all concatenated words in the given list.
     * A concatenated word is defined as a string that is entirely composed of at least two shorter words in the given array.
     */
    std::vector<std::string> findAllConcatenatedWordsInADict(std::vector<std::string>& words) {
        // Use a hash set for O(1) average time complexity lookups.
        std::unordered_set<std::string> dict(words.begin(), words.end());
        std::vector<std::string> result;
        
        // Sorting by length ensures that when we process a word, we only check if it can be 
        // formed by words that are strictly shorter (and thus already processed/added to the dict).
        std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
            return a.length() < b.length();
        });
        
        for (const std::string& word : words) {
            if (word.empty()) continue;
            
            // Check if the current word can be formed by existing words in the dictionary.
            if (canForm(word, dict)) {
                result.push_back(word);
            }
            
            // Add the current word to the dictionary for future checks.
            dict.insert(word);
        }
        return result;
    }

private:
    /**
     * Helper function using Dynamic Programming to determine if a word can be formed 
     * by concatenating two or more words from the dictionary.
     */
    bool canForm(const std::string& word, const std::unordered_set<std::string>& dict) {
        int n = word.length();
        if (n == 0) return false;
        
        // dp[i] indicates if the prefix of length i can be formed by dictionary words.
        std::vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= n; ++i) {
            // Check all possible split points j.
            // (j > 0 || i < n) ensures we don't count the word itself as a valid concatenation.
            for (int j = 0; j < i; ++j) {
                if (dp[j] && (j > 0 || i < n) && dict.count(word.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};