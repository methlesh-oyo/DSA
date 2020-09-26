#include <bits/stdc++.h>
#define vi vector<int>

using namespace std;

const int sz=1000, inf=1e9;

int n, m, u, v;

struct Node{
	int parent;
	int distance;
	string color;
};

vi adj[sz];
vector<Node> nodes(sz+1);

void BFS(int src){
	for(int i=1; i<=n; i++){
		nodes[i].color="WHITE";
		nodes[i].distance=inf;
		nodes[i].parent=-1;
	}
	nodes[src].color="GRAY";
	nodes[src].distance=0;

	queue<int> Q;
	Q.push(src);

	while(not Q.empty()){
		u=Q.front();
		Q.pop();
		for(int v: adj[u]){
			if(nodes[v].color=="WHITE"){
				nodes[v].color="GRAY";
				nodes[v].distance=nodes[u].distance+1;
				nodes[v].parent=u;
				Q.push(v);
			}
		}
		nodes[u].color="BLACK";
	}
}

void printPath(int v){
	int src=1;
	if(v==src)cout<<src<<"\n";
	else if(nodes[v].parent==-1){
		cout<<"There is not path.\n";
	}
	else{
		vi path;
		while(1){
			path.push_back(v);
			if(v==src)
				break;
			v=nodes[v].parent;
		}
        for(int i=0; i<path.size(); i++)cout<<path[i]<<" ";
        cout<<"\n";
    }
}

int main(){
	cin>>n>>m;

	for(int i=0; i<m; i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	BFS(1); // 1-indexed

	for(int i=1; i<=n; i++){
		cout<<"node "<<i<<": Distance="<<nodes[i].distance<<", Parent="<<nodes[i].parent<<", Color="<<nodes[i].color<<"\n";
	}
	printPath(8);
	return 0;
}
