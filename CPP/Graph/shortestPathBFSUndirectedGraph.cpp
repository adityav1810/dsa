#include<unordered_map>
#include<list>
#include <vector>
#include<queue>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// n nodes and m edges

	// create adjacency list
	unordered_map<int,vector<int>> adj;

	for(int i = 0; i<edges.size(); i++){
		adj[edges[i].first].push_back(edges[i].second);
		adj[edges[i].second].push_back(edges[i].first);
	}

	// create visited array for bfs
        unordered_map<int,bool> visited;
		unordered_map<int,int> parentMap;
		
       	visited[s] = true;
	parentMap[s] = -1;

	queue<int> q;
	q.push(s);
	// do bfs
	while(!q.empty()){
		int front = q.front();
		q.pop();
		for(auto neighbour : adj[front]){
			if(!visited[neighbour]){
				visited[neighbour] = true;
				parentMap[neighbour] = front;
				q.push(neighbour);
			}

		}

	}
	// get shortest path from parent
	vector<int> ans;
	int curr = t;
	ans.push_back(t);
	

	while(curr !=s){
		curr = parentMap[curr];
		ans.push_back(curr);
	}
	reverse(ans.begin(),ans.end());


		return ans;
	

	
}
