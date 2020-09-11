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
    
    //static graph adj list
    //0->1->5
    //1->2->3
    //2->4
    //3->4
    //5->3
    int n=6; // number of vertices
    vector<vector<int>> adj(n); // adjacency list of graph
    
    adj[0].push_back(1);
    adj[0].push_back(5);

    adj[1].push_back(2);
    adj[1].push_back(3);

    adj[2].push_back(4);
    
    adj[3].push_back(4);
    
    adj[5].push_back(3);
    
    vector<bool> vis(n, false); //visited array
    vector<int> ans; //topological sort
    TopologicalSort().sort(n, vis, adj, ans);

    for(auto x: ans)
        cout<<x<<" ";

    return 0;
}