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

void bfs(vector <vector<int>> v, int s){
	queue<int> q;
	int vis[v.size()] = {0};
	q.push(s);
	vis[q.front()]=1;
	while(!q.empty()){
		cout<<q.front()<<" ";
		for(int i=0;i<v[q.front()].size();i++){
			if(!vis[v[q.front()][i]]){
				q.push(v[q.front()][i]);
				vis[v[q.front()][i]]=1;
			}
		}
		q.pop();
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
	bfs(adj,s);
	
	return 0;
}
