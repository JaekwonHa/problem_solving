#include <boost/config.hpp>
#include <iostream>
#include <fstream>

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

using namespace boost;

int main(int, char*[]) {

	// 가중치 리스트 그래프 타입선언
	typedef adjacency_list < listS, vecS, directedS, no_property, property < edge_weight_t, int > > graph_t;
	typedef adjacency_list < listS, vecS, directedS, no_property, property < edge_weight_t, int > > graph_t;
	// vertex 와 edge 타입 선언
	typedef graph_traits < graph_t >::vertex_descriptor vertex_descriptor;
	typedef graph_traits < graph_t >::edge_descriptor edge_descriptor;
	typedef std::pair<int, int> Edge;
	
	// vertex 설정
	const int num_nodes = 5;
	enum nodes { A, B, C, D, E };
	char name[] = "ABCDE";
	// edge 설정
	Edge edge_array[] = { Edge(A, C), Edge(B, B), Edge(B, D), Edge(B, E), Edge(C, B), Edge(C, D), Edge(D, E), Edge(E, A), Edge(E, B) };
	// weight 설정
	int weights[] = { 1, 2, 1, 2, 7, 3, 1, 1, 1 };
	// edge 개수 설정
	int num_arcs = sizeof(edge_array) / sizeof(Edge);

	// 시작점과 끝점 입력
	char a,b;
	int st,ds;
	std::cout<<"검색할 최단경로의 시작점과 끝점을 입력하세요. ex) A D"<< std::endl;
	std::cin>>a;
	std::cin>>b;

	// 입력받은 시작점과 끝점을 숫자로 변경
	if(a=='A') st=A;
	if(a=='B') st=B;
	if(a=='C') st=C;
	if(a=='D') st=D;
	if(a=='E') st=E;
	if(b=='A') ds=A;
	if(b=='B') ds=B;
	if(b=='C') ds=C;
	if(b=='D') ds=D;
	if(b=='E') ds=E;

#if defined(BOOST_MSVC) && BOOST_MSVC <= 1300
	graph_t g(num_nodes);
	property_map<graph_t, edge_weight_t>::type weightmap = get(edge_weight, g);
	for (std::size_t j = 0; j < num_arcs; ++j) {
		edge_descriptor e;
		bool inserted;
		boost::tie(e, inserted) = add_edge(edge_array[j].first, edge_array[j].second, g);
		weightmap[e] = weights[j];
	}
#else
	graph_t g(edge_array, edge_array + num_arcs, weights, num_nodes);
	// property_map 을 만들어 edge_weight를 관리
	property_map<graph_t, edge_weight_t>::type weightmap = get(edge_weight, g);
#endif
	// 부모 vertex를 관리하는 p 생성
	std::vector<vertex_descriptor> p(num_vertices(g));
	// 거리를 관리하는 d 생성
	std::vector<int> d(num_vertices(g));
	vertex_descriptor s = vertex(st, g);

#if defined(BOOST_MSVC) && BOOST_MSVC <= 1300
	// VC++ has trouble with the named parameters mechanism
	property_map<graph_t, vertex_index_t>::type indexmap = get(vertex_index, g);
	dijkstra_shortest_paths(g, s, &p[0], &d[0], weightmap, indexmap, 
                          std::less<int>(), closed_plus<int>(), 
                          (std::numeric_limits<int>::max)(), 0,
                          default_dijkstra_visitor());
#else
	// s 에서 부터 시작하여 최단경로 계산
	dijkstra_shortest_paths(g, s, predecessor_map(&p[0]).distance_map(&d[0]));
#endif

	
	std::cout << "끝점 <- 시작점" << std::endl;
	graph_traits < graph_t >::vertex_iterator vi, vend;
	for (boost::tie(vi, vend) = vertices(g); vi != vend; ++vi) {
		// 도착점을 찾았다면 역추적 시작
		if(*vi==ds) {
			// 도착점 출력
			std::cout << name[*vi] << " <- ";
			int temp = p[*vi];
			while(temp!=st) {
				// 그 이전 방문 vertex 출력
				std::cout << name[temp] << " <- ";
				temp = p[temp];
			}
			// 시작점 출력
			std::cout << name[temp];
			break;
		}
	}
	std::cout << std::endl;
	
	system("pause");
	return EXIT_SUCCESS;
}