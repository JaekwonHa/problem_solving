#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct edge {
	string name;
	int start;
	int traveling;
};
struct node {
	string name;
	int blood;
	int time;
	
	vector<edge> route;
};
list<node> graph;
string start_city, dest_city;
int result;
queue<node> solution;

int main() {

	int n,i,j, z=1,start_time, traveling_time;
	list<node>::iterator it;

	cin>>n;
	while(n--) {
		graph.clear();
		result=0;
		cin>>i;
		for(j=0; j<i; j++) {
			cin>>start_city>>dest_city>>start_time>>traveling_time;

			start_time%=24;
			if((6<=start_time && start_time<18) || (start_time < 6 && start_time+traveling_time > 6) || (start_time >= 18 && start_time+traveling_time > 30)) continue;


			edge train;
			train.name = dest_city;
			train.start = start_time;
			train.traveling = traveling_time;

			list<node>::iterator it;
			for(it = graph.begin(); it!=graph.end(); it++) {
				if(it->name == start_city) {
					it->route.push_back(train);
					break;
				}
			}
			if(it==graph.end()) {
				node city;
				city.name=start_city;
				city.blood=200;
				city.time=0;
				city.route.push_back(train);
				graph.push_back(city);
			}
		}
		cin>>start_city>>dest_city;
		if(start_city==dest_city) {
			cout<<"Test Case "<<z++<<".\n";
			cout << "Vladimir needs 0 litre(s) of blood.\n";
			continue;
		}
		
		for(it = graph.begin(); it!=graph.end(); it++) if(it->name == dest_city) break;
		if(it==graph.end()) {
			node city;
			city.name=dest_city;
			city.blood=200;
			city.time=0;
			graph.push_back(city);
		}

		node st,cur,temp;
		for(it=graph.begin(); it!=graph.end(); it++) {
			if(it->name == start_city) st=*it;
		}
		st.time=0;
		solution.push(st);
		while(!solution.empty()) {
			cur = solution.front();
			solution.pop();
			for(int i=0; i<cur.route.size(); i++) {
				temp.blood=cur.blood;
				temp.time=cur.time;
				temp.name=cur.route.at(i).name;
				int time;

				if(temp.blood==200) {
					temp.blood=0;
				} else if (temp.time!=cur.route.at(i).start) {
					if(temp.time>=18) {
						if(temp.time < cur.route.at(i).start || cur.route.at(i).start < 6) temp.blood+=0;
						else temp.blood+=1;
					} else {
						if(temp.time < cur.route.at(i).start && cur.route.at(i).start < 6) temp.blood+=0;
						else temp.blood+=1;
					}
				}
				
				time=cur.route.at(i).start+cur.route.at(i).traveling;
				if(time>24) time=time%24;
				temp.time=time;

				for(it=graph.begin(); it!=graph.end(); it++) {
					if(it->name == temp.name) {
						if(it->blood == temp.blood) {
							if((it->time<12 && temp.time>12) || (it->time>12 && temp.time<12)) {
								if(it->time < temp.time) {
									it->blood=temp.blood;
									it->time=time;
									temp.route=it->route;
									solution.push(temp);
								}
							} else {
								if(it->time > temp.time) {
									it->blood=temp.blood;
									it->time=time;
									temp.route=it->route;
									solution.push(temp);
								}
							}
						} else if(it->blood > temp.blood) {
							it->blood=temp.blood;
							it->time=time;
							temp.route=it->route;
							solution.push(temp);
						}
						break;
					}
				}
			}
		}
		cout<<"Test Case "<<z++<<".\n";
		for(it = graph.begin(); it!=graph.end(); it++) {
			if(it->name == dest_city) {
				if(it->blood==200) cout << "There is no route Vladimir can take.\n";
				else cout << "Vladimir needs " << it->blood << " litre(s) of blood.\n";
				break;
			}
		}
	}

	return 0;
}