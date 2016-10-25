#include <iostream>
#include <utility>
#include <algorithm>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

using namespace std;

int main() {

	typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::bidirectionalS> Graph;

	enum{A,B,C,D,E,N};
	const int num_vertices = N;
	const char* name="ABCDE";

	typedef std::pair<int ,int> Edge;
	Edge edge_array[]= {
		Edge(A,B), Edge(A,D), Edge(A,D), Edge(A,D), Edge(C,A), Edge(D,C),
		Edge(C,E), Edge(B,D), Edge(D,E) };
	const int num_edges = sizeof(edge_array)/sizeof(edge_array[0]);

	//Graph g(num_vertices);
	Graph g(edge_array, edge_array+sizeof(edge_array)/sizeof(Edge), num_vertices);

	//for(int i=0; i<num_edges; ++i)
	//	boost::add_edge(edge_array[i].first, edge_array[i].second, g);
	
	typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;

	typedef boost::property_map<Graph, boost::vertex_index_t>::type indexMap;
	indexMap index = get(boost::vertex_index, g);

	std::cout << "vectices(g) = ";
	
	typedef boost::graph_traits<Graph>::vertex_iterator vertex_iter;
	std::pair<vertex_iter, vertex_iter> vp;
	for(vp=boost::vertices(g); vp.first!=vp.second; ++vp.first) {
		Vertex v = *vp.first;
		std::cout << index[v] << " ";
	}
	std::cout<<std::endl;
	

	std::cout << "edges(g) = ";
	boost::graph_traits<Graph>::edge_iterator ei, ei_end;
	for(boost::tie(ei, ei_end) = edges(g); ei!=ei_end; ++ei)
		std::cout<< "(" << index[boost::source(*ei, g)] << index[boost::target(*ei,g)] << ")" ;
	std::cout << std::endl;

	return 0;



}