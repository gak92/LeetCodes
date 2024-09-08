/*
https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int N, vector<int> adj[]) {
        vector<int> indegree(N, 0);
        queue<int> q;
        
        for(int u=0; u<N; u++) {
            for(auto& v : adj[u]) {
                indegree[v]++;
            }
        }
        
        int count = 0;
        for(int i=0; i<N; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                count++;
            }
        }
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            
            for(auto& v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                    count++;
                }
            }
        }
        
        if(count == N)
            return false;
            
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
