#include <boost/config.hpp>
#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/prim_minimum_spanning_tree.hpp>
#include <math.h>
#include <cmath>
#include <utility>
#include <vector>

using namespace boost;

#define MAXV 101

typedef adjacency_list < vecS, vecS, undirectedS, property<vertex_distance_t, int>, property < edge_weight_t, double > > Graph;
typedef std::pair < int, int >E;

std::vector<std::pair<double,double> > node;

double d(int v, int w) {
	int a_x,a_y,b_x,b_y;
	double c;
	a_x = node[v].first;
	a_y = node[v].second;
	b_x = node[w].first;
	b_y = node[w].second;
	c = pow((double)abs(a_x - b_x),2) + pow((double)abs(a_y - b_y),2);
	c = sqrt(c);
	return c;
}
int main() {

	int cases;
	
	
	std::cin>>cases;
	for(int c=0; c<cases; c++) {
		node.clear();
		if(c!=0) std::cout<<std::endl;
		double x,y,cost=0;
		int num_nodes;
		std::cin>>num_nodes;
		for(int i=0; i<num_nodes; i++) {
			std::cin>>x>>y;
			node.push_back(std::make_pair(x,y));
		}
		E *edges = new E[(num_nodes*(num_nodes-1))/2];
		double weights[MAXV];
		int q=0;
		for(int i=0; i<num_nodes; i++) {
			for(int j=i+1; j<num_nodes; j++) {
				double dist = d(i,j);
				edges[q] = E(i, j);
				weights[q] = dist;
				q++;
			}
		}
		Graph g(edges, edges + (sizeof(E)*(num_nodes*(num_nodes-1))/2) / sizeof(E), weights, q);
		property_map<Graph, edge_weight_t>::type weightmap = get(edge_weight, g);

		std::vector < graph_traits < Graph >::vertex_descriptor > p(num_vertices(g));
		prim_minimum_spanning_tree(g, &p[0]);
		/*
		try
		{
			  prim_minimum_spanning_tree(g, &p[0]);
		}
		catch ( std::exception& e )
		{
			e.what();
		}
		*/
		for (std::size_t i = 0; i != p.size(); ++i) {
			if (p[i] != i) {
				cost += d(i,p[i]);
			}
		}
		std::cout << std::fixed;
		std::cout.precision(2);
		std::cout<<cost<<std::endl;
	}
	return 0;
}