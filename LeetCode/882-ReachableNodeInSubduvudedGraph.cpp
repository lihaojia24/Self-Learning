class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        unordered_map<int, unordered_map<int, int>> g;
        for (const auto& edge : edges)
            g[edge[0]][edge[1]] = g[edge[1]][edge[0]] = edge[2];

        priority_queue<pair<int, int>> q; // {hp, node} sort by HP desc means ToDo List
        unordered_map<int, int> HP; // node -> max HP left means Done

        q.push({M, 0});
        while(!q.empty()) {
            int hp = q.top().first;
            int cur = q.top().second;
            q.pop();
            if (HP.count(cur)) continue;
            HP[cur] = hp;
            for (const auto& pair : g[cur]) {
                int nxt = pair.first;
                int nxt_hp = hp - pair.second - 1;
                if (HP.count(nxt) || nxt_hp < 0) continue;
                q.push({nxt_hp, nxt});
            }
        }

        // output
        int ans = HP.size();
        for (const auto& e : edges) {
            int l1 = HP.count(e[0]) ? HP[e[0]] : 0;
            int l2 = HP.count(e[1]) ? HP[e[1]] : 0;
            ans += min(e[2], l1+l2);
        }
        return ans;
    }
};