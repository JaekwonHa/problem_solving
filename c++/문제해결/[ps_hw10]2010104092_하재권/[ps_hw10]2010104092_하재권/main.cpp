#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <math.h>
#include <string>
#include <iomanip>

using namespace std;

struct edge {
	int arrival;
	int start;
	int end;
};
struct node {
	int time[2401];
	vector<edge> route;
};

char name[150][100];
vector<node> graph;
map< string,int > city;
int start,arr,dep;

int DFS(int now_city, int now_time) {
	int t=-1;
	if(now_city==dep && start <= now_time) return now_time;
	if(start > now_time) return -1;
	if(graph[now_city].time[now_time] != -1) return graph[now_city].time[now_time];
	
	for(int i=0; i<graph[now_city].route.size(); i++) {
		if(graph[now_city].route[i].end > now_time) continue;
		graph[now_city].time[graph[now_city].route[i].end] = max(graph[now_city].time[graph[now_city].route[i].end], DFS(graph[now_city].route[i].arrival, graph[now_city].route[i].start));
		t = max(t, graph[now_city].time[graph[now_city].route[i].end]);
	}
	return max(graph[now_city].time[now_time], t);
}

int main() {

	int n,i,j,k,l,c=1,time_1,time_2,city_1,city_2;
	
	char buffer[100];
	

	node temp;
	for(int z=0; z<2401; z++) temp.time[z]=-1;

	cin>>n;
	while(n--) {
		graph.clear();
		cin>>i;
		for(j=0; j<i; j++) {
			cin>>name[j];
			city[name[j]]=j;
			graph.push_back(temp);
		}

		cin>>i;
		
		for(j=0; j<i; j++) {
			cin>>k;
			vector<pair<int,int> > route;
			for(l=0; l<k; l++) {
				cin>>time_1>>buffer;
				int m=city[buffer];
				
				route.push_back(pair < int,int > (time_1,m));
			}
			time_1 = route[route.size()-1].first;
			city_1 = route[route.size()-1].second;
			for(l=route.size()-2; l>=0; l--) {
				time_2 = route[l].first;
				city_2 = route[l].second;
				edge train;
				train.arrival=city_2;
				train.end=time_1;
				train.start=time_2;
				graph[city_1].route.push_back(train);
				time_1 = time_2;
				city_1 = city_2;
			}
		}
		char arr_name[100], dep_name[100];
		cin>>start>>dep_name>>arr_name;
		dep = city[dep_name];
		arr = city[arr_name];

		for(i=0; i<graph[arr].route.size(); i++) {
			graph[arr].time[graph[arr].route[i].end] = max(graph[arr].time[graph[arr].route[i].end], DFS(graph[arr].route[i].arrival, graph[arr].route[i].start));
		}

		int sol_start=0, sol_end=9999;
		for(i=0; i<graph[arr].route.size(); i++) {
			if(sol_end > graph[arr].route[i].end) {
				if(graph[arr].time[graph[arr].route[i].end] == -1) continue;
				sol_start = graph[arr].time[graph[arr].route[i].end];
				sol_end = graph[arr].route[i].end;
			}
		}

		cout<<"Scenario "<<c++<<endl;
		if(sol_end==9999) {
			cout<<"No connection"<<endl;
		} else {
			cout<<"Departure "<<setw(4)<<setfill('0')<<sol_start<<" "<<dep_name<<endl;
			cout<<"Arrival   "<<setw(4)<<setfill('0')<<sol_end<<" "<<arr_name<<endl;
		}
		cout<<endl;
	}

	return 0;
}