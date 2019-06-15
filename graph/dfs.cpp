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
	dfs(v,s);
	
	return 0;
}
