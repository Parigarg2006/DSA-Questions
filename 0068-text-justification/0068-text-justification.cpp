#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int i = 0;

        // Process words line by line
        while (i < n) {
            int j = i;
            int len = 0;
            
            // Greedily pack as many words as possible into the current line
            while (j < n && len + words[j].length() + (j - i) <= maxWidth) {
                len += words[j].length();
                j++;
            }

            string line = "";
            int numWords = j - i;
            int spacesNeeded = maxWidth - len;

            // If it's the last line or the line contains only one word, left-justify it
            if (j == n || numWords == 1) {
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                line.append(maxWidth - line.length(), ' ');
            } else {
                // Fully justify the line by distributing spaces evenly
                int spacesBetween = spacesNeeded / (numWords - 1);
                int extraSpaces = spacesNeeded % (numWords - 1);

                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) {
                        int currentSpaces = spacesBetween + (k - i < extraSpaces ? 1 : 0);
                        line.append(currentSpaces, ' ');
                    }
                }
            }
            res.push_back(line);
            i = j;
        }

        return res;
    }
};