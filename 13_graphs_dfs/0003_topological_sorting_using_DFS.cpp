/*
https://www.geeksforgeeks.org/problems/topological-sort/1
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
        void DFS(vector<int> adj[], int u, vector<bool>& visited, stack<int>& st) {
            visited[u] = true;
            
            for(auto& v : adj[u]) {
                if(!visited[v])
                    DFS(adj, v, visited, st);
            }
            st.push(u);
        }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<bool> visited(V, false);
	    stack<int> st;
	    
	    for(int i=0; i<V; i++) {
	        if(!visited[i])
	            DFS(adj, i, visited, st);
	    }
	    
	    vector<int> res;
	    while(!st.empty()) {
	        res.push_back(st.top());
	        st.pop();
	    }
	    
	    return res;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
