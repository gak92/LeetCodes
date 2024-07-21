/*
https://leetcode.com/problems/build-a-matrix-with-conditions/description/?envType=daily-question&envId=2024-07-21
*/

// Kahn's algorithm (topological sorting)

class Solution {
private:
    vector<int> topoSort(vector<vector<int>>& edges, int& n)
    {
        // create adjacency list
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n+1, 0);

        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        int count = 0;

        for(int i=1; i<=n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                count++;
            }
        }

        vector<int> order;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);

            for(auto& v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                    count++;
                }
            }
        }

        if(count != n)
            return {};

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
