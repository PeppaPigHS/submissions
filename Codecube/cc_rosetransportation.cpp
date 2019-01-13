#include <bits/stdc++.h>

using namespace std;

struct edge {
	int u,v,w;
	edge(int u,int v,int w) : u(u),v(v),w(w) {}
	friend bool operator<(const edge &a,const edge &b) {
		return a.w>b.w;
	}
};

const int N = 1e5+5;

int n,m;
long long ans;
int cost[N],par[N];
vector<edge> g;

int find(int u) {
	return par[u] = par[u]==u? u : find(par[u]);
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) {
		scanf("%d",&cost[i]);
		par[i] = i;
	}
	while(m--) {
		int u,v;
		scanf("%d%d",&u,&v);
		u--,v--;
		g.emplace_back(u,v,cost[u]+cost[v]);
	}
	sort(g.begin(),g.end());
	int cnt=0;
	for(edge e : g) {
		int pu = find(e.u);
		int pv = find(e.v);
		if(pu!=pv) {
			par[pu] = pv;
			ans+=e.w;
			cnt++;
		}
		if(cnt==n-1) break;
	}

	printf("%lld",ans);

	return 0;
}