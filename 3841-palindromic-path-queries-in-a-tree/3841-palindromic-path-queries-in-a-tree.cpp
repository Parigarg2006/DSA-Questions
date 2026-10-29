class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 20;

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> depth(n, 0);
        vector<int> tin(n), tout(n);
        vector<int> parent(n, 0);

        int timer = 0;

        // Iterative DFS to calculate Euler Tour times
        stack<tuple<int, int, bool>> st;
        st.push({0, 0, false});

        while (!st.empty()) {
            auto [u, p, exiting] = st.top();
            st.pop();

            if (exiting) {
                tout[u] = timer;
                continue;
            }

            parent[u] = p;
            up[0][u] = p;
            tin[u] = ++timer;

            st.push({u, p, true});

            for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
                int v = adj[u][i];

                if (v == p)
                    continue;

                depth[v] = depth[u] + 1;
                st.push({v, u, false});
            }
        }

        // Binary lifting table
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        // Lowest Common Ancestor
        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v])
                swap(u, v);

            int diff = depth[u] - depth[v];

            for (int k = 0; k < LOG; k++) {
                if (diff & (1 << k))
                    u = up[k][u];
            }

            if (u == v)
                return u;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][u] != up[k][v]) {
                    u = up[k][u];
                    v = up[k][v];
                }
            }

            return up[0][u];
        };

        // Fenwick Tree for XOR range updates
        vector<int> bit(n + 2, 0);

        auto add = [&](int idx, int val) {
            for (; idx <= n + 1; idx += idx & -idx)
                bit[idx] ^= val;
        };

        auto rangeUpdate = [&](int l, int r, int val) {
            add(l, val);
            add(r + 1, val);
        };

        auto pointQuery = [&](int idx) {
            int res = 0;

            for (; idx > 0; idx -= idx & -idx)
                res ^= bit[idx];

            return res;
        };

        vector<int> charMask(n);

        for (int i = 0; i < n; i++) {
            charMask[i] = 1 << (s[i] - 'a');
            rangeUpdate(tin[i], tout[i], charMask[i]);
        }

        vector<bool> answer;

        for (string &q : queries) {
            stringstream ss(q);

            string type;
            int u, v;

            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int newMask = 1 << (c - 'a');
                int change = charMask[u] ^ newMask;

                if (change != 0) {
                    rangeUpdate(tin[u], tout[u], change);
                    charMask[u] = newMask;
                    s[u] = c;
                }
            }
            else {
                ss >> v;

                int w = lca(u, v);

                int maskU = pointQuery(tin[u]);
                int maskV = pointQuery(tin[v]);

                int pathMask = maskU ^ maskV ^ charMask[w];

                // At most one character can have an odd frequency
                answer.push_back(
                    (pathMask & (pathMask - 1)) == 0
                );
            }
        }

        return answer;
    }
};