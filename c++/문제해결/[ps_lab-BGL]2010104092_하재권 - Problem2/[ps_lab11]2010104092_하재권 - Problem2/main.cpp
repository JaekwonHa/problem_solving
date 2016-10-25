#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/range/irange.hpp>
#include <boost/pending/indirect_cmp.hpp>

#include <iostream>




using namespace boost;
template <typename TimeMap> class dfs_time_visitor : public default_dfs_visitor
{
	typedef typename boost::property_traits < TimeMap >::value_type T;
public:
	dfs_time_visitor(TimeMap dmap, TimeMap fmap, T & t)
		: m_dtimemap(dmap), m_ftimemap(fmap), m_time(t) {
	}
	template <typename Vertex, typename Graph>
	void discover_vertex(Vertex u, const Graph & g) const
	{
		put(m_dtimemap, u, m_time++);
	}
	template <typename Edge, typename Graph>
	void tree_edge(Edge e, Graph g) const 
	{
		std::cout<<e<<std::endl;
	}
	template <typename Vertex, typename Graph>
	void finish_vertex(Vertex u, const Graph & g) const
	{
		put(m_ftimemap, u, m_time++);
	}
	TimeMap m_dtimemap;
	TimeMap m_ftimemap;
	T & m_time;
};

typedef adjacency_list<vecS, vecS, directedS> graph_t;
typedef graph_traits<graph_t>::vertices_size_type size_type;
typedef std::pair<int,int>E;
typedef graph_traits<graph_t>::vertex_descriptor Vertex;
typedef size_type* Iiter;

int main() {

	// 방문 vertex의 이름들과 끝을 설정
	enum {u,v,w,x,y,z,N};
	char name[] = {'u','v','w','x','y','z'};

	// edge 들을 설정
	E edge_array[] = {E(u,v), E(u,x), E(x,v), E(y,x), E(v,y), E(w,y), E(w,z), E(z,z)};

	
	graph_t g(N);
	for(std::size_t j=0; j<sizeof(edge_array)/sizeof(E); ++j)
		add_edge(edge_array[j].first, edge_array[j].second, g);

	std::vector<size_type> dtime(num_vertices(g));
	std::vector<size_type> ftime(num_vertices(g));
	size_type t = 0;
	dfs_time_visitor<size_type *>vis(&dtime[0], &ftime[0], t);

	depth_first_search(g, visitor(vis));

	std::vector<size_type> discover_order(N);
	integer_range<size_type> r(0,N);
	std::copy(r.begin(), r.end(), discover_order.begin());
	std::sort(discover_order.begin(), discover_order.end(),
		indirect_cmp<Iiter, std::less<size_type> >(&dtime[0]));
	std::cout << "order of discover: ";
	int i;
	for(i=0; i<N; i++)
		std::cout<<name[discover_order[i]] << " ";

	std::vector< size_type > finish_order(N);
	std::copy(r.begin(), r.end(), finish_order.begin());
	std::sort(finish_order.begin(), finish_order.end(),
		indirect_cmp < Iiter, std::less < size_type> >(&ftime[0]));
	std::cout << std::endl << "order of finish: ";
	for(i=0; i<N; i++)
		std::cout << name[finish_order[i]] << " ";
	std::cout << std::endl;



	return EXIT_SUCCESS;
}