#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        set<string> result = parse(expression);
        return vector<string>(result.begin(), result.end());
    }

private:
    set<string> parse(const string& s) {
        // 1. Check for top-level commas (bal == 0)
        vector<string> parts;
        int bal = 0;
        int start = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '{') bal++;
            else if (s[i] == '}') bal--;
            else if (s[i] == ',' && bal == 0) {
                parts.push_back(s.substr(start, i - start));
                start = i + 1;
            }
        }
        parts.push_back(s.substr(start));

        // If there are top-level commas, take the union of all parts
        if (parts.size() > 1) {
            set<string> res;
            for (const string& part : parts) {
                set<string> sub = parse(part);
                res.insert(sub.begin(), sub.end());
            }
            return res;
        }

        // 2. No top-level commas, evaluate the product of factors (concatenation)
        if (s.empty()) return {""};

        int end_pos = 0;
        set<string> f1;
        if (s[0] == '{') {
            bal = 0;
            int j = 0;
            while (j < s.length()) {
                if (s[j] == '{') bal++;
                else if (s[j] == '}') bal--;
                if (bal == 0) break;
                j++;
            }
            string inner = s.substr(1, j - 1);
            f1 = parse(inner);
            end_pos = j + 1;
        } else {
            f1 = {string(1, s[0])};
            end_pos = 1;
        }

        // If nothing left after this factor, return f1
        if (end_pos == s.length()) {
            return f1;
        } else {
            // Otherwise, compute Cartesian product with the rest of the expression
            string rest = s.substr(end_pos);
            set<string> f2 = parse(rest);
            return multiply(f1, f2);
        }
    }

    set<string> multiply(const set<string>& s1, const set<string>& s2) {
        set<string> res;
        for (const string& a : s1) {
            for (const string& b : s2) {
                res.insert(a + b);
            }
        }
        return res;
    }
};