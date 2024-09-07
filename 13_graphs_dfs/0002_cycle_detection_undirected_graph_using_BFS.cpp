/*
https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool isCycleBFS(vector<int> adj[], int u, vector<bool>& visited) {
        queue<pair<int, int>> q;
        
        q.push({u, -1});
        visited[u] = true;
        
        while(!q.empty()) {
            pair<int, int> P = q.front();
            q.pop();
            int source = P.first;
            int parent = P.second;
            
            for(auto& v : adj[source]) {
                if(!visited[v]) {
                    visited[v] = true;
                    q.push({v, source});
                }
                else if(v != parent) {
                    return true;
                }
            }
        }
        
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        
        for(int i=0; i<V; i++) {
            if(!visited[i] && isCycleBFS(adj, i, visited))
                return true;
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
