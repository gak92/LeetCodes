/*
https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    void  BFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, vector<int>& res) {
        queue<int> q;
        
        q.push(u);
        visited[u] = true;
        res.push_back(u);
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            
            for(auto& v : adj[u]) {
                if(!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                    res.push_back(v);
                }
            }
        }
    }
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> mp[]) {
        // Code here
        unordered_map<int, vector<int>> adj;
        
        for(int u=0; u<V; u++) {
            for(auto it=mp[u].begin(); it!=mp[u].end(); it++) {
                adj[u].push_back(*it);
            }
        }
        
        vector<int> res;
        vector<bool> visited(V, false);
        BFS(adj, 0, visited, res);
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
