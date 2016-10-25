#include <iostream>
#include <utility>
#include <algorithm>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

using namespace boost;

// 그래프 타입 선언
typedef adjacency_list<vecS, vecS, bidirectionalS> Graph;

// 그래프의 vertex index를 property_map의 속성으로 정하여 타입 정의
typedef property_map<Graph, vertex_index_t>::type IndexMap;


template <class Graph> struct exercise_vertex {

	// functor 설정
	exercise_vertex(Graph& g_) : g(g_) {}

	// 그래프 생성
	Graph& g;

	// vertex 타입 선언 
	typedef typename graph_traits<Graph>::vertex_descriptor Vertex;

	// ()연산자 오버로딩
    void operator()(const Vertex& v) const {
      typedef graph_traits<Graph> GraphTraits;
      typename property_map<Graph, vertex_index_t>::type index = get(vertex_index, g);

	  // Out-Edges
      std::cout << "out-edges: ";
	  // out_edge iterator, edge 생성
      typename GraphTraits::out_edge_iterator out_i, out_end;
      typename GraphTraits::edge_descriptor e;
      for (boost::tie(out_i, out_end) = out_edges(v, g); out_i != out_end; ++out_i) {
		  // 역참조를 통한 out_edge 정보 출력
		  e = *out_i;
		  Vertex src = source(e, g), targ = target(e, g);
		  std::cout << "(" << index[src] << "," << index[targ] << ") ";
	  }
	  std::cout << std::endl;

	  // In-Edges
	  std::cout << "in-edges: ";
	  // in_edge iterator 생성
	  typename GraphTraits::in_edge_iterator in_i, in_end;
	  for (boost::tie(in_i, in_end) = in_edges(v,g); in_i != in_end; ++in_i) {
		  // 역참조를 통한 in_edge 정보 출력
		  e = *in_i;
		  Vertex src = source(e, g), targ = target(e, g);
		  std::cout << "(" << index[src] << "," << index[targ] << ") ";
	  }
	  std::cout << std::endl;

	  // edge 출력 후 adjacent vertices 출력
	  std::cout << "adjacent vertices: ";
      typename graph_traits<Graph>::adjacency_iterator ai;
	  typename graph_traits<Graph>::adjacency_iterator ai_end;
	  for (boost::tie(ai, ai_end) = adjacent_vertices(v, g); ai != ai_end; ++ai){
		  // 역참조를 통한 adjacent vertex 출력
		  std::cout << index[*ai] <<  " ";
	  }
	  std::cout << std::endl;
	}
};

int main(int, char*[]) {

	// Constructing a Graph

	
	// vertex 이름, 개수 설정
	enum {A,B,C,D,E,N};
	const int num_vertices = N;
	const char* name = "ABCDE";
	
	// edge 정보, 개수 설정
	typedef std::pair<int, int> Edge;
	Edge edge_array[] =
	{ Edge(A,B), Edge(A,D), Edge(C,A), Edge(D,C), Edge(C,E), Edge(B,D), Edge(D,E) };
	const int num_edges = sizeof(edge_array)/sizeof(edge_array[0]);
	// 그래프 생성
	Graph g(num_vertices);
	// 그래프에 edge 추가
	for(int i=0; i<num_edges; i++)
		add_edge(edge_array[i].first, edge_array[i].second, g);

	// Accessing the Vertex Set

	// vectex 타입 이름 정의
	typedef graph_traits<Graph>::vertex_descriptor Vertex;
	IndexMap index = get(vertex_index, g);

	// vertex에 접근하여 출력
	std::cout<<"vertices(g) = ";
	// vertex iterator 타입 정의
	typedef graph_traits<Graph>::vertex_iterator vertex_iter;
	std::pair<vertex_iter, vertex_iter>vp;
	for(vp=vertices(g); vp.first != vp.second; ++vp.first) {
		// 역참조를 통해 vp.first의 value에 해당하는 vertex의 이름 출력
		Vertex v = *vp.first;
		std::cout << index[v] <<" ";
	}
	std::cout << std::endl;

	// Accessing the Edge Set

	// edge_iterator 타입 정의
	std::cout << "edges(g) = ";
    graph_traits<Graph>::edge_iterator ei, ei_end;
	// tie 함수를 통해 ei, ei_end 동시에 리턴
    for (boost::tie(ei, ei_end) = edges(g); ei != ei_end; ++ei)
		// source, target 함수를 통해 출발지와 도착지를 출력
        std::cout << "(" << index[source(*ei, g)] 
                  << "," << index[target(*ei, g)] << ") ";
    std::cout << std::endl;

	// functor를 이용한 for each
	std::for_each(vertices(g).first, vertices(g).second, exercise_vertex<Graph>(g));


	return 0;
}