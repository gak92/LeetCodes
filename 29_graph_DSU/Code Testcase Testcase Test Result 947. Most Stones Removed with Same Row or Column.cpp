/*
https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
*/

class Solution {
private:
    vector<int> parent;
    vector<int> rank;
    int n;

    int find(int i) {
        if(parent[i] != i)
            parent[i] = find(parent[i]);

        return parent[i];
    }

    void Union(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if(root_i != root_j) {
            if(rank[root_i] > rank[root_j])
                parent[root_j] = root_i;
            else if(rank[root_j] > rank[root_i])
                parent[root_i] = root_j;
            else
                parent[root_j] = root_i;
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);
        rank.resize(n);

        for(int i=0; i<n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    Union(i, j);
            }
        }

        int groups = 0;
        for(int i=0; i<n; i++) {
            if(parent[i] == i)
                groups++;
        }

        return n - groups;
    }
};
