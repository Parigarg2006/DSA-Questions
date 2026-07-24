#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int word_len = words[0].length();
        int num_words = words.size();
        int total_len = word_len * num_words;
        
        // If the string s is shorter than the total concatenated length, no valid substring can exist.
        if (s.length() < total_len) return result;

        // Frequency map to store the count of each word in words.
        unordered_map<string, int> word_count;
        for (const string& w : words) {
            word_count[w]++;
        }

        // Iterate over each possible offset within the word length to handle all alignments.
        for (int i = 0; i < word_len; ++i) {
            int left = i, right = i;
            unordered_map<string, int> seen;
            int count = 0;

            while (right + word_len <= s.length()) {
                string sub = s.substr(right, word_len);
                right += word_len;

                // Check if the extracted word is part of the given words list
                if (word_count.find(sub) != word_count.end()) {
                    seen[sub]++;
                    count++;

                    // If the frequency of the word exceeds its required count, shrink the window from the left
                    while (seen[sub] > word_count[sub]) {
                        string left_sub = s.substr(left, word_len);
                        seen[left_sub]--;
                        count--;
                        left += word_len;
                    }

                    // If all words are matched exactly, record the starting index
                    if (count == num_words) {
                        result.push_back(left);
                    }
                } else {
                    // If an invalid word is encountered, reset the window
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};