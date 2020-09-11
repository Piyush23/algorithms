#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printAdjList(vector < vector<int>> v){
	for(int i=0;i<v.size();i++){
		cout<<"From vertex "<<i;
		for(int j=0;j<v[i].size();j++){
			cout<<"--->"<<v[i][j];
		}
		cout<<endl;
	}
}

void dfs(vector <vector<int>> v, int st){
	stack<int> s;
	int t;
	int vis[v.size()] = {0};
	s.push(st);
	vis[s.top()]=1;
	while(!s.empty()){
		cout<<s.top()<<" ";
		t = s.top();
		s.pop();
		for(int i=0;i<v[t].size();i++){
			if(!vis[v[t][i]]){
				s.push(v[t][i]);
				vis[v[t][i]]=1;
			}
		}
		
	}
}

int main(){
	//static graph (directed) adj list
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
	
	printAdjList(adj);
	int s;
	cout<<"start vertex: ";cin>>s;
	dfs(adj,s);
	
	return 0;
}
