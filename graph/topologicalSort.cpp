#include <bits/stdc++.h>

using namespace std;

void printEdges(vector <vector<int>> v){
	cout<<endl<<" --- Edges ---"<<endl; 
	for(int i=0;i<v.size();i++){
		cout<<i<<" --> ";
		for(int j=0;j<v[i].size();j++){
			cout<<" "<<v[i][j];
		}
		cout<<endl;
	}
	cout<<"----------------"<<endl;
}

void topoSort(vector <vector <int>> v){
	int n = v.size();
	int vis[n] = {0};
	int indeg[n] = {0};
	
	//init indegree
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			int vertex = v[i][j];
			indeg[vertex]++;
		}
	}
	
	cout<<"Indeg"<<endl;
	for(int i=0;i<n;i++)
		cout<<indeg[i]<<" ";
	cout<<endl;
	
	//find all with indegree zero in push in queue
	queue <int> q;
	
	for(int i=0;i<n;i++){
		cout<<endl<<"indegree of "<<i;
		if(!indeg[i]){
			q.push(i);
			cout<<"pushed "<<i<<endl;
		}
	}
	
	cout<<endl<<"Topological sort"<<endl;
	//while q not empty
	while(!q.empty()){
		int f = q.front();
		cout << f <<" ";
		q.pop();
		for(int i=0;i<v[f].size();i++){
			int vertex = v[f][i];
			if(!--indeg[vertex])
				q.push(vertex);
		}
	}
	
}

int main(){
	int n,e;
	cin>>n>>e; // nodes & edges
	cout<<"nodes "<<n<<" edges "<<e<<endl;
	
	//adj list
	vector <vector<int>> edges(e);
	int u,v;
	
	cout<<"Enter edges"<<endl;
	
	for(int i=0;i<e;i++){
		cin>>u>>v;
		edges[u].push_back(v);
	}
	
	printEdges(edges);
	
	topoSort(edges);
	
	return 0;
}
