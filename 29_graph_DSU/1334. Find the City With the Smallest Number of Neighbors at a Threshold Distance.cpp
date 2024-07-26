/*
https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/?envType=daily-question&envId=2024-07-26
*/

typedef pair<int, int> P;
class Solution {
private:
    void dijkstra(int n, unordered_map<int, vector<P>>& adj, vector<int>& row, int source)
    {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, source});
        fill(row.begin(), row.end(), INT_MAX);
        row[source] = 0;

        while(!pq.empty())
        {
            int d    = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto& p : adj[node]) {
                int adjNode = p.first;
                int dist    = p.second;

                if(d + dist < row[adjNode]) {
                    row[adjNode] = d + dist;
                    pq.push({d+dist, adjNode});
                }
            }
        }

    }

    int findLeastCity(int n, vector<vector<int>>& SPM, int D)
    {
        int resCity         = -1;
        int leastReachCount = INT_MAX;

        for(int i=0; i<n; i++)
        {
            int countReach = 0;
            for(int j=0; j<n; j++)
            {
                if(i != j && SPM[i][j] <= D)
                    countReach++;
            }

            if(countReach <= leastReachCount) {
                leastReachCount = countReach;
                resCity = i;
            }
        }
        return resCity;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> SPM(n, vector<int>(n, 1e9+7));
        for(int i=0; i<n; i++)
            SPM[i][i] = 0;

        unordered_map<int, vector<P>> adj;
        for(auto& edge : edges) {
            int u  = edge[0];
            int v  = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        for(int i=0; i<n; i++) {
            dijkstra(n, adj, SPM[i], i);
        }

        // find the city with least neighbor
        return findLeastCity(n, SPM, distanceThreshold);
    }
};
