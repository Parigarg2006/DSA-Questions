
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        // key -> value store karenge
        unordered_map<string, string> mp;

        for (auto &x : knowledge) {
            mp[x[0]] = x[1];
        }

        string ans = "";

        for (int i = 0; i < s.size(); i++) {

            // Normal character
            if (s[i] != '(') {
                ans += s[i];
            }

            // Bracket pair
            else {
                i++;  // '(' ko skip karo

                string key = "";

                // ')' tak key collect karo
                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }

                // key mil gayi
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                }
                else {
                    ans += "?";
                }
            }
        }

        return ans;
    }
};