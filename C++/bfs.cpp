int vis[N], dist[N] ;
vector<int> g[N] ;

void bfs(int k)
{
	queue<int> q;
	q.push(k) ;
	vis[k] = 1 ;
	
	while(!q.empty())
	{
		int node = q.front() ;
		q.pop() ;
		for(auto it : g[node])
		{
			if(!vis[it])
			{
				dist[it] = dist[node] + 1 ;
				vis[it] = 1 ;
				q.push(it);
			}
		}
	}
}
