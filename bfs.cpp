void bfs(int i, map<int,vector<int>>& mp, vector<bool>& vis){
	queue<int> q;
	q.push(i);
	while(!q.empty()){
		auto it=q.front();
		q.pop();
		vis[it]=true;
		// cout<<it<<" ";
		for(auto jt:mp[it]){
			if(!vis[jt])
			q.push(jt);
		}
	}
	return;
}

void solve() {
	int v,n;
	cin>>v>>n;
	map<int,vector<int>> mp;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		mp[a].push_back(b);
		mp[b].push_back(a);
	}	
	vector<bool> vis(v+1, false);
	for(int i=1;i<=v;i++){
		if(!vis[i])
		bfs(i, mp, vis);
	}
}