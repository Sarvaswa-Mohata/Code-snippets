int C(int n, int r){
	if(r>n) return 0;
	int ans=1;
	if(r>n-r) r=n-r;
	for(int i=r;i>=1;i--){	
		ans*=(n-r+i);
		ans/=(r-i+1);
	}
	return ans;
}
