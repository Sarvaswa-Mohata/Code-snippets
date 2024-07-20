void dfs(int i, map<int,vector<int>>& mp, vector<bool>& vis){
	if(vis[i]) return;
	vis[i]=true;
	for(auto it:mp[i]){
		// cout<<i<<"-"<<it<<endl;
		dfs(it, mp, vis);
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
		dfs(i, mp, vis);
	}
}