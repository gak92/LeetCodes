/*
https://www.geeksforgeeks.org/problems/bipartite-graph/1
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool checkBipartiteDFS(vector<int> adj[], int currNode, vector<int>& color, int currColor) {
        color[currNode] = currColor;
        
        for(auto& v : adj[currNode]) {
            if(color[v] == color[currNode])
                return false;
                
            if(color[v] == -1) {
                int colorOfV = 1 - currColor;
                
                if(checkBipartiteDFS(adj, v, color, colorOfV) == false)
                    return false;
            }
        }
        
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V, -1);
	    
	    for(int i=0; i<V; i++) {
	        if(color[i] == -1) {
	            if(checkBipartiteDFS(adj, i, color, 1) == false)
	                return false;
	        }
	    }
	    
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends
