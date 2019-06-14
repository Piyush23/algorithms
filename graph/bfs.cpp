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
	//taking input
	int n,e;
	cout<<"vertices: ";cin>>n;
	cout<<"edges: ";cin>>e; //vertices, edges
	
	vector <vector <int>> v(n);
	int i,j; //vertex 1, vertex 2
	
	for(int k=0; k<e;k++){
		cout<<"edge "<<k+1<<" : ";
		cin>>i>>j;
		v[i].push_back(j);
		v[j].push_back(i); //for undirected graph
	}
	
	printAdjList(v);
	int s;
	cout<<"start vertex: ";cin>>s;
	bfs(v,s);
	
	return 0;
}
