/*
https://leetcode.com/problems/modify-graph-edge-weights/
*/
// Solve using Dijkstras Algo

class Solution {
private:
    typedef long long ll;
    const int LARGE_VAL = 2e9;
    typedef pair<long, long> P;

    ll DijkstraAlgo(int n, vector<vector<int>>& edges, int src, int dest) {
        unordered_map<ll, vector<pair<ll, ll>>> adj;

        for(auto& edge : edges) {
            if(edge[2] != -1) {
                int u  = edge[0];
                int v  = edge[1];
                int wt = edge[2];

                adj[u].push_back({v, wt});
                adj[v].push_back({u, wt});
            }
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<ll> res(n, INT_MAX);
        vector<bool> visited(n, false);

        res[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {
            ll currDist = pq.top().first;
            ll currNode = pq.top().second;
            pq.pop();

            if(visited[currNode] == true)
                continue;

            visited[currNode] = true;
            for(auto&[nbr, wt] : adj[currNode]) {
                if(res[nbr] > currDist + wt) {
                    res[nbr] = currDist + wt;
                    pq.push({res[nbr], nbr});
                }
            }

        }

        return res[dest];    
    }

public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        ll currShortestDist = DijkstraAlgo(n, edges, source, destination);

        // 1st case
        if(currShortestDist < target) {
            return {};
        }

        bool matchedTarget = (currShortestDist == target);

        // 2nd case
        if(matchedTarget == true) {
            for(auto& edge : edges) {
                if(edge[2] == -1)
                    edge[2] = LARGE_VAL;
            }
            return edges;
        }

        // 3rd case
        for(auto& edge : edges) {
            if(edge[2] == -1) {
                edge[2] = (matchedTarget == true) ? LARGE_VAL : 1;

                if(matchedTarget != true) {
                    ll newShortestDist = DijkstraAlgo(n, edges, source, destination);

                    if(newShortestDist <= target) {
                        matchedTarget = true;
                        edge[2] += (target - newShortestDist);
                    }                
                }
            }
        }

        if(matchedTarget == false)
            return {};

        return edges;
    }
};
