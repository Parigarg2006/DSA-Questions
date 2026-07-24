#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    struct TrieNode {
        TrieNode* children[26];
        string* word;
        TrieNode() : word(nullptr) {
            for (int i = 0; i < 26; ++i) children[i] = nullptr;
        }
        ~TrieNode() {
            for (int i = 0; i < 26; ++i) delete children[i];
        }
    };

    void insert(TrieNode* root, string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->word = &word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* curr, vector<string>& result) {
        char ch = board[r][c];
        if (ch == '#' || !curr->children[ch - 'a']) return;
        
        curr = curr->children[ch - 'a'];
        if (curr->word != nullptr) {
            result.push_back(*(curr->word));
            curr->word = nullptr; // Avoid duplicate additions
        }
        
        board[r][c] = '#';
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && board[nr][nc] != '#') {
                dfs(board, nr, nc, curr, result);
            }
        }
        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& word : words) {
            insert(root, word);
        }
        
        vector<string> result;
        int rows = board.size();
        if (rows == 0) return result;
        int cols = board[0].size();
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                dfs(board, i, j, root, result);
            }
        }
        
        delete root;
        return result;
    }
};