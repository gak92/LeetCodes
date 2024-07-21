/*
https://leetcode.com/problems/build-a-matrix-with-conditions/description/?envType=daily-question&envId=2024-07-21
*/

class Solution {
private:
    void dfs(int u, vector<int>& visited, unordered_map<int, vector<int>>& adj, stack<int>& st, bool& cycle)
    {
        visited[u] = 1;     // currently running dfs
        for(auto& v : adj[u]) {
            if(visited[v] == 0)
                dfs(v, visited, adj, st, cycle);
            else if(visited[v] == 1) {
                cycle = true;
                return;
            }
        }

        visited[u] = 2;     // mark visited
        st.push(u);
    }

    vector<int> topoSort(vector<vector<int>>& edges, int& n)
    {
        // create adjacency list
        unordered_map<int, vector<int>> adj;
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        vector<int> visited(n+1, 0);
        stack<int> st;
        vector<int> order;
        bool cycle = false;

        for(int i=1; i<=n; i++)
        {
            if(visited[i] == 0) {
                dfs(i, visited, adj, st, cycle);
                if(cycle == true)
                    return {};
            }
        }

        while(!st.empty()) {
            order.push_back(st.top());
            st.pop();
        }

        return order;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> topoRow = topoSort(rowConditions, k);
        vector<int> topoCol = topoSort(colConditions, k);

        if(topoRow.empty() || topoCol.empty())      // found cycle, answer not possible
            return {};

        vector<vector<int>> res(k, vector<int>(k, 0));

        for(int i=0; i<k; i++) {
            for(int j=0; j<k; j++) {
                if(topoRow[i] == topoCol[j])
                    res[i][j] = topoRow[i];
            }
        }

        return res;
    }
};
