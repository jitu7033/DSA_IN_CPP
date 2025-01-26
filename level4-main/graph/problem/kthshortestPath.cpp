
#include<bits/stdc++.h>
using namespace std;;

#define int long long 
int mx = 100000;
int INF = 1e18;

priority_queue<int>bes[mx];
vector<pair<int,int>>adj[mx];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vector<int>ans;

void kth_shortest_path(int src, int n){

	pq.push({src,0});
	besh[src].push(0);

	while(!pq.empty()){
		auto node = pq.top();
		pq.pop();
		int currNode = node.first;
		int currDist = node.second;
		if(currDist > besh[currNode])continue;
		for(auto &i:adj[currNode]){
			int dist = currDist + i.second;
			if(besh[i.first].size() < k){
				besh[i].push(dist);
				pq.push({i.first,dist});
			}
			else if(besh[i.first].top() > dist){
				besh[i.first].pop();
				besh[i.first].push(dist);
				pq.push({i.first,dist});
			}
		}
	}

	while(!besh[n-1].empty()){
		ans.push_back(besh[n-1].top());
		besh[n-1].pop();
	}
	reverse(ans.begin(),ans.end());
}


signed main(){

}
