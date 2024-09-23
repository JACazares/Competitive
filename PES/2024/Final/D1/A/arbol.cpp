#include <iostream>
#include <vector>

using ll = long long;
using pii = std::pair<int, int>;
using vi = std::vector<int>;
using vpi = std::vector<pii>;

struct return_ans
{
	ll total[2], root[2];
};

std::ostream& operator<<(std::ostream& os, const return_ans& ans)
{
	os << "{Total: " << ans.total[0] << " " << ans.total[1] << "\n";
	os << "Root: " << ans.root[0] << " " << ans.root[1] << "}\n";
	return os;
}

int N;
std::vector<vpi> Graph;

return_ans solve(int node, int parent, int bit)
{
	ll total[2] = {0, 0}, root[2] = {0, 0};

	for(auto neighbor : Graph[node])
	{
		int child = neighbor.first;
		int weight = neighbor.second;
		
		if(child != parent)
		{
			auto child_ans = solve(child, node, bit);

			total[0] += child_ans.total[0];
			total[1] += child_ans.total[1];
			
			if(weight & (1 << bit))
			{
				total[0] += root[0] * child_ans.root[1];
				total[0] += root[1] * (child_ans.root[0] + 1);
				total[0] += child_ans.root[1];

				total[1] += root[0] * (child_ans.root[0] + 1);
				total[1] += root[1] * child_ans.root[1];
				total[1] += (child_ans.root[0] + 1);
				
				root[0] += child_ans.root[1];
				root[1] += (child_ans.root[0] + 1);
			}
			else
			{
				total[0] += root[0] * (child_ans.root[0] + 1);
				total[0] += root[1] * child_ans.root[1];
				total[0] += (child_ans.root[0] + 1);

				total[1] += root[0] * child_ans.root[1];
				total[1] += root[1] * (child_ans.root[0] + 1);
				total[1] += child_ans.root[1];
				
				root[0] += (child_ans.root[0] + 1);
				root[1] += child_ans.root[1];
			}
		}
	}
	
	return_ans node_ans;
	node_ans.total[0] = total[0];
	node_ans.total[1] = total[1];
	node_ans.root[0] = root[0];
	node_ans.root[1] = root[1];

	return node_ans;
}

ll Encuentra_xor(int _N, vi u, vi v, vi w)
{
	N = _N;
	Graph.clear();
	Graph.resize(N, vpi());
	int max_weight = 0;
	for(int i = 0; i < N - 1; i++)
	{
		Graph[u[i]].push_back({v[i], w[i]});
		Graph[v[i]].push_back({u[i], w[i]});
		max_weight = std::max(max_weight, w[i]);
	}
	
	ll ans = 0;
	for(int bit = 0; (1 << bit) <= max_weight; bit++)
		ans += solve(0, -1, bit).total[1] * (1 << bit);
	
	return ans;
}
