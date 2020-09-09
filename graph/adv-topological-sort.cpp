#include "iostream"
#include "bits/stdc++.h"
using namespace std;

class TopologicalSort{
    public:
    void sort(int n, vector<bool>& vis, vector<vector<int>>& adj, vector<int>& ans){
        for(int i=0; i<n; i++){
            if(!vis[i])
                dfs(i, vis, adj, ans);
        }
        reverse(ans.begin(), ans.end());
    }

    void dfs(int v, vector<bool>& vis, vector<vector<int>>& adj, vector<int>& ans){
        vis[v] = true;
        for(int u: adj[v]){
            if(!vis[u])
                dfs(u, vis, adj, ans);
        }
        ans.push_back(v);
    };
};

int main(){
    int n=6; // number of vertices
    vector<vector<int>> adj(n); // adjacency list of graph
    vector<bool> vis(n, false); //visited array
    vector<int> ans; //topological sort
    
    //static graph
    //0->1
    adj[0].push_back(1);

    //1->2->3
    adj[1].push_back(2);
    adj[1].push_back(3);

    //2->4
    adj[2].push_back(4);
    
    //3->4
    adj[3].push_back(4);
    
    //5->3
    adj[5].push_back(3);
    

    TopologicalSort().sort(n, vis, adj, ans);

    for(auto x: ans)
        cout<<x<<" ";

    return 0;
}