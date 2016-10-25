#include <iostream>
#include <utility>
#include <vector>
#include <math.h>
#include <cmath>
#include <string.h>

using namespace std;

#define MAXV 101
#define MAXINT 999999

vector<pair<double,double> > g;
int parent[MAXV];

double d(int v, int w) {
	int a_x,a_y,b_x,b_y;
	double c;
	a_x = g[v-1].first;
	a_y = g[v-1].second;
	b_x = g[w-1].first;
	b_y = g[w-1].second;
	c = pow((double)abs(a_x - b_x),2) + pow((double)abs(a_y - b_y),2);
	c = sqrt(c);
	return c;
}

double prim(int n, int start) {
	int i,j;
	bool intree[MAXV];
	double distance[MAXV];
	int v;
	int w;
	double weight;
	double dist;

	memset(intree,0,MAXV*sizeof(bool));
	double cost=0;

	for(i=1; i<=n; i++) {
		intree[i]=false;
		distance[i]=MAXINT;
		parent[i]=-1;
	}
	distance[start]=0;
	v = start;

	while(intree[v]==false) {
		intree[v]=true;
		for(w=1; w<=n; w++) {
			if(v==w) continue;
			weight=d(v,w);
			if(distance[w]>weight && intree[w]==false) {
				distance[w] = weight;
				parent[w]=v;
			}
		}
		v=1;
		dist=MAXINT;
		for(i=2; i<=n; i++) {
			if(intree[i]==false && dist>distance[i]) {
				dist = distance[i];
				v = i;
			}
		}
		if(dist!=MAXINT) cost += dist;
	}
	return cost;
}

int main() {

	int cases,n;
	cin>>cases;
	for(int c=0; c<cases; c++) {
		g.clear();
		if(c!=0) cout<<endl;
		double x,y;
		cin>>n;
		for(int i=0; i<n; i++) {
			cin>>x>>y;
			g.push_back(make_pair(x,y));
		}
		cout << fixed;
		cout.precision(2);
		cout<<prim(n,1)<<endl;
		
	}

	return 0;
}